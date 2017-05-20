#include "anmenu.h"

int main(int argc,char** argv){

    QApplication app(argc, argv);

    AnotherMenu window;
    window.resize(300,200);

    window.setWindowTitle("haha");

    window.show();
    return app.exec();

}
