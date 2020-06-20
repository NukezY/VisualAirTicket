#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtSql>
#include <mianview.h>
#include <QMessageBox>
#include <databases.h>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    MianView *mainview;
    databases da;

private slots:

    void on_pB_log_clicked();       // 登录
    void on_pB_resign_clicked();    // 注册

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
