#pragma once
#include <QMainWindow>

class Move: public QWidget{

    Q_OBJECT
public:
    Move(QWidget *parent = 0);
protected:
    void moveEvent(QMoveEvent *e);
};
