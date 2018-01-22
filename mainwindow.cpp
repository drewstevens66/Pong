#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "ball.h"
#include "player.h"
#include "math.h"
#include "opponent.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::run() {
    scene = new QGraphicsScene(ui->centralWidget); //create scene
    scene->setSceneRect(QRect(0,0,640,480));

    window = new QGraphicsView(ui->centralWidget); //create window/view for scene
    window->setEnabled(true);
    window->resize(660,500);

    Player * player = new Player(30,220,15,60); //initialize components of game
    Ball * ball = new Ball(310,240,20,20);
    Opponent * opponent = new Opponent(595,220, 15,60, ball);

    player->setFlag(QGraphicsItem::ItemIsFocusable); //make player the focus of the game to allow for it to accept keyboard input
    player->setFocus();
    player->setBrush(QBrush(Qt::black,Qt::SolidPattern));

    opponent->setBrush(QBrush(Qt::black,Qt::SolidPattern)); //color the opponent and the ball
    ball->setBrush(QBrush(Qt::black,Qt::SolidPattern));

    scene->addItem(player);  //add items to the scene
    scene->addItem(opponent);
    scene->addItem(ball);

    window->setParent(this); //set the parent of the window to the mainwindow and set it as the scene
    window->setScene(scene);
    window->show(); //make it visible

    timer.setInterval(1);
    QObject::connect(&timer, SIGNAL(timeout()), scene, SLOT(advance())); //create timer to allow for advancement of scene
    timer.start();
}
void MainWindow::on_playButton_clicked()
{
    ui->helpButton->hide();
    ui->playButton->hide(); //hide the ui and start the game
    run();
}
void MainWindow::on_helpButton_clicked()
{
    QMessageBox::about(this, "Help", "Welcome to Ping (definitely not Pong)!\nYou are the bar on the left.\n"
                                     "Try to get the ball all the way to the right side of the screen to score.\n" //help menu
                                     "Score up to 6 to win!\n"
                                     "Controls:\n"
                                     "W: Move your bar up\n"
                                     "S: Move your bar down");
}

void MainWindow::on_exitButton_clicked()
{
    exit(0); //exit upon clicking exit
}
