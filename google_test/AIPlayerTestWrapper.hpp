#ifndef AIPLAYER_TEST_WRAPPER_H
#define AIPLAYER_TEST_WRAPPER_H

#include <vector>
#include <string>

class AIPlayerTestWrapper
{
public:
    AIPlayerTestWrapper(char aiSymbol, char playerSymbol, const std::string &difficulty);
    void makeMove(std::vector<std::vector<char>> &board, int &row, int &col);
    bool isBoardFull(const std::vector<std::vector<char>> &board);
    bool checkWin(const std::vector<std::vector<char>> &board, char symbol);

private:
    char aiSymbol;
    char playerSymbol;
    std::string difficulty;

    int evaluateBoard(const std::vector<std::vector<char>> &board);
    int minimax(std::vector<std::vector<char>> &board, int depth, bool isMaximizing, int alpha, int beta);
};

#endif // AIPLAYER_TEST_WRAPPER_H
