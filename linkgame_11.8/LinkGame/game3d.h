#ifndef GAME3D_H
#define GAME3D_H

#include <QWidget>
#include <QPushButton>
#include <iostream>
#include <cstdio>
#include <QLayout>
#include <QWidget>
#include <QString>
#include <QTimer>
#include <QTime>
#include <QProgressBar>
#include <QPixmap>
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QLabel>
#include <QImage>
#include <QSound>
#include <QMouseEvent>
#include <QGraphicsEffect>
#include <QFrame>

#include <vector>
#include <queue>
using namespace std;

#define MAXSIZE_X 16//长度
#define MAXSIZE_Y 8//宽度
#define IMAGE_NUM 16//图片种类数
#define TOTAL_TIME 800//游戏时间

QT_BEGIN_NAMESPACE
namespace Ui { class Game3d; }
QT_END_NAMESPACE

struct node
{
    int x, y, dir;
    node(int X = 0, int Y = 0, int D = 4) :x(X), y(Y), dir(D) {}
};

class Game3d : public QWidget
{
    Q_OBJECT

public:
    explicit Game3d(QWidget *parent = nullptr);
    ~Game3d();

private:
    Ui::Game3d *ui;
    const int MAX_TIMELENGTH=60;
    const int PIC_W=60;//图片大小
    int block[5][MAXSIZE_X+2][MAXSIZE_Y+2];//消去块三维数组
    int facialblock[MAXSIZE_X+2][MAXSIZE_Y+2];//记录露在表面的二维数组的层

    int layer;
    int imageNum[IMAGE_NUM+1];
    int gameStatus=0;//游戏状态，0为初始状态，1为开始游戏界面状态，2为游戏界面状态，3为设置界面，4为暂停界面，5为游戏获胜，6为游戏失败
    int isDrawLine=0;//是否正在画线状态
    int timeLength=30;//时间进度条长度
    //logic
    int rowLast, colLast, rowNow, colNow;
    int **dis;
    bool ***in, **visit;

    int moveX[4] = { -1, 0, 1, 0 };
    int moveY[4] = { 0, -1, 0, 1 };

    QSound *bingoSound;//消去音效
    QSound *bubbleSound;//点击音效

    QPoint shamt=QPoint(125,150);//初始位置
    QImage ima[16];//连连看图标

    QImage imaPause;//暂停界面图片
    QImage imaWin;//获胜图片
    QImage imaLose;//失败图片

    QLabel *labelPicture[5][MAXSIZE_X+2][MAXSIZE_Y+2];
    QLabel *LabelPicturePause;
    QLabel *LabelPictureWin;
    QLabel *LabelPictureLose;
    QTimer *timer;//计时器
    QPalette palette;
    QGraphicsDropShadowEffect *shadow_effect[5][MAXSIZE_X+2][MAXSIZE_Y+2];//每个牌一个阴影效果

    void parseFile();//从文件中读取初始牌面
    void createBlock();//创建初始消除块矩阵
    void setLabel();
    void sleep(int msec);//延时函数
    //logic part
    void logicInit();
    void spfa(int x, int y);
    bool judge();
    bool solvable();
    void shuffle();
    bool finish();
    vector<node> route();
    bool dfsRoute(vector<node> &q);
    vector<int> hint();
    void recheck();
    bool exchange(int l, int i, int j, queue<int> &q);
protected:
    void paintEvent(QPaintEvent *event);//绘图事件
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放事件
signals:
    void vanish();        //成功消除一对
public slots:
    //void setGameWindow(); //设置游戏界面
    void timeDecrease();
    void timeIncrease();
private slots:
    void on_pushButtonPause_clicked();
    void on_pushButtonBackToMenu_clicked();
    void on_pushButtonCheat_clicked();
};

#endif // GAME3D_H
