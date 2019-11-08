#include "game3d.h"
#include "ui_game3d.h"
#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

// 初始化函数，仅在构造函数内调用一次
void Game3d::logicInit()
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

//延时函数
void Game3d::sleep(int msec)
{
    QTime reachTime = QTime::currentTime().addMSecs(msec);

    while(QTime::currentTime()<reachTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}
// 计算单源最短路径，每次更改col, row都会调用，数字代表转角数目，最大为3
// 对spfa加以调整，以适应遮挡的情况
void Game3d::spfa(int x, int y)
{
    //计算前初始化
    for (int i = 0; i < MAXSIZE_X + 2; ++i)
        for (int j = 0; j < MAXSIZE_Y + 2; ++j)
        {
            dis[i][j] = 3;
            in[0][i][j] = 0;
            in[1][i][j] = 0;
        }
    if (facialblock[x][y] == 0)  // 该点为空
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
                if (facialblock[col][row] != 0)
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
                        if (facialblock[xNext][yNext] == 0 && in[i % 2][xNext][yNext] == 0)  // 不在队内且为空
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
bool Game3d::judge()
{
    return (dis[colNow][rowNow] <= 2 && \
            facialblock[colNow][rowNow] == facialblock[colLast][rowLast])? true: false;
}

// 判断剩余局面是否可解，可以和hint()函数合并
bool Game3d::solvable()
{
    bool flag = 0;  // 判断是否有剩余方块
    for(int i = 1; i <= MAXSIZE_X; i++)
        for(int j = 1; j<= MAXSIZE_Y; j++)  // 暴力双重遍历
        {
            if(facialblock[i][j] != 0)
            {
                flag = 1;
                spfa(i, j);  // 计算距离
                for(int col = 1; col <= MAXSIZE_X; col++)
                    for(int row = 1; row <= MAXSIZE_Y; row++)
                        if(facialblock[i][j] == facialblock[col][row] && dis[col][row] <= 2 && \
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
void Game3d::shuffle()
{
    vector<int> remain;  // 用于存放剩余方块
    for(int l=0;l<layer;l++)
        for (int col = 1; col <= MAXSIZE_X; ++col)
            for(int row = 1; row <= MAXSIZE_Y; ++row)
            {
                if (block[l][col][row] != 0)
                    remain.push_back(block[l][col][row]);
            }
    random_shuffle(remain.begin(), remain.end());  // 利用shuffle函数打乱

    for(int l=0;l<layer;l++)
        for (int col = 1; col <= MAXSIZE_X; ++col)
            for(int row = 1; row <= MAXSIZE_Y; ++row)
            {
                if (block[l][col][row] != 0)  // 重新填回非空位置
                {
                    block[l][col][row] = remain.back();
                    remain.pop_back();
                }
            }

    recheck();

    memset(facialblock,0,sizeof(facialblock));
    for(int i=1;i<=MAXSIZE_X;i++)
        for(int j=1;j<=MAXSIZE_Y;j++)
            for(int l=layer;l>=0;l--){
                if(block[l][i][j]){
                    facialblock[i][j]=block[l][i][j];
                    break;
                }
            }
}

void Game3d::recheck()
{
    int cnt  = 0;
    int type = 16;
    queue<int> q;
    bool *exist = new bool[type+1];
    memset(exist, 0, sizeof(*exist)*(type+1));
    for(int i = 1; i <= MAXSIZE_X; i++)
        for(int j = 1; j <= MAXSIZE_Y; j++)
        {
            memset(exist, 0, sizeof(*exist)*(type+1));
            if (block[0][i][j])
                exist[block[0][i][j]] = 1;
            for(int l = 1; l < layer; l++)
            {
                if(exist[block[l][i][j]])
                {
                    exchange(l, i, j, q);
                    exist[block[l][i][j]] = 1;
                    cnt ++;
                }
                else
                {
                    if (block[l][i][j])
                        exist[block[l][i][j]] = 1;
                }
            }
        }
    while(!q.empty())
    {
        int j = q.front();
        q.pop();
        int i = j / MAXSIZE_X;
        j = j - i*MAXSIZE_X;
        memset(exist, 0, sizeof(*exist)*(type+1));
        if (block[0][i][j])
            exist[block[0][i][j]] = 1;
        for(int l = 1; l < layer; l++)
        {
            if(exist[block[l][i][j]])
            {
                exchange(l, i, j, q);
                exist[block[l][i][j]] = 1;
                cnt ++;
            }
            else
            {
                if (block[l][i][j])
                    exist[block[l][i][j]] = 1;
            }
        }
        cnt ++;
    }
    qDebug() << "Overlapping!" << cnt;
    delete []exist;
}

bool Game3d::exchange(int l, int i, int j, queue<int> &q)
{
    bool flag = 1;
    int cycle = 0;
    int m = i-1, n = j;
    while(flag)
    {
        while(m < MAXSIZE_X && flag)
        {
            m++;
            while(n < MAXSIZE_Y && flag)
            {
                n++;
                if(block[l][m][n] && block[l][m][n] != block[l][i][j] )
                {
                    int tmp = block[l][m][n];
                    block[l][m][n] = block[l][i][j];
                    block[l][i][j] = tmp;
                    flag = 0;
                }
            }
            if(flag)
                n = 0;
        }
        if(flag)
        {
            m = 0;
            n = 0;
            cycle += 1;
        }
    }
    if(cycle)
        q.push(m*MAXSIZE_X + n);
    return cycle? 1: 0;
}

//用来判断是否游戏结束
bool Game3d::finish()
{
    for(int col = 1; col <= MAXSIZE_X; col++)
        for(int row = 1; row <= MAXSIZE_Y; row++)
            if(facialblock[col][row] != 0)
                return false;
    return true;
}

// 根据dis数组，反向查找路径
vector<node> Game3d::route()
{
    vector<node> q;
    int col = colLast;  // 记录坐标作为出发点
    int row = rowLast;
    if (!(col < MAXSIZE_X+1 && col > 0 && \
            row < MAXSIZE_Y+1 && row > 0))
    {
        node n(0, 0, 0);
        q.push_back(n);
        q.push_back(n);
        return q;
    }
    qDebug() << "colLast:" << colLast << " rowLast:" << rowLast;
    int colN, rowN;
    // 初始化，将非空部分visit置为1
    for (int i = 0; i < MAXSIZE_X+2; i++)
        for(int j = 0; j < MAXSIZE_Y+2; j++)
        {
            if(facialblock[i][j] == 0)
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
        qDebug() << "debug11:" << dir;
        colN = col + moveX[dir];
        rowN = row + moveY[dir];
        qDebug() << "colN:" << colN << " rowN:" << rowN ;
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

// spfa算法搜索当前节点
bool Game3d::dfsRoute(vector<node> &q)
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
vector<int> Game3d::hint()
{
    vector<int> v;
    for(int i = 1; i <= MAXSIZE_X; i++)
        for(int j = 1; j<= MAXSIZE_Y; j++)  // 双遍历
        {
            if(facialblock[i][j] != 0)
            {
                spfa(i, j);
                for(int col = 1; col <= MAXSIZE_X; col++)
                    for(int row = 1; row <= MAXSIZE_Y; row++)
                        if(facialblock[i][j] == facialblock[col][row] && dis[col][row] <= 2 && \
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
void Game3d::setLabel()
{
    for(int l=0;l<layer;l++)
        for(int i=1;i<=MAXSIZE_X;i++)
            for(int j=1;j<=MAXSIZE_Y;j++)
            {
                //若被选中，则加框
                if((colNow==i)&&(rowNow==j))
                    labelPicture[l][i][j]->setFrameShape(QFrame::Box);
                else
                    labelPicture[l][i][j]->setFrameShape(QFrame::NoFrame);

                //判断块在不在
                if (block[l][i][j] != 0)
                    labelPicture[l][i][j]->show();
                else
                    labelPicture[l][i][j]->hide();
            }
}

Game3d::Game3d(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game3d)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    //加载图片
    for(int i=0;i<16;i++)
    {
        ima[i].load(QString("./newimages/image_")+QString::number(i)+".jpg");
        ima[i].scaled(PIC_W-5,PIC_W-5,Qt::KeepAspectRatio);
    }

    //初始化计时器
    timer=new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Game3d::timeDecrease);
    connect(this, &Game3d::vanish, this, &Game3d::timeIncrease);
    timer->start(TOTAL_TIME);
    ui->progressBarTimer->setVisible(true);
    timeLength=MAX_TIMELENGTH;
    //初始化label
    LabelPicturePause=new QLabel(this);
    LabelPictureWin=new QLabel(this);
    LabelPictureLose=new QLabel(this);

    //logic part
    gameStatus=2;
    parseFile();
    logicInit();
    createBlock();

    //初始化阴影效果
    for(int l=0;l<layer;l++)
        for(int i=1;i<=MAXSIZE_X;i++)
            for(int j=1;j<=MAXSIZE_Y;j++)
            {
                shadow_effect[l][i][j] = new QGraphicsDropShadowEffect();
                shadow_effect[l][i][j]->setOffset(5, 5);
                shadow_effect[l][i][j]->setColor(QColor(43, 43, 43));
                shadow_effect[l][i][j]->setBlurRadius(8);
            }
    //初始化牌
    for(int l=0;l<layer;l++)
        for(int i=1;i<=MAXSIZE_X;i++)
            for(int j=1;j<=MAXSIZE_Y;j++){
                labelPicture[l][i][j]=new QLabel(this);
                int tmp=block[l][i][j];
                if(tmp!=0){
                    labelPicture[l][i][j]->setPixmap(QPixmap::fromImage(ima[tmp-1]));
                    labelPicture[l][i][j]->setGeometry((i-1)*PIC_W+shamt.x(),(j-1)*PIC_W+shamt.y(),PIC_W-5,PIC_W-5);
                    labelPicture[l][i][j]->setScaledContents(true);
                    labelPicture[l][i][j]->setGraphicsEffect(shadow_effect[l][i][j]);
                    labelPicture[l][i][j]->show();
                }
            }
    setLabel();
    //音效
    bingoSound=new QSound("./music/bingo.wav",this);
    bubbleSound=new QSound("./music/bubble.wav",this);
}

Game3d::~Game3d()
{
    qDebug()<<"destruct game widget"<<endl;
    delete ui;
}


void Game3d::paintEvent(QPaintEvent *event)
{
    //qDebug() << "paintEvent" << ' ' << gameStatus;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPen pen(Qt::green, 5, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
    pen.setColor(QColor(0,128,255));
    painter.setPen(pen);

//    qDebug() << "debug7";
    if(gameStatus==2)//游戏界面状态
    {
        this->setFixedSize(1200,800);//窗体大小设置
        this->setAutoFillBackground(true);
        palette.setBrush(QPalette::Background,QBrush(QPixmap("./images/backGround_1.jpg")));
        this->setPalette(palette);

        LabelPicturePause->setVisible(false);
        ui->pushButtonPause->setVisible(true);
        ui->pushButtonBackToMenu->setVisible(true);
//        qDebug() << "debug8";
        if(isDrawLine)
        {
            isDrawLine=0;
            qDebug() << "debug9";
            vector<node> lines=route();
            qDebug() << "debug10";
            uint len = lines.size();

            for(uint i=len-1;i>0;i--)
            {
                qDebug() << lines[i].x <<' '<<lines[i].y <<' '<<lines[i].dir<<endl;
                painter.drawLine((lines[i].x-1)*PIC_W+PIC_W/2+shamt.x(),\
                                 (lines[i].y-1)*PIC_W+PIC_W/2+shamt.y(),\
                                 (lines[i-1].x-1)*PIC_W+PIC_W/2+shamt.x(),\
                                 (lines[i-1].y-1)*PIC_W+PIC_W/2+shamt.y());
            }
        }
    }

    else if(gameStatus==4)//暂停界面
    {
        imaPause.load("./images/backGround_2.png");
        imaPause.scaled(PIC_W*MAXSIZE_X,PIC_W*MAXSIZE_Y,Qt::KeepAspectRatio);
        LabelPicturePause->setPixmap(QPixmap::fromImage(imaPause));
        LabelPicturePause->setGeometry(shamt.x(),shamt.y(),PIC_W*MAXSIZE_X,PIC_W*MAXSIZE_Y);
        LabelPicturePause->setScaledContents(true);
        LabelPicturePause->show();
    }
    else if(gameStatus==5)//游戏获胜
    {
        imaWin.load("./images/win.png");
        imaWin.scaled(200,100,Qt::KeepAspectRatio);
        LabelPicturePause->setPixmap(QPixmap::fromImage(imaWin));
        LabelPicturePause->setGeometry(400,200,200,100);
        LabelPicturePause->setScaledContents(true);
        LabelPicturePause->show();

        timer->stop();
    }
    else if(gameStatus==6)//游戏失败
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

void Game3d::mouseReleaseEvent(QMouseEvent *event)
{
    if(gameStatus==2)  // 正在游戏
    {
        int x = event->x();
        int y = event->y();
        x = (x-shamt.x() + PIC_W) / PIC_W;
        y = (y-shamt.y() + PIC_W) / PIC_W;  // 计算下标
        if(facialblock[x][y] != 0 && !(x == colNow && y ==rowNow))
        {
            colLast = colNow;
            rowLast = rowNow;
            colNow = x;
            rowNow = y;
            bubbleSound->play();
            sleep(200);
            if(judge())  // 成功消除
            {
                isDrawLine=1;
                update();//先调用绘图事件画出消去直线
                bingoSound->play();
                qDebug() << "success";
                emit(vanish());  // 发送信号，用于更新进度条
                // 重置状态
                // 找到最上层的牌，改变状态
                int l;
                for(l=layer;(l>=0)&&(block[l][colLast][rowLast]==0);l--);
                if(l>=0)
                    block[l][colLast][rowLast]=0;
                l--;
                if(l>=0)
                    facialblock[colLast][rowLast]=block[l][colLast][rowLast];
                else
                    facialblock[colLast][rowLast]=0;
                //找到最上层的牌，改变状态
                for(l=layer;(l>=0)&&(block[l][colNow][rowNow]==0);l--);
                if(l>=0)
                    block[l][colNow][rowNow]=0;
                l--;

                if(l>=0)
                    facialblock[colNow][rowNow]=block[l][colNow][rowNow];
                else
                    facialblock[colNow][rowNow]=0;
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
                (100);
                update();//先调用绘图事件画出消去直线

            }
            else  // 消除失败
            {
                qDebug() << "fail";
                spfa(colNow, rowNow);  // 更新节点，计算距离
            }
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

void Game3d::parseFile() {
    memset(block,0,sizeof(block));
    const char* filename="./levelsetting/2.txt";
    FILE* file=fopen(filename,"r");

    if (file == nullptr) {
        printf("cannot open setting file\n");
        exit(0);
    }

    fscanf(file,"%d",&layer);

    for(int l=0;l<layer;l++){
        for(int i=1;i<=MAXSIZE_Y;i++){
            for(int j=1;j<=MAXSIZE_X;j++){
                fscanf(file,"%d",&(block[l][j][i]));
            }
        }
    }
    fclose(file);
    file=nullptr;

}

void Game3d::createBlock()
{
    qDebug() << "createBlock\n";

    int totalnum=0;
    for(int l=0;l<layer;l++)
        for(int i=1;i<=MAXSIZE_Y;i++){
            for(int j=1;j<=MAXSIZE_X;j++){
                totalnum+=block[l][j][i];
            }
        }
    int* picAll=new int[totalnum];
    int cnt=0;

    for(int i=0;2*i<totalnum;i+=1){
        picAll[2*i]=i%16;
        picAll[2*i+1]=i%16;
    }

    srand((unsigned)time(NULL));
    random_shuffle(picAll,picAll+totalnum);


    for(int l=0;l<layer;l++)
        for(int i=1;i<=MAXSIZE_X;i++)
            for(int j=1;j<=MAXSIZE_Y;j++)
            {
                if(block[l][i][j]==0) continue;
                block[l][i][j]=picAll[cnt]+1;
                cnt++;
            }

    recheck();

    //memset(ishiden,false,sizeof(ishiden));//初始化block数组
    memset(facialblock,0,sizeof(facialblock));
    for(int j=1;j<=MAXSIZE_Y;j++){
        for(int i=1;i<=MAXSIZE_X;i++)
            for(int l=layer;l>=0;l--){
                if(block[l][i][j]){
                    facialblock[i][j]=block[l][i][j];
                    //cout<<l<<" ";
                    break;
                }
            }
        //cout<<endl;
    }

}

void Game3d::timeDecrease()
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

void Game3d::timeIncrease(){
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


void Game3d::on_pushButtonPause_clicked()
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

void Game3d::on_pushButtonBackToMenu_clicked()
{
    this->close();
}

void Game3d::on_pushButtonCheat_clicked()
{
    vector<int> v=hint();
    colLast=v[0];
    rowLast=v[1];
    colNow=v[2];
    rowNow=v[3];
    if(gameStatus==2)  // 正在游戏
    {
        if(judge())  // 成功消除
        {
            isDrawLine=1;
            update();//调用paintEvent来画线
            qDebug() << "success";
            qDebug() << "debug1";
            emit(vanish());  // 发送信号，用于更新进度条
            // 重置状态
            int l;
            for(l=layer;(l>=0)&&(block[l][colLast][rowLast]==0);l--);
            if(l>=0)
                block[l][colLast][rowLast]=0;
            l--;
            if(l>=0)
                facialblock[colLast][rowLast]=block[l][colLast][rowLast];
            else
                facialblock[colLast][rowLast]=0;

            qDebug() << "debug2";
            for(l=layer;(l>=0)&&(block[l][colNow][rowNow]==0);l--);
            if(l>=0)
                block[l][colNow][rowNow]=0;
            l--;
            if(l>=0)
                facialblock[colNow][rowNow]=block[l][colNow][rowNow];
            else
                facialblock[colNow][rowNow]=0;
            qDebug() << "debug3";

            colLast = 0;
            rowLast = 0;
            colNow = 0;
            rowNow = 0;
            spfa(colNow, rowNow);
            qDebug() << "debug4";
            while(!solvable())  // 判断是否可解
            {
                qDebug() << "insolvable!";
                shuffle();  // 不可解，打乱
            }
            qDebug() << "debug5";
            sleep(100);
            update();
            qDebug() << "debug6";

        }
        else  // 消除失败
        {
            qDebug() << "fail";
            spfa(colNow, rowNow);  // 更新节点，计算距离
        }
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
