#include <QApplication>
#include "slider.h"

int main(int argc, char** argv){
    
    QApplication app(argc, argv);

    Slider window;
    window.show();
    return app.exec();
}
