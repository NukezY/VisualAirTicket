#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

  //  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
 //   db.setDatabaseName("test");
  //  db.open();
  //  if(db.open())
 //   {
        w.setWindowTitle("可视化航班查询系统");
        w.show();
  //  }
  //  else
  //  {
 //       QMessageBox::warning(NULL,"error","数据库连接失败");
 //       return 0;
 //   }

    return a.exec();
}
