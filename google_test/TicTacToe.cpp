// TicTacToe.cpp
#include "TicTacToe.hpp"

TicTacToe::TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X'), movesMade(0) {}

bool TicTacToe::makeMove(int row, int col)
{
    if (!isValidMove(row, col))
    {
        return false;
    }
    board[row][col] = currentPlayer;
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    movesMade++;
    return true;
}

char TicTacToe::checkWinner()
{
    // Check rows
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < 3; ++i)
    {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return board[0][2];
    }

    // Check for draw
    if (movesMade == 9)
    {
        return 'D';
    }

    // Game ongoing
    return ' ';
}

char TicTacToe::getCurrentPlayer()
{
    return currentPlayer;
}

char TicTacToe::getCell(int row, int col)
{
    return board[row][col];
}

bool TicTacToe::isValidMove(int row, int col)
{
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}