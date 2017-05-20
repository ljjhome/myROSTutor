#include <QLabel>
#include <QFrame>
#include <QStatusBar>
#include <QHBoxLayout>
#include "statusbar.h"

Statusbar::Statusbar(QWidget* parent):QMainWindow(parent){
   
    QFrame *frame = new QFrame(this);
    setCentralWidget(frame);

    QHBoxLayout *hbox = new QHBoxLayout(frame);

    okBtn = new QPushButton("OK",this);
    hbox->addWidget(okBtn,0,Qt::AlignLeft|Qt::AlignTop);

    aplBtn = new QPushButton("Apply",this);
    hbox->addWidget(aplBtn,1,Qt::AlignLeft|Qt::AlignTop);

    statusBar();

    connect(okBtn,&QPushButton::clicked,this,&Statusbar::OnOkPressed);
    connect(aplBtn,&QPushButton::clicked,this,&Statusbar::OnApplyPressed);
}

void Statusbar::OnOkPressed(){
    statusBar()->showMessage("Ok pressed",2000);
}

void Statusbar::OnApplyPressed(){
    statusBar()->showMessage("apply pressed",2000);
}
