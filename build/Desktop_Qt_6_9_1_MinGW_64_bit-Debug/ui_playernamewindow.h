/********************************************************************************
** Form generated from reading UI file 'playernamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERNAMEWINDOW_H
#define UI_PLAYERNAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerNameWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *clearButton;
    QLineEdit *lineEditPlayer2;
    QPushButton *okButton_2;
    QLabel *label_3;
    QLineEdit *lineEditPlayer1;
    QMenuBar *menubar;

    void setupUi(QMainWindow *PlayerNameWindow)
    {
        if (PlayerNameWindow->objectName().isEmpty())
            PlayerNameWindow->setObjectName("PlayerNameWindow");
        PlayerNameWindow->resize(591, 393);
        PlayerNameWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"background-image: url(:/image/4599316.jpg);\n"
"}"));
        centralwidget = new QWidget(PlayerNameWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(100, -20, 451, 121));
        QFont font;
        font.setPointSize(25);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white\n"
"}"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 110, 141, 51));
        QFont font1;
        font1.setPointSize(15);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white\n"
"}"));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(340, 260, 171, 61));
        QFont font2;
        font2.setPointSize(20);
        clearButton->setFont(font2);
        clearButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        clearButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/image/4599316.jpg);\n"
"color:white\n"
"}"));
        lineEditPlayer2 = new QLineEdit(centralwidget);
        lineEditPlayer2->setObjectName("lineEditPlayer2");
        lineEditPlayer2->setGeometry(QRect(170, 190, 341, 41));
        lineEditPlayer2->setFont(font1);
        lineEditPlayer2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-image: url(:/image/4599316.jpg);\n"
"color:white\n"
"}"));
        okButton_2 = new QPushButton(centralwidget);
        okButton_2->setObjectName("okButton_2");
        okButton_2->setGeometry(QRect(150, 260, 171, 61));
        okButton_2->setFont(font2);
        okButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        okButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/image/4599316.jpg);\n"
"color:white\n"
"}"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 180, 151, 51));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white\n"
"}"));
        lineEditPlayer1 = new QLineEdit(centralwidget);
        lineEditPlayer1->setObjectName("lineEditPlayer1");
        lineEditPlayer1->setGeometry(QRect(170, 120, 341, 41));
        lineEditPlayer1->setFont(font1);
        lineEditPlayer1->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-image: url(:/image/4599316.jpg);\n"
"color:white\n"
"}"));
        PlayerNameWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlayerNameWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 591, 26));
        PlayerNameWindow->setMenuBar(menubar);

        retranslateUi(PlayerNameWindow);

        QMetaObject::connectSlotsByName(PlayerNameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PlayerNameWindow)
    {
        PlayerNameWindow->setWindowTitle(QCoreApplication::translate("PlayerNameWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("PlayerNameWindow", "SELECT PLAYER NAMES", nullptr));
        label_2->setText(QCoreApplication::translate("PlayerNameWindow", "player (1) X :", nullptr));
        clearButton->setText(QCoreApplication::translate("PlayerNameWindow", "CLEAR", nullptr));
        lineEditPlayer2->setText(QCoreApplication::translate("PlayerNameWindow", "player2", nullptr));
        okButton_2->setText(QCoreApplication::translate("PlayerNameWindow", "OK", nullptr));
        label_3->setText(QCoreApplication::translate("PlayerNameWindow", "player (2) O :", nullptr));
        lineEditPlayer1->setText(QCoreApplication::translate("PlayerNameWindow", "player1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerNameWindow: public Ui_PlayerNameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERNAMEWINDOW_H
