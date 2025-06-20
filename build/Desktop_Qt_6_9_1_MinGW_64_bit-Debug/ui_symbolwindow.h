/********************************************************************************
** Form generated from reading UI file 'symbolwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYMBOLWINDOW_H
#define UI_SYMBOLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SymbolWindow
{
public:
    QWidget *centralwidget;
    QPushButton *xButton;
    QPushButton *oButton_2;
    QLabel *label;
    QMenuBar *menubar;

    void setupUi(QMainWindow *SymbolWindow)
    {
        if (SymbolWindow->objectName().isEmpty())
            SymbolWindow->setObjectName("SymbolWindow");
        SymbolWindow->resize(387, 284);
        SymbolWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"background-image: url(:/image/4599316.jpg);\n"
"}"));
        centralwidget = new QWidget(SymbolWindow);
        centralwidget->setObjectName("centralwidget");
        xButton = new QPushButton(centralwidget);
        xButton->setObjectName("xButton");
        xButton->setGeometry(QRect(30, 90, 331, 61));
        QFont font;
        font.setPointSize(25);
        xButton->setFont(font);
        xButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        xButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/image/4599316.jpg);\n"
"color:white\n"
"}"));
        oButton_2 = new QPushButton(centralwidget);
        oButton_2->setObjectName("oButton_2");
        oButton_2->setGeometry(QRect(30, 160, 331, 61));
        oButton_2->setFont(font);
        oButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        oButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(:/image/4599316.jpg);\n"
"color:white\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, -10, 381, 91));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"}"));
        SymbolWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SymbolWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 387, 26));
        SymbolWindow->setMenuBar(menubar);

        retranslateUi(SymbolWindow);

        QMetaObject::connectSlotsByName(SymbolWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SymbolWindow)
    {
        SymbolWindow->setWindowTitle(QCoreApplication::translate("SymbolWindow", "MainWindow", nullptr));
        xButton->setText(QCoreApplication::translate("SymbolWindow", "X", nullptr));
        oButton_2->setText(QCoreApplication::translate("SymbolWindow", "O", nullptr));
        label->setText(QCoreApplication::translate("SymbolWindow", "SELECT YOUR SYMBOL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SymbolWindow: public Ui_SymbolWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMBOLWINDOW_H
