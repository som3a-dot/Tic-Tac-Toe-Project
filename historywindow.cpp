#include "historywindow.h"
#include "ui_historywindow.h"
#include <QListWidget>
#include <QPushButton>
#include <QDebug>

HistoryWindow::HistoryWindow(const QString &username, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HistoryWindow)
    , gameHistory(username)
    , username(username)
    , currentReplayIndex(-1)
    , currentMoveIndex(-1)
    , replayTimer(new QTimer(this))
    , gameModeWindow(nullptr)
{
    ui->setupUi(this);

    connect(ui->historyList, &QListWidget::itemClicked,
            this, &HistoryWindow::on_historyList_itemClicked);
    connect(ui->replayButton, &QPushButton::clicked,
            this, &HistoryWindow::on_replayButton_clicked);
    connect(replayTimer, &QTimer::timeout,
            this, &HistoryWindow::replayNextMove);
    connect(ui->backToModeButton, &QPushButton::clicked,
            this, &HistoryWindow::on_backToModeButton_clicked);

    displayHistory();
}

HistoryWindow::~HistoryWindow()
{
    delete ui;
    // replayTimer is child of this, auto-deleted
}

void HistoryWindow::displayHistory()
{
    ui->historyList->clear();
    games = gameHistory.loadGames();
    for (int i = 0; i < games.size(); ++i) {
        const GameSession &session = games[i];
        QString itemText = QString("Game %1: %2 vs %3 (%4) - %5 [%6]")
                               .arg(i + 1)
                               .arg(session.player1Name)
                               .arg(session.player2Name)
                               .arg(session.gameMode)
                               .arg(session.outcome)
                               .arg(session.timestamp.toString("yyyy-MM-dd hh:mm:ss"));
        ui->historyList->addItem(itemText);
    }
}

void HistoryWindow::on_historyList_itemClicked()
{
    currentReplayIndex = ui->historyList->currentRow();
    resetReplayBoard();
    ui->replayButton->setEnabled(currentReplayIndex >= 0);
}

void HistoryWindow::on_replayButton_clicked()
{
    if (currentReplayIndex < 0 || currentReplayIndex >= games.size())
        return;

    currentMoveIndex = -1;
    resetReplayBoard();
    replayTimer->start(1000); // 1 second intervals
}

void HistoryWindow::replayNextMove()
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

    if (session.gameMode == "Player vs Player") {
        symbol = (currentMoveIndex % 2 == 0) ? "X" : "O";
    } else {
        char playerSymbol = 'X';
        char aiSymbol = 'O';

        if (!session.winnerSymbol.isEmpty()) {
            playerSymbol = session.winnerSymbol[0].toLatin1();
            aiSymbol = (playerSymbol == 'X') ? 'O' : 'X';
        }

        if (session.outcome.contains("Player wins")) {
            symbol = (currentMoveIndex % 2 == 0) ? playerSymbol : aiSymbol;
        } else if (session.outcome.contains("AI wins")) {
            symbol = (currentMoveIndex % 2 == 0) ? aiSymbol : playerSymbol;
        } else {
            symbol = (currentMoveIndex % 2 == 0) ? playerSymbol : aiSymbol;
        }
    }

    QPushButton *button = nullptr;
    QString btnName = QString("replay_%1_%2").arg(row).arg(col);
    button = findChild<QPushButton*>(btnName);

    if (button) {
        button->setText(symbol);
    }
}

void HistoryWindow::resetReplayBoard()
{
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            QPushButton *btn = findChild<QPushButton*>(
                QString("replay_%1_%2").arg(r).arg(c));
            if (btn) btn->setText("");
        }
    }
}

void HistoryWindow::on_clearHistoryButton_2_clicked()
{
    gameHistory.clearHistory();
    displayHistory();
    resetReplayBoard();
    ui->replayButton->setEnabled(false);
}

void HistoryWindow::on_backToModeButton_clicked()
{
    // Close this dialog
    this->close();

    // Open GameModeWindow with the same username
    gameModeWindow = new GameModeWindow(username, nullptr);
    gameModeWindow->show();
}
