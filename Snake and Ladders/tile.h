#ifndef TILE_H
#define TILE_H


class tile
{
public:
    tile(int X, int Y, int I, int N);
    int x,y,index,next,color;
    int snakeOrLadder;
    int occupancies;
};

#endif // TILE_H
