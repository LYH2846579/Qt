#include "sqlinsert.h"
#include "ui_sqlinsert.h"
#include "QStringList"
#include <QtDebug>
#include <QSqlQuery>

sqlinsert::sqlinsert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sqlinsert)
{
    ui->setupUi(this);

    //打开test数据库 首先必须添加驱动文件QSQLITE!
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


    //设置comboBox内容
    ui->comboBox->addItem(tr("S"));
    ui->comboBox->addItem(tr("C"));
    ui->comboBox->addItem(tr("SC"));

    //设置编辑框只读
    ui->lineEdit_12->setReadOnly(true);
    //将combobox中的内容打印在编辑框中lineEdit_10
    //由于需要点击作为信号对选中的值进行不断修改，因此将打印以函数形式实现
    connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(PrintText()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(getTable()));
    //connect(this,SIGNAL(clicked()),this,SLOT(getTable()));    //自己造的不知道是啥的东西

    //优化
    //更换表格对tableBrowser进行清空
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(Clear_TB()));


    //获取选择的表格
    //table = getTable();   //为了保证数据会随着选择的修改而修改，建议在函数中对其进行实现

    //进入插入程序
    //这里采用使用QpushButton的方法进行数据读取

}

void sqlinsert::PrintText()
{
    int index = 0;
    index = ui->comboBox->currentIndex();
    ui->lineEdit_12->setText(ui->comboBox->itemText(index));
}

QString sqlinsert::getTable()
{
    QString temp;
    temp = ui->comboBox->currentText();
    //qDebug() << temp;                         //打印表格信息，确定表格会随着选择不同而改变
    //ui->lineEdit_16->setText(temp);
    this->table = temp;
    return temp;
}

bool sqlinsert::Insert()
{
    //数据录入
    if(db.open())
    {
        if(table == "S")
        {
            //获取信息
            SCLASS = ui->lineEdit_1->text();
            SNO = ui->lineEdit_2->text();
            SNAME = ui->lineEdit_3->text();
            SSEX = ui->lineEdit_4->text();
            SAGE = ui->lineEdit_5->text();
            SDEPT = ui->lineEdit_6->text();

            QSqlQuery query(db);
            //query.exec("INSERT INTO S VALUES (7,7,7,7,7,7);");
            query.prepare("INSERT INTO S VALUES(?,?,?,?,?,?);");    //※尽量让语句在一行内部执行 //使用命名占位符进行插入
            query.addBindValue(SCLASS);
            query.addBindValue(SNO);
            query.addBindValue(SNAME);
            query.addBindValue(SSEX);
            query.addBindValue(SAGE);
            query.addBindValue(SDEPT);
            if(!query.exec())
            {
                qDebug() << "Insert data ERROR!";
                ui->textBrowser->setText("Insert data ERROR!");
                return false;
            }
            else
            {
                ui->textBrowser->setText("Insert data successful!");
                return true;
            }
        }
        else if(table == "C")
        {
            CNO = ui->lineEdit_7->text();
            CNAME = ui->lineEdit_8->text();
            CPNO = ui->lineEdit_9->text();
            CCREDIT = ui->lineEdit_11->text();

            QSqlQuery query(db);
            //另一种命名占位符的插入方式
            query.prepare("INSERT INTO C VALUES (?,?,?,?);");
            query.bindValue(0,CNO);
            query.bindValue(1,CNAME);
            query.bindValue(2,CPNO);
            query.bindValue(3,CCREDIT);
            if(!query.exec())
            {
                qDebug() << "Insert data ERROR!";
                ui->textBrowser->setText("Insert data ERROR!");
                return false;
            }
            else
            {
                ui->textBrowser->setText("Insert data successful!");
                return true;
            }

        }
        else if(table == "SC")
        {
            //获取数据
            SCLASS = ui->lineEdit_1->text();
            SNO = ui->lineEdit_2->text();
            CNO = ui->lineEdit_7->text();
            GRADE = ui->lineEdit_10->text();

            //插入数据
            QSqlQuery query(db);
            query.prepare("INSERT INTO SC VALUES (?,?,?,?);");
            query.addBindValue(SCLASS);
            query.addBindValue(SNO);
            query.addBindValue(CNO);
            query.addBindValue(GRADE);
            //检测是否插入成功
            if(!query.exec())
            {
                //qDebug() << "Insert data ERROR!";
                ui->textBrowser->setText("Insert data ERROR!");
                return false;
            }
            else
            {
                ui->textBrowser->setText("Insert data successful!");
                return true;
            }
        }
        else
        {
            ui->textBrowser->setText("Table input ERROR!");
            return false;
        }
    }
    //附：①数据录入的时候会忽略完整性约束！！！
}


//驱动插入
void sqlinsert::on_Insert_PushButton_clicked()
{
    this->Insert();
}

//清空表格
void sqlinsert::Clear_TB()
{
    ui->textBrowser->clear();
}

sqlinsert::~sqlinsert()
{
    delete ui;
}
