#ifndef _TicTacToe_H
#define _TicTacToe_H

// TicTacToe.hpp
#pragma once
#include <vector>
#include <string>

class TicTacToe
{
public:
    TicTacToe();
    bool makeMove(int row, int col); // Returns true if move is valid
    char checkWinner();              // Returns 'X', 'O', 'D' (draw), or ' ' (ongoing)
    char getCurrentPlayer();         // Returns 'X' or 'O'
    char getCell(int row, int col);  // Returns 'X', 'O', or ' '

private:
    std::vector<std::vector<char>> board;
    char currentPlayer;
    int movesMade;
    bool isValidMove(int row, int col); // Checks if move is valid
};

#endif
