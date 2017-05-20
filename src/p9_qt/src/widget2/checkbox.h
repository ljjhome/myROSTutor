#pragma once 
#include <QWidget>

class CheckBox : public QWidget {
    
public:
    CheckBox(QWidget *parent = 0);
private slots:
    void showTitle(int);
};
