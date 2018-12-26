#ifndef SETDANMU_H
#define SETDANMU_H

#include <QApplication>
#include <QWidget>
#include <QDesktopWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QTime>
#include <QQueue>
#include <QRect>
#include <QPainter>
#include <QStyleOption>
#include <QDebug>

#include "danmu.h"

class setDanmu: public QWidget
{
    Q_OBJECT
public:
    explicit setDanmu(QWidget *parent = nullptr);
    ~setDanmu();
    QGraphicsScene *scene;
    QGraphicsView *view;
    int width;
    int height;
    int posy;
    QString string;
    QQueue<Danmu*> DanmuQue;

    void sendDanmu(Danmu *danmu);

private slots:
    void GetDanmu(QString data);

private:

};

#endif // SETDANMU_H
