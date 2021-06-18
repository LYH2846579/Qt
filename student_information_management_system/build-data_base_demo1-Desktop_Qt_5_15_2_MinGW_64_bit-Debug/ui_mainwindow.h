/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton_change;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_copy;
    QPushButton *pushButton_insert;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(791, 584);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 100, 301, 71));
        pushButton_change = new QPushButton(centralwidget);
        pushButton_change->setObjectName(QString::fromUtf8("pushButton_change"));
        pushButton_change->setGeometry(QRect(330, 300, 93, 28));
        pushButton_delete = new QPushButton(centralwidget);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(330, 340, 93, 28));
        pushButton_copy = new QPushButton(centralwidget);
        pushButton_copy->setObjectName(QString::fromUtf8("pushButton_copy"));
        pushButton_copy->setGeometry(QRect(330, 380, 93, 28));
        pushButton_insert = new QPushButton(centralwidget);
        pushButton_insert->setObjectName(QString::fromUtf8("pushButton_insert"));
        pushButton_insert->setGeometry(QRect(330, 260, 93, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 791, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600;\">\346\225\260\346\215\256\345\272\223\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", nullptr));
        pushButton_change->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\346\225\260\346\215\256", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\346\225\260\346\215\256", nullptr));
        pushButton_copy->setText(QCoreApplication::translate("MainWindow", "\345\244\207\344\273\275\346\225\260\346\215\256", nullptr));
        pushButton_insert->setText(QCoreApplication::translate("MainWindow", "\345\275\225\345\205\245\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
