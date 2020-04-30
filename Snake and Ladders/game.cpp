#include "game.h"
#include "ui_game.h"

game::game(QVector <QString> names, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);

    //initialising graphics view
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    //taking player names
    for(int i=0; i!=names.size(); i++){
        player *current = new player(names[i]);
        playerList.push_back(current);
    }

    num_players= playerList.size();
    gameOver = false;
    rolls=0;
    num_winners=0;

    //setting color representation for the players
    playerList[0]->color = QColor(Qt::red);
    if(num_players > 1)
        playerList[1]->color = QColor(255,255,0);
    if(num_players > 2)
        playerList[2]->color = QColor(Qt::cyan);
    if(num_players > 3)
        playerList[3]->color = QColor(Qt::darkGreen);
    if(num_players > 4)
        playerList[4]->color = QColor(Qt::magenta);
    if(num_players > 5)
        playerList[5]->color = QColor(Qt::darkBlue);
    if(num_players > 6)
        playerList[6]->color = QColor(128,0,0);
    if(num_players > 7)
        playerList[7]->color = QColor(250,69,0);

    rolling = new QMediaPlayer();
    rolling->setMedia(QUrl("qrc:/dice_sound/sounds/Shake And Roll Dice-SoundBible.com-591494296.mp3"));

    game::setBoard();
}

game::~game()
{
    delete ui;
}
void game::setBoard(){

    //creating tiles

    int rows = 10;
    int cols = 10;
    int size = 100;
    int dir = 1;

    int offset = 600;
    int x = offset;
    int y = (rows-1)*size;

    for (int i=0; i != rows*cols; i++){
        tile *current = new tile(x,y,i,i+1);
        tiles.push_back(current);

        x += size*dir;
        if( x>=rows*size + offset || offset-size>=x ){
            dir *= -1;
            x += size*dir ;
            y -= size;
        }
    }

    //creating snakes and ladders

    for(int i=0; i!=3; i++){
        int rand1 = (rand() % 100) + 1;
        int rand2 = (rand() % 100) + 1;

        //making rand1 greater than rand2
        if(rand2 > rand1){
            int temp = rand2;
            rand2 = rand1;
            rand1 = temp;
        }

        //if head and tail are in the same row
        if( rand1/10 == rand2/10 || ( rand1/10 == (rand2/10)+1 && rand1%10 ==0) ){
            i--;
            continue;
        }

        snakeHeads.push_back(rand1);
        snakeTails.push_back(rand2);
        tiles[rand1]->snakeOrLadder = -1*(rand1 - rand2);
    }
    for(int i=0; i!=3; i++){
        int rand1 = (rand() % 100) + 1;
        int rand2 = (rand() % 100) + 1;

        //making rand1 greater than rand2
        if(rand2 > rand1){
            int temp = rand2;
            rand2 = rand1;
            rand1 = temp;
        }

        //if top and bottom are in the same row
        if( rand1/10 == rand2/10 || ( rand1/10 == (rand2/10)+1 && rand1%10 ==0) ){
            i--;
            continue;
        }
        ladderTop.push_back(rand1);
        ladderBottom.push_back(rand2);
        tiles[rand2]->snakeOrLadder = (rand1 - rand2);
    }

    //showing tiles

    QBrush brush1(QColor(230,131,121));
    QBrush brush2(QColor(230,230,250));

    QPen blackPen(Qt::black);

    for(int i=0; i!=tiles.size(); i++){
        tile *current = tiles[i];
        if(i%2 == 0)
            rectangle = scene->addRect(current->x, current->y, size, size, blackPen, brush1);
        else
            rectangle = scene->addRect(current->x, current->y, size, size, blackPen, brush2);
        QGraphicsTextItem *text = scene->addText(QString::number(i+1));
        text->setPos(tiles[i]->x, tiles[i]->y);
        text->adjustSize();
    }

    //showing snakes and ladders

    QPen redPen(Qt::red);
    redPen.setWidth(8);
    for(int i=0; i!=snakeHeads.size(); i++){

        tile *currHead = tiles[snakeHeads[i]];
        int xhCenter = (currHead->x) + size/2;
        int yhCenter = (currHead->y) + size/2;

        tile *currTail = tiles[snakeTails[i]];
        int xtCenter = (currTail->x) + size/2;
        int ytCenter = (currTail->y) + size/2;

        line = scene->addLine(xhCenter, yhCenter, xtCenter, ytCenter, redPen);
    }
    QPen greenPen(Qt::darkGreen);
    greenPen.setWidth(8);
    for(int i=0; i!=ladderTop.size(); i++){

        tile *currHead = tiles[ladderTop[i]];
        int xtCenter = (currHead->x) + size/2;
        int ytCenter = (currHead->y) + size/2;

        tile *currTail = tiles[ladderBottom[i]];
        int xbCenter = (currTail->x) + size/2;
        int ybCenter = (currTail->y) + size/2;

        line = scene->addLine(xtCenter, ytCenter, xbCenter, ybCenter, greenPen);
    }

    //showing player names

    x = 200;
    y = 200;
    for(int i=0; i<num_players; i++){
        QPen pen(Qt::black);
        QBrush brush(playerList[i]->color);
        playerRep = scene->addEllipse(x,y,40,40,pen,brush);
        playerName = scene->addText(playerList[i]->name);
        playerName->setPos(x+100,y);
        playerName->setFont(QFont("Helvetica",20,QFont::Bold));
        y += 100;
    }

}

