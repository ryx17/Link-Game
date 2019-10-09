#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cstdio>
#include <ctime>
#include <queue>
#include <vector>
using namespace std;

struct node
{
    int x, y, dir;
    node(int X = 0, int Y = 0, int D = 4) :x(X), y(Y), dir(D) {}
};

void MainWindow::logicInit()
{
    rowLast = 0;
    colLast = 0;
    rowNow = 0;
    colNow = 0;

    dis = new int*[MAXSIZE_X + 2];
    in = new bool**[2];
    in[0] = new bool*[MAXSIZE_X + 2];
    in[1] = new bool*[MAXSIZE_X + 2];
    for (int i = 0; i < MAXSIZE_X + 2; i++)
    {
        dis[i] = new int[MAXSIZE_Y + 2];
        in[0][i] = new bool[MAXSIZE_Y + 2];
        in[1][i] = new bool[MAXSIZE_Y + 2];
    }
    for (int i = 0; i < MAXSIZE_X + 2; ++i)
        for (int j = 0; j < MAXSIZE_Y + 2; ++j)
        {
            dis[i][j] = 3;
            in[0][i][j] = 0;
            in[1][i][j] = 0;
        }
}

void MainWindow::spfa(int x, int y)
{
    for (int i = 0; i < MAXSIZE_X + 2; ++i)
        for (int j = 0; j < MAXSIZE_Y + 2; ++j)
        {
            dis[i][j] = 3;
            in[0][i][j] = 0;
            in[1][i][j] = 0;
        }
    if (block[x][y] == 0)
    {
        qDebug() << "invalid pos:" << x << ' ' << y;
        return;
    }
    else
    {
        int xMin = MAXSIZE_X+1, xMax = 0, yMin = MAXSIZE_Y+1, yMax = 0;
        for (int col = 1; col <= MAXSIZE_X; ++col)
            for (int row = 1; row <= MAXSIZE_Y; ++row)
            {
                if (block[col][row] != 0)
                {
                    xMin = min(xMin, col-1);
                    xMax = max(xMax, col+1);
                    yMin = min(yMin, row-1);
                    yMax = max(yMax, row+1);
                }
            }
        queue<node> q;
        node p(x, y, 4);
        dis[x][y] = 0;
        q.push(p);
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            in[p.dir % 2][p.x][p.y] = 0;
            for (int i = 0; i < 4; i++)
            {
                int xNext = p.x + moveX[i];
                int yNext = p.y + moveY[i];
                if (xNext >= xMin && xNext <= xMax && \
                    yNext >= yMin && yNext <= yMax)
                {
                    int n = (p.dir == 4) || (p.dir == i) ? dis[p.x][p.y]\
                        : dis[p.x][p.y] + 1;
                    if (n <= dis[xNext][yNext] && n < 3)
                    {
                        dis[xNext][yNext] = n;
                        if (block[xNext][yNext] == 0 && in[i % 2][xNext][yNext] == 0)
                        {
                            node y(xNext, yNext, i);
                            in[i % 2][xNext][yNext] = 1;
                            q.push(y);
                        }
                    }
                }
            }
        }
    }
}

bool MainWindow::judge()
{
    return (dis[colNow][rowNow] <= 2 && \
            block[colNow][rowNow] == block[colLast][rowLast])? true: false;
}

bool MainWindow::solvable()
{
    bool flag = 0;
    for(int i = 1; i <= MAXSIZE_X; i++)
        for(int j = 1; j<= MAXSIZE_Y; j++)
        {
            if(block[i][j] != 0)
            {
                flag = 1;
                spfa(i, j);
                for(int col = 1; col <= MAXSIZE_X; col++)
                    for(int row = 1; row <= MAXSIZE_Y; row++)
                        if(block[i][j] == block[col][row] && dis[col][row] <= 2 && \
                                !(i == col && j == row))
                        {
                            qDebug() << "solvable";
                            return true;
                        }
            }
        }
    qDebug() << "insolvable";
    return flag? false: true;
}

