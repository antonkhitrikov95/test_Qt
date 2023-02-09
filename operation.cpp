#include "operation.h"
#include "ui_operation.h"

operation::operation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::operation)
{
    ui->setupUi(this);

    blCheckboxes = new QBoxLayout(QBoxLayout::TopToBottom);
    blCheckboxes->setContentsMargins(20,20,20,20);
    blCheckboxes->setSpacing(20);

    cbAddition = new QCheckBox("Addition");
    cbSubtraction = new QCheckBox("Subtraction");
    cbMultiplication = new QCheckBox("Multiplication");
    cbDivision = new QCheckBox("Division");

    blCheckboxes->addWidget(cbAddition);
    blCheckboxes->addWidget(cbSubtraction);
    blCheckboxes->addWidget(cbMultiplication);
    blCheckboxes->addWidget(cbDivision);

    blButtons = new QBoxLayout(QBoxLayout::LeftToRight);
    blButtons->setContentsMargins(20,20,20,20);
    blButtons->setSpacing(20);

    btnOK = new QPushButton("OK");
    btnOK->setDefault(true);
    btnCancel = new QPushButton("CANCEL");

    blButtons->addWidget(btnOK);
    blButtons->addWidget(btnCancel);

    blMain = new QBoxLayout(QBoxLayout::TopToBottom);
    blMain->addLayout(blCheckboxes);
    blMain->addLayout(blButtons);

    setLayout(blMain);

    connect (cbAddition, &QCheckBox::stateChanged, this, &operation::check_cbAddition);
    connect (cbSubtraction, &QCheckBox::stateChanged, this, &operation::check_cbSubtraction);
    connect (cbMultiplication, &QCheckBox::stateChanged, this, &operation::check_cbMultiplication);
    connect (cbDivision, &QCheckBox::stateChanged, this, &operation::check_cbDivision);
}

operation::~operation()
{
    delete ui;
}
void operation::check_cbAddition()
{
    if (cbAddition->isChecked())
    {
        cbSubtraction->setEnabled(false);
        cbMultiplication->setEnabled(false);
        cbDivision->setEnabled(false);
    }
    else
    {
        cbSubtraction->setEnabled(true);
        cbMultiplication->setEnabled(true);
        cbDivision->setEnabled(true);
    }
}
void operation::check_cbSubtraction()
{
    if (cbSubtraction->isChecked())
    {
        cbAddition->setEnabled(false);
        cbMultiplication->setEnabled(false);
        cbDivision->setEnabled(false);
    }
    else
    {
        cbAddition->setEnabled(true);
        cbMultiplication->setEnabled(true);
        cbDivision->setEnabled(true);
    }
}
void operation::check_cbMultiplication()
{
    if (cbMultiplication->isChecked())
    {
        cbAddition->setEnabled(false);
        cbSubtraction->setEnabled(false);
        cbDivision->setEnabled(false);
    }
    else
    {
        cbAddition->setEnabled(true);
        cbSubtraction->setEnabled(true);
        cbDivision->setEnabled(true);
    }
}
void operation::check_cbDivision()
{
    if (cbDivision->isChecked())
    {
        cbAddition->setEnabled(false);
        cbSubtraction->setEnabled(false);
        cbMultiplication->setEnabled(false);
    }
    else
    {
        cbAddition->setEnabled(true);
        cbSubtraction->setEnabled(true);
        cbMultiplication->setEnabled(true);
    }
}
