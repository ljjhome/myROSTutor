#include <QApplication>
#include "pixmap.h"

int main(int argc, char** argv){
    
    QApplication app(argc, argv);

    Pixmap window;
    window.show();

    return app.exec();

}
