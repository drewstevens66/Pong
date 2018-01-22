#ifndef PLAYER_H
#define PLAYER_H
#include <QPointF>
#include <QGraphicsRectItem>
#include <QKeyEvent>


class Player : public QGraphicsRectItem
{
public:
    Player(int x, int y, int width, int height);
    virtual void advance(int phase);
    void keyPressEvent(QKeyEvent *key);
private:
    QPointF point;
};

#endif // PLAYER_H
