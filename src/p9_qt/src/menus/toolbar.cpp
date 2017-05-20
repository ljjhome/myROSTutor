#include "toolbar.h"
#include <QToolBar>
#include <QIcon>
#include <QAction>

Toolbar::Toolbar(QWidget *parent): QMainWindow(parent){

    QPixmap newpix("/home/ab/code/ros/tutorial/rosqt/src/p9_qt/p9_qt/images/apple.png");
    QPixmap openpix("/home/ab/code/ros/tutorial/rosqt/src/p9_qt/p9_qt/images/ball.png");
    QPixmap quitpix("/home/ab/code/ros/tutorial/rosqt/src/p9_qt/p9_qt/images/brick.png");

    QAction *newa = new QAction(newpix,"&new",this);
    QAction *open = new QAction(openpix,"&open",this);
    QAction *quit = new QAction(quitpix,"&quit",this);
    QToolBar *toolbar = addToolBar("main toolbar");
    toolbar->addAction(newa);
    toolbar->addAction(open);
    toolbar->addSeparator();
    toolbar->addAction(quit);
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
}


