#include "ai.h"
#include "board.h"
#include "globals.h"
#include "game.h"

AI::AI(){}

Move AI::bestMoveSearch(int player){
    Move bestMove;
    bestMove.score = INF;
    for(int i = 0; i < 3; i++){
        for(auto j = 0; j < 3; j++){
            if(board.GetSquare(j, i) == EMPTY){
                Move currMove;
                currMove.posY = i;
                currMove.posX = j;
                board.SetSquare(j, i, player);
                currMove.score = maxSearch(-player).score;
                board.UnsetSquare(j, i);
                if(currMove.score < bestMove.score){
                    bestMove = currMove;
                }
            }
        }
    }
    return bestMove;
}

Move AI::maxSearch(int player){
    switch(board.Evaluate(player)){
    case WIN: return WIN_SCORE;
    case LOSE: return -WIN_SCORE;
    case TIE: return TIE_SCORE;
    }
    Move bestMove;
    bestMove.score = -INF;
    for(int i = 0; i < 3; i++){
        for(auto j = 0; j < 3; j++){
            if(board.GetSquare(j, i) == EMPTY){
                Move currMove;
                currMove.posY = i;
                currMove.posX = j;
                board.SetSquare(j, i, player);
                currMove.score = minSearch(-player).score;
                board.UnsetSquare(j, i);
                if(currMove.score > bestMove.score){
                    bestMove = currMove;
                }
            }
        }
    }
    return bestMove;
}

Move AI::minSearch(int player){
    switch(board.Evaluate(player)){
    case WIN: return -WIN_SCORE;
    case LOSE: return WIN_SCORE;
    case TIE: return TIE_SCORE;
    }
    Move bestMove;
    bestMove.score = INF;
    for(int i = 0; i < 3; i++){
        for(auto j = 0; j < 3; j++){
            if(board.GetSquare(j, i) == EMPTY){
                Move currMove;
                currMove.posY = i;
                currMove.posX = j;
                board.SetSquare(j, i, player);
                currMove.score = maxSearch(-player).score;
                board.UnsetSquare(j, i);
                if(currMove.score < bestMove.score){
                    bestMove = currMove;
                }
            }
        }
    }
    return bestMove;
}
