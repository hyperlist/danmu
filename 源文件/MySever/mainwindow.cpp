#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);
    QHostAddress ipAddress("127.0.0.1");
    quint16 ipPort = 12346;
    if( !tcpServer->listen(ipAddress, ipPort) )
    {
        qDebug() << tcpServer->errorString();
    }
    con = false;
    connect(tcpServer, &QTcpServer::newConnection, this, &MainWindow::newconnect);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getMassage(const QString &message)
{
    ui->message->appendPlainText(message);
    massgelist.enqueue(message);
    if(con){
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_10);
        out << message;
        tcpsocket->write(block);
    }
}

void MainWindow::newconnect()
{
    tcpsocket = tcpServer->nextPendingConnection();
    //获取对方的IP:port
    QString ipCli = tcpsocket->peerAddress().toString();
    int portCli = tcpsocket->peerPort();
    client = QString("[%1:%2]").arg(ipCli).arg(portCli);
    ui->client->appendPlainText(client);
    ui->client->appendPlainText("client连接成功");
    connect(tcpsocket, &QTcpSocket::disconnected, this,&MainWindow::disconnect);
    con = true;

}

void MainWindow::disconnect()
{
    ui->client->appendPlainText(client);
    ui->client->appendPlainText("client断开连接");
    con = false;
}

