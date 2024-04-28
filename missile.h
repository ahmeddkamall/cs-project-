#ifndef MISSILE_H
#define MISSILE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QImage>
#include "player.h"

class Missile : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Missile();

public slots:
    void move();
};

#endif // MISSILE_H
