#pragma once 
#include <QPushButton>

class Disconnect : public QWidget{
    
    Q_OBJECT
public:
    Disconnect(QWidget* parent = 0);
private slots:
    void onClick();
    void onCheck(int);
private:
    QPushButton *clickBtn;
};
