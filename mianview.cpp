#include "mianview.h"
#include "ui_mianview.h"
#include <QDebug>
#include <mainwindow.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

MianView::MianView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MianView)
{
    ui->setupUi(this);
    // 非管理员不可对数据进行操作
    if(!isroot){
        ui->pB_add->setEnabled(false);
        ui->pB_del->setEnabled(false);
        ui->pB_modify->setEnabled(false);
    }
    updataTablewidgetData();

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

    da.m_db.open();
    if(da.m_db.open() == true)
    {
        QSqlQuery query(da.m_db);
        QString tableName = "airticket";
        bool isTableExist = da.m_db.tables().contains(tableName);
        if(!isTableExist)
        {
            // create table
            bool ret = query.exec(QString("create table %1(航班号 char(8) primary key,起点 varchar(15),终点 varchar(15),日期 datetime(8),起飞时刻 char(8),到达时刻 char(8),剩余座位数 int(4),票价    float(8),折扣票数 float(8),折扣率  float(8),航班所属航空公司 varchar(20))").arg(tableName));
           /*
            *
            *
            *  bool ret = query.exec(QString("create table %1(航班号 char(8) ,起点 char(8) )").arg(tableName));
            */
            qDebug() << "create table ret" << ret << "table does not exist";
        }
        else
        {
            qDebug() << "table exists";
        }
        updataTablewidgetData();
    }
}

MianView::~MianView()
{
    delete ui;
}
void MianView::on_pB_exit_clicked()
{
    this->close();
}
void MianView::on_pB_shuaxin_clicked()
{
    updataTablewidgetData();
}
void MianView::updataTablewidgetData(){
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
    da.m_db.open();
    if(true == da.m_db.open())
    {
        QSqlQuery query(da.m_db);
        if(query.exec("select * from airticket"))
        {
            ui->tableWidget->clearContents();
            ui->tableWidget->setRowCount(0);

            while(query.next())
            {
                int rowCount = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(rowCount);

                QTableWidgetItem *columnItem0 = new QTableWidgetItem(
                            query.value(0).toString());
                QTableWidgetItem *columnItem1 = new QTableWidgetItem(
                            query.value(1).toString());
                QTableWidgetItem *columnItem2 = new QTableWidgetItem(
                            query.value(2).toString());
                QTableWidgetItem *columnItem3 = new QTableWidgetItem(
                            query.value(3).toString());
                QTableWidgetItem *columnItem4 = new QTableWidgetItem(
                            query.value(4).toString());
                QTableWidgetItem *columnItem5 = new QTableWidgetItem(
                            query.value(5).toString());
                QTableWidgetItem *columnItem6 = new QTableWidgetItem(
                            query.value(6).toString());
                QTableWidgetItem *columnItem7 = new QTableWidgetItem(
                            query.value(7).toString());
                QTableWidgetItem *columnItem8 = new QTableWidgetItem(
                            query.value(8).toString());
                QTableWidgetItem *columnItem9 = new QTableWidgetItem(
                            query.value(9).toString());
                QTableWidgetItem *columnItem10 = new QTableWidgetItem(
                            query.value(10).toString());

                ui->tableWidget->setItem(rowCount,0, columnItem0);
                ui->tableWidget->setItem(rowCount,1, columnItem1);
                ui->tableWidget->setItem(rowCount,2, columnItem2);
                ui->tableWidget->setItem(rowCount,3, columnItem3);
                ui->tableWidget->setItem(rowCount,4, columnItem4);
                ui->tableWidget->setItem(rowCount,5, columnItem5);
                ui->tableWidget->setItem(rowCount,6, columnItem6);
                ui->tableWidget->setItem(rowCount,7, columnItem7);
                ui->tableWidget->setItem(rowCount,8, columnItem8);
                ui->tableWidget->setItem(rowCount,9, columnItem9);
                ui->tableWidget->setItem(rowCount,10, columnItem10);
            }
        }
    }
}

