#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QTcpSocket>

class MyTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    MyTcpSocket();

    QString getName()const;

private:
    QString strName="null";
public slots:
    void onOffline();
    void onRecvMsg();
signals:
    void offline(MyTcpSocket* socket);
};

#endif // MYTCPSOCKET_H
