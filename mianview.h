#ifndef MIANVIEW_H
#define MIANVIEW_H

#include <QWidget>
#include <QStandardItemModel>
#include <QSqlTableModel>
#include <QMessageBox>
#include <adddata.h>
#include <databases.h>
namespace Ui {
class MianView;
}

class MianView : public QWidget
{
    Q_OBJECT

public:
    explicit MianView(QWidget *parent = nullptr);
    ~MianView();
    adddata *add;
    databases da;
    void updataTablewidgetData();

private slots:
    void on_pB_del_clicked();
    void on_pB_add_clicked();
    void on_pB_exit_clicked();

    void on_pB_shuaxin_clicked();

    void on_pB_modify_clicked();

    void on_pB_Inquire_clicked();

private:
    Ui::MianView *ui;
};

#endif // MIANVIEW_H
