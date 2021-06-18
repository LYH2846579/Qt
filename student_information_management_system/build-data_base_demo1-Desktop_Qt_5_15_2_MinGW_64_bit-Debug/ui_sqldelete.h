/********************************************************************************
** Form generated from reading UI file 'sqldelete.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQLDELETE_H
#define UI_SQLDELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sqldelete
{
public:
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_9;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_1;
    QLabel *label_7;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextBrowser *textBrowser;
    QComboBox *comboBox;
    QLineEdit *lineEdit;

    void setupUi(QWidget *sqldelete)
    {
        if (sqldelete->objectName().isEmpty())
            sqldelete->setObjectName(QString::fromUtf8("sqldelete"));
        sqldelete->resize(865, 551);
        label = new QLabel(sqldelete);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 50, 291, 61));
        lineEdit_2 = new QLineEdit(sqldelete);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(400, 150, 113, 21));
        label_9 = new QLabel(sqldelete);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(600, 150, 72, 15));
        label_3 = new QLabel(sqldelete);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 150, 72, 15));
        lineEdit_3 = new QLineEdit(sqldelete);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(700, 150, 113, 21));
        lineEdit_1 = new QLineEdit(sqldelete);
        lineEdit_1->setObjectName(QString::fromUtf8("lineEdit_1"));
        lineEdit_1->setGeometry(QRect(120, 150, 113, 21));
        label_7 = new QLabel(sqldelete);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(300, 150, 72, 15));
        tableWidget = new QTableWidget(sqldelete);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 200, 821, 221));
        pushButton = new QPushButton(sqldelete);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(730, 440, 93, 28));
        pushButton_2 = new QPushButton(sqldelete);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(730, 480, 93, 28));
        textBrowser = new QTextBrowser(sqldelete);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 430, 521, 91));
        comboBox = new QComboBox(sqldelete);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(580, 440, 87, 22));
        lineEdit = new QLineEdit(sqldelete);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(580, 480, 121, 28));

        retranslateUi(sqldelete);

        QMetaObject::connectSlotsByName(sqldelete);
    } // setupUi

    void retranslateUi(QWidget *sqldelete)
    {
        sqldelete->setWindowTitle(QCoreApplication::translate("sqldelete", "Form", nullptr));
        label->setText(QCoreApplication::translate("sqldelete", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600;\">\345\210\240\351\231\244\346\225\260\346\215\256</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("sqldelete", "CNO", nullptr));
        label_3->setText(QCoreApplication::translate("sqldelete", "SCLASS", nullptr));
        label_7->setText(QCoreApplication::translate("sqldelete", "SNO", nullptr));
        pushButton->setText(QCoreApplication::translate("sqldelete", "Query", nullptr));
        pushButton_2->setText(QCoreApplication::translate("sqldelete", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sqldelete: public Ui_sqldelete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQLDELETE_H
