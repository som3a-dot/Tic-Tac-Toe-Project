/********************************************************************************
** Form generated from reading UI file 'aidifficultywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIDIFFICULTYWINDOW_H
#define UI_AIDIFFICULTYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AIDifficultyWindow
{
public:
    QWidget *centralwidget;
    QPushButton *mediumButton;
    QLabel *label;
    QPushButton *hardButton;
    QPushButton *easyButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AIDifficultyWindow)
    {
        if (AIDifficultyWindow->objectName().isEmpty())
            AIDifficultyWindow->setObjectName("AIDifficultyWindow");
        AIDifficultyWindow->resize(552, 403);
        AIDifficultyWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"background-image: url(:/image/4599316.jpg);\n"
"}"));
        centralwidget = new QWidget(AIDifficultyWindow);
        centralwidget->setObjectName("centralwidget");
        mediumButton = new QPushButton(centralwidget);
        mediumButton->setObjectName("mediumButton");
        mediumButton->setGeometry(QRect(70, 170, 401, 71));
        QFont font;
        mediumButton->setFont(font);
        mediumButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        mediumButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{ \n"
"background-color: gold;\n"
"      color: white;\n"
"        font-size: 20px;\n"
"        border-radius: 30px;\n"
"        padding: 10px 20px\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(60, -10, 531, 101));
        QFont font1;
        font1.setPointSize(25);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"}"));
        hardButton = new QPushButton(centralwidget);
        hardButton->setObjectName("hardButton");
        hardButton->setGeometry(QRect(70, 250, 401, 71));
        hardButton->setFont(font);
        hardButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        hardButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{ \n"
"background-color: red;\n"
"      color: white;\n"
"        font-size: 20px;\n"
"        border-radius: 30px;\n"
"        padding: 10px 20px\n"
"}"));
        easyButton = new QPushButton(centralwidget);
        easyButton->setObjectName("easyButton");
        easyButton->setGeometry(QRect(70, 90, 401, 71));
        easyButton->setFont(font);
        easyButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        easyButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{ \n"
"background-color: green;\n"
"      color: white;\n"
"        font-size: 20px;\n"
"        border-radius: 30px;\n"
"        padding: 10px 20px\n"
"}"));
        AIDifficultyWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AIDifficultyWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 552, 26));
        AIDifficultyWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AIDifficultyWindow);
        statusbar->setObjectName("statusbar");
        AIDifficultyWindow->setStatusBar(statusbar);

        retranslateUi(AIDifficultyWindow);

        QMetaObject::connectSlotsByName(AIDifficultyWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AIDifficultyWindow)
    {
        AIDifficultyWindow->setWindowTitle(QCoreApplication::translate("AIDifficultyWindow", "MainWindow", nullptr));
        mediumButton->setText(QCoreApplication::translate("AIDifficultyWindow", "MEDIUM", nullptr));
        label->setText(QCoreApplication::translate("AIDifficultyWindow", "SELECT YOUR AI DIFFICULTY", nullptr));
        hardButton->setText(QCoreApplication::translate("AIDifficultyWindow", "HARD", nullptr));
        easyButton->setText(QCoreApplication::translate("AIDifficultyWindow", "EASY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AIDifficultyWindow: public Ui_AIDifficultyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIDIFFICULTYWINDOW_H
