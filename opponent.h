#ifndef OPPONENT_H
#define OPPONENT_H
#include <QPointF>
#include <ball.h>

class Opponent : public QGraphicsRectItem
{
public:
    Opponent(int x, int y, int width, int height, Ball *newball); //constructor for opponent

private:
    Ball *ball; //ball so that opponent can follow it on advancing
    QPointF *myPoint;
    virtual void advance(int phase);
};

#endif // OPPONENT_H