void MianView::on_pB_add_clicked()
{
    add = new adddata;
    add->setWindowTitle("数据填写");
    add->show();
}
void MianView::on_pB_del_clicked()
{ 
    QList<QTableWidgetItem*>items=ui->tableWidget->selectedItems();
    int count=items.count();
    int m_row;
    for(int i=0;i<count;i++)
    {
       m_row=ui->tableWidget->row(items.at(i));
    }
                                                                            //获取选中的行
    da.m_db.close();
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        da.m_db = QSqlDatabase::database("qt_sql_default_connection");
        qDebug() << "contains";
    }
    else
    {
        da.m_db = QSqlDatabase::addDatabase( "QSQLITE", "qt_sql_default_connection");
        da.m_db.setDatabaseName("test");
    }
                                                                            //连接数据库
    da.m_db.open();
    if(da.m_db.open())
    {
        QString airid = ui->tableWidget->item(m_row,0)->text();
        QSqlQuery query(da.m_db);
        query.prepare("delete from airticket where 航班号=?");
        query.addBindValue(airid);
        query.exec();
                                                                            //在数据库中删除相应内容
    }
    updataTablewidgetData();
                                                                            //对数据库内容刷新显示
}
void MianView::on_pB_modify_clicked()
{
    QList<QTableWidgetItem*>items=ui->tableWidget->selectedItems();
    int count=items.count();
    int m_row;
    for(int i=0;i<count;i++)
    {
       m_row=ui->tableWidget->row(items.at(i));//获取选中的行
       qDebug() << m_row;
    }
    da.m_db.close();
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        da.m_db = QSqlDatabase::database("qt_sql_default_connection");
        qDebug() << "contains";
    }
    else
    {
        da.m_db = QSqlDatabase::addDatabase( "QSQLITE", "qt_sql_default_connection");
        da.m_db.setDatabaseName("test");
    }
    da.m_db.open();
    if(da.m_db.open() == true)
    {
        QString s0 = ui->tableWidget->item(m_row,0)->text();
        QString s1 = ui->tableWidget->item(m_row, 1)->text();
        QString s2 = ui->tableWidget->item(m_row, 2)->text();
        QString s3 = ui->tableWidget->item(m_row, 3)->text();
        QString s4 = ui->tableWidget->item(m_row, 4)->text();
        QString s5 = ui->tableWidget->item(m_row, 5)->text();
        QString s6 = ui->tableWidget->item(m_row, 6)->text();
        QString s7 = ui->tableWidget->item(m_row, 7)->text();
        QString s8 = ui->tableWidget->item(m_row, 8)->text();
        QString s9 = ui->tableWidget->item(m_row, 9)->text();
        QString s10 = ui->tableWidget->item(m_row, 10)->text();
                                                                        //   获取表单中所选行内容
        qDebug() << s0<<" "<<s1<<" "<<s2<<" "<<s3<<" "<<s4;
        QSqlQuery query(da.m_db);
        query.prepare("update airticket set 起点=?,终点=?,日期=?,起飞时刻=?,到达时刻=?,剩余座位数=?,票价=?,折扣票数=?,折扣率=?,航班所属航空公司=? where 航班号=?");
        query.addBindValue(s1);
        query.addBindValue(s2);
        query.addBindValue(s3);
        query.addBindValue(s4);
        query.addBindValue(s5);
        query.addBindValue(s6);
        query.addBindValue(s7);
        query.addBindValue(s8);
        query.addBindValue(s9);
        query.addBindValue(s10);
        query.addBindValue(s0);
        query.exec();
                                                                        // 数据写入数据库
    }

    updataTablewidgetData();
}
void MianView::on_pB_Inquire_clicked()
{
    QString text = ui->lineEdit_Fightid->text();        // 获取输入框内容
    QList<QTableWidgetItem*> findItems = ui->tableWidget->findItems(text,Qt::MatchContains);

    int nRow = ui->tableWidget->rowCount();
    bool bRowHidden = true;
    for(int i=0;i<nRow; i++)
    {
         bRowHidden = true;
         foreach(QTableWidgetItem* item,findItems)
         {
            if(NULL == item) continue;
            if(ui->tableWidget->row(item) == i)
            {
                bRowHidden = false;                         // 对含输入内容的行进行设置不隐藏
                break;
            }
         }
         ui->tableWidget->setRowHidden(i,bRowHidden);       // 对行进行隐藏
    }

}
