#include "simplemenu.h"
int main(int argc, char** argv){

    QApplication app(argc, argv);

    SimpleMenu window;

    window.resize(400,200);
    window.setWindowTitle("simple menu");
    window.show();

    return app.exec();
}
