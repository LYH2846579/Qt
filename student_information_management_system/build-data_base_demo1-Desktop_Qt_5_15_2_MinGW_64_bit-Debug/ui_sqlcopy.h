/********************************************************************************
** Form generated from reading UI file 'sqlcopy.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQLCOPY_H
#define UI_SQLCOPY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sqlcopy
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *sqlcopy)
    {
        if (sqlcopy->objectName().isEmpty())
            sqlcopy->setObjectName(QString::fromUtf8("sqlcopy"));
        sqlcopy->resize(630, 468);
        label = new QLabel(sqlcopy);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 100, 211, 41));
        pushButton = new QPushButton(sqlcopy);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(420, 330, 89, 24));
        textBrowser = new QTextBrowser(sqlcopy);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(50, 210, 311, 201));

        retranslateUi(sqlcopy);

        QMetaObject::connectSlotsByName(sqlcopy);
    } // setupUi

    void retranslateUi(QWidget *sqlcopy)
    {
        sqlcopy->setWindowTitle(QCoreApplication::translate("sqlcopy", "Form", nullptr));
        label->setText(QCoreApplication::translate("sqlcopy", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600;\">\346\225\260\346\215\256\345\272\223\345\244\207\344\273\275</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("sqlcopy", "BackUp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sqlcopy: public Ui_sqlcopy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQLCOPY_H
