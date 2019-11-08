#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

#include <vector>
#include <queue>
using namespace std;

#define MAXSIZE_X 16//长度
#define MAXSIZE_Y 8//宽度
#define IMAGE_NUM 16//图片种类数

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPalette palette;
    int gameStatus;

    bool isBGMOn;//背景音乐是否在播放

    QSound *bgm;//背景音乐
protected:
    void paintEvent(QPaintEvent *event);//绘图事件

signals:

public slots:
    //void showMainWindow();//重新显示MainWindow

private slots:
    void on_pushButtonStart_clicked();
    void on_pushButtonSettings_clicked();
    void on_pushButtonQuit_clicked();
    void on_pushButtonOn_clicked();
    void on_pushButtonBackToMenu_clicked();
};

#endif // MAINWINDOW_H
