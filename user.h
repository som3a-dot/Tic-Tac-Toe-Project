#ifndef USER_H
#define USER_H

#include <QString>
#include <QSqlDatabase>

class User {
public:
    User();
    ~User();
    bool registerUser(const QString& username, const QString& password);
    bool login(const QString& username, const QString& password);
    void logout();
    int getUserId() const;
    bool isLoggedIn() const;
    QString getUsername() const; // Added to retrieve username

private:
    QSqlDatabase db_;
    int user_id_;
    bool is_logged_in_;
    QString username_; // Added to store username
    QString hashPassword(const QString& password) const;
    bool initDatabase();
};

#endif // USER_H
