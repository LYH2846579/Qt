#include "sqlcopy.h"
#include "ui_sqlcopy.h"
#include <QDir>
#include <QDateTime>
#include <QProcess>
#include <QFileDialog>


sqlcopy::sqlcopy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sqlcopy)
{
    ui->setupUi(this);


}

sqlcopy::~sqlcopy()
{
    delete ui;
}

void sqlcopy::on_pushButton_clicked()
{
    QMessageBox* QmsBox = new QMessageBox();
    QmsBox->setText("提示");
    QmsBox->setInformativeText("您要备份数据库吗?");
    QmsBox->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    QmsBox->setDefaultButton(QMessageBox::Ok);
    int ret = QmsBox->exec();
    if(ret == QMessageBox::Ok)
    {
        //QString dirName = QDir::currentPath();
//        QString dirName = "F:\\QT\build-data_base_demo1-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\Backup_P";
//            if(!dirName.isEmpty()){
//                QString backupsFile = QDateTime::currentDateTime().toString("yyyyMMddhhmmss") + ".bak";
//                bool result = QFile::copy("F:\\QT\build-data_base_demo1-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\test.db",dirName + "/" + backupsFile);
//                if(!result){
//                    ui->textBrowser->setText("数据库备份失败");
//                    //备份失败
//                }
//                else
//                {
//                    ui->textBrowser->setText("数据库备份成功");
//                }
//            }

        this->Back_up();

    }
    else
    {
        ui->textBrowser->setText("数据库备份失败");
    }
}


//重定向技术实现SQLITE数据库备份
void sqlcopy::Back_up()
{
    QProcess *Pro;
    Pro = new QProcess(this);

    QFileDialog * file = new QFileDialog(this);
    QString Dir = file->getExistingDirectory(this, tr("Open Directory"),"F:\\",
                                             QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
    QStringList List = Dir.split("/");
    Dir = List[0];
    for(int i=1;i<List.count();i++)
    {
        Dir += "\\\\" + List[i];
    }
    //QString Text = QString("sqlite3.exe test.db \".dump\" > %1\\test01.db\n").arg(Dir);

    Pro->start("Cmd");
    Pro->waitForStarted();
    Pro->write(QString("copy test.db %1\\test01.db \n").arg(Dir).toLatin1().data());
    Pro->closeWriteChannel();
    Pro->waitForFinished();
    Pro->close();


    ui->textBrowser->setText("数据库备份成功");

}
