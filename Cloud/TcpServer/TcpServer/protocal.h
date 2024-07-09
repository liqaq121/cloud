#ifndef PROTOCAL_H
#define PROTOCAL_H

typedef unsigned int uint;

#define REGISTER_OK "注册成功"
#define REGISTER_FAILED "注册失败: 用户名已存在"

/* 协议数据单元*/
struct PDU
{
    uint uiPDULen;//协议数据单元总长
    uint uiMsgType;//消息类型
    char caData[64];//文件名或者用户名和密码等
    uint uiMsgLen;//实际消息大小
    int caMsg[];//实际消息
};

enum ENUM_MSG_TYPE
{
    ENUM_MSG_TYPE_MIN=0,
    ENUM_MSG_TYPE_REGISTER_REQUEST,
    ENUM_MSG_TYPE_REGISTER_RESPOND,
    ENUM_MSG_TYPE_MAX=0x00ffffff
};

PDU* mkPDU(uint uiMsgLen);

#endif // PROTOCAL_H
