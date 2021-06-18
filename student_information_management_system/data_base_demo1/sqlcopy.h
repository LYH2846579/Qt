#ifndef SQLCOPY_H
#define SQLCOPY_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class sqlcopy;
}

class sqlcopy : public QWidget
{
    Q_OBJECT

public:
    explicit sqlcopy(QWidget *parent = nullptr);
    ~sqlcopy();

private slots:
    void on_pushButton_clicked();
    void Back_up();
private:
    Ui::sqlcopy *ui;
};

#endif // SQLCOPY_H
