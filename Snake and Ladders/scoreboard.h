#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QMainWindow>
#include "game.h"
#include "player.h"
#include "playerintroduction.h"
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QBrush>

namespace Ui {
class scoreBoard;
}

class scoreBoard : public QMainWindow
{
    Q_OBJECT

public:
    explicit scoreBoard(QVector <player*> playerList, QWidget *parent = nullptr);
    ~scoreBoard();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::scoreBoard *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *playerRep;
    QGraphicsTextItem *text;

};

#endif // SCOREBOARD_H
