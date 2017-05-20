#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include "form.h"

FormEx::FormEx(QWidget *parent): QWidget(parent){
    QLineEdit *nameEdit = new QLineEdit(this);
    QLineEdit *addrEdit = new QLineEdit(this);
    QLineEdit *occpEdit = new QLineEdit(this);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignVCenter);
    formLayout->addRow("Name: ", nameEdit);
    formLayout->addRow("Email: ", addrEdit);
    formLayout->addRow("Age: ", occpEdit);

    setLayout(formLayout);
}

