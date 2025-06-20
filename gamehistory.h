#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <QString>
#include <QVector>
#include <QDateTime>

struct GameSession {
    QString player1Name;
    QString player2Name;
    QString gameMode;
    QString outcome;
    QDateTime timestamp;
    QVector<QPair<int, int>> moves; // Store moves as (row, col)
    QString winnerSymbol; // 'X', 'O', or empty for tie
};

class GameHistory {
public:
    explicit GameHistory(const QString &username = "");
    void saveGame(const GameSession &session);
    QVector<GameSession> loadGames();
    void clearHistory();

private:
    QString getHistoryFilePath() const;
    QString username;
    QString historyFilePath;
};

#endif // GAMEHISTORY_H
