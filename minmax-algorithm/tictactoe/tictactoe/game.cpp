#include "game.h"
#include "board.h"
#include "ai.h"
#include "globals.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>

Game::Game(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("Tic Tac Toe");
    this->setFixedSize(300, 300);

    QSize size(100, 100);
    boardRects[0][0] = QRect(QPoint(0, 0), size);
    boardRects[0][1] = QRect(QPoint(0, 100), size);
    boardRects[0][2] = QRect(QPoint(0, 200), size);
    boardRects[1][0] = QRect(QPoint(100, 0), size);
    boardRects[1][1] = QRect(QPoint(100, 100), size);
    boardRects[1][2] = QRect(QPoint(100, 200), size);
    boardRects[2][0] = QRect(QPoint(200, 0), size);
    boardRects[2][1] = QRect(QPoint(200, 100), size);
    boardRects[2][2] = QRect(QPoint(200, 200), size);

    player = X;
}

Game::~Game(){}

void Game::paintEvent(QPaintEvent *e)
{
    painter = new QPainter(this);
    //painter->drawRects(boardRects, 3, 3);

    for(auto i = 0; i < 3; i++){
        for (auto j = 0; j < 3; j++){
            QString path;
            switch(displayBoard[i][j])
            {
            case EMPTY: path = "../img/puste.png"; break;
            case X: path = "../img/krzyzyk.png"; break;
            case O: path = "../img/kolko.png"; break;
            }

            painter->drawPixmap(boardRects[i][j].x(), boardRects[i][j].y(),
                               boardRects[i][j].width(), boardRects[i][j].height(),
                               QPixmap(path));
        }
    }
}

void Game::mousePressEvent(QMouseEvent *e)
{
    for(auto i = 0; i < 3; i++){
        for (auto j = 0; j < 3; j++){
            if(boardRects[i][j].contains(e->pos()) && displayBoard[i][j] == EMPTY){
                if(CheckGame() == PLAY){
                    board.SetSquare(j, i, currentPlayer.player);
                    displayBoard[i][j] = currentPlayer.player;
                    QWidget::update();
                }

                if(CheckGame() == WIN){
                    if(currentPlayer.player == player)
                        Win();
                    else
                        Lose();
                    return;
                }

                if(CheckGame() == LOSE){
                    if(currentPlayer.player == player)
                        Lose();
                    else
                        Win();
                    return;
                }

                if(CheckGame() == TIE){
                    Tie();
                    return;
                }

                if(CheckGame() == PLAY){
                    currentPlayer.TogglePlayer();

                    PlayAI();
                    QWidget::update();
                }

                if(CheckGame() == WIN){
                    if(currentPlayer.player == player)
                        Win();
                    else
                        Lose();
                    return;
                }

                if(CheckGame() == LOSE){
                    if(currentPlayer.player == player)
                        Lose();
                    else
                        Win();
                    return;
                }

                if(CheckGame() == TIE){
                    Tie();
                    return;
                }

                if(CheckGame() == PLAY){
                    currentPlayer.TogglePlayer();
                    return;
                }
            break;
            }
        }
    }
}

void Game::Tie()
{
    QMessageBox tie;
    tie.setWindowTitle("Rezultat");
    tie.setText("Remis");
    tie.setFixedSize(400, 400);
    tie.exec();
    Reset();
}

void Game::Lose()
{
    QMessageBox lose;
    lose.setWindowTitle("Rezultat");
    lose.setText("Przegrales");
    lose.setFixedSize(400, 400);
    lose.exec();
    Reset();
}

void Game::Win()
{
    QMessageBox win;
    win.setWindowTitle("Rezultat");
    win.setText("Wygrales");
    win.setFixedSize(400, 400);
    win.exec();
    Reset();
}

GameState Game::CheckGame()
{
    return board.Evaluate(currentPlayer.player);
}

void Game::Reset()
{
    painter->end();
    board.Init();
    currentPlayer.player = X;
    for (auto i = 0; i < 3; i++){
        for (auto j = 0; j < 3; j++){
            displayBoard[i][j] = EMPTY;
        }
    }
}

void Game::PlayAI()
{
    AI ai;
    Move bestMove = ai.bestMoveSearch(currentPlayer.player);
    board.SetSquare(bestMove.posX, bestMove.posY, currentPlayer.player);
    displayBoard[bestMove.posY][bestMove.posX] = currentPlayer.player;
}
