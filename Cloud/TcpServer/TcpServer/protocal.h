#ifndef PROTOCAL_H
#define PROTOCAL_H

typedef unsigned int uint;

/* 协议数据单元*/
struct PDU
{
    uint uiPDULen;//协议数据单元总长
    uint uiMsgType;//消息类型
    char caData[64];//文件名或者用户名等
    uint uiMsgLen;//实际消息大小
    int caMsg[];//实际消息
};

PDU* mkPDU(uint uiMsgLen);

#endif // PROTOCAL_H
