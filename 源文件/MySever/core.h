
#ifndef CORE_H
#define CORE_H

#include <QObject>

class Core : public QObject
{
    Q_OBJECT

public:
    Core()
    {
        //connect(dialog, &Dialog::sendText, this, &Core::sendText);
    }

signals:
    void sendText(const QString &text);

public slots:
    void receiveText(const QString &text)
    {
        emit sendText(text);
    }

private:

};

#endif // CORE_H
