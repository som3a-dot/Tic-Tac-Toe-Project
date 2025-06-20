/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QLabel *label_4;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *passwordStrengthLabel;
    QPushButton *registerButton;
    QLabel *label_5;
    QPushButton *cancelButton_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(961, 596);
        RegisterWindow->setStyleSheet(QString::fromUtf8("QDialog {\n"
"background-image: url(:/image/4599316.jpg);\n"
"}"));
        label_4 = new QLabel(RegisterWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(210, 340, 257, 33));
        QFont font;
        font.setPointSize(15);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("QLabel\n"
"{ \n"
"   color: white;\n"
"}"));
        label = new QLabel(RegisterWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(400, 10, 181, 44));
        QFont font1;
        font1.setPointSize(25);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"\n"
"color:white\n"
"}"));
        lineEdit_2 = new QLineEdit(RegisterWindow);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(210, 260, 591, 41));
        lineEdit_2->setFont(font);
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background-image: url(:/image/4599316.jpg);\n"
"color:white\n"
"}"));
        lineEdit_2->setEchoMode(QLineEdit::EchoMode::Password);
        label_2 = new QLabel(RegisterWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(260, 60, 491, 51));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white\n"
"}"));
        passwordStrengthLabel = new QLabel(RegisterWindow);
        passwordStrengthLabel->setObjectName("passwordStrengthLabel");
        passwordStrengthLabel->setGeometry(QRect(210, 310, 401, 20));
        registerButton = new QPushButton(RegisterWindow);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(210, 420, 281, 81));
        QFont font2;
        registerButton->setFont(font2);
        registerButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        registerButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{ \n"
"background-color: teal;\n"
"      color: white;\n"
"        font-size: 20px;\n"
"        border-radius: 30px;\n"
"        padding: 10px 20px\n"
"}"));
        label_5 = new QLabel(RegisterWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(210, 140, 140, 33));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("QLabel\n"
"{ \n"
"   color: white;\n"
"}"));
        cancelButton_2 = new QPushButton(RegisterWindow);
        cancelButton_2->setObjectName("cancelButton_2");
        cancelButton_2->setGeometry(QRect(500, 420, 311, 81));
        cancelButton_2->setFont(font2);
        cancelButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        cancelButton_2->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{ \n"
"background-color: teal;\n"
"      color: white;\n"
"        font-size: 20px;\n"
"        border-radius: 30px;\n"
"        padding: 10px 20px\n"
"}"));
        label_3 = new QLabel(RegisterWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(210, 220, 141, 33));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{ \n"
"   color: white;\n"
"}"));
        lineEdit_3 = new QLineEdit(RegisterWindow);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(210, 370, 591, 41));
        lineEdit_3->setFont(font);
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background-image: url(:/image/4599316.jpg);\n"
"color:white\n"
"}"));
        lineEdit_3->setEchoMode(QLineEdit::EchoMode::Password);
        lineEdit = new QLineEdit(RegisterWindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(210, 170, 591, 41));
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background-image: url(:/image/4599316.jpg);\n"
"color:white\n"
"}"));

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterWindow", "CONFIRM PASSWORD :", nullptr));
        label->setText(QCoreApplication::translate("RegisterWindow", "REGISTER", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterWindow", "CREATE A NEW ACCOUNT", nullptr));
        passwordStrengthLabel->setText(QString());
        registerButton->setText(QCoreApplication::translate("RegisterWindow", "REGISTER", nullptr));
        label_5->setText(QCoreApplication::translate("RegisterWindow", "USERNAME :", nullptr));
        cancelButton_2->setText(QCoreApplication::translate("RegisterWindow", "CANCEL", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterWindow", "PASSWORD :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
