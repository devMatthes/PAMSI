#include "board.h"
#include "globals.h"


void Board::Init()
{
    for(auto i = 0; i < 3; i++){
        for (auto j = 0; j < 3; j++){
            board[i][j] = EMPTY;
        }
    }
}


void Board::SetSquare(int posX, int posY, int player)
{
    board[posY][posX] = player;
}


int Board::GetSquare(int posX, int posY)
{
    return board[posY][posX];
}


void Board::UnsetSquare(int posX, int posY)
{
    board[posY][posX] = EMPTY;
}


GameState Board::Evaluate(int player)
{
    // Rows
    if (board[0][0] != EMPTY && board[0][0] == board[0][1] && board[0][1] == board[0][2]) return (board[0][0] == player)? WIN : LOSE;
    if (board[1][0] != EMPTY && board[1][0] == board[1][1] && board[1][1] == board[1][2]) return (board[1][0] == player)? WIN : LOSE;
    if (board[2][0] != EMPTY && board[2][0] == board[2][1] && board[2][1] == board[2][2]) return (board[2][0] == player)? WIN : LOSE;
    // Columns
    if (board[0][0] != EMPTY && board[0][0] == board[1][0] && board[1][0] == board[2][0]) return (board[0][0] == player)? WIN : LOSE;
    if (board[0][1] != EMPTY && board[0][1] == board[1][1] && board[1][1] == board[2][1]) return (board[0][1] == player)? WIN : LOSE;
    if (board[0][2] != EMPTY && board[0][2] == board[1][2] && board[1][2] == board[2][2]) return (board[0][2] == player)? WIN : LOSE;
    // Diagonals
    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return (board[0][0] == player)? WIN : LOSE;
    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return (board[0][2] == player)? WIN : LOSE;

    // Check for playing
    for(auto i = 0; i < 3; i++){
        for (auto j = 0; j < 3; j++){
            if (board[i][j] == EMPTY){
                return PLAY;
            }
        }
    }
    return TIE;
}
