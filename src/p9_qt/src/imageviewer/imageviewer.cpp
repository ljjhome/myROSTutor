#include <QtWidget>
#ifndef QT_NO_PRINTER
#include <QPrintDialog>
#endif

#include "imageviewer.h"

ImageViewer::ImageViewer():imageLabel(new QLabel),
    scrollArea(new QScrollArea),scaleFactor(1){
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    scrollArea->setVisible(false);
    setCentralWidget(scrollArea);

    createActions();

    resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);     
}

bool ImageViewer::loadFile(const QString &fileName){
    
}
