#include "keypress.h"
#include <QApplication>

int main(int argc, char** argv){
    
    QApplication app(argc, argv);

    KeyPress window;
    window.show();
    return app.exec();
}
