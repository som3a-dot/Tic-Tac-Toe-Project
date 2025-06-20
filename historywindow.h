#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QDialog>
#include <QTimer>
#include "gamehistory.h"

namespace Ui {
class HistoryWindow;
}

class historywindow : public QDialog
{
    Q_OBJECT

public:
    explicit historywindow(const QString &username = "", QWidget *parent = nullptr);
    ~historywindow();

private slots:
    void on_historyList_itemClicked();
    void on_replayButton_clicked();
    void replayNextMove();
    void on_clearHistoryButton_2_clicked();

private:
    void displayHistory();
    void resetReplayBoard();
    Ui::HistoryWindow *ui;
    GameHistory gameHistory;
    QVector<GameSession> games;
    int currentReplayIndex;
    int currentMoveIndex;
    QTimer *replayTimer;
};

#endif // HISTORYWINDOW_H
