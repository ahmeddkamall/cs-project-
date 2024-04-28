#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QLabel>

class Enemy: public QObject , public QGraphicsPixmapItem
{   Q_OBJECT

public:
    Enemy();


private:

    QTimer* move_timer_;

public slots:
    void move();

signals:
    void enemyDestroyed();

};

#endif // ENEMY_H
