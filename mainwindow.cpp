#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    blText = new QBoxLayout(QBoxLayout::LeftToRight);
    blText->setContentsMargins(20,20,20,20);
    blText->setSpacing(50);
    teFirstArg = new QTextEdit();
    teFirstArg->setPlaceholderText(QString("Input of Arg #1"));
    teSecondArg = new QTextEdit();
    teSecondArg->setPlaceholderText(QString("Input of Arg #2"));
    teResult = new QTextEdit();
    teResult->setPlaceholderText(QString("Output for result"));
    blText->addWidget(teFirstArg);
    blText->addWidget(teSecondArg);
    blText->addWidget(teResult);

    blButtons = new QBoxLayout(QBoxLayout::LeftToRight);
    blButtons->setContentsMargins(20,20,20,20);
    blButtons->setSpacing(100);
    btnCalculate = new QPushButton("Calculate");
    btnChooseOperation = new QPushButton("Operation");
    blButtons->addWidget(btnCalculate);
    blButtons->addWidget(btnChooseOperation);

    blMain = new QBoxLayout(QBoxLayout::TopToBottom);
    blMain->setSpacing(400);
    blMain->addLayout(blText);
    blMain->addLayout(blButtons);

    wgMain = new QWidget(this);
    wgMain->setLayout(blMain);

    wgMain->show();

    setCentralWidget(wgMain);

    connect(btnChooseOperation, &QPushButton::released, this, &MainWindow::btnOperationClicked);
    connect(btnCalculate, &QPushButton::released, this, &MainWindow::btnCalcutate_slot);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::btnOperationClicked()
{
    operationWindow = new operation();
    operationWindow->setModal(true);

    connect(operationWindow, SIGNAL(btnOKsignal(int)), this, SLOT(operaionValue(int)));

    operationWindow->exec();
}
void MainWindow::operaionValue(int value)
{
    switch (value)
    {
        case 0:
            btnChooseOperation->setText(QString("Operation"));
            break;

        case 1:
            btnChooseOperation->setText(QString("Addition"));
            break;

        case 2:
            btnChooseOperation->setText(QString("Subtraction"));
            break;

        case 3:
            btnChooseOperation->setText(QString("Multiplication"));
            break;

        case 4:
            btnChooseOperation->setText(QString("Division"));
            break;
    }

}
void MainWindow::btnCalcutate_slot()
{
    int firstArg;
    int secondArg;
    int result;

    bool ok;

    if (!teFirstArg->toPlainText().isEmpty() && !teSecondArg->toPlainText().isEmpty())
    {
        firstArg = teFirstArg->toPlainText().toInt(&ok,10);
        secondArg = teSecondArg->toPlainText().toInt(&ok, 10);
        if (btnChooseOperation->text() == "Addition")
            teResult->setPlainText(QString(QString::number(firstArg + secondArg, 10)));
        if (btnChooseOperation->text() == "Subtraction")
            teResult->setPlainText(QString(QString::number(firstArg - secondArg, 10)));
        if (btnChooseOperation->text() == "Multiplication")
            teResult->setPlainText(QString(QString::number(firstArg * secondArg, 10)));
        if (btnChooseOperation->text() == "Division")
            teResult->setPlainText(QString(QString::number(firstArg / secondArg, 10)));
    }
}
















