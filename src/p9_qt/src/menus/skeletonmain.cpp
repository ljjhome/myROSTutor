#include "skeleton.h"

int main(int argc, char** argv){

    QApplication app(argc, argv);

    Skeleton window;

    window.resize(400,300);
    window.setWindowTitle("hahha");
    window.show();
    return app.exec();
}
