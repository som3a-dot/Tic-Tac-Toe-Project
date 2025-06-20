#include "gameboard.h"
#include "ui_gameboard.h"
#include <QMessageBox>
#include <QPushButton>
#include <QDebug>
#include "gamemodewindow.h"

GameBoard::GameBoard(const QString &username, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameBoard),
    currentPlayer(1),
    gameMode(PlayerVsPlayer),
    aiDifficulty("Easy"),
    aiPlayer(nullptr),
    playerSymbol('X'),
    aiSymbol('O'),
    player1Score(0),
    player2Score(0),
    tieScore(0),
    gameHistory(username),
    username(username)
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = 0;

    ui->setupUi(this);
    if (ui->button_0_0) connect(ui->button_0_0, &QPushButton::clicked, this, &GameBoard::onButtonClicked);
    else qDebug() << "button_0_0 not found";
    if (ui->button_0_1) connect(ui->button_0_1, &QPushButton::clicked, this, &GameBoard::onButtonClicked);
    else qDebug() << "button_0_1 not found";
    if (ui->button_0_2) connect(ui->button_0_2, &QPushButton::clicked, this, &GameBoard::onButtonClicked);
    else qDebug() << "button_0_2 not found";
    if (ui->button_1_0) connect(ui->button_1_0, &QPushButton::clicked, this, &GameBoard::onButtonClicked);
    else qDebug() << "button_1_0 not found";
    if (ui->button_1_1) connect(ui->button_1_1, &QPushButton::clicked, this, &GameBoard::onButtonClicked);
    else qDebug() << "button_1_1 not found";
    if (ui->button_1_2) connect(ui->button_1_2, &QPushButton::clicked, this, &GameBoard::onButtonClicked);
    else qDebug() << "button_1_2 not found";
    if (ui->button_2_0) connect(ui->button_2_0, &QPushButton::clicked, this, &GameBoard::onButtonClicked);
    else qDebug() << "button_2_0 not found";
    if (ui->button_2_1) connect(ui->button_2_1, &QPushButton::clicked, this, &GameBoard::onButtonClicked);
    else qDebug() << "button_2_1 not found";
    if (ui->button_2_2) connect(ui->button_2_2, &QPushButton::clicked, this, &GameBoard::onButtonClicked);
    else qDebug() << "button_2_2 not found";

    resetBoard();
}

GameBoard::~GameBoard()
{
    delete ui;
    delete aiPlayer;
}

