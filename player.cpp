#include "player.h"
#include "missile.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QDebug>
#include <QMediaPlayer>



Player::Player(): QObject(), QGraphicsPixmapItem(QPixmap("C:\\Users\\user\\Downloads\\player icon.png").scaled(50, 60)) {

    missilesound = new QMediaPlayer();
    missilesound-> setSource(QUrl("C:\\Users\\user\\Downloads\\laser_sound.wav"));


}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0)
        {
            setPos(x()-20,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<1000)
            setPos(x()+20,y());
    }
    else if(event->key()== Qt::Key_Up)

    { if(y()+100<800)
            setPos(x(),y()-20);
    }
    else if(event->key()== Qt::Key_Down)

    { if(y()+100<800)
            setPos(x(),y()+20);
    }
    else if(event->key()== Qt::Key_Space)
    {
        Missile * missile = new Missile();
        missile->setPos(x()-15,y()-70);
        scene()->addItem(missile);

        //play missile sound effect
        if (missilesound->mediaStatus() == QMediaPlayer::PlayingState){

            missilesound->setPosition(0);
        } else if (missilesound->mediaStatus() == QMediaPlayer::StoppedState){
            missilesound->play();


        }



    }

}


void Player::createEnemy(){

    Enemy* chick = new Enemy();
    scene()->addItem(chick);

}
