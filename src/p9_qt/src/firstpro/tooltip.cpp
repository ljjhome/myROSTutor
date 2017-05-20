#include <QApplication>
#include <QWidget>

int main(int argc, char** argv){

    QApplication app(argc,argv);

    QWidget window;

    window.resize(250,150);
    window.move(300,300);

    window.setWindowTitle("Tooltip");
    window.setToolTip("QWidget");
    window.show();
    return app.exec();
}
