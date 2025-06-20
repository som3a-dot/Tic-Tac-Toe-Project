#include "History.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib> // For getenv
#include <filesystem>

GameHistory::GameHistory()
{
#ifdef _WIN32
    historyFilePath = std::getenv("USERPROFILE");
#else
    historyFilePath = std::getenv("HOME");
#endif
    historyFilePath += "/tictactoe_history.txt";
}

void GameHistory::saveGame(const GameSession &session)
{
    std::ofstream file(historyFilePath, std::ios::app);
    if (!file.is_open())
        return;

    file << "[SESSION]\n";
    file << session.player1Name << '\n';
    file << session.player2Name << '\n';
    file << session.gameMode << '\n';
    file << session.outcome << '\n';
    file << session.timestamp << '\n';
    file << session.winnerSymbol << '\n';
    file << session.moves.size() << '\n';
    for (auto &move : session.moves)
        file << move.first << ' ' << move.second << '\n';

    file.close();
}

std::vector<GameSession> GameHistory::loadGames()
{
    std::vector<GameSession> sessions;
    std::ifstream file(historyFilePath);
    if (!file.is_open())
        return sessions;

    std::string line;
    while (std::getline(file, line))
    {
        if (line == "[SESSION]")
        {
            GameSession session;
            std::getline(file, session.player1Name);
            std::getline(file, session.player2Name);
            std::getline(file, session.gameMode);
            std::getline(file, session.outcome);
            std::getline(file, session.timestamp);
            std::getline(file, session.winnerSymbol);
            std::getline(file, line);
            int moveCount = std::stoi(line);
            for (int i = 0; i < moveCount; ++i)
            {
                std::getline(file, line);
                std::istringstream iss(line);
                int row, col;
                iss >> row >> col;
                session.moves.emplace_back(row, col);
            }
            sessions.push_back(session);
        }
    }

    file.close();
    return sessions;
}

void GameHistory::clearHistory()
{
    std::ofstream file(historyFilePath, std::ios::trunc);
    file.close();
}
