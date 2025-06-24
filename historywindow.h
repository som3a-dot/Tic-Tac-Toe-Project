#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QDialog>
#include <QTimer>
#include "gamehistory.h"
#include "gamemodewindow.h"

namespace Ui {
class HistoryWindow;
}

class HistoryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryWindow(const QString &username = "", QWidget *parent = nullptr);
    ~HistoryWindow();

private slots:
    void on_historyList_itemClicked();
    void on_replayButton_clicked();
    void replayNextMove();
    void on_clearHistoryButton_2_clicked();
    void on_backToModeButton_clicked();

private:
    void displayHistory();
    void resetReplayBoard();

    Ui::HistoryWindow *ui;
    GameHistory gameHistory;
    QString username;
    QVector<GameSession> games;
    int currentReplayIndex;
    int currentMoveIndex;
    QTimer *replayTimer;

    GameModeWindow *gameModeWindow;
};

#endif // HISTORYWINDOW_H
