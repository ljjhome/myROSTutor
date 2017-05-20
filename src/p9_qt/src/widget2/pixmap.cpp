#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>
#include "pixmap.h"

Pixmap::Pixmap(QWidget* parent):QWidget(parent){
    QHBoxLayout *hbox = new QHBoxLayout(this);

    QPixmap pixmap("/home/ab/code/ros/tutorial/rosqt/src/p9_qt/p9_qt/images/brick.png");

    QLabel *label = new QLabel(this);
    label->setPixmap(pixmap);

    hbox->addWidget(label,0,Qt::AlignTop);
}
