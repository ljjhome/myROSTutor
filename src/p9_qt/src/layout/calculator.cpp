#include <QGridLayout>
#include <QPushButton>
#include "calculator.h"

Calculator::Calculator(QWidget *parent): QWidget(parent){
    
    QGridLayout *grid = new QGridLayout(this);
    grid->setSpacing(2);

    QList<QString> values({"7","8","9","/",
            "4","5","6","*",
            "1","2","3","-",
            "0",".","=","+"});

    int pos = 0;
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            QPushButton *btn = new QPushButton(values[pos],this);
            btn->setFixedSize(40,40);
            grid->addWidget(btn,i,j);
            pos++;
        } 
    }
    setLayout(grid);
}
