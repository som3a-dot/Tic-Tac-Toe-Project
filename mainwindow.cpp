#include "mainwindow.h"
#include "gamemodewindow.h"
#include "registerwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QCryptographicHash>
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadRegisteredUsers();
}

MainWindow::~MainWindow()
{
    saveRegisteredUsers();
    delete ui;
}

QString MainWindow::hashPassword(const QString &password)
{
    return QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
}

bool MainWindow::isUsernameTaken(const QString &username) const
{
    return registeredUsers.contains(username);
}

void MainWindow::addRegisteredUser(const QString &username, const QString &hashedPassword)
{
    registeredUsers[username] = hashedPassword;
}

void MainWindow::on_RegisterButton_2_clicked()
{
    registerwindow registerwindow(this);
    registerwindow.setModal(true);
    registerwindow.exec();
    saveRegisteredUsers();
}

void MainWindow::on_clearButton_3_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::on_LoginButton_clicked()
{
    QString username = ui->lineEdit->text().trimmed();
    QString password = ui->lineEdit_2->text().trimmed();
    QString hashedPassword = hashPassword(password);

    if (username.isEmpty() || password.isEmpty()) {
        qDebug() << "Error: Username or password is empty";
        QMessageBox::warning(this, "Error", "Username and password are required.");
        return;
    }

    if (registeredUsers.contains(username)) {
        if (registeredUsers.value(username) == hashedPassword) {
            QMessageBox::information(this, "Success", "LOGGED IN SUCCESSFULLY!");
            GameModeWindow *gameModeWindow = new GameModeWindow(username, nullptr);
            if (gameModeWindow) {
                gameModeWindow->show();
                this->hide();
            } else {
                qDebug() << "Failed to create GameModeWindow";
            }
        } else {
            qDebug() << "Authentication failed - Stored hash:" << registeredUsers.value(username) << "vs Input hash:" << hashedPassword;
            QMessageBox::warning(this, "Error", "Invalid username or password.");
        }
    } else {
        qDebug() << "Username" << username << "not found in registeredUsers";
        QMessageBox::warning(this, "Error", "Invalid username or password.");
    }
}

void MainWindow::on_GuestButton_4_clicked()
{
    GameModeWindow *gameModeWindow = new GameModeWindow("", nullptr);
    if (gameModeWindow) {
        gameModeWindow->show();
        this->hide();
    } else {
        qDebug() << "Failed to create GameModeWindow for guest";
    }
}

void MainWindow::saveRegisteredUsers()
{
    QFile file("registered_users.json");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open registered_users.json for writing";
        return;
    }

    QJsonObject usersObject;
    for (auto it = registeredUsers.constBegin(); it != registeredUsers.constEnd(); ++it) {
        usersObject[it.key()] = it.value();
    }

    QJsonDocument doc(usersObject);
    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
}

void MainWindow::loadRegisteredUsers()
{
    QFile file("registered_users.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No registered_users.json found, starting with empty list";
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject()) {
        qDebug() << "Invalid JSON format in registered_users.json";
        return;
    }

    registeredUsers.clear();
    QJsonObject usersObject = doc.object();
    for (auto it = usersObject.constBegin(); it != usersObject.constEnd(); ++it) {
        registeredUsers.insert(it.key(), it.value().toString());
    }
}
