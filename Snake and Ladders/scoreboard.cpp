#include "scoreboard.h"
#include "ui_scoreboard.h"

scoreBoard::scoreBoard(QVector <player*> playerList, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::scoreBoard)
{
    ui->setupUi(this);
    scene = new QGraphicsScene ();
    ui->graphicsView->setScene(scene);

    text = scene->addText("RANKING", QFont("Times", 40,QFont::Bold));
    text->setPos(350,0);

    int x= 250;
    int y= 100;

    for(int i=0; i<playerList.size(); i++){
        text = scene->addText(QString::number(i+1));
        text->setPos(x,y);
        text->setFont(QFont("Times",25));

        text = scene->addText(".");
        text->setPos(x+20,y);
        text->setFont(QFont("Times",25));

        playerRep = scene->addEllipse(x+40,y+15,30,30,QPen(Qt::black), QBrush(playerList[i]->color));

        text = scene->addText(playerList[i]->name);
        text->setPos(x+80,y);
        text->setFont(QFont("Times",25));

        y += 100;
    }
}

scoreBoard::~scoreBoard()
{
    delete ui;
}

void scoreBoard::on_pushButton_clicked()
{
    hide();
    playerIntroduction *p = new playerIntroduction();
    p->showMaximized();
}

void scoreBoard::on_pushButton_2_clicked()
{
    close();
}
