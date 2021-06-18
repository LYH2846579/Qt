#include "sqlconfirm.h"
#include "ui_sqlconfirm.h"

sqlconfirm::sqlconfirm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sqlconfirm)
{
    ui->setupUi(this);
}

sqlconfirm::~sqlconfirm()
{
    delete ui;
}

void sqlconfirm::on_pushButton_clicked()
{

}
