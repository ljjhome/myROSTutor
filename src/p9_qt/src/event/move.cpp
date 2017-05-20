#include <QMoveEvent>
#include "move.h"

Move::Move(QWidget *parent): QWidget(parent){
    

}

void Move::moveEvent(QMoveEvent *e){
    
    int x = e->pos().x();
    int y = e->pos().y();

    QString text = QString::number(x) + ","+ QString::number(y);

    setWindowTitle(text);
}
