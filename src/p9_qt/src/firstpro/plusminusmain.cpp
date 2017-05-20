#include "plusminus.h"

int main(int argc, char** argv){

    QApplication app(argc, argv);

    PlusMinus window;

    window.resize(300,500);
    window.setWindowTitle("plusminus");
    window.show();

    return app.exec();
}
