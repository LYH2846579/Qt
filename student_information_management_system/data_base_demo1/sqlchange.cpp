#include "sqlchange.h"
#include "ui_sqlchange.h"
#include <QSqlQuery>
#include <QDebug>

sqlchange::sqlchange(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sqlchange)
{
    ui->setupUi(this);

    //信号和槽的连接
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(PrintText()));   //在修改选项之后，对应的选中值将在文本框中显示出来
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(getTable()));
    connect(ui->comboBox_2,SIGNAL(currentIndexChanged(QString)),this,SLOT(PrintText_C()));
    connect(ui->comboBox_2,SIGNAL(currentIndexChanged(QStirng)),this,SLOT(getTable_C()));   //信号链接出现问题！在PushButton中增加信号



    //优化性分析
    //在每次切换表格的时候，都将TableWidget中的内容进行清空
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(Clear_TW()));



    //连接数据库
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

    //设置选择表格
    ui->comboBox->addItem(tr("S"));
    ui->comboBox->addItem(tr("C"));
    ui->comboBox->addItem(tr("SC"));
    //设置表格显式栏 -> 只读模式
    ui->lineEdit_12->setReadOnly(true);


    //获取选中的表格
    //由insert设计经验，在函数中获取

    //通过输入条件将对应表格中的数据输出
    //想法是通过构造一个Search函数来实现对数据的查询    --> 在修改与查询模块中，采用主码的方式进行查询 --> 即精确查询方式 后期可以考虑动态查询方法

    //修改方法
    //以筛选条件 和选择的修改项进行修改
    ui->comboBox_2->addItem(tr("SCLASS"));
    ui->comboBox_2->addItem(tr("SNO"));
    ui->comboBox_2->addItem(tr("SNAME"));
    ui->comboBox_2->addItem(tr("SSEX"));
    ui->comboBox_2->addItem(tr("SAGE"));
    ui->comboBox_2->addItem(tr("CNO"));
    ui->comboBox_2->addItem(tr("CNAME"));
    ui->comboBox_2->addItem(tr("CPNO"));
    ui->comboBox_2->addItem(tr("CCREDIT"));
    ui->comboBox_2->addItem(tr("GRADE"));

    //将comboBox_2中的内容显示到文本框中并且读入table_C变量中    //根据主码可以唯一确定一条变量，识别需要修改的变量值进行对应修改
    //借助PrintText_C函数与getTable_C函数实现
    ui->lineEdit_13->setReadOnly(true);


}

void sqlchange::PrintText()
{
    int index = 0;
    index = ui->comboBox->currentIndex();
    ui->lineEdit_12->setText(ui->comboBox->itemText(index));   //选择comboBox的选中项进行展示
}


void sqlchange::getTable()
{
    table = ui->comboBox->currentText();                      //直接获取conboBox中当前选择的文本
    //qDebug() <<table;
}

