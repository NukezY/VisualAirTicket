#include "adddata.h"
#include "ui_adddata.h"
#include <QDebug>
#include <mianview.h>

adddata::adddata(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adddata)
{
    ui->setupUi(this);
}

adddata::~adddata()
{
    delete ui;
}

void adddata::on_pB_Y_clicked()
{
    QString str1 = ui->lineEdit_a->text();
    QString str2 = ui->lineEdit_b->text();
    QString str3 = ui->lineEdit_c->text();
    QString str4 = ui->lineEdit_d->text();
    QString str5 = ui->lineEdit_e->text();
    QString str6 = ui->lineEdit_f->text();
    QString str7 = ui->lineEdit_g->text();
    QString str8 = ui->lineEdit_h->text();
    QString str9 = ui->lineEdit_i->text();
    QString str10 = ui->lineEdit_j->text();
    QString str11 = ui->lineEdit_k->text();
                                                                        // 获取输入的信息
    da.m_db.close();
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        da.m_db = QSqlDatabase::database("qt_sql_default_connection");

        qDebug() << "contains";
    }
    else
    {
        da.m_db = QSqlDatabase::addDatabase(
                    "QSQLITE", "qt_sql_default_connection");

        da.m_db.setDatabaseName("test");
    }
                                                                         // 连接数据库
    da.m_db.open();
    if(da.m_db.open() == true)
    {
        QSqlQuery query(da.m_db);
        query.prepare("insert into airticket (航班号,起点,终点,日期,起飞时刻,到达时刻,剩余座位数,票价,折扣票数,折扣率,航班所属航空公司)"
                      "values(?,?,?,?,?,?,?,?,?,?,?)");
        query.addBindValue(str1);
        query.addBindValue(str2);
        query.addBindValue(str3);
        query.addBindValue(str4);
        query.addBindValue(str5);
        query.addBindValue(str6);
        query.addBindValue(str7);
        query.addBindValue(str8);
        query.addBindValue(str9);
        query.addBindValue(str10);
        query.addBindValue(str11);
        query.exec();
                                                                         // 数据写入数据库
    }
    else{
        qDebug() << "da.m_db not open";
    }
    this->close();
}

void adddata::on_pB_N_clicked()
{
    this->close();
}
