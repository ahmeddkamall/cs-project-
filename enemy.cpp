#include "enemy.h"
#include "status.h"
#include <QGraphicsScene>
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <player.h>

Enemy::Enemy() : QObject(), QGraphicsPixmapItem(QPixmap("C:\\Users\\user\\OneDrive\\Documents\\Desktop\\enemy new.png").scaled(50, 60))
{
    // Setting the postion of the enemy within the view dimensions
    int random_number = rand() % 900;
    setPos(random_number,0);

    // Moving the enemies downwards automatically
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT (move()));
    timer->start(30);

}

// Function move: move the enemy downwards untill the end of the scene then remove it and delete it
void Enemy:: move()
{
    setPos(x(),y()+5);
    if(y()>800)
    {
        Status::decrease();
        scene()->removeItem(this);
        delete this;
    }
}

