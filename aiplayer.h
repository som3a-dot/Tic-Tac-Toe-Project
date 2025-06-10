#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "gameboard.h"

class AIPlayer {
public:
    AIPlayer(char symbol);
    void getBestMove(const GameBoard& board, int& row, int& col) const;

private:
    char symbol_;
    int evaluateBoard(const GameBoard& board) const;
    int minimax(GameBoard board, int depth, bool is_max, int alpha, int beta) const;
};

#endif // AIPLAYER_H
