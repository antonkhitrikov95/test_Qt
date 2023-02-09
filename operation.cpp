#include "operation.h"
#include "ui_operation.h"

operation::operation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::operation)
{
    ui->setupUi(this);
}

operation::~operation()
{
    delete ui;
}
