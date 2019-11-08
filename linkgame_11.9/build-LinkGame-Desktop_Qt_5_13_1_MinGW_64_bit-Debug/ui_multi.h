/********************************************************************************
** Form generated from reading UI file 'multi.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTI_H
#define UI_MULTI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Multi
{
public:
    QTextBrowser *textBrowser1;
    QLabel *IPPort;
    QPushButton *pushButtonBackToMenu;
    QLabel *labelIP;
    QRadioButton *ClientButton;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonBuild;
    QPushButton *pushButtonConnect;
    QTextEdit *textEditPort;
    QRadioButton *HostButton;
    QTextBrowser *textBrowser2;
    QTextEdit *textEditIP;

    void setupUi(QWidget *Multi)
    {
        if (Multi->objectName().isEmpty())
            Multi->setObjectName(QString::fromUtf8("Multi"));
        Multi->resize(991, 582);
        textBrowser1 = new QTextBrowser(Multi);
        textBrowser1->setObjectName(QString::fromUtf8("textBrowser1"));
        textBrowser1->setGeometry(QRect(60, 70, 256, 192));
        IPPort = new QLabel(Multi);
        IPPort->setObjectName(QString::fromUtf8("IPPort"));
        IPPort->setGeometry(QRect(390, 320, 71, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Rockwell"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        IPPort->setFont(font);
        IPPort->setStyleSheet(QString::fromUtf8(""));
        pushButtonBackToMenu = new QPushButton(Multi);
        pushButtonBackToMenu->setObjectName(QString::fromUtf8("pushButtonBackToMenu"));
        pushButtonBackToMenu->setGeometry(QRect(790, 50, 141, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        pushButtonBackToMenu->setFont(font1);
        pushButtonBackToMenu->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); }"));
        labelIP = new QLabel(Multi);
        labelIP->setObjectName(QString::fromUtf8("labelIP"));
        labelIP->setGeometry(QRect(320, 280, 131, 30));
        labelIP->setFont(font);
        labelIP->setStyleSheet(QString::fromUtf8(""));
        ClientButton = new QRadioButton(Multi);
        ClientButton->setObjectName(QString::fromUtf8("ClientButton"));
        ClientButton->setGeometry(QRect(480, 230, 141, 31));
        ClientButton->setFont(font1);
        ClientButton->setContextMenuPolicy(Qt::DefaultContextMenu);
        ClientButton->setStyleSheet(QString::fromUtf8("QRadioButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QRadioButton:hover { background-color: rgb(0, 170, 255); }"));
        pushButtonStart = new QPushButton(Multi);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));
        pushButtonStart->setGeometry(QRect(480, 370, 141, 30));
        pushButtonStart->setFont(font1);
        pushButtonStart->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); } QPushButton:disabled { background-color: rgb(170, 170, 170); }"));
        pushButtonBuild = new QPushButton(Multi);
        pushButtonBuild->setObjectName(QString::fromUtf8("pushButtonBuild"));
        pushButtonBuild->setGeometry(QRect(790, 320, 141, 30));
        pushButtonBuild->setFont(font1);
        pushButtonBuild->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); } QPushButton:disabled { background-color: rgb(170, 170, 170); }"));
        pushButtonConnect = new QPushButton(Multi);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));
        pushButtonConnect->setGeometry(QRect(790, 280, 141, 30));
        pushButtonConnect->setFont(font1);
        pushButtonConnect->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); } QPushButton:disabled { background-color: rgb(170, 170, 170); }"));
        textEditPort = new QTextEdit(Multi);
        textEditPort->setObjectName(QString::fromUtf8("textEditPort"));
        textEditPort->setGeometry(QRect(480, 320, 141, 31));
        HostButton = new QRadioButton(Multi);
        HostButton->setObjectName(QString::fromUtf8("HostButton"));
        HostButton->setGeometry(QRect(480, 180, 141, 31));
        HostButton->setFont(font1);
        HostButton->setLayoutDirection(Qt::LeftToRight);
        HostButton->setAutoFillBackground(false);
        HostButton->setStyleSheet(QString::fromUtf8("QRadioButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QRadioButton:hover { background-color: rgb(0, 170, 255); }"));
        textBrowser2 = new QTextBrowser(Multi);
        textBrowser2->setObjectName(QString::fromUtf8("textBrowser2"));
        textBrowser2->setGeometry(QRect(60, 340, 256, 192));
        textEditIP = new QTextEdit(Multi);
        textEditIP->setObjectName(QString::fromUtf8("textEditIP"));
        textEditIP->setGeometry(QRect(480, 280, 141, 31));

        retranslateUi(Multi);

        QMetaObject::connectSlotsByName(Multi);
    } // setupUi

    void retranslateUi(QWidget *Multi)
    {
        Multi->setWindowTitle(QCoreApplication::translate("Multi", "Form", nullptr));
        IPPort->setText(QCoreApplication::translate("Multi", "Port:", nullptr));
        pushButtonBackToMenu->setText(QCoreApplication::translate("Multi", "BackToMenu", nullptr));
        labelIP->setText(QCoreApplication::translate("Multi", "IP Address:", nullptr));
        ClientButton->setText(QCoreApplication::translate("Multi", "Play as client", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("Multi", "Start!", nullptr));
        pushButtonBuild->setText(QCoreApplication::translate("Multi", "Build", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("Multi", "Connect", nullptr));
        HostButton->setText(QCoreApplication::translate("Multi", "Play as host", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Multi: public Ui_Multi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTI_H
