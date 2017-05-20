#include <QApplication>
#include "disconnect.h"

int main(int argc, char** argv){
    
    QApplication app(argc, argv);

    Disconnect window;
    window.show();
    return app.exec();

}
