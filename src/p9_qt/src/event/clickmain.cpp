#include "click.h"
#include <QApplication>

int main(int argc, char** argv){
    
    QApplication app(argc, argv);
    Click window;
    window.show();
    return app.exec();


}