void MainWindow::shuffle()
{
    vector<int> remain;
    for (int col = 1; col <= MAXSIZE_X; ++col)
        for(int row = 1; row <= MAXSIZE_Y; ++row)
        {
            if (block[col][row] != 0)
                remain.push_back(block[col][row]);
        }
    random_shuffle(remain.begin(), remain.end());
    for (int col = 1; col <= MAXSIZE_X; ++col)
        for(int row = 1; row <= MAXSIZE_Y; ++row)
        {
            if (block[col][row] != 0)
            {
                block[col][row] = remain.back();
                remain.pop_back();
            }
        }
}

bool MainWindow::finish()
{
    for(int col = 1; col <= MAXSIZE_X; col++)
        for(int row = 1; row <= MAXSIZE_Y; row++)
            if(block[col][row] != 0)
                return false;
    return true;
}

void MainWindow::setLabel()
{
    for(int i=1;i<=MAXSIZE_X;i++)
        for(int j=1;j<=MAXSIZE_Y;j++)
        {
            int tmp=block[i][j];
            if (tmp != 0)
            {
                ima[tmp-1].scaled(PIC_W,PIC_W,Qt::KeepAspectRatio);
                labelPicture[i][j]->setPixmap(QPixmap::fromImage(ima[tmp-1]));
                labelPicture[i][j]->setGeometry((i-1)*PIC_W+shamt.x(),(j-1)*PIC_W+shamt.y(),PIC_W,PIC_W);
                labelPicture[i][j]->setScaledContents(true);
                labelPicture[i][j]->show();
            }
            else
            {
                labelPicture[i][j]->hide();
//                    qDebug() << "zero";
            }

        }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //qDebug() << "paintEvent" << ' ' << gameStatus;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    if(gameStatus==1)//开始游戏界面
    {
        this->setFixedSize(1000,600);//窗体大小设置
        this->setAutoFillBackground(true);
        palette.setBrush(QPalette::Background,QBrush(QPixmap("./images/backGround_1.jpg")));
        this->setPalette(palette);
        ui->pushButtonStart->setVisible(true);
        ui->pushButtonSettings->setVisible(true);
        ui->pushButtonQuit->setVisible(true);
        ui->pushButtonPause->setVisible(false);
        ui->pushButtonBackToMenu->setVisible(false);
        ui->pushButtonOn->setVisible(false);
        ui->labelBGM->setVisible(false);
        ui->progressBarTimer->setVisible(false);
    }
    else
    {
        ui->pushButtonStart->setVisible(false);
        ui->pushButtonSettings->setVisible(false);
        ui->pushButtonQuit->setVisible(false);
    }

    if(gameStatus==2)//游戏界面状态
    {
        LabelPicturePause->setVisible(false);
        ui->pushButtonPause->setVisible(true);
        ui->pushButtonBackToMenu->setVisible(true);
        for(int i=0;i<16;i++)
        {
            ima[i].load(QString("./images/image_")+QString::number(i)+".jpg");
        }
        if(block[colNow][rowNow] != 0)
        {
            ima[block[colNow][rowNow]-1].scaled(PIC_W,PIC_W,Qt::KeepAspectRatio);
            QPixmap a = QPixmap::fromImage(ima[block[colNow][rowNow]-1]);
            QPixmap b(a.size());
            b.fill(Qt::transparent);
            QPainter pb(&b);
            pb.setCompositionMode(QPainter::CompositionMode_Source);
            pb.drawPixmap(0, 0, a);
            pb.setCompositionMode(QPainter::CompositionMode_DestinationIn);
            pb.fillRect(b.rect(), QColor(0, 0, 0, 200));
            pb.end();
            labelPicture[colNow][rowNow]->setPixmap(b);
            labelPicture[colNow][rowNow]->setGeometry((colNow-1)*PIC_W+shamt.x(),(rowNow-1)*PIC_W+shamt.y(),PIC_W,PIC_W);
            labelPicture[colNow][rowNow]->setScaledContents(true);
            labelPicture[colNow][rowNow]->show();
        }
    }
    if(gameStatus==3)//设置界面
    {
        ui->pushButtonOn->setVisible(true);
        ui->labelBGM->setVisible(true);
        ui->pushButtonBackToMenu->setVisible(true);
    }
    if(gameStatus==4)//暂停界面
    {
        imaPause.load("./images/backGround_2.png");
        imaPause.scaled(PIC_W*MAXSIZE_X,PIC_W*MAXSIZE_Y,Qt::KeepAspectRatio);
        LabelPicturePause->setPixmap(QPixmap::fromImage(imaPause));
        LabelPicturePause->setGeometry(shamt.x(),shamt.y(),PIC_W*MAXSIZE_X,PIC_W*MAXSIZE_Y);
        LabelPicturePause->setScaledContents(true);
        LabelPicturePause->show();
    }
    if(gameStatus==5)//游戏获胜
    {
        imaWin.load("./images/win.png");
        imaWin.scaled(200,100,Qt::KeepAspectRatio);
        LabelPicturePause->setPixmap(QPixmap::fromImage(imaWin));
        LabelPicturePause->setGeometry(400,200,200,100);
        LabelPicturePause->setScaledContents(true);
        LabelPicturePause->show();
    }
    if(gameStatus==6)//游戏失败
    {
        imaLose.load("./images/lose.png");
        imaLose.scaled(200,100,Qt::KeepAspectRatio);
        LabelPicturePause->setPixmap(QPixmap::fromImage(imaLose));
        LabelPicturePause->setGeometry(400,200,200,100);
        LabelPicturePause->setScaledContents(true);
        LabelPicturePause->show();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(gameStatus==2)//游戏状态
    {
        int x = event->x();
        int y = event->y();
        x = (x-shamt.x() + PIC_W) / PIC_W;
        y = (y-shamt.y() + PIC_W) / PIC_W;
        if(block[x][y] != 0 && !(x == colNow && y ==rowNow))
        {
            colLast = colNow;
            rowLast = rowNow;
            colNow = x;
            rowNow = y;
            if(judge())
            {
                qDebug() << "success";
                emit(vanish());
                block[colLast][rowLast] = 0;
                block[colNow][rowNow] = 0;
                colLast = 0;
                rowLast = 0;
                colNow = 0;
                rowNow = 0;
                spfa(colNow, rowNow);
                while(!solvable())
                {
                    qDebug() << "insolvable!";
                    shuffle();
                }
            }
            else
            {
                qDebug() << "fail";
                spfa(colNow, rowNow);
            }
            update();
            setLabel();
            if (finish())
            {
                gameStatus = 5;
                update();
                qDebug() << "finish!";
                return;
            }
        }

    }

}

void MainWindow::createBlock()
{
    qDebug() << "createBlock\n";
    int picAll[MAXSIZE_X*MAXSIZE_Y];
    int cnt=0;

    for(int i=0;i<MAXSIZE_X*MAXSIZE_Y;i+=8)//每种类型图片有8张
    {
        picAll[i]=i/8;
        picAll[i+1]=i/8;
        picAll[i+2]=i/8;
        picAll[i+3]=i/8;
        picAll[i+4]=i/8;
        picAll[i+5]=i/8;
        picAll[i+6]=i/8;
        picAll[i+7]=i/8;
    }

    srand((unsigned)time(NULL));
    random_shuffle(picAll,picAll+MAXSIZE_X*MAXSIZE_Y);
    memset(block,0,sizeof(block));//初始化block数组

    for(int i=1;i<=MAXSIZE_X;i++)
        for(int j=1;j<=MAXSIZE_Y;j++)
        {
            block[i][j]=picAll[cnt]+1;
            cnt++;
        }
    //setUpdatesEnabled(true);
    //update();
    repaint();
}

void MainWindow::setStartWindow()
{
    printf("setStartWindow\n");
    gameStatus=1;
}

void MainWindow::setGameWindow()
{
    qDebug() << "setGameWindow\n";
    createBlock();

    for(int i=1;i<=MAXSIZE_X;i++)
        for(int j=1;j<=MAXSIZE_Y;j++)
        {
            int tmp=block[i][j];
            if (tmp != 0)
            {
                ima[tmp-1].scaled(PIC_W,PIC_W,Qt::KeepAspectRatio);
                labelPicture[i][j]->setPixmap(QPixmap::fromImage(ima[tmp-1]));
                labelPicture[i][j]->setGeometry((i-1)*PIC_W+shamt.x(),(j-1)*PIC_W+shamt.y(),PIC_W,PIC_W);
                labelPicture[i][j]->setScaledContents(true);
                labelPicture[i][j]->show();
            }
            else
            {
                labelPicture[i][j]->hide();
            }
        }
    timeLength=MAX_TIMELENGTH;
}

void MainWindow::timeDecrease()
{
    timeLength--;
    ui->progressBarTimer->setValue(timeLength);
    if(timeLength==0)
    {
        gameStatus=6;//游戏失败
        timer->stop();
        update();
    }
}

void MainWindow::timeIncrease(){
    if(timeLength+6>=MAX_TIMELENGTH)
    {
        timeLength=MAX_TIMELENGTH;
    }
    else
    {
        timeLength+=6;
    }
    ui->progressBarTimer->setValue(timeLength);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i=1;i<=MAXSIZE_X;i++)
        for(int j=1;j<=MAXSIZE_Y;j++)
        {
            labelPicture[i][j]=new QLabel(this);
            labelPicture[i][j]->hide();
        }
    LabelPicturePause=new QLabel(this);
    LabelPictureWin=new QLabel(this);
    LabelPictureLose=new QLabel(this);
    bgm=new QSound("./music/bgm.wav",this);
    timer=new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::timeDecrease);
    connect(this, &MainWindow::vanish, this, &MainWindow::timeIncrease);
    //logic part
    logicInit();

    setStartWindow();
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_pushButtonStart_clicked()
{
    gameStatus=2;
    timer->start(500);
    ui->progressBarTimer->setVisible(true);
    setGameWindow();
}

