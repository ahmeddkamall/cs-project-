#include "status.h"
#include "player.h"
#include "enemy.h"
#include "missile.h"
#include <QString>
#include <QMessageBox>
#include <QGraphicsScene>

//initializing health and score
int Status::health = 5;
int Status::score = 0;
QGraphicsTextItem* Status::healthTextItem = nullptr;
QGraphicsTextItem* Status::scoreTextItem = nullptr;

//showing health status on screen
void Status::setHealthText(QGraphicsTextItem* healthText) {
    healthTextItem = healthText;
    healthTextItem->setPlainText("Health: " + QString::number(health));
    healthTextItem->setPos(20, 30);
}

//showing score status on screen
void Status::setScoreText(QGraphicsTextItem* scoreText){
    scoreTextItem = scoreText;
    scoreTextItem->setPlainText("Score: " + QString::number(score));
    scoreTextItem->setPos(20, 50);
}

//score status increasing
void Status::increase() {
    score += 10;
    scoreTextItem->setPlainText("Score: " + QString::number(score));

    if (score == 50){

        healthTextItem->setPlainText("Health: " + QString::number(health));
        scoreTextItem->setPlainText("Score: " + QString::number(score));
        QGraphicsScene* healthscene = healthTextItem->scene();
        QGraphicsScene* scorescene = scoreTextItem->scene();
        scorescene->clear();

        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle(QString("level"));
        msg->setText(QString("LEVEL COMPLETED! CONGRATULATIONS"));
        msg->exec();
    }
}

//health status decreasing
void Status::decrease() {
    if(health > 0){
        health--;
        score -= 10;
    }
    healthTextItem->setPlainText("Health: " + QString::number(health));
    scoreTextItem->setPlainText("Score: " + QString::number(score));
    QGraphicsScene* healthscene = healthTextItem->scene();
    QGraphicsScene* scorescene = scoreTextItem->scene();

    if(health == 0) {
        healthscene->clear();
        QGraphicsTextItem* gameOverText = new QGraphicsTextItem();
        gameOverText->setDefaultTextColor(Qt::red);
        gameOverText->setPlainText("GAME OVER!");
        gameOverText->setPos(healthscene->width() / 2, healthscene->height() / 2);

        healthscene->addItem(gameOverText);

        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle(QString("Game Over"));
        msg->setText(QString("GAME OVER. Your score was ") + QString::number(score));
        msg->exec();
    }
}