void GameBoard::onButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button || !button->text().isEmpty()) {
        qDebug() << "Invalid button click or already filled:" << (button ? button->objectName() : "nullptr");
        return;
    }

    QString moveSymbol;
    if (gameMode == PlayerVsPlayer) {
        moveSymbol = (currentPlayer == 1) ? "X" : "O";
    } else {
        moveSymbol = (currentPlayer == 1) ? QString(playerSymbol) : QString(aiSymbol);
    }
    if (moveSymbol == "X") {
        button->setStyleSheet("color: red;");
    } else if (moveSymbol == "O") {
        button->setStyleSheet("color: blue;");
    }
    button->setText(moveSymbol);
    int row = (button == ui->button_0_0 || button == ui->button_0_1 || button == ui->button_0_2) ? 0 :
                  (button == ui->button_1_0 || button == ui->button_1_1 || button == ui->button_1_2) ? 1 : 2;
    int col = (button == ui->button_0_0 || button == ui->button_1_0 || button == ui->button_2_0) ? 0 :
                  (button == ui->button_0_1 || button == ui->button_1_1 || button == ui->button_2_1) ? 1 : 2;
    board[row][col] = (currentPlayer == 1) ? 1 : 2;
    currentGameMoves.append({row, col});
    currentPlayer = 3 - currentPlayer;

    if (checkWin()) {
        QString winner = (currentPlayer == 2) ? player1Name : player2Name;
        QString winnerSymbol = (currentPlayer == 2) ? (gameMode == PlayerVsPlayer ? "X" : QString(playerSymbol)) :
                                   (gameMode == PlayerVsPlayer ? "O" : QString(aiSymbol));
        QMessageBox::information(this, "Winner", winner + " wins!");
        if (currentPlayer == 2) player1Score++;
        else player2Score++;
        updateScore();
        if (!username.isEmpty()) saveGameHistory(winner + " wins", winnerSymbol);
        resetBoard();
        return;
    }

    bool tie = true;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == 0) tie = false;
    if (tie) {
        QMessageBox::information(this, "Game Over", "It's a tie!");
        tieScore++;
        updateScore();
        if (!username.isEmpty()) saveGameHistory("Tie", "");
        resetBoard();
        return;
    }

    if (gameMode == PlayerVsAI && currentPlayer == 2 && aiPlayer) {
        int aiRow = -1, aiCol = -1;
        QVector<QVector<char>> aiBoard(3, QVector<char>(3, ' '));
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == 1) aiBoard[i][j] = playerSymbol;
                else if (board[i][j] == 2) aiBoard[i][j] = aiSymbol;
        aiPlayer->makeMove(aiBoard, aiRow, aiCol);

        if (aiRow != -1 && aiCol != -1) {
            board[aiRow][aiCol] = 2;
            QString aiMoveSymbol = QString(aiSymbol);
            QPushButton *aiButton = nullptr;
            if (aiRow == 0 && aiCol == 0) aiButton = ui->button_0_0;
            else if (aiRow == 0 && aiCol == 1) aiButton = ui->button_0_1;
            else if (aiRow == 0 && aiCol == 2) aiButton = ui->button_0_2;
            else if (aiRow == 1 && aiCol == 0) aiButton = ui->button_1_0;
            else if (aiRow == 1 && aiCol == 1) aiButton = ui->button_1_1;
            else if (aiRow == 1 && aiCol == 2) aiButton = ui->button_1_2;
            else if (aiRow == 2 && aiCol == 0) aiButton = ui->button_2_0;
            else if (aiRow == 2 && aiCol == 1) aiButton = ui->button_2_1;
            else if (aiRow == 2 && aiCol == 2) aiButton = ui->button_2_2;
            if (aiButton) {
                if (aiMoveSymbol == "X") {
                    aiButton->setStyleSheet("color: red;");
                } else if (aiMoveSymbol == "O") {
                    aiButton->setStyleSheet("color: blue;");
                }
                aiButton->setText(aiMoveSymbol);
            }
            currentGameMoves.append({aiRow, aiCol});
            currentPlayer = 1;
        }

        if (checkWin()) {
            QMessageBox::information(this, "Game Over", "AI wins!");
            player2Score++;
            updateScore();
            if (!username.isEmpty()) saveGameHistory("AI wins", QString(aiSymbol));
            resetBoard();
            return;
        }
        tie = true;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == 0) tie = false;
        if (tie) {
            QMessageBox::information(this, "Game Over", "It's a tie!");
            tieScore++;
            updateScore();
            if (!username.isEmpty()) saveGameHistory("Tie", "");
            resetBoard();
            return;
        }
    }
    updateStatus();
}

void GameBoard::on_resetButton_clicked()
{
    resetBoard();
}

void GameBoard::resetBoard()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            board[i][j] = 0;
            if (i == 0 && j == 0 && ui->button_0_0) ui->button_0_0->setText("");
            else if (i == 0 && j == 1 && ui->button_0_1) ui->button_0_1->setText("");
            else if (i == 0 && j == 2 && ui->button_0_2) ui->button_0_2->setText("");
            else if (i == 1 && j == 0 && ui->button_1_0) ui->button_1_0->setText("");
            else if (i == 1 && j == 1 && ui->button_1_1) ui->button_1_1->setText("");
            else if (i == 1 && j == 2 && ui->button_1_2) ui->button_1_2->setText("");
            else if (i == 2 && j == 0 && ui->button_2_0) ui->button_2_0->setText("");
            else if (i == 2 && j == 1 && ui->button_2_1) ui->button_2_1->setText("");
            else if (i == 2 && j == 2 && ui->button_2_2) ui->button_2_2->setText("");
        }
    currentPlayer = 1;
    currentGameMoves.clear();
    updateStatus();
}

