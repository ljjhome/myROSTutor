#include <QApplication>
#include "ledit.h"

int main(int argc, char** argv){
    
    QApplication app(argc, argv);

    Ledit window;
    window.show();
    return app.exec();

}
