#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QQueue>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void getMassage(const QString &message);
    void newconnect();
    void disconnect();

private:
    QQueue<QString> massgelist;
    QTcpSocket *tcpsocket;
    QTcpServer *tcpServer;
    QString client;
    bool con;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
