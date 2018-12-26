#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void GetDanmu(QString);

private slots:
    int newConnect();   //连接服务器
    void readMessage();  //接收数据
    void displayError(QAbstractSocket::SocketError); //显示错误

    void on_connect_clicked();

    void on_test_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *tcpSocket;
    QString message; //存放从服务器接收到的字符串
    quint16 blockSize; //存放文件的大小信息
};

#endif // MAINWINDOW_H
