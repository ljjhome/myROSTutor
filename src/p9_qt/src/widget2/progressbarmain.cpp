#include <QApplication>
#include "progressbar.h"

int main(int argc, char** argv){
    
    QApplication app(argc, argv);

    ProgressBarex window;
    window.show();
    return app.exec();
}
