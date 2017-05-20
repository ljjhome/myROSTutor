#include "checkable.h"

int main(int argc, char** argv){

    QApplication app(argc, argv);

    Checkable window;

    window.resize(300,300);
    window.setWindowTitle("haha");
    window.show();
    return app.exec();
}
