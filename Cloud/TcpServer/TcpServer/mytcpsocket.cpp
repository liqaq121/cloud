#include "mytcpsocket.h"
#include "protocal.h"
#include <QDebug>
#include "operatedb.h"

MyTcpSocket::MyTcpSocket()
{
    connect(this,&MyTcpSocket::readyRead,this,&MyTcpSocket::onRecvMsg);
}

void MyTcpSocket::onRecvMsg()
{
    //先收协议数据单元的第一个数据: 消息总长
    uint uiPDULen;
    this->read((char*)&uiPDULen,sizeof(uint));
    uint uiMsgLen=uiPDULen-sizeof(PDU);
    PDU* pdu=mkPDU(uiMsgLen);
    //再偏移第一个数据大小，接收后续数据
    this->read((char*)pdu+sizeof(uint),uiPDULen-sizeof(uint));


    //判断消息类型
    PDU* resPdu=mkPDU(0);
    switch(pdu->uiMsgType)
    {
    case ENUM_MSG_TYPE_REGISTER_REQUEST:
        char name[33]={0};
        char pwd[33]={0};
        strncpy(name,pdu->caData,32);
        strncpy(pwd,pdu->caData+32,32);
        //处理注册
        bool ret=OperateDB::getInstance().handleRegister(name,pwd);
        //注册返回处理
        resPdu->uiMsgType=ENUM_MSG_TYPE_REGISTER_RESPOND;
        if(ret)
        {
            strcpy(resPdu->caData,REGISTER_OK);
        }
        else
        {
             strcpy(resPdu->caData,REGISTER_FAILED);
        }
        this->write((char*)resPdu,resPdu->uiPDULen);
        free(resPdu);
        resPdu=NULL;
        break;
    }
    free(pdu);
    pdu=NULL;
}
