#include "nesting.h"
#include <QApplication>

int main(int argc, char** argv){

    QApplication app(argc, argv);
    Layouts window;
    window.show();
    return app.exec();
}
