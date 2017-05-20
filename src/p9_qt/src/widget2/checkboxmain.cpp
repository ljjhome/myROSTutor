#include <QApplication>
#include "checkbox.h"

int main(int argc, char** argv){
    
    QApplication app(argc, argv);

    CheckBox window;
    window.show();
    return app.exec();

}
