#ifndef OPERATION_H
#define OPERATION_H

#include <QDialog>

namespace Ui {
class operation;
}

class operation : public QDialog
{
    Q_OBJECT

public:
    explicit operation(QWidget *parent = nullptr);
    ~operation();

private:
    Ui::operation *ui;
};

#endif // OPERATION_H
