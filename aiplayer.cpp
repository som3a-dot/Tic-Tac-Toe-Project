#include "aiplayer.h"
#include <limits>
#include <algorithm>

AIPlayer::AIPlayer(char symbol) : symbol_(symbol) {}

int AIPlayer::evaluateBoard(const GameBoard& board) const {
    if (board.checkWin(symbol_)) return 10;
    if (board.checkWin(symbol_ == 'X' ? 'O' : 'X')) return -10;
    return 0;
}

int AIPlayer::minimax(GameBoard board, int depth, bool is_max, int alpha, int beta) const {
    int score = evaluateBoard(board);
    if (score == 10) return score - depth;
    if (score == -10) return score + depth;
    if (board.isTie()) return 0;

    if (is_max) {
        int best = std::numeric_limits<int>::min();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board.getCell(i, j) == ' ') {
                    board.makeMove(i, j);
                    best = std::max(best, minimax(board, depth + 1, false, alpha, beta));
                    board.makeMove(i, j); // Undo move
                    alpha = std::max(alpha, best);
                    if (beta <= alpha) break;
                }
            }
        }
        return best;
    } else {
        int best = std::numeric_limits<int>::max();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board.getCell(i, j) == ' ') {
                    board.makeMove(i, j);
                    best = std::min(best, minimax(board, depth + 1, true, alpha, beta));
                    board.makeMove(i, j); // Undo move
                    beta = std::min(beta, best);
                    if (beta <= alpha) break;
                }
            }
        }
        return best;
    }
}

void AIPlayer::getBestMove(const GameBoard& board, int& row, int& col) const {
    int best_val = std::numeric_limits<int>::min();
    row = -1;
    col = -1;

    GameBoard temp_board = board;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (temp_board.getCell(i, j) == ' ') {
                temp_board.makeMove(i, j);
                int move_val = minimax(temp_board, 0, false, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
                temp_board.makeMove(i, j); // Undo move
                if (move_val > best_val) {
                    row = i;
                    col = j;
                    best_val = move_val;
                }
            }
        }
    }
}
