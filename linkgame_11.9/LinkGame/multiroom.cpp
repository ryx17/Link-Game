#include "multiroom.h"
#include "ui_multiroom.h"
#include "multiplayer.h"

void MultiRoom::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    if(roomStatus==0)//初始界面
    {
        this->setFixedSize(1200,700);//窗体大小设置
        this->setAutoFillBackground(true);
        ui->pushButtonBuild->setDisabled(true);
        ui->pushButtonConnect->setDisabled(true);
        ui->pushButtonStart->setDisabled(true);
    }
    else if(roomStatus==1)//选择作为主机
    {
        ui->pushButtonBuild->setEnabled(true);
        ui->pushButtonConnect->setDisabled(true);
    }
    else if(roomStatus==2)//选择作为客户端
    {
        ui->pushButtonConnect->setEnabled(true);
        ui->pushButtonBuild->setDisabled(true);
    }
}

MultiRoom::MultiRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiRoom)
{
    ui->setupUi(this);

    // 对客户端的初始化
    TcpClient = new QTcpSocket(this);   //实例化tcpClient
    TcpClient->abort();                 //取消原有连接
    connect(TcpClient, SIGNAL(readyRead()), this, SLOT(ClientReadData()));
    connect(TcpClient, SIGNAL(error(QAbstractSocket::SocketError)), \
                this, SLOT(ClientReadError(QAbstractSocket::SocketError)));
    // 对服务器端的初始化
    TcpServer = new QTcpServer(this);
    ui->textEditIP->setText(QNetworkInterface().allAddresses().at(1).toString());   //获取本地IP
    connect(TcpServer, SIGNAL(newConnection()), this, SLOT(NewConnectionSlot()));
}

MultiRoom::~MultiRoom()
{
    delete ui;
}

void MultiRoom::on_HostButton_toggled(bool checked)
{
    roomStatus = 1;
    update();
}

void MultiRoom::on_ClientButton_toggled(bool checked)
{
    roomStatus = 2;
    update();
}

void MultiRoom::on_pushButtonBackToMenu_clicked()
{
    this->close();
}

void MultiRoom::on_pushButtonConnect_clicked() // 客户端连接button
{
    if(ui->pushButtonConnect->text()=="Connect")
    { //连接
        TcpClient->connectToHost(ui->textEditIP->toPlainText(), ui->textEditPort->toPlainText().toInt());
        if (TcpClient->waitForConnected(1000))
        {
            ui->pushButtonConnect->setText("Disconnect");
            ui->HostButton->setDisabled(true);
            ui->ClientButton->setDisabled(true);
            TcpClient->write("Hello! Server!");
        }
    }
    else
    {  //断开连接
        TcpClient->disconnectFromHost();
        if (TcpClient->state() == QAbstractSocket::UnconnectedState || TcpClient->waitForDisconnected(1000))
        {
            ui->pushButtonConnect->setText("Connect");
        }
        ui->HostButton->setEnabled(true);
        ui->ClientButton->setEnabled(true);

    }
}


void MultiRoom::on_pushButtonBuild_clicked() // 服务器端创建房间
{
    if(ui->pushButtonBuild->text()=="Build")
    {
        bool ok = TcpServer->listen(QHostAddress::Any, ui->textEditPort->toPlainText().toInt());
        if(ok)
        {
            ui->pushButtonBuild->setText("Quit");
            ui->HostButton->setDisabled(true);
            ui->ClientButton->setDisabled(true);
            ui->pushButtonStart->setEnabled(true);
        }
    }
    else
    {
        for(int i = 0; i < tcpClients.length(); i++)//断开所有连接
        {
            tcpClients[i]->disconnectFromHost();
            bool ok = tcpClients[i]->waitForDisconnected(1000);
            if(!ok)
            {
                // 处理异常
            }
            tcpClients.removeAt(i);  //从保存的客户端列表中去除
        }
        TcpServer->close();     //不再监听端口
        ui->pushButtonBuild->setText("Build");
        ui->HostButton->setEnabled(true);
        ui->ClientButton->setEnabled(true);
        ui->pushButtonStart->setDisabled(true);
    }
}

// 客户端函数实现
void MultiRoom::ClientReadData()
{
    QByteArray buffer = TcpClient->readAll();
    ui->textBrowser2->append(buffer);
    if(buffer=="Game Start"){   //客户端收到主机发送的游戏开始标志
        Multiplayer* game=new Multiplayer(this, nullptr, TcpClient, roomStatus);
        TcpClient->write("Ready");  //向主机发送准备标志
        disconnect(TcpClient, SIGNAL(readyRead()), this, SLOT(ClientReadData()));
        game->show();   //客户端进入游戏
    }
}

void MultiRoom::ClientReadError(QAbstractSocket::SocketError)
{
    TcpClient->disconnectFromHost();
    ui->pushButtonConnect->setText("Connect");
    QMessageBox msgBox;
    msgBox.setText(tr("无法连接到服务器\n %1").arg(TcpClient->errorString()));
    msgBox.exec();
}

// 服务器端函数实现
void MultiRoom::NewConnectionSlot()
{
    currentClient = TcpServer->nextPendingConnection();
    tcpClients.append(currentClient);
    connect(currentClient, SIGNAL(readyRead()), this, SLOT(ServerReadData()));
    connect(currentClient, SIGNAL(disconnected()), this, SLOT(disconnectedSlot()));
}

void MultiRoom::disconnectedSlot()
{
    for(int i = 0; i < tcpClients.length(); i++)
    {
        if(tcpClients[i]->state() == QAbstractSocket::UnconnectedState)
        {
             tcpClients[i]->destroyed();
             tcpClients.removeAt(i);
        }
    }
}

void MultiRoom::ServerReadData()
{
    for(int i = 0; i < tcpClients.length(); i++)
    {
        QByteArray buffer = tcpClients[i]->readAll();
        if(buffer.isEmpty())    continue;
        else if(buffer=="Ready"){   //主机接收到客户端发送的准备标志
            Multiplayer* game=new Multiplayer(this, tcpClients[0], TcpClient, roomStatus);
            disconnect(tcpClients[0], SIGNAL(readyRead()), this, SLOT(ServerReadData()));   //断开连接，防止在Multiplayer类中调用Multiroom读取函数
            game->show();   //主机进入游戏
        }
        static QString IP_Port, IP_Port_Pre;
        IP_Port = tr("[%1:%2]:").arg(tcpClients[i]->peerAddress().toString().split("::ffff:")[1])\
                                     .arg(tcpClients[i]->peerPort());
        // test
        if(IP_Port != IP_Port_Pre)
            ui->textBrowser1->append(IP_Port);
        ui->textBrowser1->append(buffer);

        IP_Port_Pre = IP_Port;

        for(int i = 0; i < tcpClients.length(); i++){
            tcpClients[i]->write("Hello, Client!");
        }

    }
}

void MultiRoom::on_pushButtonStart_clicked()
{
    for(int i = 0; i < tcpClients.length(); i++){
        tcpClients[i]->write("Game Start");  //向客户端传输游戏开始标志
    }
}
