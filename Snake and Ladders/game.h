#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include "tile.h"
#include "player.h"
#include <QGraphicsScene>
#include <QPen>
#include <QBrush>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QColor>
#include "finished.h"
#include "scoreboard.h"
#include <QPixmap>
#include <QMediaPlayer>

using namespace std;
namespace Ui {
class game;
}
class game : public QMainWindow
{
    Q_OBJECT

public:
    explicit game( QVector <QString> names, QWidget *parent = nullptr);
    ~game();

    void setBoard();
    void move(int die);
    void incrementRolls();
    void updateWinners(player *currPlayer);
    void rollDie();
    int getNumPlayers();
    bool gameFinished();
    QVector <player*> getPlayerList();



private slots:
    void on_pushButton_clicked();

private:
    Ui::game *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    QGraphicsEllipseItem *ellipse;
    QGraphicsTextItem *playerName;
    QGraphicsEllipseItem *playerRep;
    QGraphicsLineItem *line;
    QMediaPlayer *rolling;

    QVector <player*> playerList;
    QVector <int> snakeHeads;
    QVector <int> snakeTails;
    QVector <int> ladderTop;
    QVector <int> ladderBottom;
    int num_players;
    int num_winners;
    int rolls;
    bool gameOver;

    QVector <tile*> tiles;
    QVector <QGraphicsEllipseItem*> positions;
};

#endif // GAME_H
