#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include "gameboard.h"
#include "aiplayer.h"
#include "user.h"
#include "gamehistory.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleButtonClick(int row, int col);
    void handleLogin();
    void handleRegister();
    void handlePlayAsGuest();
    void handleClearLogin();
    void handleCancelRegister();
    void handleRestart();
    void selectPlayerVsAi();
    void selectPlayerVsPlayer();
    void showSplashScreen();
    void showLoginScreen();
    void showRegisterScreen();
    void showModeSelectionScreen();
    void showGameScreen();
    void showHistoryScreen();
    void replayGame(QListWidgetItem* item);
    void replayStep();
    void updatePasswordStrength();

private:
    void setupSplashScreenUi();
    void setupLoginUi();
    void setupRegisterUi();
    void setupModeSelectionUi();
    void setupGameUi();
    void setupHistoryUi();
    void updateBoard();
    void checkGameStatus();
    void resetGame();
    void resetButtons();

    User user_;
    GameBoard game_board_;
    AIPlayer ai_player_;
    GameHistory game_history_;
    QWidget* splash_widget_;
    QWidget* login_widget_;
    QWidget* register_widget_;
    QWidget* mode_selection_widget_;
    QWidget* game_widget_;
    QWidget* history_widget_;
    QPushButton* buttons_[3][3];
    QLabel* status_label_;
    QLineEdit* username_input_;
    QLineEdit* password_input_;
    QLineEdit* register_username_input_;
    QLineEdit* register_password_input_;
    QLineEdit* confirm_password_input_;
    QLabel* password_strength_label_;
    QListWidget* history_list_;
    std::vector<std::pair<int, int>> replay_moves_;
    size_t replay_index_;
    QTimer* replay_timer_;
    bool is_player_vs_ai_;
    bool is_guest_mode_;
    QString player_x_name_;
    QString player_o_name_;
    QLineEdit* player_x_input_;
    QLineEdit* player_o_input_;
};

#endif // MAINWINDOW_H
