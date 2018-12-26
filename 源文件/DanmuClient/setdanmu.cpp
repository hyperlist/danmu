#include "setdanmu.h"
#include "danmu.h"

setDanmu::setDanmu(QWidget *parent) :
    QWidget(parent)
{
    /*获取桌面设备*/
    QDesktopWidget* desktopWidget;
    QRect screenRect;
    desktopWidget = QApplication::desktop();
    screenRect = desktopWidget->screenGeometry(this);
    width = screenRect.width();
    height = screenRect.height();

    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowStaysOnTopHint);
    this->resize(width,height);

    /*设置活动场景和道路背景*/
    scene = new QGraphicsScene(this);
    scene -> setSceneRect(0,0,width,height);

    /*设置view*/
    view = new QGraphicsView(this);
    view->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    view->setMinimumSize(width,height);
    view->setScene(scene);
    view->setStyleSheet("background: transparent;padding:0px;border:0px");
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



}

void setDanmu::sendDanmu(Danmu *danmu)
{
    danmu->setPos(width, 50+((qrand()+qrand())%10)*50);
    danmu->setColor((qrand()+qrand())%15);
    scene->addItem(danmu);
}

void setDanmu::GetDanmu(QString data)
{
    Danmu *danmu = new Danmu;
    danmu->DText = data;
    DanmuQue.enqueue(danmu);
    sendDanmu(danmu);
    while(!DanmuQue.isEmpty()&&DanmuQue.head()->out == 1) {
        delete DanmuQue.dequeue();
    }
}

setDanmu::~setDanmu()
{
    while(!DanmuQue.isEmpty()&&DanmuQue.head()->out == 1) {
        delete DanmuQue.dequeue();
    }
}
