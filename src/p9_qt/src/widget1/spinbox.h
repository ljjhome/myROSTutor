#pragma once
#include <QWidget>
#include <QSpinBox>

class SpinBox : public QWidget {
    
    Q_OBJECT

public:
    SpinBox(QWidget *parent = 0);
private:
    QSpinBox *spinbox;
    
};

