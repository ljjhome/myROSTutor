#include <QApplication>
#include "statusbar.h"

int main(int argc, char** argv){
    
    QApplication app(argc, argv);

    Statusbar window;
    window.show();
    return app.exec();

}
