#include "gamewidget.h"
#include "ui_gamewidget.h"
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

// 初始化函数，仅在构造函数内调用一次
void GameWidget::logicInit()
{
    rowLast = 0;
    colLast = 0;
    rowNow = 0;
    colNow = 0;

    dis = new int*[MAXSIZE_X + 2];
    visit = new bool*[MAXSIZE_X + 2];
    in = new bool**[2];
    in[0] = new bool*[MAXSIZE_X + 2];
    in[1] = new bool*[MAXSIZE_X + 2];
    for (int i = 0; i < MAXSIZE_X + 2; i++)
    {
        dis[i] = new int[MAXSIZE_Y + 2];
        visit[i] = new bool[MAXSIZE_Y + 2];
        in[0][i] = new bool[MAXSIZE_Y + 2];
        in[1][i] = new bool[MAXSIZE_Y + 2];
    }
    // 全部进行初始化赋值
    for (int i = 0; i < MAXSIZE_X + 2; ++i)
        for (int j = 0; j < MAXSIZE_Y + 2; ++j)
        {
            dis[i][j] = 3;
            visit[i][j] = 0;
            in[0][i][j] = 0;
            in[1][i][j] = 0;
        }
}

// 计算单源最短路径，每次更改col, row都会调用，数字代表转角数目，最大为3
void GameWidget::spfa(int x, int y)
{
    //计算前初始化
    for (int i = 0; i < MAXSIZE_X + 2; ++i)
        for (int j = 0; j < MAXSIZE_Y + 2; ++j)
        {
            dis[i][j] = 3;
            in[0][i][j] = 0;
            in[1][i][j] = 0;
        }
    if (block[x][y] == 0)  // 该点为空
    {
        qDebug() << "invalid pos:" << x << ' ' << y;
        return;
    }
    else
    {
        // 用于减小计算量，仅在有方块的附近进行计算
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
        // 开始计算
        queue<node> q;
        node p(x, y, 4);  // 初始节点，方向任意
        dis[x][y] = 0;  // 转角为0个
        q.push(p);
        while (!q.empty())  // 当队列非空时
        {
            p = q.front();  // 取队首节点并出队
            q.pop();
            in[p.dir % 2][p.x][p.y] = 0;  // 入队标志设置为0
            for (int i = 0; i < 4; i++)  // 遍历四个方向
            {
                int xNext = p.x + moveX[i];
                int yNext = p.y + moveY[i];
                if (xNext >= xMin && xNext <= xMax && \
                    yNext >= yMin && yNext <= yMax)  // 搜索点在范围内
                {
                    int n = (p.dir == 4) || (p.dir == i) ? dis[p.x][p.y]\
                        : dis[p.x][p.y] + 1;  // 转换方向则转角数+1
                    if (n <= dis[xNext][yNext] && n < 3)
                    {
                        dis[xNext][yNext] = n;  // 更新最短距离
                        if (block[xNext][yNext] == 0 && in[i % 2][xNext][yNext] == 0)  // 不在队内且为空
                        {
                            node y(xNext, yNext, i);
                            in[i % 2][xNext][yNext] = 1;
                            q.push(y);  // 入队
                        }
                    }
                }
            }
        }
    }
}

// 用来判断block[colNow][rowNow]是否可达block[colLast][rowLast]
bool GameWidget::judge()
{
    return (dis[colNow][rowNow] <= 2 && \
            block[colNow][rowNow] == block[colLast][rowLast])? true: false;
}

// 判断剩余局面是否可解，可以和hint()函数合并
bool GameWidget::solvable()
{
    bool flag = 0;  // 判断是否有剩余方块
    for(int i = 1; i <= MAXSIZE_X; i++)
        for(int j = 1; j<= MAXSIZE_Y; j++)  // 暴力双重遍历
        {
            if(block[i][j] != 0)
            {
                flag = 1;
                spfa(i, j);  // 计算距离
                for(int col = 1; col <= MAXSIZE_X; col++)
                    for(int row = 1; row <= MAXSIZE_Y; row++)
                        if(block[i][j] == block[col][row] && dis[col][row] <= 2 && \
                                !(i == col && j == row))  // 存在可达点
                        {
                            qDebug() << "solvable";
                            return true;
                        }
            }
        }
    qDebug() << "insolvable";  // 无解
    return flag? false: true;
}

// 打乱当前局面但不改变形状
void GameWidget::shuffle()
{
    vector<int> remain;  // 用于存放剩余方块
    for (int col = 1; col <= MAXSIZE_X; ++col)
        for(int row = 1; row <= MAXSIZE_Y; ++row)
        {
            if (block[col][row] != 0)
                remain.push_back(block[col][row]);
        }
    random_shuffle(remain.begin(), remain.end());  // 利用shuffle函数打乱
    for (int col = 1; col <= MAXSIZE_X; ++col)
        for(int row = 1; row <= MAXSIZE_Y; ++row)
        {
            if (block[col][row] != 0)  // 重新填回非空位置
            {
                block[col][row] = remain.back();
                remain.pop_back();
            }
        }
}

