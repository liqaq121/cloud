#include "mytcpserver.h"
#include <QMessageBox>

MyTcpServer::MyTcpServer()
{


}

void MyTcpServer::deleteSocket(MyTcpSocket *socket)
{
//    for(QList<MyTcpSocket*>::iterator it=m_tcpSocketList.begin(); it != m_tcpSocketList.end() ;it++)
//    {
//            if(*it == socket)
//            {
//                (*it)->deleteLater();
//                m_tcpSocketList.erase(it);
//                break;
//            }
//    }
      m_tcpSocketList.removeAt(m_tcpSocketList.indexOf(socket));
      socket->deleteLater();
      QStringList strList;
     for(int i=0;i<m_tcpSocketList.size();i++)
     {
         strList.append(m_tcpSocketList.at(i)->getName());
     }
     qDebug()<<"当前用户: "<<strList;
}

//listen到有新的连接，自动调用
void MyTcpServer::incomingConnection(qintptr handle)
{
    MyTcpSocket* socket=new MyTcpSocket;
    socket->setSocketDescriptor(handle);
    connect(socket,&MyTcpSocket::offline,this,&MyTcpServer::deleteSocket);
    m_tcpSocketList.append(socket);
    qDebug()<<"新的连接";
}
