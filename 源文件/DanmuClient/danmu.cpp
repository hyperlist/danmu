#include "danmu.h"
#include <QDebug>
Danmu::Danmu():
stop(0)
{
    out = 0;
    speed = 8;
    setPos(600,800);
    font.setFamily("SimHei");
    font.setPointSize(15);

    timerId = startTimer(80);
    //setColor(6);
    rect = boundingRect();
}

QRectF Danmu::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(0 - adjust, 0 - adjust,
                  300,200);
}

QPainterPath Danmu::shape() const
{
    QPainterPath path;

    path.addRect(0, 0, 300, 200);
    return path;
}

void Danmu::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setFont(font);
    painter->setPen(qcolor);
    painter->drawText(rect,DText);
}

void Danmu::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    stop = !stop;
}

void Danmu::timerEvent(QTimerEvent *)
{
    QPointF p = mapToParent(0,0);
    if(!stop)
        setPos(mapToParent(-speed, 0));
    else setPos(mapToParent(0, 0));
    if(p.rx() <-300)
    {
        //qDebug()<<DText;
        //qDebug()<<timerId;
        out = 1;
        killTimer(timerId);
    }
}
void Danmu::setColor(int color)
{
    switch(color){
        case 1:
           qcolor = QColor(255,255,246,255);
           break;
        case 2:
           qcolor = QColor(231,0,18,255);
           break;
        case 3:
           qcolor = QColor(254,241,2,255);
           break;
        case 4:
           qcolor = QColor(226,2,127,255);
           break;
        case 5:
           qcolor = QColor(144,195,32,255);
           break;
        case 6:
           qcolor = QColor(0,46,114,255);
           break;
        case 7:
           qcolor = QColor(240,171,42,255);
           break;
        case 8:
           qcolor = QColor(104,58,123,255);
           break;
        case 9:
           qcolor = QColor(129,193,205,255);
           break;
        case 10:
           qcolor = QColor(149,119,57,255);
           break;
        case 11:
           qcolor = QColor(0,152,67,255);
           break;
        case 12:
           qcolor = QColor(0,160,234,255);
           break;
        default:
           qcolor = QColor(231,0,18,255);
           break;
        }
}
