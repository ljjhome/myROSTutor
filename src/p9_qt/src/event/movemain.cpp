#include "move.h"
#include <QApplication>

int main(int argc, char** argv){
    
    QApplication app(argc, argv);

    Move window;

    window.resize(399,320);
    window.show();
    return app.exec();

}
