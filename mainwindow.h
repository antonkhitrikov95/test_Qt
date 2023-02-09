#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "operation.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void btnOperationClicked();

private:
    Ui::MainWindow *ui;
    operation *operationWindow;

    QWidget *wgMain;

    QBoxLayout *blMain;
    QBoxLayout *blText;
    QBoxLayout *blButtons;

    QTextEdit *teFirstArg;
    QTextEdit *teSecondArg;
    QTextEdit *teResult;

    QPushButton *btnCalculate;
    QPushButton *btnChooseOperation;
};
#endif // MAINWINDOW_H
