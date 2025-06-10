#include "mainwindow.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QTimer>
#include <QDebug>
#include <QLinearGradient>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ai_player_('O'),
    splash_widget_(nullptr),
    login_widget_(nullptr),
    register_widget_(nullptr),
    mode_selection_widget_(nullptr),
    game_widget_(nullptr),
    history_widget_(nullptr),
    replay_index_(0),
    is_player_vs_ai_(true),
    is_guest_mode_(false),
    player_x_name_("Player X"),
    player_o_name_("Player O") {
    qDebug() << "MainWindow constructor started.";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            buttons_[i][j] = nullptr;
        }
    }
    replay_timer_ = new QTimer(this);
    connect(replay_timer_, &QTimer::timeout, this, &MainWindow::replayStep);
    setupSplashScreenUi();
    setCentralWidget(splash_widget_);
    setWindowTitle("Advanced Tic Tac Toe");
    resize(400, 400);
    qDebug() << "MainWindow constructor finished.";

    // Apply gradient background with stars
    QLinearGradient gradient(0, 0, 0, height());
    gradient.setColorAt(0, QColor("#1C2526"));
    gradient.setColorAt(1, QColor("#FF4040"));
    QPalette palette;
    palette.setBrush(QPalette::Window, gradient);
    setPalette(palette);
}

MainWindow::~MainWindow() {
    qDebug() << "MainWindow destructor called.";
    if (replay_timer_) {
        replay_timer_->stop();
        delete replay_timer_;
    }
}

