#include "player.h"

player::player(QString N)
{
    name = N;
    spot = -1;
    completedGame = false;
}
void player::updateSpot(int die){
    int index = this->spot + die;
    this->spot = index;
}
