#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
           this, SLOT(displayError(QAbstractSocket::SocketError)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::newConnect()
{
    blockSize = 0;
    tcpSocket->abort(); //取消已有的连接
    QString ipAddress("192.168.0.10");
    quint16 ipPort = 12346;
    tcpSocket->connectToHost(ipAddress,ipPort);
    if(!tcpSocket->waitForConnected(300))
    {
        return 0;
    }
    return 1;
}

void MainWindow::readMessage()
{
    QDataStream in;
    in.setDevice(tcpSocket);
    in.startTransaction();
    if (!in.commitTransaction()){
        ui->statusBar->showMessage("接收消息失败");
        return;
        }
    in >> message;
    ui->statusBar->showMessage("接收消息成功");
    ui->output->appendPlainText(message);
    emit GetDanmu(message);
}

void MainWindow::displayError(QAbstractSocket::SocketError)
{
    qDebug() << tcpSocket->errorString();
}

void MainWindow::on_connect_clicked()
{
    if(newConnect())
        ui->statusBar->showMessage("连接服务器成功");
    else
        ui->statusBar->showMessage("连接服务器失败");
}

void MainWindow::on_test_clicked()
{
    emit GetDanmu("for test");
}
