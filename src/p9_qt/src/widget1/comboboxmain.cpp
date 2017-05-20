#include <QApplication>
#include "combobox.h"

int main(int argc, char** argv){
    
    QApplication app(argc,argv);

    ComboBoxEx window;
    window.show();
    return app.exec();

}
