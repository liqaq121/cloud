#ifndef OPERATEDB_H
#define OPERATEDB_H

#include <QSqlDatabase>

class OperateDB
{
public:
    OperateDB();
    ~OperateDB();
    static OperateDB& getInstance();
    void init();
    bool handleRegister(const char* name,const char* pwd);
    bool handleLogin(const char* name,const char* pwd);
    void handleOffline(const QString& name);
private:
    QSqlDatabase m_db;
};

#endif // OPERATEDB_H
