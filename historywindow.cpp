#include "historywindow.h"
#include "ui_historywindow.h"
#include <QListWidget>
#include <QPushButton>
#include <QDebug>

historywindow::historywindow(const QString &username, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HistoryWindow)
    , gameHistory(username)
    , currentReplayIndex(-1)
    , currentMoveIndex(-1)
    , replayTimer(new QTimer(this))
{
    ui->setupUi(this);
    connect(ui->historyList, &QListWidget::itemClicked, this, &historywindow::on_historyList_itemClicked);
    connect(ui->replayButton, &QPushButton::clicked, this, &historywindow::on_replayButton_clicked);
    connect(replayTimer, &QTimer::timeout, this, &historywindow::replayNextMove);

    displayHistory();
}

historywindow::~historywindow()
{
    delete ui;
    delete replayTimer;
}

void historywindow::displayHistory()
{
    ui->historyList->clear();
    games = gameHistory.loadGames();
    for (int i = 0; i < games.size(); ++i) {
        const GameSession &session = games[i];
        QString itemText = QString("Game %1: %2 vs %3 (%4) - %5 [%6]")
                               .arg(i + 1)
                               .arg(session.player1Name, session.player2Name, session.gameMode, session.outcome, session.timestamp.toString("yyyy-MM-dd hh:mm:ss"));
        ui->historyList->addItem(itemText);
    }
}

void historywindow::on_historyList_itemClicked()
{
    currentReplayIndex = ui->historyList->currentRow();
    resetReplayBoard();
    ui->replayButton->setEnabled(currentReplayIndex >= 0);
}

void historywindow::on_replayButton_clicked()
{
    if (currentReplayIndex < 0 || currentReplayIndex >= games.size()) return;

    currentMoveIndex = -1;
    resetReplayBoard();
    replayTimer->start(1000); // Replay moves every 1 second
}

void historywindow::replayNextMove()
{
    if (currentReplayIndex < 0 || currentReplayIndex >= games.size()) {
        replayTimer->stop();
        return;
    }

    const GameSession &session = games[currentReplayIndex];
    currentMoveIndex++;

    if (currentMoveIndex >= session.moves.size()) {
        replayTimer->stop();
        return;
    }

    int row = session.moves[currentMoveIndex].first;
    int col = session.moves[currentMoveIndex].second;
    QString symbol;

    // Determine symbol based on game mode and move index
    if (session.gameMode == "Player vs Player") {
        // In Player vs Player, Player 1 is 'O', Player 2 is 'X'
        symbol = (currentMoveIndex % 2 == 0) ? "X" : "O";
    } else {
        // In Player vs AI, use winnerSymbol to determine player and AI symbols
        char playerSymbol = session.winnerSymbol[0].toLatin1(); // Player's symbol if they won
        char aiSymbol = (playerSymbol == 'X') ? 'O' : 'X';     // AI's opposite symbol

        if (session.outcome.contains("Player wins")) {
            // Player won, first move is player's symbol, alternate with AI's
            symbol = (currentMoveIndex % 2 == 0) ? playerSymbol : aiSymbol;
        } else if (session.outcome.contains("AI wins")) {
            // AI won, first move is AI's symbol, alternate with player's
            symbol = (currentMoveIndex % 2 == 0) ? aiSymbol : playerSymbol;
        } else {
            // Tie or no winner, use the player's starting symbol and alternate
            symbol = (currentMoveIndex % 2 == 0) ? playerSymbol : aiSymbol;
        }
    }

    QPushButton *button = nullptr;
    if (row == 0 && col == 0) button = ui->replay_0_0;
    else if (row == 0 && col == 1) button = ui->replay_0_1;
    else if (row == 0 && col == 2) button = ui->replay_0_2;
    else if (row == 1 && col == 0) button = ui->replay_1_0;
    else if (row == 1 && col == 1) button = ui->replay_1_1;
    else if (row == 1 && col == 2) button = ui->replay_1_2;
    else if (row == 2 && col == 0) button = ui->replay_2_0;
    else if (row == 2 && col == 1) button = ui->replay_2_1;
    else if (row == 2 && col == 2) button = ui->replay_2_2;
    if (button) {
        button->setText(symbol);
    }
}

void historywindow::resetReplayBoard()
{
    // Clear the replay board
    ui->replay_0_0->setText("");
    ui->replay_0_1->setText("");
    ui->replay_0_2->setText("");
    ui->replay_1_0->setText("");
    ui->replay_1_1->setText("");
    ui->replay_1_2->setText("");
    ui->replay_2_0->setText("");
    ui->replay_2_1->setText("");
    ui->replay_2_2->setText("");
}

void historywindow::on_clearHistoryButton_2_clicked()
{
    gameHistory.clearHistory();
    displayHistory();
    resetReplayBoard();
    ui->replayButton->setEnabled(false);
}
