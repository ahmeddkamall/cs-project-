#ifndef STATUS_H
#define STATUS_H
#include <QGraphicsTextItem>

class Status
{
private:
    static int health;
    static int score;
    static QGraphicsTextItem* healthTextItem;
    static QGraphicsTextItem* scoreTextItem;
public:
    Status();
    static void setHealthText(QGraphicsTextItem* healthTextItem);
    static void setScoreText(QGraphicsTextItem* scoreTextItem);
    static void increase();
    static void decrease();
};

#endif // STATUS_H
