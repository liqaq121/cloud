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

bool OperateDB::handleLogin(const char *name, const char *pwd)
{
    QString strQuery=QString("select * from usrInfo where name=\'%1\' and pwd=\'%2\' and online=0")
            .arg(name)
            .arg(pwd);
    QSqlQuery query;
    query.exec(strQuery);
    bool ret=query.next();
    if(ret)
    {
        query.exec(QString("update usrInfo set online=1 where name=\'%1\' and pwd=\'%2\'")
                   .arg(name)
                   .arg(pwd));
        return true;
    }
    else
        return false;
}
//下线
void OperateDB::handleOffline(const QString& name)
{
    QString strQuery=QString("update usrInfo set online=0 where name=\'%1\'").arg(name);
    QSqlQuery query;
    query.exec(strQuery);
}
