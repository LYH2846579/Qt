#ifndef SQLINSERT_H
#define SQLINSERT_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class sqlinsert;
}

class sqlinsert : public QWidget
{
    Q_OBJECT

public:
    explicit sqlinsert(QWidget *parent = nullptr);
    ~sqlinsert();

private:
    Ui::sqlinsert *ui;
    QString table;
    QSqlDatabase db;

    //看样子信号和槽必须在类中单独声明
public slots:
    void PrintText();
    QString getTable();
    bool Insert();
    void Clear_TB();
public:
    //插入需要的变量
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
private slots:
    void on_Insert_PushButton_clicked();
};

#endif // SQLINSERT_H