void MainWindow::on_pushButtonSettings_clicked()
{
    qDebug()<< "Pause" <<endl;
    gameStatus=3;

}

void MainWindow::on_pushButtonQuit_clicked()
{
    QApplication *app = nullptr;
    app->quit();
}

void MainWindow::on_pushButtonPause_clicked()
{
    if(gameStatus==4)
    {
        gameStatus=2;
        timer->start(500);
        ui->pushButtonPause->setText("Pause");
    }
    else if(gameStatus==2)
    {
        gameStatus=4;
        timer->stop();
        ui->pushButtonPause->setText("Continue");
    }
}

void MainWindow::on_pushButtonBackToMenu_clicked()
{
    LabelPicturePause->setVisible(false);
    gameStatus=1;//恢复开始游戏界面
    timer->stop();
    ui->progressBarTimer->setVisible(false);
    for(int i=1;i<=MAXSIZE_X;i++)
        for(int j=1;j<=MAXSIZE_Y;j++)
        {
            labelPicture[i][j]->hide();
        }
}

void MainWindow::on_pushButtonOn_clicked()
{
    if(isBGMOn)
    {
        isBGMOn=0;
        ui->pushButtonOn->setText("ON");
        bgm->play();
    }
    else if(!isBGMOn)
    {
        isBGMOn=1;
        ui->pushButtonOn->setText("OFF");
        bgm->stop();
    }
}

