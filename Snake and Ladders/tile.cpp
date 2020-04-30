#include "tile.h"

tile::tile(int X, int Y, int I, int N)
{
    x=X;
    y=Y;
    index=I;
    next=N;
    snakeOrLadder = 0;
    occupancies = 0;
}
