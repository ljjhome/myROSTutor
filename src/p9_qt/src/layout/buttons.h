#pragma once
#include <QWidget>
#include <QPushButton>

class Buttons : public QWidget {
public:
    Buttons(QWidget *parent = 0);

private:
    QPushButton *okBtn;
    QPushButton *applyBtn;
};
