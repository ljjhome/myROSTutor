#pragma once

#include <QWidget>
#include <QProgressBar>
#include <QPushButton>

class ProgressBarex : public QWidget{
    Q_OBJECT
public:
    ProgressBarex(QWidget *parent = 0);

private:
    int progress;
    QTimer *timer;
    QProgressBar *pbar;
    QPushButton *startBtn;
    QPushButton *stopBtn;

    static const int DELAY = 200;
    static const int MAX_VALUE = 100;

    void updateBar();
    void startMyTimer();
    void stopMyTimer();

};
