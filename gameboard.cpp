#include "gameboard.h"

GameBoard::GameBoard() : current_player_('X') {
    for (auto& row : board_) {
        for (char& cell : row) {
            cell = ' ';
        }
    }
}

bool GameBoard::makeMove(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board_[row][col] != ' ') {
        return false;
    }
    board_[row][col] = current_player_;
    moves_.emplace_back(row, col);
    current_player_ = (current_player_ == 'X') ? 'O' : 'X';
    return true;
}

bool GameBoard::checkWin(char player) const {
    for (int i = 0; i < 3; ++i) {
        if ((board_[i][0] == player && board_[i][1] == player && board_[i][2] == player) ||
            (board_[0][i] == player && board_[1][i] == player && board_[2][i] == player)) {
            return true;
        }
    }
    if ((board_[0][0] == player && board_[1][1] == player && board_[2][2] == player) ||
        (board_[0][2] == player && board_[1][1] == player && board_[2][0] == player)) {
        return true;
    }
    return false;
}

bool GameBoard::isTie() const {
    for (const auto& row : board_) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return !checkWin('X') && !checkWin('O');
}

char GameBoard::getCell(int row, int col) const {
    return board_[row][col];
}

char GameBoard::getCurrentPlayer() const {
    return current_player_;
}

void GameBoard::reset() {
    for (auto& row : board_) {
        for (char& cell : row) {
            cell = ' ';
        }
    }
    current_player_ = 'X';
    moves_.clear();
}

std::vector<std::pair<int, int>> GameBoard::getMoves() const {
    return moves_;
}
