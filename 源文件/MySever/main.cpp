#include "mainwindow.h"
#include "core.h"
#include "websocketclientwrapper.h"
#include "websockettransport.h"
#include <QApplication>
#include <QDir>
#include <QUrl>
#include <QWebChannel>
#include <QWebSocketServer>


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWebSocketServer server(QStringLiteral("QWebChannel Standalone Example Server"), QWebSocketServer::NonSecureMode);
    QHostAddress ipAddress("127.0.0.1");
    quint16 ipPort = 12345;

    if (!server.listen(ipAddress, ipPort)) {
        qFatal("Failed to open web socket server.");
        return 1;
    }

    WebSocketClientWrapper clientWrapper(&server);
    QWebChannel channel;
    QObject::connect(&clientWrapper, &WebSocketClientWrapper::clientConnected,
                     &channel, &QWebChannel::connectTo);

    MainWindow mainwindow;
    Core core;
    QObject::connect(&core,SIGNAL(sendText(QString)),&mainwindow,SLOT(getMassage(QString)));
    channel.registerObject(QStringLiteral("core"), &core);


    mainwindow.show();

    return app.exec();
}
