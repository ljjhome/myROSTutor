#include "verticalbox.h"
#include <QApplication>

int main(int argc,char** argv){

    QApplication app(argc, argv);

    VerticalBox window;
    window.resize(400,300);
    window.show();
    return app.exec();
}
