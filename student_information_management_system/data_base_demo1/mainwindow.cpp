#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //连接数据库
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");
    if(!db.open())                          //测试是否连接成功
    {
        qDebug() << "open db error!";
    }

    //QSqlQuery query;


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_insert_clicked()
{
    QWidget* insert = new sqlinsert();
    insert->show();

    insert->setWindowTitle("录入数据");
}

void MainWindow::on_pushButton_change_clicked()
{
    QWidget* change = new sqlchange();
    change->show();

    change->setWindowTitle("修改数据");
}

void MainWindow::on_pushButton_delete_clicked()
{
    QWidget* delete_d = new sqldelete();
    delete_d->show();

    delete_d->setWindowTitle("修改数据");
}

void MainWindow::on_pushButton_copy_clicked()
{
    QWidget* copy = new sqlcopy();
    copy->show();

    copy->setWindowTitle("备份数据");
}