void sqlchange::Search()
{
    if(db.open())
    {
        if(table == "S")
        {
            //获取输入信息
            SCLASS = ui->lineEdit_1->text();
            SNO = ui->lineEdit_2->text();

            //查询输出结果
            //查询
            QSqlQuery query(db);
//            query.prepare("SELECT * FROM S WHERE SCALSS = ? AND SNO = ?;");                        //待优化代码
//            query.addBindValue(SCLASS);
//            query.addBindValue(SNO);
            query.prepare("SELECT * FROM S WHERE SCLASS = "+SCLASS+" AND SNO = "+SNO+";");           //字符串嗯相加就行，上述代码就不行
            //query.prepare("SELECT * FROM S;");                              //测试表格异常输出
            if(query.exec())                                                        //是不是应该增加空值判断机制？？？
            {
                ui->textBrowser->setText("SELECT SUCCESSFUL!");
                //结果输出
                QStringList header;                                           //显示提示内容，即列标

                //尝试设置行列数                                                //不提前设置好 就不显示  爬~
                ui->tableWidget->setRowCount(10);
                ui->tableWidget->setColumnCount(5);

                header<<"SCLASS"<<tr("SNO")<<tr("SNAME")<<tr("SSEX")
                      <<tr("SAGE")<<tr("SDEPT");                              //在需要时可以对名称进行修改
                ui->tableWidget->setHorizontalHeaderLabels(header);           //打印表头

                query.previous();
                if(query.next())
                {
                    ui->tableWidget->insertRow(0);                                //插入一个空行
                    for(int i=0;i<5;i++)
                    {
                        ui->tableWidget->setItem(0,i,new QTableWidgetItem(query.value(i).toString()));     //一定加上.toString(); ※
                        //ui->tableWidget->setItem(0,i,new QTableWidgetItem("1"));                         //测试表格异常输出
                    }
                }
                else
                {
                    //ui->textBrowser->setText("OutPut ERROR!");
                }
            }
            else
            {
                ui->textBrowser->setText(("SELECT ERROR!"));
            }
        }
        else if(table == "C")
        {
            //获取信息
            CNO = ui->lineEdit_7->text();

            QSqlQuery query(db);
            //尝试采用另外一种查询方式
            query.prepare("SELECT * FROM C WHERE CNO = :CNO");
            query.bindValue(":CNO",CNO);

            //执行语句
            if(query.exec())
            {
                ui->textBrowser->setText("SELECT SUCCESSFUL!");

                //设置行列数
                ui->tableWidget->setRowCount(10);
                ui->tableWidget->setColumnCount(4);
                //设置列名
                QStringList header;
                header<<"CNO"<<"CNAME"<<"CPNO"<<"CCREDIT";
                ui->tableWidget->setHorizontalHeaderLabels(header);
                //显示查询信息
                query.previous();
                if(query.next())
                {
                    ui->tableWidget->insertRow(0);          //插入空行
                    for(int i=0;i<4;i++)
                    {
                        ui->tableWidget->setItem(0,i,new QTableWidgetItem(query.value(i).toString()));  //类型转换
                    }
                }
                else
                {
                    ui->textBrowser->setText("OutPut ERROR!");
                }
            }
            else
            {
                ui->textBrowser->setText("SELECT ERROR!");
            }
        }
        else if(table == "SC")
        {
            SCLASS = ui->lineEdit_1->text();
            SNO = ui->lineEdit_2->text();
            CNO = ui->lineEdit_7->text();

            //查询sql语句准备
            QSqlQuery query(db);
            query.prepare("SELECT * FROM SC WHERE SCLASS=:SCLASS AND SNO=:SNO AND CNO=:CNO;");
            query.bindValue(":SCLASS",SCLASS);
            query.bindValue(":SNO",SNO);
            query.bindValue(":CNO",CNO);

            if(query.exec())
            {
                ui->textBrowser->setText("SELECT SUCCESSFUL!");
                //表格准备
                ui->tableWidget->setRowCount(10);
                ui->tableWidget->setColumnCount(4);
                QStringList header;
                header<<"SCLASS"<<"SNO"<<"CNO"<<"GRADE";
                ui->tableWidget->setHorizontalHeaderLabels(header);

                query.previous();
                if(query.next())
                {
                    ui->tableWidget->insertRow(0);
                    for(int i=0;i<4;i++)
                    {
                        ui->tableWidget->setItem(0,i,new QTableWidgetItem(query.value(i).toString()));
                    }
                }
            }
            else
            {
                ui->textBrowser->setText("SELECT ERROR!");

            }
        }
        else
        {
            //表格所示不在范围内 -> 出现系统故障
            ui->textBrowser->setText("System ERROR!");
            exit(0);
        }
    }
}

void sqlchange::PrintText_C()
{
    int index = 0;
    index = ui->comboBox_2->currentIndex();
    ui->lineEdit_13->setText(ui->comboBox_2->itemText(index));
}

void sqlchange::getTable_C()
{
    //this->table_C = ui->comboBox_2->currentText();    //调试信号与槽代码
    table_C = ui->comboBox_2->currentText();
    //table_C = ui->lineEdit->text();
    //qDebug() << table_C;
}

