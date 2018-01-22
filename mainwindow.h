#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include "ball.h"
#include "player.h"

class QGraphicsScene;
class QTimer;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void getWindow();
    ~MainWindow();



private slots: //slots for when menu buttons are pressed
    void on_playButton_clicked();

    void on_helpButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::MainWindow *ui; //set private variables for the mainwindow
    QGraphicsView * window;
    QGraphicsScene * scene;
    Player *player;
    QGraphicsRectItem*opponent;
    Ball *ball;
    QTimer timer;
    void run();
};

#endif // MAINWINDOW_H
