#ifndef DANMU_H
#define DANMU_H

#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QPainter>
#include <QList>
#include <QDebug>
#include <QString>


class Danmu : public QGraphicsObject
{
    Q_OBJECT

public:
    Danmu();

    QRectF boundingRect() const  Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget)  Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;

    QString DText;
    qreal speed;    //行驶速度
    bool out;
    void setColor(int color);

protected:
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QGraphicsSceneMouseEvent* event)override;

private:
    bool stop;
    QFont font;
    QColor qcolor;
    QRectF rect;
    int textWidth;
    int textHeight;
    int timerId;

};

#endif // DANMU_H
