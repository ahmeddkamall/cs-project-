#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>
#include "enemy.h"
#include <QMediaPlayer>


class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QGraphicsTextItem* healthText;
    QGraphicsTextItem* scoreText;
    QMediaPlayer * missilesound;


public:
    Player();
    void keyPressEvent(QKeyEvent * event);

public slots:
    void createEnemy();

};

#endif // PLAYER_H
