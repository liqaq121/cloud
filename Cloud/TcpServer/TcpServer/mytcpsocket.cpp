#include "mytcpsocket.h"
#include "protocal.h"
#include <QDebug>

MyTcpSocket::MyTcpSocket()
{
    connect(this,&MyTcpSocket::readyRead,this,&MyTcpSocket::onRecvMsg);
}

void MyTcpSocket::onRecvMsg()
{
    //先收协议数据单元的第一个数据: 消息总长
    uint uiPDULen=this->read(sizeof(uint)).toUShort();
    uint uiMsgLen=uiPDULen-sizeof(PDU);
    PDU* pdu=mkPDU(uiMsgLen);
    //再偏移第一个数据大小，接受后续数据
    this->read((char*)pdu+sizeof(uint),uiMsgLen);
    qDebug()<<pdu->uiMsgType<<(char*)pdu->caMsg;
}
