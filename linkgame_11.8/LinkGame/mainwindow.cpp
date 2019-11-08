#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game3d.h"
#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

void MainWindow::paintEvent(QPaintEvent *event)
{
    //qDebug() << "paintEvent" << ' ' << gameStatus;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    if(gameStatus==1)//开始游戏界面
    {
        this->setFixedSize(1200,700);//窗体大小设置
        this->setAutoFillBackground(true);
        palette.setBrush(QPalette::Background,QBrush(QPixmap("./images/backGround_1.jpg")));
        this->setPalette(palette);

        ui->pushButtonStart->setVisible(true);
        ui->pushButtonSettings->setVisible(true);
        ui->pushButtonQuit->setVisible(true);
        ui->pushButtonOn->setVisible(false);
        ui->pushButtonBackToMenu->setVisible(false);
        ui->labelBGM->setVisible(false);

    }
    else
    {
        ui->pushButtonStart->setVisible(false);
        ui->pushButtonSettings->setVisible(false);
        ui->pushButtonQuit->setVisible(false);
    }
    if(gameStatus==3)//设置界面
    {
        ui->pushButtonOn->setVisible(true);
        ui->labelBGM->setVisible(true);
        ui->pushButtonBackToMenu->setVisible(true);
    }
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gameStatus=1;
    bgm=new QSound("./music/bgm.wav",this);
}

MainWindow::~MainWindow()
{

}

/*
void MainWindow::on_pushButtonStart_clicked()
{
    gameStatus=2;
    timer->start(500);
    ui->progressBarTimer->setVisible(true);
    setGameWindow();
}
*/

void MainWindow::on_pushButtonStart_clicked()
{
    Game3d* game=new Game3d(this);
    game->show();
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

void MainWindow::on_pushButtonOn_clicked()
{
    if(isBGMOn)
    {
        isBGMOn=0;
        ui->pushButtonOn->setText("ON");
        bgm->play();
        bgm->setLoops(-1);
    }
    else if(!isBGMOn)
    {
        isBGMOn=1;
        ui->pushButtonOn->setText("OFF");
        bgm->stop();
    }

}

void MainWindow::on_pushButtonBackToMenu_clicked(){
    gameStatus=1;
    update();
}
