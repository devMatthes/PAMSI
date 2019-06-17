#ifndef AI_H
#define AI_H

#include "globals.h"
#include "game.h"
#include <limits>

class AI
{
private:
    enum {WIN_SCORE = 100, TIE_SCORE = 0, INF = std::numeric_limits<int>::max()};
public:
    AI();
    Move bestMoveSearch(int player);
    Move maxSearch(int player);
    Move minSearch(int player);
};

extern AI ai;

#endif // AI_H