void MainWindow::setupSplashScreenUi() {
    qDebug() << "Setting up splash screen UI.";
    splash_widget_ = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(splash_widget_);

    QLabel* title_label = new QLabel("TIC TAC TOE", this);
    title_label->setAlignment(Qt::AlignCenter);
    title_label->setFont(QFont("Arial", 24, QFont::Bold));
    title_label->setStyleSheet("QLabel { color: #00FFFF; text-shadow: 0 0 10px #00FFFF, 0 0 20px #00FFFF; }");
    layout->addWidget(title_label);

    QPushButton* start_button = new QPushButton("START", this);
    start_button->setStyleSheet("QPushButton { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; font-size: 16px; }"
                                "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
    connect(start_button, &QPushButton::clicked, this, &MainWindow::showLoginScreen);
    layout->addWidget(start_button);

    splash_widget_->setStyleSheet("background-color: transparent;");
}

void MainWindow::setupLoginUi() {
    qDebug() << "Setting up login UI.";
    login_widget_ = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(login_widget_);

    QLabel* title_label = new QLabel("TIC TAC TOE", this);
    title_label->setAlignment(Qt::AlignCenter);
    title_label->setFont(QFont("Arial", 24, QFont::Bold));
    title_label->setStyleSheet("QLabel { color: #00FFFF; text-shadow: 0 0 10px #00FFFF, 0 0 20px #00FFFF; }");
    layout->addWidget(title_label);

    QLabel* subtitle_label = new QLabel("WELCOME TO THE GAME", this);
    subtitle_label->setAlignment(Qt::AlignCenter);
    subtitle_label->setStyleSheet("QLabel { color: #00FFFF; text-shadow: 0 0 10px #00FFFF; font-size: 16px; }");
    layout->addWidget(subtitle_label);

    QLabel* username_label = new QLabel("USERNAME:", this);
    username_label->setStyleSheet("QLabel { color: #00FFFF; text-shadow: 0 0 10px #00FFFF; }");
    layout->addWidget(username_label);

    username_input_ = new QLineEdit(this);
    username_input_->setPlaceholderText("Username");
    username_input_->setStyleSheet("QLineEdit { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; }"
                                   "QLineEdit:focus { border: 2px solid #FF00FF; box-shadow: 0 0 10px #FF00FF; }");
    layout->addWidget(username_input_);

    QLabel* password_label = new QLabel("PASSWORD:", this);
    password_label->setStyleSheet("QLabel { color: #00FFFF; text-shadow: 0 0 10px #00FFFF; }");
    layout->addWidget(password_label);

    password_input_ = new QLineEdit(this);
    password_input_->setPlaceholderText("Password");
    password_input_->setEchoMode(QLineEdit::Password);
    password_input_->setStyleSheet("QLineEdit { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; }"
                                   "QLineEdit:focus { border: 2px solid #FF00FF; box-shadow: 0 0 10px #FF00FF; }");
    layout->addWidget(password_input_);

    QPushButton* login_button = new QPushButton("LOGIN", this);
    login_button->setStyleSheet("QPushButton { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; font-size: 16px; }"
                                "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
    connect(login_button, &QPushButton::clicked, this, &MainWindow::handleLogin);
    layout->addWidget(login_button);

    QPushButton* register_button = new QPushButton("REGISTER", this);
    register_button->setStyleSheet("QPushButton { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; font-size: 16px; }"
                                   "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
    connect(register_button, &QPushButton::clicked, this, &MainWindow::showRegisterScreen);
    layout->addWidget(register_button);

    QPushButton* guest_button = new QPushButton("PLAY AS GUEST", this);
    guest_button->setStyleSheet("QPushButton { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; font-size: 16px; }"
                                "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
    connect(guest_button, &QPushButton::clicked, this, &MainWindow::handlePlayAsGuest);
    layout->addWidget(guest_button);

    QPushButton* clear_button = new QPushButton("CLEAR", this);
    clear_button->setStyleSheet("QPushButton { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; font-size: 16px; }"
                                "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
    connect(clear_button, &QPushButton::clicked, this, &MainWindow::handleClearLogin);
    layout->addWidget(clear_button);

    login_widget_->setStyleSheet("background-color: transparent;");
}

void MainWindow::setupRegisterUi() {
    qDebug() << "Setting up register UI.";
    register_widget_ = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(register_widget_);

    QLabel* title_label = new QLabel("REGISTER", this);
    title_label->setAlignment(Qt::AlignCenter);
    title_label->setFont(QFont("Arial", 24, QFont::Bold));
    title_label->setStyleSheet("QLabel { color: #00FFFF; text-shadow: 0 0 10px #00FFFF, 0 0 20px #00FFFF; }");
    layout->addWidget(title_label);

    QLabel* subtitle_label = new QLabel("CREATE A NEW ACCOUNT", this);
    subtitle_label->setAlignment(Qt::AlignCenter);
    subtitle_label->setStyleSheet("QLabel { color: #00FFFF; text-shadow: 0 0 10px #00FFFF; font-size: 16px; }");
    layout->addWidget(subtitle_label);

    QLabel* username_label = new QLabel("USERNAME:", this);
    username_label->setStyleSheet("QLabel { color: #00FFFF; text-shadow: 0 0 10px #00FFFF; }");
    layout->addWidget(username_label);

    register_username_input_ = new QLineEdit(this);
    register_username_input_->setPlaceholderText("Letters and numbers only");
    register_username_input_->setStyleSheet("QLineEdit { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; }"
                                            "QLineEdit:focus { border: 2px solid #FF00FF; box-shadow: 0 0 10px #FF00FF; }");
    layout->addWidget(register_username_input_);

    QLabel* password_label = new QLabel("PASSWORD:", this);
    password_label->setStyleSheet("QLabel { color: #00FFFF; text-shadow: 0 0 10px #00FFFF; }");
    layout->addWidget(password_label);

    register_password_input_ = new QLineEdit(this);
    register_password_input_->setPlaceholderText("Password");
    register_password_input_->setEchoMode(QLineEdit::Password);
    register_password_input_->setStyleSheet("QLineEdit { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; }"
                                            "QLineEdit:focus { border: 2px solid #FF00FF; box-shadow: 0 0 10px #FF00FF; }");
    connect(register_password_input_, &QLineEdit::textChanged, this, &MainWindow::updatePasswordStrength);
    layout->addWidget(register_password_input_);

    QLabel* strength_label = new QLabel("PASSWORD STRENGTH:", this);
    strength_label->setStyleSheet("QLabel { color: #00FFFF; text-shadow: 0 0 10px #00FFFF; }");
    layout->addWidget(strength_label);

    password_strength_label_ = new QLabel("WEAK", this);
    password_strength_label_->setStyleSheet("QLabel { color: #FF4040; text-shadow: 0 0 10px #FF4040; }");
    layout->addWidget(password_strength_label_);

    QLabel* confirm_label = new QLabel("CONFIRM PASSWORD:", this);
    confirm_label->setStyleSheet("QLabel { color: #00FFFF; text-shadow: 0 0 10px #00FFFF; }");
    layout->addWidget(confirm_label);

    confirm_password_input_ = new QLineEdit(this);
    confirm_password_input_->setPlaceholderText("Confirm Password");
    confirm_password_input_->setEchoMode(QLineEdit::Password);
    confirm_password_input_->setStyleSheet("QLineEdit { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; }"
                                           "QLineEdit:focus { border: 2px solid #FF00FF; box-shadow: 0 0 10px #FF00FF; }");
    layout->addWidget(confirm_password_input_);

    QPushButton* register_button = new QPushButton("REGISTER", this);
    register_button->setStyleSheet("QPushButton { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; font-size: 16px; }"
                                   "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
    connect(register_button, &QPushButton::clicked, this, &MainWindow::handleRegister);
    layout->addWidget(register_button);

    QPushButton* cancel_button = new QPushButton("CANCEL", this);
    cancel_button->setStyleSheet("QPushButton { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; font-size: 16px; }"
                                 "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
    connect(cancel_button, &QPushButton::clicked, this, &MainWindow::handleCancelRegister);
    layout->addWidget(cancel_button);

    register_widget_->setStyleSheet("background-color: transparent;");
}

void MainWindow::setupModeSelectionUi() {
    qDebug() << "Setting up mode selection UI.";
    mode_selection_widget_ = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(mode_selection_widget_);

    QLabel* title_label = new QLabel("TIC TAC TOE", this);
    title_label->setAlignment(Qt::AlignCenter);
    title_label->setFont(QFont("Arial", 24, QFont::Bold));
    title_label->setStyleSheet("QLabel { color: #00FFFF; text-shadow: 0 0 10px #00FFFF, 0 0 20px #00FFFF; }");
    layout->addWidget(title_label);

    QLabel* label = new QLabel("SELECT A GAME MODE", this);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("QLabel { color: #00FFFF; text-shadow: 0 0 10px #00FFFF; font-size: 16px; }");
    layout->addWidget(label);

    player_x_input_ = new QLineEdit(this);
    player_x_input_->setPlaceholderText("Player X Name");
    player_x_input_->setStyleSheet("QLineEdit { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; }"
                                   "QLineEdit:focus { border: 2px solid #FF00FF; box-shadow: 0 0 10px #FF00FF; }");
    layout->addWidget(player_x_input_);

    player_o_input_ = new QLineEdit(this);
    player_o_input_->setPlaceholderText("Player O Name (or leave blank for AI)");
    player_o_input_->setStyleSheet("QLineEdit { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; }"
                                   "QLineEdit:focus { border: 2px solid #FF00FF; box-shadow: 0 0 10px #FF00FF; }");
    layout->addWidget(player_o_input_);

    QPushButton* player_vs_ai_button = new QPushButton("VS AI", this);
    player_vs_ai_button->setStyleSheet("QPushButton { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; font-size: 16px; }"
                                       "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
    connect(player_vs_ai_button, &QPushButton::clicked, this, &MainWindow::selectPlayerVsAi);
    layout->addWidget(player_vs_ai_button);

    QPushButton* player_vs_player_button = new QPushButton("VS PLAYER", this);
    player_vs_player_button->setStyleSheet("QPushButton { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; font-size: 16px; }"
                                           "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
    connect(player_vs_player_button, &QPushButton::clicked, this, &MainWindow::selectPlayerVsPlayer);
    layout->addWidget(player_vs_player_button);

    mode_selection_widget_->setStyleSheet("background-color: transparent;");
}

void MainWindow::resetButtons() {
    qDebug() << "Resetting buttons array.";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            buttons_[i][j] = nullptr;
        }
    }
}

void MainWindow::setupGameUi() {
    qDebug() << "Setting up game UI.";
    game_widget_ = new QWidget(this);
    QVBoxLayout* main_layout = new QVBoxLayout(game_widget_);

    QLabel* title_label = new QLabel("TIC TAC TOE", this);
    title_label->setAlignment(Qt::AlignCenter);
    title_label->setFont(QFont("Arial", 24, QFont::Bold));
    title_label->setStyleSheet("QLabel { color: #00FFFF; text-shadow: 0 0 10px #00FFFF, 0 0 20px #00FFFF; }");
    main_layout->addWidget(title_label);

    status_label_ = new QLabel(QString("MODE: %1").arg(is_player_vs_ai_ ? "VS AI" : "VS PLAYER"), this);
    status_label_->setAlignment(Qt::AlignCenter);
    status_label_->setStyleSheet("QLabel { color: #00FFFF; text-shadow: 0 0 10px #00FFFF; font-size: 16px; }");
    main_layout->addWidget(status_label_);

    QLabel* mode_label = new QLabel("SELECT A GAME MODE", this);
    mode_label->setAlignment(Qt::AlignCenter);
    mode_label->setStyleSheet("QLabel { color: #00FFFF; text-shadow: 0 0 10px #00FFFF; font-size: 16px; }");
    main_layout->addWidget(mode_label);

    QHBoxLayout* button_layout = new QHBoxLayout();
    QPushButton* vs_ai_button = new QPushButton("VS AI", this);
    vs_ai_button->setStyleSheet("QPushButton { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; font-size: 16px; }"
                                "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
    connect(vs_ai_button, &QPushButton::clicked, this, &MainWindow::selectPlayerVsAi);
    button_layout->addWidget(vs_ai_button);

    QPushButton* vs_player_button = new QPushButton("VS PLAYER", this);
    vs_player_button->setStyleSheet("QPushButton { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; font-size: 16px; }"
                                    "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
    connect(vs_player_button, &QPushButton::clicked, this, &MainWindow::selectPlayerVsPlayer);
    button_layout->addWidget(vs_player_button);

    QPushButton* restart_button = new QPushButton("RESTART", this);
    restart_button->setStyleSheet("QPushButton { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; font-size: 16px; }"
                                  "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
    connect(restart_button, &QPushButton::clicked, this, &MainWindow::handleRestart);
    button_layout->addWidget(restart_button);

    QPushButton* history_button = new QPushButton("HISTORY", this);
    history_button->setStyleSheet("QPushButton { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; font-size: 16px; }"
                                  "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
    connect(history_button, &QPushButton::clicked, this, &MainWindow::showHistoryScreen);
    button_layout->addWidget(history_button);

    QPushButton* logout_button = new QPushButton("LOGOUT", this);
    logout_button->setStyleSheet("QPushButton { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; font-size: 16px; }"
                                 "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
    connect(logout_button, &QPushButton::clicked, this, &MainWindow::showLoginScreen);
    button_layout->addWidget(logout_button);

    main_layout->addLayout(button_layout);

    resetButtons();

    QGridLayout* grid_layout = new QGridLayout();
    grid_layout->setSpacing(0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            buttons_[i][j] = new QPushButton("", this);
            buttons_[i][j]->setFixedSize(100, 100);
            buttons_[i][j]->setFont(QFont("Arial", 24));
            buttons_[i][j]->setStyleSheet("QPushButton { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; }"
                                          "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
            grid_layout->addWidget(buttons_[i][j], i, j);
            connect(buttons_[i][j], &QPushButton::clicked, this, [this, i, j]() { handleButtonClick(i, j); });
        }
    }
    main_layout->addLayout(grid_layout);

    game_widget_->setStyleSheet("background-color: transparent;");
}

void MainWindow::setupHistoryUi() {
    qDebug() << "Setting up history UI.";
    history_widget_ = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(history_widget_);

    QLabel* title_label = new QLabel("HISTORY", this);
    title_label->setAlignment(Qt::AlignCenter);
    title_label->setFont(QFont("Arial", 24, QFont::Bold));
    title_label->setStyleSheet("QLabel { color: #00FFFF; text-shadow: 0 0 10px #00FFFF, 0 0 20px #00FFFF; }");
    layout->addWidget(title_label);

    history_list_ = new QListWidget(this);
    history_list_->setStyleSheet("QListWidget { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; }"
                                 "QListWidget::item { padding: 5px; }"
                                 "QListWidget::item:selected { background-color: rgba(0, 255, 255, 50); color: #00FFFF; box-shadow: 0 0 10px #00FFFF; }");
    connect(history_list_, &QListWidget::itemDoubleClicked, this, &MainWindow::replayGame);
    layout->addWidget(history_list_);

    QPushButton* back_button = new QPushButton("BACK TO GAME", this);
    back_button->setStyleSheet("QPushButton { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; border-radius: 5px; padding: 5px; font-size: 16px; }"
                               "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
    connect(back_button, &QPushButton::clicked, this, &MainWindow::showGameScreen);
    layout->addWidget(back_button);

    history_widget_->setStyleSheet("background-color: transparent;");
}

void MainWindow::handleLogin() {
    qDebug() << "Handling login.";
    QString username = username_input_->text();
    QString password = password_input_->text();
    if (user_.login(username, password)) {
        is_guest_mode_ = false;
        showModeSelectionScreen();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

void MainWindow::handleRegister() {
    qDebug() << "Handling register.";
    QString username = register_username_input_->text();
    QString password = register_password_input_->text();
    QString confirm_password = confirm_password_input_->text();

    if (password != confirm_password) {
        QMessageBox::warning(this, "Registration Failed", "Passwords do not match.");
        return;
    }

    if (user_.registerUser(username, password)) {
        QMessageBox::information(this, "Success", "User registered successfully. Please login.");
        showLoginScreen();
    } else {
        QMessageBox::warning(this, "Registration Failed", "Username already exists or invalid input.");
    }
}

void MainWindow::handlePlayAsGuest() {
    qDebug() << "Handling play as guest.";
    is_guest_mode_ = true;
    user_.logout();
    showModeSelectionScreen();
}

void MainWindow::handleClearLogin() {
    qDebug() << "Handling clear login.";
    username_input_->clear();
    password_input_->clear();
}

void MainWindow::handleCancelRegister() {
    qDebug() << "Handling cancel register.";
    showLoginScreen();
}

void MainWindow::handleRestart() {
    qDebug() << "Handling restart.";
    resetGame();
}

void MainWindow::updatePasswordStrength() {
    QString password = register_password_input_->text();
    QString strength;
    QColor color;

    if (password.length() < 6) {
        strength = "WEAK";
        color = QColor("#FF4040");
    } else if (password.length() < 10) {
        strength = "MEDIUM";
        color = QColor("#FFFF00");
    } else {
        strength = "STRONG";
        color = QColor("#00FF00");
    }

    password_strength_label_->setText(strength);
    password_strength_label_->setStyleSheet(QString("QLabel { color: %1; text-shadow: 0 0 10px %1; }").arg(color.name()));
}

void MainWindow::selectPlayerVsAi() {
    qDebug() << "Selected Player vs AI mode.";
    is_player_vs_ai_ = true;
    player_x_name_ = player_x_input_->text().isEmpty() ? "Player X" : player_x_input_->text();
    player_o_name_ = "AI";
    showGameScreen();
}

void MainWindow::selectPlayerVsPlayer() {
    qDebug() << "Selected Player vs Player mode.";
    is_player_vs_ai_ = false;
    player_x_name_ = player_x_input_->text().isEmpty() ? "Player X" : player_x_input_->text();
    player_o_name_ = player_o_input_->text().isEmpty() ? "Player O" : player_o_input_->text();
    showGameScreen();
}

void MainWindow::showSplashScreen() {
    qDebug() << "Showing splash screen.";
    if (splash_widget_) {
        delete splash_widget_;
    }
    setupSplashScreenUi();
    setCentralWidget(splash_widget_);
}

void MainWindow::showLoginScreen() {
    qDebug() << "Showing login screen.";
    if (login_widget_) {
        delete login_widget_;
        login_widget_ = nullptr;
    }
    if (register_widget_) {
        delete register_widget_;
        register_widget_ = nullptr;
    }
    if (game_widget_) {
        delete game_widget_;
        game_widget_ = nullptr;
    }
    if (history_widget_) {
        delete history_widget_;
        history_widget_ = nullptr;
    }
    if (mode_selection_widget_) {
        delete mode_selection_widget_;
        mode_selection_widget_ = nullptr;
    }
    setupLoginUi();
    user_.logout();
    setCentralWidget(login_widget_);
    username_input_->clear();
    password_input_->clear();
}

void MainWindow::showRegisterScreen() {
    qDebug() << "Showing register screen.";
    if (register_widget_) {
        delete register_widget_;
        register_widget_ = nullptr;
    }
    if (login_widget_) {
        delete login_widget_;
        login_widget_ = nullptr;
    }
    if (game_widget_) {
        delete game_widget_;
        game_widget_ = nullptr;
    }
    if (history_widget_) {
        delete history_widget_;
        history_widget_ = nullptr;
    }
    if (mode_selection_widget_) {
        delete mode_selection_widget_;
        mode_selection_widget_ = nullptr;
    }
    setupRegisterUi();
    setCentralWidget(register_widget_);
}

void MainWindow::showModeSelectionScreen() {
    qDebug() << "Showing mode selection screen.";
    if (mode_selection_widget_) {
        delete mode_selection_widget_;
        mode_selection_widget_ = nullptr;
    }
    if (login_widget_) {
        delete login_widget_;
        login_widget_ = nullptr;
    }
    if (register_widget_) {
        delete register_widget_;
        register_widget_ = nullptr;
    }
    if (game_widget_) {
        delete game_widget_;
        game_widget_ = nullptr;
    }
    if (history_widget_) {
        delete history_widget_;
        history_widget_ = nullptr;
    }
    setupModeSelectionUi();
    setCentralWidget(mode_selection_widget_);
    player_x_input_->clear();
    player_o_input_->clear();
}

void MainWindow::showGameScreen() {
    qDebug() << "Showing game screen.";
    replay_timer_->stop();
    qDebug() << "Replay timer stopped.";
    if (game_widget_) {
        qDebug() << "Deleting existing game_widget_.";
        delete game_widget_;
        game_widget_ = nullptr;
    }
    if (history_widget_) {
        delete history_widget_;
        history_widget_ = nullptr;
    }
    if (mode_selection_widget_) {
        delete mode_selection_widget_;
        mode_selection_widget_ = nullptr;
    }
    setupGameUi();
    setCentralWidget(game_widget_);
    qDebug() << "Central widget set to game_widget_.";
    resetGame();
    qDebug() << "Game reset called.";
    updateBoard();
    qDebug() << "Board updated.";
}

void MainWindow::showHistoryScreen() {
    qDebug() << "Showing history screen.";
    if (is_guest_mode_) {
        QMessageBox::warning(this, "Access Denied", "History is not available in guest mode.");
        showGameScreen();
        return;
    }
    replay_timer_->stop();
    qDebug() << "Replay timer stopped.";
    if (history_widget_) {
        qDebug() << "Deleting existing history_widget_.";
        delete history_widget_;
        history_widget_ = nullptr;
    }
    if (game_widget_) {
        delete game_widget_;
        game_widget_ = nullptr;
    }
    if (mode_selection_widget_) {
        delete mode_selection_widget_;
        mode_selection_widget_ = nullptr;
    }
    setupHistoryUi();
    history_list_->clear();
    qDebug() << "History list cleared.";
    history_list_->addItems(game_history_.getGames(user_.getUserId()));
    qDebug() << "History list populated.";
    setCentralWidget(history_widget_);
    qDebug() << "Central widget set to history_widget_.";
}

void MainWindow::replayGame(QListWidgetItem* item) {
    qDebug() << "Starting game replay.";
    int game_id = item->text().split(" ")[1].toInt();
    replay_moves_ = game_history_.getGameMoves(game_id);
    is_player_vs_ai_ = game_history_.isGamePlayerVsAi(game_id);
    player_x_name_ = game_history_.getPlayerXName(game_id);
    player_o_name_ = game_history_.getPlayerOName(game_id);
    replay_index_ = 0;
    game_board_.reset();
    if (game_widget_) {
        delete game_widget_;
        game_widget_ = nullptr;
    }
    setupGameUi();
    setCentralWidget(game_widget_);
    replay_timer_->start(1000);
    qDebug() << "Replay timer started.";
}

void MainWindow::replayStep() {
    qDebug() << "Replay step called.";
    if (replay_index_ >= replay_moves_.size()) {
        replay_timer_->stop();
        qDebug() << "Replay finished, timer stopped.";
        return;
    }

    auto move = replay_moves_[replay_index_++];
    game_board_.makeMove(move.first, move.second);
    updateBoard();
    qDebug() << "Replay step completed, move:" << replay_index_;
}

void MainWindow::handleButtonClick(int row, int col) {
    qDebug() << "Button clicked at row:" << row << "col:" << col;
    if (!user_.isLoggedIn() && !is_guest_mode_) {
        qDebug() << "Button click ignored: User not logged in and not in guest mode.";
        return;
    }
    if (replay_timer_->isActive()) {
        qDebug() << "Button click ignored: Replay timer active.";
        return;
    }

    if (!game_board_.makeMove(row, col)) {
        qDebug() << "Invalid move.";
        return;
    }
    updateBoard();
    checkGameStatus();

    if (is_player_vs_ai_ && !game_board_.checkWin('X') && !game_board_.isTie()) {
        int ai_row, ai_col;
        ai_player_.getBestMove(game_board_, ai_row, ai_col);
        game_board_.makeMove(ai_row, ai_col);
        updateBoard();
        checkGameStatus();
    }
}

void MainWindow::updateBoard() {
    qDebug() << "Updating board.";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!buttons_[i][j]) {
                qDebug() << "Error: Button at [" << i << "][" << j << "] is null!";
                return;
            }
            QString cell = QString(game_board_.getCell(i, j));
            buttons_[i][j]->setText(cell);
            if (cell == "X") {
                buttons_[i][j]->setStyleSheet("QPushButton { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; font-size: 24px; }"
                                              "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
            } else if (cell == "O") {
                buttons_[i][j]->setStyleSheet("QPushButton { background-color: #1C2526; color: #FF00FF; border: 2px solid #FF00FF; font-size: 24px; }"
                                              "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
            } else {
                buttons_[i][j]->setStyleSheet("QPushButton { background-color: #1C2526; color: #00FFFF; border: 2px solid #FF00FF; }"
                                              "QPushButton:hover { background-color: rgba(0, 255, 255, 50); box-shadow: 0 0 10px #00FFFF; }");
            }
        }
    }
    status_label_->setText(QString("MODE: %1").arg(is_player_vs_ai_ ? "VS AI" : "VS PLAYER"));
    qDebug() << "Board updated successfully.";
}

void MainWindow::checkGameStatus() {
    qDebug() << "Checking game status.";
    QString result;
    if (game_board_.checkWin('X')) {
        result = QString("%1 Wins").arg(player_x_name_);
        QMessageBox::information(this, "Game Over", result);
    } else if (game_board_.checkWin('O')) {
        result = QString("%1 Wins").arg(player_o_name_);
        QMessageBox::information(this, "Game Over", result);
    } else if (game_board_.isTie()) {
        result = "Tie";
        QMessageBox::information(this, "Game Over", result);
    }

    if (!result.isEmpty() && !is_guest_mode_) {
        game_history_.saveGame(user_.getUserId(), user_.getUsername(), player_x_name_, player_o_name_, result, game_board_.getMoves(), is_player_vs_ai_);
    }
    if (!result.isEmpty()) {
        resetGame();
    }
}

void MainWindow::resetGame() {
    qDebug() << "Resetting game.";
    game_board_.reset();
    updateBoard();
}
