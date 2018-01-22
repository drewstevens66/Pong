#ifndef BALL_H
#define BALL_H

#include <QGraphicsRectItem>


class Ball : public QGraphicsRectItem
{
public:
    Ball(int x, int y, int width, int height); //constructor
    virtual void advance(int phase); //reimplementation of advance
    QPointF getPoint();
    typedef enum {WIN,LOSE,STOP, GO} condition; //game conditions enumerator
private:
    double angle;
    QPointF point;
    condition gamestate;
    void endGame(condition endstate);
    int playerScore, oppScore;
};

#endif // BALL_H
