#include "skeleton.h"
#include <QToolBar>
#include <QIcon>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QTextEdit>

Skeleton::Skeleton(QWidget *parent): QMainWindow(parent){

    QPixmap newpix("/home/ab/code/ros/tutorial/rosqt/src/p9_qt/p9_qt/images/apple.png");
    QPixmap openpix("/home/ab/code/ros/tutorial/rosqt/src/p9_qt/p9_qt/images/dot.png");
    QPixmap quitpix("/home/ab/code/ros/tutorial/rosqt/src/p9_qt/p9_qt/images/brick.png");

    QAction *newa = new QAction(newpix,"&New",this);
    QAction *open = new QAction(openpix,"&Open",this);
    QAction *quit = new QAction(quitpix,"&Quit",this);

    QMenu *file;
    file = menuBar()->addMenu("&File");
    file->addAction(quit);
    connect(quit,&QAction::triggered, qApp, &QApplication::quit);

    QToolBar *toolbar = addToolBar("main Toolbar");
    toolbar->addAction(newa);
    toolbar->addAction(open);
    toolbar->addAction(quit);

    QTextEdit *edit = new QTextEdit(this);

    setCentralWidget(edit);
    statusBar()->showMessage("Ready");
}

