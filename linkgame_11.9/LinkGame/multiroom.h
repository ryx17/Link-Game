#ifndef MULTIROOM_H
#define MULTIROOM_H

#include <QWidget>
#include <QPushButton>
#include <iostream>
#include <cstdio>
#include <QLayout>
#include <QWidget>
#include <QString>
#include <QTimer>
#include <QProgressBar>
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include <QLabel>
#include <QImage>
#include <QSound>
#include <QMouseEvent>
#include <QGraphicsEffect>
#include <QFrame>
#include <QWidget>
// added by xuewei, 网络通信需要头文件
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QHostAddress>
#include <QMessageBox>

namespace Ui {
class MultiRoom;
}

class MultiRoom : public QWidget
{
    Q_OBJECT

public:
    explicit MultiRoom(QWidget *parent = nullptr);
    ~MultiRoom();

private:
    Ui::MultiRoom *ui;
    int roomStatus=0;//游戏状态，0为初始状态，1为主机状态，2为客户端状态
    int lastRoomStatus=0;
    // 客户端私有成员
    QTcpSocket *TcpClient;
    // 服务器端私有成员
    QTcpServer *TcpServer;
    QList<QTcpSocket*> tcpClients;
    QTcpSocket *currentClient;

protected:
    void paintEvent(QPaintEvent *event);//绘图事件

private slots:
    void on_HostButton_toggled(bool checked);
    void on_ClientButton_toggled(bool checked);
    void on_pushButtonBackToMenu_clicked();
    // 客户端槽函数
    void ClientReadData();
    void ClientReadError(QAbstractSocket::SocketError);
    // 服务器端槽函数
    void NewConnectionSlot();
    void disconnectedSlot();
    void ServerReadData();
    void on_pushButtonConnect_clicked();
    void on_pushButtonBuild_clicked();
    void on_pushButtonStart_clicked();
};


#endif // MULTIROOM_H
