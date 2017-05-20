#include <QApplication>
#include "review.h"

int main(int argc, char** argv){
    QApplication app(argc,argv);

    Review window;

    window.show();

    return app.exec();

}
