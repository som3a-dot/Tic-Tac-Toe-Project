/********************************************************************************
** Form generated from reading UI file 'historywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYWINDOW_H
#define UI_HISTORYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HistoryWindow
{
public:
    QPushButton *replay_2_2;
    QPushButton *replay_2_0;
    QPushButton *replay_1_1;
    QPushButton *replay_0_0;
    QListWidget *historyList;
    QPushButton *replay_2_1;
    QPushButton *replay_0_1;
    QPushButton *replay_0_2;
    QPushButton *replayButton;
    QPushButton *clearHistoryButton_2;
    QPushButton *replay_1_2;
    QPushButton *replay_1_0;

    void setupUi(QDialog *HistoryWindow)
    {
        if (HistoryWindow->objectName().isEmpty())
            HistoryWindow->setObjectName("HistoryWindow");
        HistoryWindow->resize(612, 496);
        HistoryWindow->setStyleSheet(QString::fromUtf8("QDialog{\n"
"background-image: url(:/image/4599316.jpg);\n"
"}"));
        replay_2_2 = new QPushButton(HistoryWindow);
        replay_2_2->setObjectName("replay_2_2");
        replay_2_2->setGeometry(QRect(210, 390, 80, 80));
        QFont font;
        font.setPointSize(20);
        replay_2_2->setFont(font);
        replay_2_0 = new QPushButton(HistoryWindow);
        replay_2_0->setObjectName("replay_2_0");
        replay_2_0->setGeometry(QRect(10, 390, 80, 80));
        replay_2_0->setFont(font);
        replay_1_1 = new QPushButton(HistoryWindow);
        replay_1_1->setObjectName("replay_1_1");
        replay_1_1->setGeometry(QRect(110, 300, 80, 80));
        replay_1_1->setFont(font);
        replay_0_0 = new QPushButton(HistoryWindow);
        replay_0_0->setObjectName("replay_0_0");
        replay_0_0->setGeometry(QRect(10, 210, 80, 80));
        replay_0_0->setFont(font);
        historyList = new QListWidget(HistoryWindow);
        historyList->setObjectName("historyList");
        historyList->setGeometry(QRect(10, 0, 571, 201));
        QFont font1;
        font1.setPointSize(12);
        historyList->setFont(font1);
        replay_2_1 = new QPushButton(HistoryWindow);
        replay_2_1->setObjectName("replay_2_1");
        replay_2_1->setGeometry(QRect(110, 390, 80, 80));
        replay_2_1->setFont(font);
        replay_0_1 = new QPushButton(HistoryWindow);
        replay_0_1->setObjectName("replay_0_1");
        replay_0_1->setGeometry(QRect(110, 210, 80, 80));
        replay_0_1->setFont(font);
        replay_0_2 = new QPushButton(HistoryWindow);
        replay_0_2->setObjectName("replay_0_2");
        replay_0_2->setGeometry(QRect(210, 210, 80, 80));
        replay_0_2->setFont(font);
        replayButton = new QPushButton(HistoryWindow);
        replayButton->setObjectName("replayButton");
        replayButton->setGeometry(QRect(330, 220, 181, 71));
        QFont font2;
        replayButton->setFont(font2);
        replayButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        replayButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{ \n"
"background-color: teal;\n"
"      color: white;\n"
"        font-size: 20px;\n"
"        border-radius: 30px;\n"
"        padding: 10px 20px\n"
"}"));
        clearHistoryButton_2 = new QPushButton(HistoryWindow);
        clearHistoryButton_2->setObjectName("clearHistoryButton_2");
        clearHistoryButton_2->setGeometry(QRect(330, 300, 181, 71));
        clearHistoryButton_2->setFont(font2);
        clearHistoryButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        clearHistoryButton_2->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{ \n"
"background-color: teal;\n"
"      color: white;\n"
"        font-size: 20px;\n"
"        border-radius: 30px;\n"
"        padding: 10px 20px\n"
"}"));
        replay_1_2 = new QPushButton(HistoryWindow);
        replay_1_2->setObjectName("replay_1_2");
        replay_1_2->setGeometry(QRect(210, 300, 80, 80));
        replay_1_2->setFont(font);
        replay_1_0 = new QPushButton(HistoryWindow);
        replay_1_0->setObjectName("replay_1_0");
        replay_1_0->setGeometry(QRect(10, 300, 80, 80));
        replay_1_0->setFont(font);

        retranslateUi(HistoryWindow);

        QMetaObject::connectSlotsByName(HistoryWindow);
    } // setupUi

    void retranslateUi(QDialog *HistoryWindow)
    {
        HistoryWindow->setWindowTitle(QCoreApplication::translate("HistoryWindow", "Dialog", nullptr));
        replay_2_2->setText(QString());
        replay_2_0->setText(QString());
        replay_1_1->setText(QString());
        replay_0_0->setText(QString());
        replay_2_1->setText(QString());
        replay_0_1->setText(QString());
        replay_0_2->setText(QString());
        replayButton->setText(QCoreApplication::translate("HistoryWindow", "REPLAY", nullptr));
        clearHistoryButton_2->setText(QCoreApplication::translate("HistoryWindow", "CLEAR HISTORY", nullptr));
        replay_1_2->setText(QString());
        replay_1_0->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HistoryWindow: public Ui_HistoryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYWINDOW_H
