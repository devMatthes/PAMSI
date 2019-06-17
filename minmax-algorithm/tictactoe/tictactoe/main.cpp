#include "game.h"
#include "globals.h"
#include "ai.h"
#include "board.h"
#include <QApplication>

int displayBoard[3][3];
CurrentPlayer currentPlayer;
Board board;
AI ai;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Game game;

    game.show();

    return app.exec();
}
