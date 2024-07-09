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
        this->m_port=strList.at(1).toUShort();
    }
    else
    {
        QMessageBox::critical(this,"客户端错误","读取客户端配置出错: " + file.errorString());
    }
}

void TcpClient::onConnected()
{
    QMessageBox::information(this,"连接服务器提示","连接服务器成功!");
}

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
