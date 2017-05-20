#include <QVBoxLayout>
#include <QFont>
#include "label.h"

Label::Label(QWidget *parent):QWidget(parent){
    
    QString lyrics = "WHo donen;t for some to hold \n\
        who noew how to lov eyou withoud being told \n\
        some body tell me whiy i'm on my won \n\
        if there is a solu mate for every one \n\
            \n\
        here we are argina cirlce never end \n\
        How do i find the cper fect fit \n\
        but i' m still waiting in the line \n\
        if ther eis some for one\n\
            \n\
        who doen't for long for somewone to hole\n\
        who knows how to love you without bening told\n\
        some body tell me whiy i'm one my won\n\
        if there a solul mainte for everymone";

    label = new QLabel(lyrics,this);
    label->setFont(QFont("Purisa",10));

    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->addWidget(label);
    setLayout(vbox);

}
