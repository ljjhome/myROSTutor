#pragma once 
#include <QSlider>
#include <QLabel>

class Slider : public QWidget {
    
    Q_OBJECT
public:
    Slider(QWidget *parent = 0);
private:
    QSlider *slider;
    QLabel *label;
};
