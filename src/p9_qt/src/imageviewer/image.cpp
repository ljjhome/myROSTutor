#include "image.h"
#include <QLabel>
MyImage::MyImage(QWidget *parent):QWidget(parent){
    QPixmap mypix("/home/ab/Downloads/images.jpg");
    QLabel *mylabel = new QLabel("haha",this);
    mylabel->setPixmap(mypix);
}
