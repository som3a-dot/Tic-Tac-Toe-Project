/********************************************************************************
** Form generated from reading UI file 'gamemodewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEMODEWINDOW_H
#define UI_GAMEMODEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameModeWindow
{
public:
    QWidget *centralwidget;
    QPushButton *settingButton;
    QPushButton *playerVsPlayer;
    QPushButton *playerVsAI;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GameModeWindow)
    {
        if (GameModeWindow->objectName().isEmpty())
            GameModeWindow->setObjectName("GameModeWindow");
        GameModeWindow->resize(591, 328);
        GameModeWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"background-image: url(:/image/4599316.jpg);\n"
"}"));
        centralwidget = new QWidget(GameModeWindow);
        centralwidget->setObjectName("centralwidget");
        settingButton = new QPushButton(centralwidget);
        settingButton->setObjectName("settingButton");
        settingButton->setGeometry(QRect(20, 30, 41, 41));
        QFont font;
        font.setPointSize(20);
        settingButton->setFont(font);
        settingButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        settingButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:teal;\n"
"border-radius:20px;\n"
"}"));
        playerVsPlayer = new QPushButton(centralwidget);
        playerVsPlayer->setObjectName("playerVsPlayer");
        playerVsPlayer->setGeometry(QRect(140, 80, 321, 81));
        QFont font1;
        font1.setPointSize(15);
        playerVsPlayer->setFont(font1);
        playerVsPlayer->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        playerVsPlayer->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:Crimson;\n"
"color:white;\n"
"border-radius:20px;\n"
"}"));
        playerVsAI = new QPushButton(centralwidget);
        playerVsAI->setObjectName("playerVsAI");
        playerVsAI->setGeometry(QRect(140, 170, 321, 81));
        playerVsAI->setFont(font1);
        playerVsAI->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        playerVsAI->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:SeaGreen;\n"
"color:white;\n"
"border-radius:20px;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 10, 521, 71));
        QFont font2;
        font2.setPointSize(25);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white\n"
"}"));
        GameModeWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GameModeWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 591, 26));
        GameModeWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(GameModeWindow);
        statusbar->setObjectName("statusbar");
        GameModeWindow->setStatusBar(statusbar);

        retranslateUi(GameModeWindow);

        QMetaObject::connectSlotsByName(GameModeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameModeWindow)
    {
        GameModeWindow->setWindowTitle(QCoreApplication::translate("GameModeWindow", "MainWindow", nullptr));
        settingButton->setText(QCoreApplication::translate("GameModeWindow", "\342\232\231", nullptr));
        playerVsPlayer->setText(QCoreApplication::translate("GameModeWindow", "\360\237\221\244vs\360\237\221\244PLAYER VS PLAYER", nullptr));
        playerVsAI->setText(QCoreApplication::translate("GameModeWindow", "\360\237\221\244\360\237\206\232\360\237\244\226 PLAYER VS AI", nullptr));
        label->setText(QCoreApplication::translate("GameModeWindow", "SELECT YOUR GAME MODE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameModeWindow: public Ui_GameModeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEMODEWINDOW_H