bool GameBoard::checkWin()
{
    for (int i = 0; i < 3; ++i)
        if (board[i][0] && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;

    for (int j = 0; j < 3; ++j)
        if (board[0][j] && board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return true;

    if (board[0][0] && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

void GameBoard::updateStatus()
{
    if (ui->statusLabel) {
        QString currentName = (gameMode == PlayerVsAI && currentPlayer == 2) ? "AI" : (currentPlayer == 1 ? player1Name : player2Name);
        QString symbol = (gameMode == PlayerVsPlayer) ? (currentPlayer == 1 ? "X" : "O") :
                             (currentPlayer == 1 ? QString(playerSymbol) : QString(aiSymbol));
        ui->statusLabel->setText("Current Player: " + currentName + " (" + symbol + ")");
    } else {
        qDebug() << "statusLabel not found";
    }
}

void GameBoard::updateScore()
{
    if (ui->scoreLabel) {
        ui->scoreLabel->setText(QString("Score: %1: %2, %3: %4, Ties: %5")
                                    .arg(player1Name).arg(player1Score)
                                    .arg(gameMode == PlayerVsAI ? "AI" : player2Name).arg(player2Score)
                                    .arg(tieScore));
    } else {
        qDebug() << "scoreLabel not found";
    }
}

void GameBoard::saveGameHistory(const QString &outcome, const QString &winnerSymbol)
{
    GameSession session;
    session.player1Name = player1Name;
    session.player2Name = player2Name;
    session.gameMode = (gameMode == PlayerVsPlayer) ? "Player vs Player" : "Player vs AI";
    session.outcome = outcome;
    session.timestamp = QDateTime::currentDateTime();
    session.moves = currentGameMoves;
    session.winnerSymbol = winnerSymbol;
    gameHistory.saveGame(session);
}

void GameBoard::setGameMode(GameMode mode)
{
    gameMode = mode;
    if (gameMode == PlayerVsAI) {
        char aiSym = (playerSymbol == 'O') ? 'X' : 'O';
        aiSymbol = aiSym;
        if (aiPlayer) delete aiPlayer;
        aiPlayer = new AIPlayer(aiSymbol, playerSymbol, aiDifficulty);
        player2Name = "AI";
    } else if (gameMode == PlayerVsPlayer) {
        delete aiPlayer;
        aiPlayer = nullptr;
        playerSymbol = 'X';
        aiSymbol = 'O';
    }
    resetBoard();
    updateStatus();
    updateScore();
}

void GameBoard::setAIDifficulty(const QString &difficulty)
{
    aiDifficulty = difficulty;
    if (gameMode == PlayerVsAI) {
        char aiSym = (playerSymbol == 'O') ? 'X' : 'O';
        aiSymbol = aiSym;
        if (aiPlayer) delete aiPlayer;
        aiPlayer = new AIPlayer(aiSymbol, playerSymbol, aiDifficulty);
    }
    resetBoard();
}

void GameBoard::setPlayerNames(const QString &player1, const QString &player2)
{
    player1Name = player1.isEmpty() ? (username.isEmpty() ? "Player 1" : username) : player1;
    player2Name = (gameMode == PlayerVsAI) ? "AI" : (player2.isEmpty() ? "Player 2" : player2);
    updateStatus();
    updateScore();
}

void GameBoard::setPlayerSymbol(char symbol)
{
    if (symbol != 'X' && symbol != 'O') {
        qDebug() << "Invalid symbol:" << symbol;
        return;
    }

    if (gameMode == PlayerVsAI) {
        playerSymbol = symbol;
        aiSymbol = (playerSymbol == 'O') ? 'X' : 'O';
        if (aiPlayer) delete aiPlayer;
        aiPlayer = new AIPlayer(aiSymbol, playerSymbol, aiDifficulty);
        resetBoard();
        updateStatus();
    } else {
        qDebug() << "Symbol selection ignored in PlayerVsPlayer mode; Player 1 is X, Player 2 is O";
        playerSymbol = 'X';
        aiSymbol = 'O';
    }
}

void GameBoard::on_ReturnButton_clicked()
{
    this->hide();
    GameModeWindow *gameModeWindow = new GameModeWindow(username, nullptr);
    if (gameModeWindow) {
        gameModeWindow->show();
        gameModeWindow->activateWindow();
    } else {
        qDebug() << "Failed to create GameModeWindow";
    }
}
