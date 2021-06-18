#ifndef QCHANGE_H
#define QCHANGE_H

#include <QWidget>

namespace Ui {
class qchange;
}

class qchange : public QWidget
{
    Q_OBJECT

public:
    explicit qchange(QWidget *parent = nullptr);
    ~qchange();

private:
    Ui::qchange *ui;
};

#endif // QCHANGE_H