//在这里不允许对表格信息的主码进行修改，若想实现对主码的修改，可以先将对应的信息删除，再重新修改插入
//这里修改采用了大量的重复代码，后期可以尝试修改为动态SQL语言进行实现
void sqlchange::change()
{
    //qDebug() << table << table_C;
    if(db.open())
    {
        if(table == "S")
        {
            QSqlQuery query(db);
            if(table_C == "SNAME")
            {
                SCLASS = ui->lineEdit_1->text();
                SNO = ui->lineEdit_2->text();
                SNAME = ui->lineEdit->text();
                qDebug()<<SCLASS<<SNO<<SNAME;
                query.prepare("UPDATE S SET SNAME = ? WHERE SCLASS=? AND SNO=?;");          //SQL语句都写错了，你是想升天嘛
                query.addBindValue(SNAME);
                query.addBindValue(SCLASS);
                query.addBindValue(SNO);
                //经过测试如下代码也可
//                query.prepare("UPDATE S SET SNAME = :SNAME WHERE SCLASS=:SCLASS AND SNO=:SNO;");
//                query.bindValue(":SNAME",SNAME);
//                query.bindValue(":SCLASS",SCLASS);
//                query.bindValue(":SNO",SNO);

                if(query.exec())
                {
                    ui->textBrowser->setText("UPDATE SUCCESSFUL!");
                }
                else
                {
                    ui->textBrowser->setText("UPDATE ERROR!");
                }
            }
            else if(table_C == "SSEX")
            {
                SCLASS = ui->lineEdit_1->text();
                SNO = ui->lineEdit_2->text();
                SSEX = ui->lineEdit->text();
                query.prepare("UPDATE S SET SSEX = ? WHERE SCLASS=? AND SNO=?;");
                query.addBindValue(SSEX);
                query.addBindValue(SCLASS);
                query.addBindValue(SNO);
                if(query.exec())
                {
                    ui->textBrowser->setText("UPDATE SUCCESSFUL!");
                }
                else
                {
                    ui->textBrowser->setText("UPDATE ERROR!");
                }
            }
            else if(table_C == "SAGE")
            {
                SCLASS = ui->lineEdit_1->text();
                SNO = ui->lineEdit_2->text();
                SAGE = ui->lineEdit->text();
                query.prepare("UPDATE S SET SAGE = ? WHERE SCLASS=? AND SNO=?;");
                query.addBindValue(SAGE);
                query.addBindValue(SCLASS);
                query.addBindValue(SNO);
                if(query.exec())
                {
                    ui->textBrowser->setText("UPDATE SUCCESSFUL!");
                }
                else
                {
                    ui->textBrowser->setText("UPDATE ERROR!");
                }
            }
            else if(table_C == "SDEPT")
            {
                SCLASS = ui->lineEdit_1->text();
                SNO = ui->lineEdit_2->text();
                SDEPT = ui->lineEdit->text();
                query.prepare("UPDATE SET SDEPT = ? WHERE SCLASS=? AND SNO=?;");
                query.addBindValue(SDEPT);
                query.addBindValue(SCLASS);
                query.addBindValue(SNO);
                if(query.exec())
                {
                    ui->textBrowser->setText("UPDATE SUCCESSFUL!");
                }
                else
                {
                    ui->textBrowser->setText("UPDATE ERROR!");
                }
            }
            else if(table_C == "SCLASS" || table_C == "SNO")
            {
                ui->textBrowser->setText("Sorry! This operation is not allowed.");
            }
            else
            {
                ui->textBrowser->setText("System ERROR!");
            }
        }
        else if(table == "C")
        {
            QSqlQuery query(db);
            if(table_C == "CNAME")
            {
                CNO = ui->lineEdit_7->text();
                CNAME = ui->lineEdit->text();
                query.prepare("UPDATE C SET CNAME=? WHERE CNO=?;");
                query.addBindValue(CNAME);
                query.addBindValue(CNO);
                if(query.exec())
                {
                    ui->textBrowser->setText("UPDATE SUCCESSFUL!");
                }
                else
                {
                    ui->textBrowser->setText("UPDATE ERROR!");
                }
            }
            else if(table_C == "CPNO")
            {
                CNO = ui->lineEdit_7->text();
                CPNO = ui->lineEdit->text();
                query.prepare("UPDATE C SET CPNO=? WHERE CNO=?;");
                query.addBindValue(CPNO);
                query.addBindValue(CNO);
                if(query.exec())
                {
                    ui->textBrowser->setText("UPDATE SUCCESSFUL!");
                }
                else
                {
                    ui->textBrowser->setText("UPDATE ERROR!");
                }
            }
            else if(table_C == "CCREDIT")
            {
                CNO = ui->lineEdit_7->text();
                CCREDIT = ui->lineEdit->text();
                query.prepare("UPDATE C SET CCREDIT=? WHERE CNO=?;");
                query.addBindValue(CCREDIT);
                query.addBindValue(CNO);
                if(query.exec())
                {
                    ui->textBrowser->setText("UPDATE SUCCESSFUL!");
                }
                else
                {
                    ui->textBrowser->setText("UPDATE ERROR!");
                }
            }
            else if(table_C == "CNO")
            {
                ui->textBrowser->setText("Sorry! This operation is not allowed.");
            }
            else
            {
                ui->textBrowser->setText("System ERROR!");
                exit(0);
            }

        }
        else if(table == "SC")
        {
            QSqlQuery query(db);
            if(table_C == "GRADE")
            {
                SCLASS = ui->lineEdit_1->text();
                SNO = ui->lineEdit_2->text();
                CNO = ui->lineEdit_7->text();
                GRADE = ui->lineEdit->text();
                query.prepare("UPDATE SC SET GRADE=? WHERE SCLASS=? AND SNO=? AND CNO=?;");
                query.addBindValue(GRADE);
                query.addBindValue(SCLASS);
                query.addBindValue(SNO);
                query.addBindValue(CNO);
                if(query.exec())
                {
                    ui->textBrowser->setText("UPDATE SUCCESSFUL!");
                }
                else
                {
                    ui->textBrowser->setText("UPDATE ERROR!");
                }
            }
            else if(table_C == "SCLASS" || table_C == "SNO" || table_C == "CNO")
            {
                ui->textBrowser->setText("Sorry! This opearation is not allowed.");
            }
            else
            {
                ui->textBrowser->setText("Please check your choice!");
                //exit(0);
            }
        }
        else
        {
            ui->textBrowser->setText("System ERROR!");
            //exit(0);
        }
    }
}

void sqlchange::on_pushButton_clicked()
{
    this->Search();
}

void sqlchange::on_pushButton_2_clicked()
{
    this->getTable_C();
    this->change();
}

//将TableWidget中的内容进行清空
void sqlchange::Clear_TW()
{
    ui->tableWidget->clear();
}

sqlchange::~sqlchange()
{
    delete ui;
}
















