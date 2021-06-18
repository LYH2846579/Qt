/********************************************************************************
** Form generated from reading UI file 'sqlconfirm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQLCONFIRM_H
#define UI_SQLCONFIRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sqlconfirm
{
public:
    QLabel *label;
    QCheckBox *checkBox;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *sqlconfirm)
    {
        if (sqlconfirm->objectName().isEmpty())
            sqlconfirm->setObjectName(QString::fromUtf8("sqlconfirm"));
        sqlconfirm->resize(572, 428);
        label = new QLabel(sqlconfirm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 120, 321, 41));
        checkBox = new QCheckBox(sqlconfirm);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(290, 250, 131, 21));
        label_2 = new QLabel(sqlconfirm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(260, 190, 201, 41));
        pushButton = new QPushButton(sqlconfirm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 300, 89, 24));

        retranslateUi(sqlconfirm);

        QMetaObject::connectSlotsByName(sqlconfirm);
    } // setupUi

    void retranslateUi(QWidget *sqlconfirm)
    {
        sqlconfirm->setWindowTitle(QCoreApplication::translate("sqlconfirm", "Form", nullptr));
        label->setText(QCoreApplication::translate("sqlconfirm", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">\346\202\250\347\241\256\350\256\244\350\246\201\345\210\240\351\231\244\345\220\227\357\274\237</span></p></body></html>", nullptr));
        checkBox->setText(QCoreApplication::translate("sqlconfirm", "\346\210\221\345\267\262\350\200\203\350\231\221\345\256\214\346\257\225", nullptr));
        label_2->setText(QCoreApplication::translate("sqlconfirm", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">\350\257\245\346\223\215\344\275\234\346\227\240\346\263\225\346\222\244\351\224\200\357\274\201</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("sqlconfirm", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sqlconfirm: public Ui_sqlconfirm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQLCONFIRM_H
