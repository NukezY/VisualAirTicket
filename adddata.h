#ifndef ADDDATA_H
#define ADDDATA_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <databases.h>

namespace Ui {
class adddata;
}

class adddata : public QWidget
{
    Q_OBJECT

public:
    explicit adddata(QWidget *parent = nullptr);
    ~adddata();
    databases da;

private slots:
    void on_pB_Y_clicked();
    void on_pB_N_clicked();

private:
    Ui::adddata *ui;
};

#endif // ADDDATA_H
