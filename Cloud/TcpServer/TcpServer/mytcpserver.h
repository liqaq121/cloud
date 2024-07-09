#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>
#include "mytcpsocket.h"

class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    MyTcpServer();

    //单例
    static MyTcpServer& getInstance()
    {
        static MyTcpServer tcpServer;
        return tcpServer;
    }

    QList<MyTcpSocket*> m_tcpSocketList;
    // QTcpServer interface
protected:
    void incomingConnection(qintptr handle) override;
};

#endif // MYTCPSERVER_H
