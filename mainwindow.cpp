#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setCentralWidget(new QWidget());
    blMainLayout = new QHBoxLayout();
    this->centralWidget()->setLayout(blMainLayout);
   // blMainLayout->setGeometry(QRect(QPoint(0,0), QSize(800,600)));

    teFirstArg = new QTextEdit("Arg #1", this);
    blMainLayout->addWidget(teFirstArg);
    blMainLayout->setStretch(1, 20);
   // teFirstArg->setGeometry(QRect(QPoint(100,100), QSize(100,30)));
    teFirstArg->setAlignment(Qt::AlignHCenter);

    teSecondArg = new QTextEdit("Arg #2", this);
  //  teSecondArg->setGeometry(QRect(QPoint(100,150), QSize(100,30)));
    teSecondArg->setAlignment(Qt::AlignHCenter);

    teResult = new QTextEdit("Result", this);
  //  teResult->setGeometry(QRect(QPoint(100,200), QSize(100,30)));
    teResult->setAlignment(Qt::AlignHCenter);

    btnCalculate = new QPushButton("Calculate", this);
  //  btnCalculate->setGeometry(QRect(QPoint(300,100), QSize(100,50)));

    btnChooseOperation = new QPushButton("Operation", this);
  //  btnChooseOperation->setGeometry(QRect(QPoint(300,180), QSize(100,50)));

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

