#include <QApplication>
#include "calculator.h"

int main(int argc, char** argv){
    
    QApplication app(argc,argv);

    Calculator window;
    window.move(300,300);
    window.show();
    return app.exec();

}
