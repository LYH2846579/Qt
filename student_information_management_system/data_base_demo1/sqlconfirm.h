#ifndef SQLCONFIRM_H
#define SQLCONFIRM_H

#include <QWidget>

namespace Ui {
class sqlconfirm;
}

class sqlconfirm : public QWidget
{
    Q_OBJECT

//public:
//    friend class MainWindow;
public:
    explicit sqlconfirm(QWidget *parent = nullptr);
    ~sqlconfirm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::sqlconfirm *ui;
};

#endif // SQLCONFIRM_H
