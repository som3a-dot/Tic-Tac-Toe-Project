#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_switchaccountButton_3_clicked();
    void on_historyButton_2_clicked();
    void on_exitButton_clicked();

public:
    explicit SettingsWindow(const QString &username = "", QWidget *parent = nullptr);
    ~SettingsWindow();

private:
    Ui::SettingsWindow *ui;
    MainWindow *mainWindow;
    QString username;
};

#endif // SETTINGSWINDOW_H
