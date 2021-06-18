#include "qchange.h"
#include "ui_qchange.h"

qchange::qchange(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qchange)
{
    ui->setupUi(this);
}

qchange::~qchange()
{
    delete ui;
}