//用来判断是否游戏结束
bool GameWidget::finish()
{
    for(int col = 1; col <= MAXSIZE_X; col++)
        for(int row = 1; row <= MAXSIZE_Y; row++)
            if(block[col][row] != 0)
                return false;
    return true;
}

// 根据dis数组，反向查找路径
vector<node> GameWidget::route()
{
    vector<node> q;
    int col = colLast;  // 记录坐标作为出发点
    int row = rowLast;
    int colN, rowN;
    // 初始化，将非空部分visit置为1
    for (int i = 0; i < MAXSIZE_X+2; i++)
        for(int j = 0; j < MAXSIZE_Y+2; j++)
        {
            if(block[i][j] == 0)
                visit[i][j] = 0;
            else
                visit[i][j] = 1;
        }
    for (int dir = 0; dir < 4; dir++)  // 先确定是否相邻
    {
        colN = col + moveX[dir];
        rowN = row + moveY[dir];
        if(colN == colNow && rowN == rowNow)
        {
            node n(col, row, dir);
            q.push_back(n);
            n = node(colN, rowN, dir);
            q.push_back(n);
            return q;  // 将两个点入栈
        }
    }

    for (int dir = 0; dir < 4; dir++) // 找出可行出口
    {
        colN = col + moveX[dir];
        rowN = row + moveY[dir];
        if (!visit[colN][rowN] && dis[colN][rowN] <= 2)  // 没有访问过且可行
        {
            node n(col, row, dir);
            visit[col][row] = 1;
            q.push_back(n);
            n = node(colN, rowN, dir);
            visit[colN][rowN] = 1;
            q.push_back(n);
            if(dfsRoute(q))  // dfs递归查找
                return q;
            else
            {
                while(!q.empty())  // 清空向量，走另外一条路
                {
                    node n = q.back();
                    visit[n.x][n.y] = 0;
                    q.pop_back();
                }

            }
        }
    }
    qDebug() << "Error";
    return q;
}

// dfs算法搜索当前节点
bool GameWidget::dfsRoute(vector<node> &q)
{
    node n = q.back();
    int col = n.x;
    int row = n.y;
    int turn = n.dir;
    int colN, rowN;
    for(int dir = 0; dir < 4; dir++)  // 先判断附近有没有终点
    {
        colN = col + moveX[dir];
        rowN = row + moveY[dir];
        if(colN < MAXSIZE_X+2 && colN >= 0 && \
                rowN < MAXSIZE_Y+2 && rowN >= 0 && \
                colN == colNow && rowN == rowNow)
        {
            if (dis[col][row] <= 1 || dir == turn)  // 可达终点，直接返回
            {
                n = node(colNow, rowNow, dir);
                q.push_back(n);
                return true;
            }
            else  // 不可达，可知该路已经不可行，返回false
            {
                visit[col][row] = 0;
                q.pop_back();
                return false;
            }
        }
    }

    for (int dir = 0; dir < 4; dir++)
    {
        colN = col + moveX[dir];
        rowN = row + moveY[dir];
        // 先判断坐标合法，再是否访问过，再判断方向是否正确
        if(colN < MAXSIZE_X+2 && colN >= 0 && rowN < MAXSIZE_Y+2 && rowN >= 0 && \
                !visit[colN][rowN] && (dir == turn || (dis[colN][rowN] > dis[col][row] && dis[colN][rowN] < 3)))
        {
            n = node(colN, rowN, dir);
            visit[colN][rowN] = 1;
            q.push_back(n);  // 进入下一层递归
            if(dfsRoute(q))
                return true;
        }
    }
    visit[col][row] = 0;  // 均没有可行解，出栈，恢复访问标志
    q.pop_back();
    return false;
}

// 提示函数，无解返回空向量，有解分别返回起点xy和终点xy
vector<int> GameWidget::hint()
{
    vector<int> v;
    for(int i = 1; i <= MAXSIZE_X; i++)
        for(int j = 1; j<= MAXSIZE_Y; j++)  // 双遍历
        {
            if(block[i][j] != 0)
            {
                spfa(i, j);
                for(int col = 1; col <= MAXSIZE_X; col++)
                    for(int row = 1; row <= MAXSIZE_Y; row++)
                        if(block[i][j] == block[col][row] && dis[col][row] <= 2 && \
                                !(i == col && j == row))
                        {
                            qDebug() << i << j << col << row;
                            v.push_back(i);
                            v.push_back(j);
                            v.push_back(col);
                            v.push_back(row);
                            return v;
                        }
            }
        }
    qDebug() << "insolvable";
    return v;
}

