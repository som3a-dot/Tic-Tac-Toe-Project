#ifndef HISTORY_HPP
#define HISTORY_HPP

#include <string>
#include <vector>
#include <utility> // for std::pair

struct GameSession
{
    std::string player1Name;
    std::string player2Name;
    std::string gameMode;
    std::string outcome;
    std::string timestamp;
    std::vector<std::pair<int, int>> moves; // (row, col)
    std::string winnerSymbol;               // "X", "O", or empty for tie
};

class GameHistory
{
public:
    GameHistory();
    void saveGame(const GameSession &session);
    std::vector<GameSession> loadGames();
    void clearHistory();

private:
    std::string historyFilePath;
};

#endif // HISTORY_HPP
