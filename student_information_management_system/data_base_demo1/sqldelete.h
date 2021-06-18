#ifndef SQLDELETE_H
#define SQLDELETE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "sqlconfirm.h"

namespace Ui {
class sqldelete;
}

class sqldelete : public QWidget
{
    Q_OBJECT
public:
    //修改需要的变量
    QString SCLASS;
    QString SNO;
    QString CNO;
public:
    explicit sqldelete(QWidget *parent = nullptr);
    ~sqldelete();

private:
    Ui::sqldelete *ui;
    QSqlDatabase db;
public slots:
    void PrintText();
    void fun_delete_query();
    void fun_delete();
public:
    QString table;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // SQLDELETE_H
