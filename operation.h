#ifndef OPERATION_H
#define OPERATION_H

#include <QDialog>
#include <QtWidgets>

namespace Ui {
class operation;
}

class operation : public QDialog
{
    Q_OBJECT

public:
    explicit operation(QWidget *parent = nullptr);
    ~operation();

    QPushButton *btnOK;

 public slots:
    void check_cbAddition();
    void check_cbSubtraction();
    void check_cbMultiplication();
    void check_cbDivision();
    void btnOKpush();
    void btnCANCELpush();

signals:
    void btnOKsignal(int);

private:
    Ui::operation *ui;

    QBoxLayout *blMain;
    QBoxLayout *blCheckboxes;
    QBoxLayout *blButtons;

    QCheckBox *cbAddition;
    QCheckBox *cbSubtraction;
    QCheckBox *cbMultiplication;
    QCheckBox *cbDivision;

    QPushButton *btnCancel;

};

#endif // OPERATION_H
