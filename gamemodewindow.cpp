#include "gamemodewindow.h"
#include "symbolwindow.h"
#include "ui_gamemodewindow.h"
#include <QDebug>

GameModeWindow::GameModeWindow(const QString &username, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameModeWindow),
    gameBoard(nullptr),
    playerNameWindow(nullptr),
    aiDifficultyWindow(nullptr),
    settingsWindow(nullptr),
    username(username)
{
    ui->setupUi(this);
}

GameModeWindow::~GameModeWindow()
{
    delete ui;
    delete gameBoard;
    delete playerNameWindow;
    delete aiDifficultyWindow;
    delete settingsWindow;
}

void GameModeWindow::on_playerVsPlayer_clicked()
{
    playerNameWindow = new PlayerNameWindow(nullptr);
    if (playerNameWindow) {
        connect(playerNameWindow, &PlayerNameWindow::namesEntered, this, &GameModeWindow::onPlayerNamesEntered);
        playerNameWindow->show();

    } else {
        qDebug() << "Failed to create PlayerNameWindow";
    }
}

void GameModeWindow::on_playerVsAI_clicked()
{
    aiDifficultyWindow = new AIDifficultyWindow(nullptr);
    if (aiDifficultyWindow) {
        connect(aiDifficultyWindow, &AIDifficultyWindow::difficultySelected, this, &GameModeWindow::onAIDifficultySelected);
         connect(aiDifficultyWindow, &AIDifficultyWindow::backToGameMode, this, &GameModeWindow::onBackToGameMode);
        aiDifficultyWindow->show();
        this->hide();
    } else {
        qDebug() << "Failed to create AIDifficultyWindow";
    }
}

void GameModeWindow::onPlayerNamesEntered(const QString &player1, const QString &player2)
{
    gameBoard = new GameBoard(username, nullptr);
    if (gameBoard) {
        gameBoard->setGameMode(GameBoard::PlayerVsPlayer);
        gameBoard->setPlayerNames(player1, player2);
        gameBoard->show();
        this->hide();
    } else {
        qDebug() << "Failed to create GameBoard";
    }
}

void GameModeWindow::onAIDifficultySelected(const QString &difficulty)
{
    SymbolWindow *symbolWindow = new SymbolWindow(nullptr);
    if (symbolWindow) {
        connect(symbolWindow, &SymbolWindow::symbolSelected, this, [this, difficulty](const QString &symbol) {
            gameBoard = new GameBoard(username, nullptr);
            if (gameBoard) {
                gameBoard->setGameMode(GameBoard::PlayerVsAI);
                gameBoard->setAIDifficulty(difficulty);
                gameBoard->setPlayerSymbol(symbol.toUpper()[0].toLatin1());
                gameBoard->setPlayerNames(username.isEmpty() ? "Player" : username, "AI");
                gameBoard->show();
            } else {
                qDebug() << "Failed to create GameBoard";
            }
            delete aiDifficultyWindow;
            aiDifficultyWindow = nullptr;
        });
        symbolWindow->show();
    } else {
        qDebug() << "Failed to create SymbolWindow";
    }
}
void GameModeWindow::onBackToGameMode()
{
    this->show();
}
void GameModeWindow::back()
{
    this->show();
}
void GameModeWindow::on_settingButton_clicked()
{
    settingsWindow = new SettingsWindow(username, nullptr);
    if (settingsWindow) {
        connect(settingsWindow, &SettingsWindow::back, this, &GameModeWindow::back);
        settingsWindow->show();
        this->hide();
    } else {
        qDebug() << "Failed to create SettingsWindow";
    }
}
