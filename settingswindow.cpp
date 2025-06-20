#include "settingswindow.h"
#include "ui_settingswindow.h"
#include <QApplication>
#include "historywindow.h"

SettingsWindow::SettingsWindow(const QString &username, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingsWindow),
    mainWindow(nullptr),
    username(username)
{
    ui->setupUi(this);
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
    delete mainWindow;
}

void SettingsWindow::on_switchaccountButton_3_clicked()
{
    if (!mainWindow) {
        mainWindow = new MainWindow(nullptr);
    }
    mainWindow->show();
    this->close(); //
}

void SettingsWindow::on_historyButton_2_clicked()
{
    historywindow *historyWindow = new historywindow(username, nullptr);
    historyWindow->show();
}

void SettingsWindow::on_exitButton_clicked()
{
    QApplication::quit();
}

void SettingsWindow::on_backButton_clicked()
{
    emit back();
    this->hide();
}

