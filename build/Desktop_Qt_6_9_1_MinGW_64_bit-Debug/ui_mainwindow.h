/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *RegisterButton_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *clearButton_3;
    QLabel *label;
    QLabel *label_4;
    QPushButton *LoginButton;
    QPushButton *GuestButton_4;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1186, 629);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"background-image: url(:/image/4599316.jpg);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        RegisterButton_2 = new QPushButton(centralwidget);
        RegisterButton_2->setObjectName("RegisterButton_2");
        RegisterButton_2->setGeometry(QRect(10, 10, 250, 90));
        QFont font;
        RegisterButton_2->setFont(font);
        RegisterButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        RegisterButton_2->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{ \n"
"background-color: teal;\n"
"      color: white;\n"
"        font-size: 20px;\n"
"        border-radius: 30px;\n"
"        padding: 10px 20px\n"
"}"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(380, 170, 140, 33));
        QFont font1;
        font1.setPointSize(15);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color:black;\n"
"}"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(380, 200, 411, 51));
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background-image: url(:/image/4599316.jpg);\n"
"color:white\n"
"}"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(380, 270, 141, 33));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color:black;\n"
"}"));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(380, 300, 411, 51));
        lineEdit_2->setFont(font1);
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background-image: url(:/image/4599316.jpg);\n"
"color:white\n"
"}"));
        lineEdit_2->setEchoMode(QLineEdit::EchoMode::Password);
        clearButton_3 = new QPushButton(centralwidget);
        clearButton_3->setObjectName("clearButton_3");
        clearButton_3->setGeometry(QRect(380, 440, 411, 71));
        clearButton_3->setFont(font);
        clearButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        clearButton_3->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{ \n"
"background-color: teal;\n"
"      color: white;\n"
"        font-size: 20px;\n"
"        border-radius: 30px;\n"
"        padding: 10px 20px\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(400, 10, 361, 71));
        QFont font2;
        font2.setPointSize(40);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color:white\n"
"}"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(360, 80, 481, 41));
        QFont font3;
        font3.setPointSize(25);
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color:white\n"
"}"));
        LoginButton = new QPushButton(centralwidget);
        LoginButton->setObjectName("LoginButton");
        LoginButton->setGeometry(QRect(380, 360, 411, 71));
        LoginButton->setFont(font);
        LoginButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        LoginButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{ \n"
"background-color: teal;\n"
"      color: white;\n"
"        font-size: 20px;\n"
"        border-radius: 30px;\n"
"        padding: 10px 20px\n"
"}"));
        GuestButton_4 = new QPushButton(centralwidget);
        GuestButton_4->setObjectName("GuestButton_4");
        GuestButton_4->setGeometry(QRect(930, 10, 250, 90));
        GuestButton_4->setFont(font);
        GuestButton_4->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        GuestButton_4->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{ \n"
"background-color: teal;\n"
"      color: white;\n"
"        font-size: 20px;\n"
"        border-radius: 30px;\n"
"        padding: 10px 20px\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1186, 26));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        RegisterButton_2->setText(QCoreApplication::translate("MainWindow", "REGISTER", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "USERNAME :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "PASSWORD :", nullptr));
        clearButton_3->setText(QCoreApplication::translate("MainWindow", "CLEAR", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TIC TAK TOE", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "WELCOME TO THE GAME", nullptr));
        LoginButton->setText(QCoreApplication::translate("MainWindow", "LOGIN", nullptr));
        GuestButton_4->setText(QCoreApplication::translate("MainWindow", "PLAY AS GUEST", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
