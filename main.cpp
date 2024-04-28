#include "player.h"
#include "status.h"
#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include <QUrl>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QApplication>


bool isHit;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // creating view
    QGraphicsView * view = new QGraphicsView();
    view->setFixedSize(1000, 1000);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // creating scene
    QGraphicsScene * scene =  new QGraphicsScene() ;
    scene->setSceneRect(0, 0, 1000, 800);

    // initializing health and score
    QGraphicsTextItem* scoreText = new QGraphicsTextItem();
    QGraphicsTextItem* healthText = new QGraphicsTextItem();

    scene->addItem(scoreText);
    scene->addItem(healthText);

    Status::setHealthText(healthText);
    Status::setScoreText(scoreText);

    QAudioOutput* audioOutput = new QAudioOutput();
    QMediaPlayer* soundEffect = new QMediaPlayer();
    soundEffect->setAudioOutput(audioOutput);
    audioOutput->setVolume(50);
    soundEffect->setLoops(1000);
    soundEffect->play();

    // creating the player
    Player *player = new Player();
    player->setPos(scene->width()/2, (scene->height() - player->pixmap().height())/2);

    // focus on player
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // adjusting position of player
    player->setPos(view->width()/2, view->height()-player->y()/2);
    scene->addItem(player);

    // add scene ot view
    view->setScene(scene);
    view->show();

    // automatically create enemy
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()), player, SLOT(createEnemy()));
    time->start(2000);

    //sound effects
    QMediaPlayer *MediaPlayer = new QMediaPlayer();


    return a.exec();


}
