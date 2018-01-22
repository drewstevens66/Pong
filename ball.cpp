#include "ball.h"
#include <QList>
#include <QMessageBox>
#include <mainwindow.h>
#include <QFont>

#define _USE_MATH_DEFINES
#include "math.h"

Ball::Ball(int x, int y, int width, int height)
{
    this->setRect(x,y,width,height); //set the rectangle for the ball's geometry
    point = mapFromScene(x,y); //create a point that we can use to track around the window
    playerScore = 0; //initialize scores
    oppScore = 0;
    angle = 5 * M_PI / 4; //initial angle for starting of game
    gamestate = GO; //start game
}
void Ball::advance(int phase) {
    if (phase == 0)
        return;
    if (gamestate == GO) {
        QList<QGraphicsItem*> colliding; //creates list of items colliding with the ball
        colliding = collidingItems();
        if (colliding.isEmpty()) { //if it's not colliding with any items, check to see if it's a win condition
            if (point.x() < 45) {
                gamestate = LOSE;
            }
            if(point.x() > 575) {
                gamestate = WIN;
            }
            if (point.y() <= 0)
                angle += M_PI / 2; //if it's at a top or bottom wall, rotate by 90 degrees
            if (point.y() > 470)
                angle -= M_PI / 2;
        }
        else {

            if (point.x() < 45) //if it's not empty, it hit a paddle and we need to allow it to bounce off of our paddle
                angle += M_PI / 2;
            if (point.x() > 575)
                angle -= M_PI / 2;
        }
        moveBy(cos(angle),sin(angle)); //movement of ball
        point.setX(point.x()+cos(angle));
        point.setY(point.y()+sin(angle));
    } else if (gamestate == WIN) { //if you score on opponent
        if (point.x() < 660) { //if the ball still isn't off the screen
            if (point.y() <= 0) //bounce off walls
                angle += M_PI / 2;
            if (point.y() > 470)
                angle -= M_PI / 2;
            moveBy(2*cos(angle),2*sin(angle));
            point.setX(point.x()+2*cos(angle)); //move it
            point.setY(point.y()+2*sin(angle));
        } else { //ball is off the screen
            if (playerScore == 5) //check total score
            endGame(gamestate); //end game if score is 5
            else {
                playerScore++; //add score to player
                setPos(0,0); //set position back to original
                point = mapFromScene(310,240); //remap point
                angle = M_PI / 4;//set angle towards player
                gamestate = GO;
            }
        }
    } else if (gamestate == LOSE) { //if scored on
        if (point.x() > -40) { //if it's still on screen
            if (point.y() <= 0)
                angle += M_PI / 2; //bounce off walls
            if (point.y() > 470)
                angle -= M_PI / 2;
            moveBy(2*cos(angle),2*sin(angle));
            point.setX(point.x()+2*cos(angle));
            point.setY(point.y()+2*sin(angle));
        } else {
            if (oppScore == 5) //check if you lose
                endGame(gamestate);
            else {
                oppScore++; //add score to opponent
                setPos(0,0);
                point = mapFromScene(310,240); //reset point
                gamestate = GO;
            }
        }
    } else if (gamestate == STOP) { //if the game is over, stop all movement
        return;
    }
}

QPointF Ball::getPoint()
{
    return point;
}

void Ball::endGame(Ball::condition endstate)
{
    gamestate = STOP;
    if (endstate == WIN) {
        this->scene()->addSimpleText("You Win! Congratulations!\nClose program and play again if you would like :)");
    } else if (endstate == LOSE) {
        this->scene()->addSimpleText("You lost! I'm sorry, try again next time\nClose program and play again if you would like :)");
    }
}