// 对labelPicture的修改，在每次成功消除后调用，避免拖动卡顿
void GameWidget::setLabel()
{
    for(int i=1;i<=MAXSIZE_X;i++)
        for(int j=1;j<=MAXSIZE_Y;j++)
        {
            int tmp=block[i][j];
            if (tmp != 0)
            {
                labelPicture[i][j]->setFrameStyle(QFrame::Raised|QFrame::Panel);
                ima[tmp-1].scaled(PIC_W,PIC_W,Qt::KeepAspectRatio);
                labelPicture[i][j]->setPixmap(QPixmap::fromImage(ima[tmp-1]));
                labelPicture[i][j]->setGeometry((i-1)*PIC_W+shamt.x(),(j-1)*PIC_W+shamt.y(),PIC_W-5,PIC_W-5);
                labelPicture[i][j]->setScaledContents(true);
                labelPicture[i][j]->show();
            }
            else
            {
                labelPicture[i][j]->hide();  // 为空则隐藏
            }

        }
}

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    for(int i=1;i<=MAXSIZE_X;i++)
        for(int j=1;j<=MAXSIZE_Y;j++)
        {
            labelPicture[i][j]=new QLabel(this);
            labelPicture[i][j]->hide();
        }
    for(int i=0;i<16;i++)
    {
        ima[i].load(QString("./newimages/image_")+QString::number(i)+".jpg");
    }
    LabelPicturePause=new QLabel(this);
    LabelPictureWin=new QLabel(this);
    LabelPictureLose=new QLabel(this);

    timer=new QTimer(this);
    connect(timer, &QTimer::timeout, this, &GameWidget::timeDecrease);
    connect(this, &GameWidget::vanish, this, &GameWidget::timeIncrease);

    gameStatus=2;
    timer->start(TOTAL_TIME);
    ui->progressBarTimer->setVisible(true);

    //logic part
    logicInit();
    createBlock();
    setLabel();//调用绘制主体部分
    timeLength=MAX_TIMELENGTH;
}

GameWidget::~GameWidget()
{
    qDebug()<<"destruct game widget"<<endl;
    delete ui;
}


void GameWidget::paintEvent(QPaintEvent *event)
{
    //qDebug() << "paintEvent" << ' ' << gameStatus;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    if(gameStatus==2)//游戏界面状态
    {
        this->setFixedSize(1000,600);//窗体大小设置
        this->setAutoFillBackground(true);
        palette.setBrush(QPalette::Background,QBrush(QPixmap("./images/backGround_1.jpg")));
        this->setPalette(palette);

        LabelPicturePause->setVisible(false);
        ui->pushButtonPause->setVisible(true);
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

        timer->stop();
    }
    if(gameStatus==6)//游戏失败
    {
        imaLose.load("./images/lose.png");
        imaLose.scaled(200,100,Qt::KeepAspectRatio);
        LabelPicturePause->setPixmap(QPixmap::fromImage(imaLose));
        LabelPicturePause->setGeometry(400,200,200,100);
        LabelPicturePause->setScaledContents(true);
        LabelPicturePause->show();

        timer->stop();
    }
}

void GameWidget::mouseReleaseEvent(QMouseEvent *event)
{
   if(gameStatus==2)  // 正在游戏
    {
        int x = event->x();
        int y = event->y();
        x = (x-shamt.x() + PIC_W) / PIC_W;
        y = (y-shamt.y() + PIC_W) / PIC_W;  // 计算下标
        if(block[x][y] != 0 && !(x == colNow && y ==rowNow))
        {
            colLast = colNow;
            rowLast = rowNow;
            colNow = x;
            rowNow = y;
            if(judge())  // 成功消除
            {
                qDebug() << "success";
                emit(vanish());  // 发送信号，用于更新进度条
                vector<node> q = route();
                qDebug() << q.size();
                // 重置状态
                block[colLast][rowLast] = 0;
                block[colNow][rowNow] = 0;
                colLast = 0;
                rowLast = 0;
                colNow = 0;
                rowNow = 0;
                //spfa(colNow, rowNow);
                while(!solvable())  // 判断是否可解
                {
                    qDebug() << "insolvable!";
                    shuffle();  // 不可解，打乱
                }
            }
            else  // 消除失败
            {
                qDebug() << "fail";
                spfa(colNow, rowNow);  // 更新节点，计算距离
            }
            update();  // 调用PaintEvent
            setLabel();  // 调用绘制主体部分
            if (finish())
            {
                gameStatus = 5;  // 游戏结束
                update();  // 调用PaintEvent
                qDebug() << "finish!";
                return;
            }
        }

    }

}

void GameWidget::createBlock()
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

void GameWidget::timeDecrease()
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

void GameWidget::timeIncrease(){
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


void GameWidget::on_pushButtonPause_clicked()
{
    if(gameStatus==4)
    {
        gameStatus=2;
        timer->start(TOTAL_TIME);
        ui->pushButtonPause->setText("Pause");
    }
    else if(gameStatus==2)
    {
        gameStatus=4;
        timer->stop();
        ui->pushButtonPause->setText("Continue");
    }
}

void GameWidget::on_pushButtonBackToMenu_clicked()
{
    this->close();
}
