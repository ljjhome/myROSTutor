#include "timer.h"
#include <QApplication>

int main(int argc, char** argv){
    
    QApplication app(argc, argv);

    Timer window;
    window.show();
    return app.exec();
}
