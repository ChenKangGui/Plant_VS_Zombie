#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSound>
#include <QTimer>
#include "shop.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addZombie();
    void check();

    QSound *sound;
    QTimer *timer;
    QGraphicsScene *scene;
    QGraphicsView *view;


};

#endif // MAINWINDOW_H
