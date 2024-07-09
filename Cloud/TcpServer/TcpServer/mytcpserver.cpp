#include "mytcpserver.h"
#include <QMessageBox>

MyTcpServer::MyTcpServer()
{


}

//listen到有新的连接，自动调用
void MyTcpServer::incomingConnection(qintptr handle)
{
    MyTcpSocket* socket=new MyTcpSocket;
    socket->setSocketDescriptor(handle);
    m_tcpSocketList.append(socket);
    qDebug()<<"新的连接";
}
