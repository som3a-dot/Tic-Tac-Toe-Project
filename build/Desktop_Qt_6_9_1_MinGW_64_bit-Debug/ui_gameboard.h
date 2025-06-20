/********************************************************************************
** Form generated from reading UI file 'gameboard.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEBOARD_H
#define UI_GAMEBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameBoard
{
public:
    QWidget *centralwidget;
    QPushButton *button_0_2;
    QPushButton *button_0_1;
    QPushButton *button_2_0;
    QLabel *scoreLabel;
    QPushButton *ReturnButton;
    QPushButton *button_1_0;
    QPushButton *button_2_2;
    QPushButton *button_0_0;
    QPushButton *resetButton;
    QLabel *statusLabel;
    QPushButton *button_1_1;
    QPushButton *button_2_1;
    QPushButton *button_1_2;

    void setupUi(QMainWindow *GameBoard)
    {
        if (GameBoard->objectName().isEmpty())
            GameBoard->setObjectName("GameBoard");
        GameBoard->resize(1159, 682);
        GameBoard->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"background-image: url(:/image/4599316.jpg);\n"
"}"));
        centralwidget = new QWidget(GameBoard);
        centralwidget->setObjectName("centralwidget");
        button_0_2 = new QPushButton(centralwidget);
        button_0_2->setObjectName("button_0_2");
        button_0_2->setGeometry(QRect(710, 60, 300, 170));
        QFont font;
        font.setPointSize(40);
        button_0_2->setFont(font);
        button_0_1 = new QPushButton(centralwidget);
        button_0_1->setObjectName("button_0_1");
        button_0_1->setGeometry(QRect(410, 60, 300, 170));
        button_0_1->setFont(font);
        button_0_1->setStyleSheet(QString::fromUtf8(""));
        button_2_0 = new QPushButton(centralwidget);
        button_2_0->setObjectName("button_2_0");
        button_2_0->setGeometry(QRect(110, 400, 300, 170));
        button_2_0->setFont(font);
        scoreLabel = new QLabel(centralwidget);
        scoreLabel->setObjectName("scoreLabel");
        scoreLabel->setGeometry(QRect(570, 10, 441, 51));
        QFont font1;
        font1.setPointSize(15);
        scoreLabel->setFont(font1);
        scoreLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background-image: url(:/image/4599316.jpg);\n"
"color:white\n"
"}"));
        ReturnButton = new QPushButton(centralwidget);
        ReturnButton->setObjectName("ReturnButton");
        ReturnButton->setGeometry(QRect(550, 570, 461, 81));
        ReturnButton->setFont(font1);
        ReturnButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        ReturnButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/image/4599316.jpg);\n"
"color:white\n"
"}"));
        button_1_0 = new QPushButton(centralwidget);
        button_1_0->setObjectName("button_1_0");
        button_1_0->setGeometry(QRect(110, 230, 300, 170));
        button_1_0->setFont(font);
        button_2_2 = new QPushButton(centralwidget);
        button_2_2->setObjectName("button_2_2");
        button_2_2->setGeometry(QRect(710, 400, 300, 170));
        button_2_2->setFont(font);
        button_0_0 = new QPushButton(centralwidget);
        button_0_0->setObjectName("button_0_0");
        button_0_0->setGeometry(QRect(110, 60, 300, 170));
        button_0_0->setFont(font);
        button_0_0->setStyleSheet(QString::fromUtf8(""));
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(110, 570, 441, 81));
        resetButton->setFont(font1);
        resetButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        resetButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/image/4599316.jpg);\n"
"color:white\n"
"}"));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(110, 10, 451, 51));
        statusLabel->setFont(font1);
        statusLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background-image: url(:/image/4599316.jpg);\n"
"color:white\n"
"}"));
        button_1_1 = new QPushButton(centralwidget);
        button_1_1->setObjectName("button_1_1");
        button_1_1->setGeometry(QRect(410, 230, 300, 170));
        button_1_1->setFont(font);
        button_1_1->setStyleSheet(QString::fromUtf8(""));
        button_2_1 = new QPushButton(centralwidget);
        button_2_1->setObjectName("button_2_1");
        button_2_1->setGeometry(QRect(410, 400, 300, 170));
        button_2_1->setFont(font);
        button_1_2 = new QPushButton(centralwidget);
        button_1_2->setObjectName("button_1_2");
        button_1_2->setGeometry(QRect(710, 230, 300, 170));
        button_1_2->setFont(font);
        GameBoard->setCentralWidget(centralwidget);

        retranslateUi(GameBoard);

        QMetaObject::connectSlotsByName(GameBoard);
    } // setupUi

    void retranslateUi(QMainWindow *GameBoard)
    {
        GameBoard->setWindowTitle(QCoreApplication::translate("GameBoard", "MainWindow", nullptr));
        button_0_2->setText(QString());
        button_0_1->setText(QString());
        button_2_0->setText(QString());
        scoreLabel->setText(QCoreApplication::translate("GameBoard", "score", nullptr));
        ReturnButton->setText(QCoreApplication::translate("GameBoard", "RETURN MAIN WINDOW", nullptr));
        button_1_0->setText(QString());
        button_2_2->setText(QString());
        button_0_0->setText(QString());
        resetButton->setText(QCoreApplication::translate("GameBoard", "RESET", nullptr));
        statusLabel->setText(QCoreApplication::translate("GameBoard", "statusLabel", nullptr));
        button_1_1->setText(QString());
        button_2_1->setText(QString());
        button_1_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameBoard: public Ui_GameBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEBOARD_H
