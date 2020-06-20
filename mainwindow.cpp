#include "mainwindow.h"
#include "ui_mainwindow.h"

bool isroot = false;        // 默认不是管理员

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pB_login_clicked()
{
    lo = new Login;
    lo->setWindowTitle("登录页面");
    lo->show();
    this->hide();
}

void MainWindow::on_pB_view_clicked()
{
    mavi = new MianView;
    mavi->setWindowTitle("民航票务管理系统");
    mavi->show();
    this->hide();
}
