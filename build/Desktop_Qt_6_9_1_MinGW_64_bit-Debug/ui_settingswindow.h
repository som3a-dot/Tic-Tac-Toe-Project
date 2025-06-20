/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *switchaccountButton_3;
    QLabel *label;
    QPushButton *historyButton_2;
    QPushButton *exitButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName("SettingsWindow");
        SettingsWindow->resize(296, 279);
        SettingsWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"background-image: url(:/image/4599316.jpg);\n"
"}"));
        centralwidget = new QWidget(SettingsWindow);
        centralwidget->setObjectName("centralwidget");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 190, 191, 21));
        QFont font;
        font.setPointSize(13);
        label_4->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 140, 91, 21));
        label_3->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 90, 51, 31));
        label_2->setFont(font);
        switchaccountButton_3 = new QPushButton(centralwidget);
        switchaccountButton_3->setObjectName("switchaccountButton_3");
        switchaccountButton_3->setGeometry(QRect(20, 180, 41, 41));
        QFont font1;
        font1.setPointSize(18);
        switchaccountButton_3->setFont(font1);
        switchaccountButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        switchaccountButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:teal;\n"
"border-radius:20px;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 10, 191, 61));
        QFont font2;
        font2.setPointSize(25);
        label->setFont(font2);
        historyButton_2 = new QPushButton(centralwidget);
        historyButton_2->setObjectName("historyButton_2");
        historyButton_2->setGeometry(QRect(20, 130, 41, 41));
        historyButton_2->setFont(font1);
        historyButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        historyButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:blue;\n"
"border-radius:20px;\n"
"}"));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(20, 80, 41, 41));
        exitButton->setFont(font1);
        exitButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:red;\n"
"border-radius:20px;\n"
"}"));
        SettingsWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SettingsWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 296, 26));
        SettingsWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SettingsWindow);
        statusbar->setObjectName("statusbar");
        SettingsWindow->setStatusBar(statusbar);

        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QCoreApplication::translate("SettingsWindow", "MainWindow", nullptr));
        label_4->setText(QCoreApplication::translate("SettingsWindow", "SWITCH ACCOUNT", nullptr));
        label_3->setText(QCoreApplication::translate("SettingsWindow", "HISTORY", nullptr));
        label_2->setText(QCoreApplication::translate("SettingsWindow", "EXIT", nullptr));
        switchaccountButton_3->setText(QCoreApplication::translate("SettingsWindow", "\360\237\224\204", nullptr));
        label->setText(QCoreApplication::translate("SettingsWindow", "SETTINGS", nullptr));
        historyButton_2->setText(QCoreApplication::translate("SettingsWindow", "\360\237\223\234", nullptr));
        exitButton->setText(QCoreApplication::translate("SettingsWindow", "\360\237\232\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
