#include "buttons.h"
#include <QApplication>

int main(int argc, char** argv){

    QApplication app(argc, argv);

    Buttons window;

    window.resize(400,500);
    window.show();

    return app.exec();
}
