#include "user.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include <QDebug>

User::User() : user_id_(-1), is_logged_in_(false) {
    initDatabase();
}

User::~User() {
    if (db_.isOpen()) {
        db_.close();
    }
}

bool User::initDatabase() {
    db_ = QSqlDatabase::addDatabase("QSQLITE");
    db_.setDatabaseName("tictactoe.db");
    if (!db_.open()) {
        qDebug() << "Database error:" << db_.lastError().text();
        return false;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "username TEXT UNIQUE, "
               "password_hash TEXT)");
    return true;
}

QString User::hashPassword(const QString& password) const {
    return QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
}

bool User::registerUser(const QString& username, const QString& password) {
    if (username.isEmpty() || password.isEmpty()) {
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password_hash) VALUES (:username, :password_hash)");
    query.bindValue(":username", username);
    query.bindValue(":password_hash", hashPassword(password));
    if (!query.exec()) {
        qDebug() << "Register error:" << query.lastError().text();
        return false;
    }
    return true;
}

bool User::login(const QString& username, const QString& password) {
    QSqlQuery query;
    query.prepare("SELECT id, password_hash FROM users WHERE username = :username");
    query.bindValue(":username", username);
    if (!query.exec() || !query.next()) {
        return false;
    }

    QString stored_hash = query.value("password_hash").toString();
    if (hashPassword(password) != stored_hash) {
        return false;
    }

    user_id_ = query.value("id").toInt();
    username_ = username; // Store username
    is_logged_in_ = true;
    return true;
}

void User::logout() {
    user_id_ = -1;
    username_.clear();
    is_logged_in_ = false;
}

int User::getUserId() const {
    return user_id_;
}

bool User::isLoggedIn() const {
    return is_logged_in_;
}

QString User::getUsername() const {
    return username_;
}
