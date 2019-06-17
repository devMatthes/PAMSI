#ifndef BOARD_H
#define BOARD_H
#include "globals.h"
#define SIZE 3

class Board
{
public:
    int board[SIZE][SIZE];
    void Init();
    void SetSquare(int posX, int posY, int player);
    void UnsetSquare(int posX, int posY);
    int GetSquare(int posX, int posY);
    GameState Evaluate(int player);
};

extern Board board;
#endif
