#include <QApplication>
#include <QWidget>
#include <QPushButton>

class MyButton: public QWidget{
public:
    MyButton(QWidget *parent = 0);
};

MyButton::MyButton(QWidget* parent):QWidget(parent){
    QPushButton *quitBtn = new QPushButton("Quit",this);
    quitBtn->setGeometry(50,40,75,30);
    connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
}

int main(int argc, char** argv){
    QApplication app(argc, argv);

    MyButton window;

    window.resize(250,400);
    window.setWindowTitle("haha");

    window.show();
    return app.exec();
}
