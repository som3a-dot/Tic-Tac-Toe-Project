#include "gamehistory.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

GameHistory::GameHistory() {
    initDatabase();
}

GameHistory::~GameHistory() {
    if (db_.isOpen()) {
        db_.close();
    }
}

bool GameHistory::initDatabase() {
    db_ = QSqlDatabase::addDatabase("QSQLITE", "history_connection");
    db_.setDatabaseName("tictactoe.db");
    if (!db_.open()) {
        qDebug() << "Database error:" << db_.lastError().text();
        return false;
    }

    QSqlQuery query(db_);
    query.exec("CREATE TABLE IF NOT EXISTS games ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "user_id INTEGER, "
               "user_username TEXT, "  // Added to store username
               "player_x_name TEXT, "  // Added to store Player X's name
               "player_o_name TEXT, "  // Added to store Player O's name
               "result TEXT, "
               "is_player_vs_ai INTEGER, "
               "FOREIGN KEY(user_id) REFERENCES users(id))");

    query.exec("CREATE TABLE IF NOT EXISTS moves ("
               "game_id INTEGER, "
               "move_number INTEGER, "
               "row INTEGER, "
               "col INTEGER, "
               "FOREIGN KEY(game_id) REFERENCES games(id))");
    return true;
}

bool GameHistory::saveGame(int user_id, const QString& user_username, const QString& player_x_name, const QString& player_o_name, const QString& result, const std::vector<std::pair<int, int>>& moves, bool is_player_vs_ai) {
    QSqlQuery query(db_);
    query.prepare("INSERT INTO games (user_id, user_username, player_x_name, player_o_name, result, is_player_vs_ai) VALUES (:user_id, :user_username, :player_x_name, :player_o_name, :result, :is_player_vs_ai)");
    query.bindValue(":user_id", user_id);
    query.bindValue(":user_username", user_username);
    query.bindValue(":player_x_name", player_x_name);
    query.bindValue(":player_o_name", player_o_name);
    query.bindValue(":result", result);
    query.bindValue(":is_player_vs_ai", is_player_vs_ai ? 1 : 0);
    if (!query.exec()) {
        qDebug() << "Save game error:" << query.lastError().text();
        return false;
    }

    int game_id = query.lastInsertId().toInt();
    for (size_t i = 0; i < moves.size(); ++i) {
        const auto& move = moves[i];
        query.prepare("INSERT INTO moves (game_id, move_number, row, col) VALUES (:game_id, :move_number, :row, :col)");
        query.bindValue(":game_id", game_id);
        query.bindValue(":move_number", static_cast<int>(i));
        query.bindValue(":row", move.first);
        query.bindValue(":col", move.second);
        if (!query.exec()) {
            qDebug() << "Save move error:" << query.lastError().text();
            return false;
        }
    }
    return true;
}

QStringList GameHistory::getGames(int user_id) const {
    QStringList games;
    QSqlQuery query(db_);
    query.prepare("SELECT id, user_username, player_x_name, player_o_name, result, is_player_vs_ai FROM games WHERE user_id = :user_id");
    query.bindValue(":user_id", user_id);
    if (query.exec()) {
        while (query.next()) {
            int game_id = query.value("id").toInt();
            QString user_username = query.value("user_username").toString();
            QString player_x_name = query.value("player_x_name").toString();
            QString player_o_name = query.value("player_o_name").toString();
            QString result = query.value("result").toString();
            bool is_player_vs_ai = query.value("is_player_vs_ai").toInt() == 1;
            QString mode = is_player_vs_ai ? "Player vs AI" : "Player vs Player";
            games << QString("Game %1: %2 (%3, %4 vs %5) by %6").arg(game_id).arg(result).arg(mode).arg(player_x_name).arg(player_o_name).arg(user_username);
        }
    }
    return games;
}

std::vector<std::pair<int, int>> GameHistory::getGameMoves(int game_id) const {
    std::vector<std::pair<int, int>> moves;
    QSqlQuery query(db_);
    query.prepare("SELECT row, col FROM moves WHERE game_id = :game_id ORDER BY move_number");
    query.bindValue(":game_id", game_id);
    if (query.exec()) {
        while (query.next()) {
            int row = query.value("row").toInt();
            int col = query.value("col").toInt();
            moves.emplace_back(row, col);
        }
    }
    return moves;
}

bool GameHistory::isGamePlayerVsAi(int game_id) const {
    QSqlQuery query(db_);
    query.prepare("SELECT is_player_vs_ai FROM games WHERE id = :game_id");
    query.bindValue(":game_id", game_id);
    if (query.exec() && query.next()) {
        return query.value("is_player_vs_ai").toInt() == 1;
    }
    return false;
}

QString GameHistory::getPlayerXName(int game_id) const {
    QSqlQuery query(db_);
    query.prepare("SELECT player_x_name FROM games WHERE id = :game_id");
    query.bindValue(":game_id", game_id);
    if (query.exec() && query.next()) {
        return query.value("player_x_name").toString();
    }
    return "Player X";
}

QString GameHistory::getPlayerOName(int game_id) const {
    QSqlQuery query(db_);
    query.prepare("SELECT player_o_name FROM games WHERE id = :game_id");
    query.bindValue(":game_id", game_id);
    if (query.exec() && query.next()) {
        return query.value("player_o_name").toString();
    }
    return "Player O";
}
