#include <QApplication>
#include "image.h"

int main(int argc, char** argv){
    
    QApplication app(argc, argv);

    MyImage window;
    window.resize(300,400);
    window.show();
    return app.exec();

}
