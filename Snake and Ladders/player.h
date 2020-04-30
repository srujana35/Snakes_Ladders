#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QGraphicsItem>

class player
{
public:
    player(QString N);
    QString name;
    int spot;
    QColor color;
    QGraphicsEllipseItem *ellipse;
    void updateSpot(int die);
    QVector <int> movement;
    bool completedGame;
};

#endif // PLAYER_H
