#include "mainwindow.h"
#include "setdanmu.h"
#include "danmu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    setDanmu s;
    QObject::connect(&w,SIGNAL(GetDanmu(QString)),&s,SLOT(GetDanmu(QString)));
    s.show();
    w.show();

    return a.exec();
}
