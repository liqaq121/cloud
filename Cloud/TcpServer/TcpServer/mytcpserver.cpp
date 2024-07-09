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
    QMessageBox::information(nullptr,"客户端连接提示","客户端连接成功!");
}
