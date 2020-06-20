#include "databases.h"
#include <QMessageBox>
#include <QDebug>
databases::databases()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("test");
    m_db.open();
    if(m_db.open())
    {
        qDebug() << "数据库已连接";
    }
    else
    {
        QMessageBox::warning(NULL,"error","数据库连接失败");
    }
}
