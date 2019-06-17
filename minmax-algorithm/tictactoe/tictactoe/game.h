#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "ai.h"
#include <QDialog>
#include <QPainter>

class Game : public QDialog
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

private:
    //bool userTurn;
    int player;

    QPainter *painter;
    QRect boardRects[SIZE][SIZE];

    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    GameState CheckGame();
    void Reset();
    void Tie();
    void Lose();
    void Win();
    void PlayAI();
};

#endif
