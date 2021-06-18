#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "sqlinsert.h"
#include "sqldelete.h"
#include "sqlcopy.h"
#include "sqlchange.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase db;

private slots:
    void on_pushButton_insert_clicked();

    void on_pushButton_change_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_copy_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
