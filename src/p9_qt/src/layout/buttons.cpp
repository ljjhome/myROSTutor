#include "buttons.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

Buttons::Buttons(QWidget* parent): QWidget(parent){

    QVBoxLayout *vbox = new QVBoxLayout(this);
    QHBoxLayout *hbox = new QHBoxLayout(this);

    okBtn = new QPushButton("OK",this);
    applyBtn = new QPushButton("Apply",this);

    hbox->addWidget(okBtn,1,Qt::AlignRight);
    hbox->addWidget(applyBtn,0);

    vbox->addStretch(0.1);
    vbox->addLayout(hbox);
}

