#include "operatedb.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

OperateDB::OperateDB()
{

}

OperateDB::~OperateDB()
{
    m_db.close();
}

OperateDB &OperateDB::getInstance()
{
    static OperateDB OpDB;
    return OpDB;
}

void OperateDB::init()
{
    m_db=QSqlDatabase::addDatabase("QSQLITE");
    m_db.setHostName("localhost");
    m_db.setDatabaseName("D:\\code\\src\\projects\\Qt\\Cloud\\TcpServer\\TcpServer\\cloud.db");
    if(m_db.open())
    {
        qDebug()<<"连接数据库成功";
    }
    else
    {
        QSqlError err=m_db.lastError();
        QMessageBox::critical(nullptr,"数据库提示","连接数据库失败: " + err.text());
    }
}

bool OperateDB::handleRegister(const char *name, const char *pwd)
{
    QString strQuery=QString("insert into usrInfo(name,pwd) values(\'%1\',\'%2\')")
            .arg(name)
            .arg(pwd);
    QSqlQuery query;
    return query.exec(strQuery);
}
