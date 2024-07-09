#include "tcpclient.h"
#include "ui_tcpclient.h"
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QMessageBox>
#include <QHostAddress>
#include "protocal.h"

TcpClient::TcpClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    loadConfig();

    //先连接信号
    connect(&m_tcpSocket,QOverload<>::of(&QTcpSocket::connected),this,&TcpClient::onConnected);
    connect(&m_tcpSocket,QOverload<>::of(&QTcpSocket::readyRead),this,&TcpClient::onRecvMsg);
    //连接服务器
    m_tcpSocket.connectToHost(QHostAddress(m_strIP),m_port);
}

TcpClient::~TcpClient()
{
    delete ui;
}

void TcpClient::loadConfig()
{
    QFile file(":/config/client.cfg");
    if(true == file.open(QFile::OpenModeFlag::ReadOnly))
    {
        QString data=QString::fromUtf8(file.readAll());
        file.close();

        data.replace("\r\n"," ");
        QStringList strList=data.split(' ');
        this->m_strIP=strList.at(0);
        this->m_port=strList.at(1).toUInt();
    }
    else
    {
        QMessageBox::critical(this,"客户端错误","读取客户端配置出错: " + file.errorString());
    }
}

void TcpClient::onConnected()
{
    qDebug()<<"连接服务器成功";
}

void TcpClient::onRecvMsg()
{
    //先收协议数据单元的第一个数据: 消息总长
    uint uiPDULen;
    m_tcpSocket.read((char*)&uiPDULen,sizeof(uint));
    uint uiMsgLen=uiPDULen-sizeof(PDU);
    PDU* pdu=mkPDU(uiMsgLen);
    //再偏移第一个数据大小，接收后续数据
    m_tcpSocket.read((char*)pdu+sizeof(uint),uiPDULen-sizeof(uint));

    //判断消息类型
    switch(pdu->uiMsgType)
    {
    case ENUM_MSG_TYPE_REGISTER_RESPOND:
        if(strcmp(pdu->caData,REGISTER_OK) == 0)
        {
            QMessageBox::warning(this,"注册提示",REGISTER_OK);
        }
        else if(strcmp(pdu->caData,REGISTER_FAILED) == 0)
        {
            QMessageBox::warning(this,"注册提示",REGISTER_FAILED);
        }
        break;
    }

    free(pdu);
    pdu=NULL;
}

/*
//发送
void TcpClient::on_btnSend_clicked()
{
    if(!ui->lineEdit->text().isEmpty())
    {
        QString strMsg=ui->lineEdit->text();
        uint uiMsgLen=strMsg.size()+1;
        PDU* pdu=mkPDU(uiMsgLen);
        memcpy(pdu->caMsg,strMsg.toStdString().c_str(),uiMsgLen);
        pdu->uiMsgType=8888;
        m_tcpSocket.write((char*)pdu,pdu->uiPDULen);
        free(pdu);
        pdu=NULL;
    }
    else
    {

    }
}
*/
//登录
void TcpClient::on_btnLogin_clicked()
{

}
//注册
void TcpClient::on_btnRegister_clicked()
{
    QString strName=ui->editName->text();
    QString strPwd=ui->editPwd->text();
    if(strName.isEmpty() || strPwd.isEmpty())
    {
        QMessageBox::warning(this,"注册提示","用户名或密码为空!");
    }
    else
    {
        PDU* pdu=mkPDU(0);//没有消息
        strncpy(pdu->caData,strName.toStdString().c_str(),32);
        strncpy(pdu->caData+32,strPwd.toStdString().c_str(),32);
        pdu->uiMsgType=ENUM_MSG_TYPE_REGISTER_REQUEST;
        m_tcpSocket.write((char*)pdu,pdu->uiPDULen);
        free(pdu);
        pdu=NULL;
    }
}
