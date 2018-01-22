#include "player.h"
#include <QDebug>

Player::Player(int x, int y, int width, int height)
{
    this->setRect(x,y,width,height);
    point = mapFromScene(x,y);
}

void Player::advance(int phase) {

}

void Player::keyPressEvent(QKeyEvent *key)
{
    if (key->key() == Qt::Key_W) { //when w is pressed, move the player by 35 up
        if (point.y() >= 0) {
            moveBy(0,-35);
            point.setY(point.y()-35);
        }
    } else if (key->key() == Qt::Key_S) { //when s is pressed, move the player by 35 down
        if (point.y() <= 420)  {
            moveBy(0,35);
            point.setY(point.y()+35);
        }
    }
}