void game::incrementRolls(){
    (this->rolls)++;
}
void game::updateWinners(player *currPlayer){
    num_winners++;
    currPlayer->completedGame = true;

    //if all players but one in a multiplayer game or the single player has completed the board, game is over
    if( (num_players==1 && num_winners == 1) || (num_players >1 && num_winners == num_players -1) )
        gameOver = true;
    if(num_winners < num_players-1){
        finished *f = new finished(currPlayer->name);
        f->show();
    }
    else{
        hide();
        gameOver = true;

        //showing score board
        scoreBoard *b = new scoreBoard(playerList);
        b->showMaximized();
    }
}
void game::rollDie(){
    rolling->play();
    int random = rand();
    int die = (random % 6) + 1;
    incrementRolls();
    if(die ==1 ){
        QPixmap pix(":/dice/images/index.png");
        ui->label->setPixmap(pix);
    }
    else if(die == 2){
        QPixmap pix(":/dice/images/index2.png");
        ui->label->setPixmap(pix);
    }
    else if(die == 3){
        QPixmap pix(":/dice/images/index3.png");
        ui->label->setPixmap(pix);
    }
    else if(die == 4){
        QPixmap pix(":/dice/images/index4.png");
        ui->label->setPixmap(pix);
    }
    else if(die == 5){
        QPixmap pix(":/dice/images/index5.png");
        ui->label->setPixmap(pix);
    }
    else if(die == 6){
        QPixmap pix(":/dice/images/index6.png");
        ui->label->setPixmap(pix);
    }
    game::move(die);
}

int game::getNumPlayers()
{
    return num_players;
}

QVector<player*> game::getPlayerList()
{
    return playerList;
}

bool game::gameFinished()
{
    return gameOver;
}

void game::move(int die){

    int chance = rolls%num_players -1;
    if(rolls%num_players == 0)
        chance=num_players-1;

    //if the player has already completed the game, it is the chance of the next player
    while(playerList[chance]->completedGame)
        chance++;

    player *currPlayer = playerList[chance];
    currPlayer->updateSpot(die);

    QBrush brush(currPlayer->color);
    QPen pen(currPlayer->color);

    //if it is a valid spot
    if(currPlayer->spot < 99)
        currPlayer->spot += tiles[currPlayer->spot]->snakeOrLadder;

    //if the player completes the game now
    if(currPlayer->spot >= 99 && (currPlayer->completedGame)==false ){
        delete positions[chance];
        positions[chance] = scene->addEllipse((tiles[99]->x)+35+7*num_winners, (tiles[99]->y)+35, 30,30, pen, brush);
        updateWinners(currPlayer);
    }

    //if the player is yet to finish the game
    else if(!currPlayer->completedGame){

        int xCenter = ((tiles[currPlayer->spot])->x) + 35;
        int yCenter = ((tiles[currPlayer->spot])->y) + 35;
        int offset = 7*(tiles[currPlayer->spot]->occupancies);

        //if it is the player's first move
        if(num_players >= rolls){
            QGraphicsEllipseItem *temp;
            positions.push_back(temp);
        }
        else{
            delete positions[chance];
            int moves = currPlayer->movement.size();
            int prevSpot = currPlayer->movement[moves-1];
            tiles[prevSpot]->occupancies--;
        }

        //showing the player's spot
        positions[chance] = scene->addEllipse(xCenter+offset, yCenter, 30,30, pen, brush);

        //updating the number of occupants of the corresponding tile
        (tiles[currPlayer->spot]->occupancies)++;

        //updating the movement data of the player
        currPlayer->movement.push_back(currPlayer->spot);
     }
}

void game::on_pushButton_clicked()
{
    game::rollDie();
}
