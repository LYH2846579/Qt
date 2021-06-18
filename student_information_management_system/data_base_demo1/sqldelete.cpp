#include "sqldelete.h"
#include "ui_sqldelete.h"
#include <QMessageBox>

sqldelete::sqldelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sqldelete)
{
    //数据库的连接
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("F:\\QT\\build-data_base_demo1-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\test.db");
    if(!db.open())
    {
        ui->textBrowser->setText("Connect database ERROR!");
    }
    else
    {
        ui->textBrowser->setText("Connect database Successful!");
    }

    //信号链接模块
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(PrintText()));

    //查询模块实现
    //1.表格选择
    ui->comboBox->addItem(tr("S"));
    ui->comboBox->addItem(tr("C"));
    ui->comboBox->addItem(tr("SC"));
    //2.表格选择信息打印
    ui->lineEdit->setReadOnly(true);
    //以独立函数实现实时性    -> PrintText();

    //功能实现模块
    //使用一个函数，首相将查询结果在tableWidget中显示出来，接着选择是否删除该项
    //fun_delete();
}


void sqldelete::PrintText()
{
    int index = 0;
    index = ui->comboBox->currentIndex();
    ui->lineEdit->setText(ui->comboBox->itemText(index));
    this->table = ui->comboBox->currentText();
}

void sqldelete::fun_delete_query()
{
    if(db.open())
    {
        QSqlQuery query(db);
        if(table == "S")
        {
            //查询模块
            SCLASS = ui->lineEdit_1->text();
            SNO = ui->lineEdit_2->text();
            query.prepare("SELECT * FROM S WHERE SCLASS=? AND SNO=?;");
            query.addBindValue(SCLASS);
            query.addBindValue(SNO);
            if(query.exec())
            {
                ui->textBrowser->setText("SELECT SUCCESSFUL!");
                //将过往的查询数据删除
                ui->tableWidget->clear();
                //将查询信息进行打印
                QStringList header;
                header<<"SCLASS"<<"SNO"<<"SNAME"<<"SSEX"<<"SAGE"<<"SDEPT";
                ui->tableWidget->setHorizontalHeaderLabels(header);

                ui->tableWidget->setRowCount(10);
                ui->tableWidget->setColumnCount(5);

                query.previous();
                if(query.next())
                {
                    ui->tableWidget->insertRow(0);
                    for(int i=0;i<5;i++)
                    {
                        ui->tableWidget->setItem(0,i,new QTableWidgetItem(query.value(i).toString()));
                    }
                }
                else
                {
                    ui->textBrowser->setText("No relevant information found.");
                }
            }
            else
                ui->textBrowser->setText("SELECT ERROR!");
        }
        else if(table == "C")
        {
            //查询模块
            CNO = ui->lineEdit_3->text();
            query.prepare("SELECT * FROM C WHERE CNO=?;");
            query.addBindValue(CNO);
            if(query.exec())
            {
                ui->textBrowser->setText("SELECT SUCCESSFUL!");
                //将过往的查询数据删除
                ui->tableWidget->clear();
                //将查询信息进行打印
                QStringList header;
                header<<"CNO"<<"CNAME"<<"CPNO"<<"CCREDIT";
                ui->tableWidget->setHorizontalHeaderLabels(header);

                ui->tableWidget->setRowCount(10);
                ui->tableWidget->setColumnCount(4);

                query.previous();
                if(query.next())
                {
                    ui->tableWidget->insertRow(0);
                    for(int i=0;i<4;i++)
                    {
                        ui->tableWidget->setItem(0,i,new QTableWidgetItem(query.value(i).toString()));
                    }
                }
                else
                {
                    ui->textBrowser->setText("No relevant information found.");
                }
            }
            else
                ui->textBrowser->setText("SELECT ERROR!");
        }
        else if(table == "SC")
        {
            //查询模块
            SCLASS = ui->lineEdit_1->text();
            SNO = ui->lineEdit_2->text();
            CNO = ui->lineEdit_3->text();
            query.prepare("SELECT * FROM SC WHERE SCLASS=? AND SNO=? AND CNO=?;");
            query.addBindValue(SCLASS);
            query.addBindValue(SNO);
            query.addBindValue(CNO);
            if(query.exec())
            {
                ui->textBrowser->setText("SELECT SUCCESSFUL!");
                //将过往的查询数据删除
                ui->tableWidget->clear();
                //将查询信息进行打印
                QStringList header;
                header<<"SCLASS"<<"SNO"<<"CNO"<<"GRADE";
                ui->tableWidget->setHorizontalHeaderLabels(header);

                ui->tableWidget->setRowCount(10);
                ui->tableWidget->setColumnCount(4);

                query.previous();
                if(query.next())
                {
                    ui->tableWidget->insertRow(0);
                    for(int i=0;i<4;i++)
                    {
                        ui->tableWidget->setItem(0,i,new QTableWidgetItem(query.value(i).toString()));
                    }
                }
                else
                {
                    ui->textBrowser->setText("No relevant information found.");
                }
            }
            else
                ui->textBrowser->setText("SELECT ERROR!");
        }
        else
        {
            ui->textBrowser->setText("Please check your choice");
        }
    }
}

void sqldelete::fun_delete()
{
    if(db.open())
    {
        if(table == "S")
        {
            QSqlQuery query(db);
            query.prepare("DELETE FROM S WHERE SCLASS=? AND SNO=?;");
            query.addBindValue(SCLASS);
            query.addBindValue(SNO);
            if(query.exec())
            {
                ui->textBrowser->setText("Delete Successful!");
            }
            else
                ui->textBrowser->setText("Delete ERROR!");
        }
        else if(table == "C")
        {
            QSqlQuery query(db);
            query.prepare("DELETE FROM C WHERE CNO=?;");
            query.addBindValue(CNO);
            if(query.exec())
            {
                ui->textBrowser->setText("Delete Successful!");
            }
            else
                ui->textBrowser->setText("Delete ERROR!");
        }
        else if(table == "SC")
        {
            QSqlQuery query(db);
            query.prepare("DELETE FROM SC WHERE SCLASS=? AND SNO=? AND CNO=?;");
            query.addBindValue(SCLASS);
            query.addBindValue(SNO);
            query.addBindValue(CNO);
            if(query.exec())
            {
                ui->textBrowser->setText("Delete Successful!");
            }
            else
                ui->textBrowser->setText("Delete ERROR!");
        }
        else
        {
            ui->textBrowser->setText("Please check your selection!");
        }
    }
}

sqldelete::~sqldelete()
{
    delete ui;
}

void sqldelete::on_pushButton_clicked()
{
    this->fun_delete_query();
}

void sqldelete::on_pushButton_2_clicked()
{
    //如下是想要以一个新的ui界面进行实现
//    QWidget* confirm = new sqlconfirm();
//    confirm->show();

//    confirm->setWindowTitle("警告");
//    bool tag ;

    //尝试使用QMessageBox来实现
    QMessageBox msgBox;
    msgBox.setText("提示");
    msgBox.setInformativeText("您确定要删除该项吗?（该操作不可逆）");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);  //Ok中k必须为小写！
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Ok)
    {
        this->fun_delete();
    }

}
