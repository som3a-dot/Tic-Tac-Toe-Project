#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <array>
#include <vector>
#include <utility>

class GameBoard {
public:
    GameBoard();
    bool makeMove(int row, int col);
    bool checkWin(char player) const;
    bool isTie() const;
    char getCell(int row, int col) const;
    char getCurrentPlayer() const;
    void reset();
    std::vector<std::pair<int, int>> getMoves() const;

private:
    std::array<std::array<char, 3>, 3> board_;
    char current_player_;
    std::vector<std::pair<int, int>> moves_; // Store moves for history
};

#endif // GAMEBOARD_H
