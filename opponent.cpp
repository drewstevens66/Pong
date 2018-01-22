#include "opponent.h"
#include "ball.h"
#include <QPointF>


Opponent::Opponent(int x, int y, int width, int height, Ball *newball)
{
    this->setRect(x,y,width,height);
    ball = newball; //set ball object to follow
    myPoint = new QPointF(x,y); //create our point
}

void Opponent::advance(int phase)
{
    if (phase == 0)
        return;
    QPointF ballPoint = ball->getPoint(); //get point from ball
    if (ballPoint.y() < myPoint->y()) { // if the ball is above opponent, then go up
        if (myPoint->y() > 0) {
            moveBy(0,-.5);
            myPoint->setY(myPoint->y()-.5);
        }
        //go up
    } else if (ballPoint.y() > myPoint->y()) { //if ball is below opponent, then go down
        if (myPoint->y() < 540) {
            moveBy(0,.5);
        myPoint->setY(myPoint->y()+.5);
        }
        //go down
    }

}


