#include "anmenu.h"
#include <QMenu>
#include <QMenuBar>

AnotherMenu::AnotherMenu(QWidget *parent): QMainWindow(parent){

    QPixmap newpix("/home/ab/code/ros/tutorial/rosqt/src/p9_qt/p9_qt/images/apple.png");
    QPixmap openpix("/home/ab/code/ros/tutorial/rosqt/src/p9_qt/p9_qt/images/ball.png");
    QPixmap quitpix("/home/ab/code/ros/tutorial/rosqt/src/p9_qt/p9_qt/images/brick.png");

    QAction *newa = new QAction(newpix, "&New", this);
    QAction *open = new QAction(openpix, "&open", this);
    QAction *quit = new QAction(quitpix, "&quit", this);

    quit->setShortcut(tr("CTRL+Q"));

    QMenu *file;
    file = menuBar()->addMenu("&File");
    file->addAction(newa);
    file->addAction(open);
    file->addSeparator();
    file->addAction(quit);

    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);

    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
}

