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
}

operation::~operation()
{
    delete ui;
}
