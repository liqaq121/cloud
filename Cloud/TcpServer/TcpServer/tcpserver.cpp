#include "tcpserver.h"
#include "ui_tcpserver.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include "mytcpserver.h"
#include <QHostAddress>

TcpServer::TcpServer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpServer)
{
    ui->setupUi(this);
    loadConfg();
    //监听 自动调用虚函数incomingConnection()
    //获取单例
    MyTcpServer::getInstance().listen(QHostAddress(m_strIP),m_port);

}

TcpServer::~TcpServer()
{
    delete ui;
}

void TcpServer::loadConfg()
{
    QFile file(":/config/server.cfg");
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
        QMessageBox::critical(this,"服务器端错误","读取服务器配置出错: " + file.errorString());
    }
}


void TcpServer::on_pushButton_clicked()
{
    qDebug()<<MyTcpServer::getInstance().m_tcpSocketList.size();
}
