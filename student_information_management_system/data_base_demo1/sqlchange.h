#ifndef SQLCHANGE_H
#define SQLCHANGE_H

#include <QWidget>
#include "QSqlDatabase"

namespace Ui {
class sqlchange;
}

class sqlchange : public QWidget
{
    Q_OBJECT

public:
    explicit sqlchange(QWidget *parent = nullptr);
    ~sqlchange();

private:
    Ui::sqlchange *ui;
    QSqlDatabase db;

public slots:
    void PrintText();
    void getTable();
    void Search();
    void PrintText_C();
    void getTable_C();
    void change();
    void Clear_TW();

public:
    //修改需要的变量
    QString SCLASS;
    QString SNO;
    QString SNAME;
    QString SSEX;
    QString SAGE;
    QString SDEPT;
    QString CNO;
    QString CNAME;
    QString CPNO;
    QString GRADE;
    QString CCREDIT;
public:
    QString table;   //存储选择表格的变量
    QString table_C; //修改表格变量

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // SQLCHANGE_H
