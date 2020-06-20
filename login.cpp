#include "login.h"
#include "ui_login.h"
#include <mainwindow.h>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pB_log_clicked()
{
    QString id=ui->lineEdit_id->text();
    QString password=ui->lineEdit_password->text();

    if(id == "" ||password == ""){
            QMessageBox::information(this,"警告","输入不能为空",QMessageBox::Ok);
    }
    else{
        QSqlQuery query;
        query.prepare("select id,password from user where id=:id and password=:password");
        query.bindValue(":id",id);
        query.bindValue(":password",password);
        query.exec();
        if(!query.next()){
            QMessageBox::information(this,"警告","用户名或密码错误！",QMessageBox::Ok);
        }
        else{
            isroot = true;                              // 管理员登录权限修改
            mainview = new MianView;
            mainview->setWindowTitle("民航票务管理系统");
            mainview->show();
            this->hide();
        }
    }
}

void Login::on_pB_resign_clicked()
{
    QString id=ui->lineEdit_id->text();
    QString password=ui->lineEdit_password->text();
    if(id == "")
        QMessageBox::warning(this,"","用户名不能为空！");
    else if(password == "")
        QMessageBox::warning(this,"","密码不能为空！");
    else
    {
        QString i=QString("insert into user values ('%1','%2'); ").arg(id).arg(password);
        QString S=QString("select * from user where id='%1' ").arg(id);
        QSqlQuery query;
        if(query.exec(i))
        {
            QMessageBox::information(NULL, "注册成功", "注册成功！！！", QMessageBox::Yes);
        }
        else if(query.exec(S)&&query.first())
            QMessageBox::warning(NULL,"Error","用户名重复！！！");
        else
            QMessageBox::warning(NULL,"Error","注册失败，请重试！！！");
    }
}
