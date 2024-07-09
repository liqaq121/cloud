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
private:
    QSqlDatabase m_db;
};

#endif // OPERATEDB_H
