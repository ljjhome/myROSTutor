#include <QApplication>
#include "spinbox.h"

int main(int argc, char** argv){
    
    QApplication app(argc, argv);
    SpinBox window;
    window.show();
    return app.exec();
}
