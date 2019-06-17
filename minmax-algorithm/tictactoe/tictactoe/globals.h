#ifndef GLOBALS_H
#define GLOBALS_H
#define SIZE 3
enum GameState { WIN = 6, LOSE = -6, TIE = 0, PLAY = 1, END = -1};
enum { X = 1, O = -1, EMPTY = 0 };

struct Move
{
    int score;
    int posX, posY;

    Move(){}
    Move(int s) : score(s) {}
};

struct CurrentPlayer
{
    int player;
    CurrentPlayer() : player(X) {}
    inline void TogglePlayer()
    {
        player *= -1;
    }
};
extern int displayBoard[SIZE][SIZE];
extern CurrentPlayer currentPlayer;
#endif // GLOBALS_H
