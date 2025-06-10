#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <QString>
#include <QSqlDatabase>
#include <vector>
#include <utility>

class GameHistory {
public:
    GameHistory();
    ~GameHistory();
    bool saveGame(int user_id, const QString& user_username, const QString& player_x_name, const QString& player_o_name, const QString& result, const std::vector<std::pair<int, int>>& moves, bool is_player_vs_ai);
    QStringList getGames(int user_id) const;
    std::vector<std::pair<int, int>> getGameMoves(int game_id) const;
    bool isGamePlayerVsAi(int game_id) const;
    QString getPlayerXName(int game_id) const;
    QString getPlayerOName(int game_id) const;

private:
    QSqlDatabase db_;
    bool initDatabase();
};

#endif // GAMEHISTORY_H
