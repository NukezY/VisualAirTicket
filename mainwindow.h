#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <login.h>
#include <mianview.h>
#include <databases.h>

extern bool isroot ;        // 管理员权限全局变量声明

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Login *lo;                  // 登录窗口声明；
    MianView *mavi;             //
private slots:
    void on_pB_login_clicked(); // 管理员登录按钮
    void on_pB_view_clicked();  // 查询登录

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
