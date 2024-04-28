#include <missile.h>
#include <status.h>
#include <enemy.h>
#include <player.h>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <QMediaPlayer>
#include <QAudioOutput>

Missile :: Missile() : QObject(), QGraphicsPixmapItem(QPixmap("C:\\Users\\user\\Downloads\\missile icon.png").scaled(80, 90))
{
    QAudioOutput* audioLaser = new QAudioOutput();
    QMediaPlayer* soundLaser = new QMediaPlayer();
    soundLaser->setSource(QUrl("qrc:/resources/sounds/lasershot.mp3"));
    soundLaser->setAudioOutput(audioLaser);
    audioLaser->setVolume(50);
    soundLaser->play();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

}

void Missile:: move()
{
    setPos(x(),y()-10);
    if (pos().y() + 50 < 0){
        scene()->removeItem (this);
        delete this;
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0; i< colliding_items.size(); i++){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            Status::increase();

            QAudioOutput* audioKill = new QAudioOutput();
            QMediaPlayer* soundKill = new QMediaPlayer();
            soundKill->setSource(QUrl());
            soundKill->setAudioOutput(audioKill);
            audioKill->setVolume(50);
            soundKill->play();

            scene () -> removeItem(colliding_items[i]);
            scene () -> removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
}
