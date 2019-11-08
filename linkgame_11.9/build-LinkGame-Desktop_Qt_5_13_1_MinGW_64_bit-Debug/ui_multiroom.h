/********************************************************************************
** Form generated from reading UI file 'multiroom.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIROOM_H
#define UI_MULTIROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MultiRoom
{
public:
    QRadioButton *HostButton;
    QRadioButton *ClientButton;
    QTextEdit *textEditIP;
    QTextEdit *textEditPort;
    QPushButton *pushButtonBuild;
    QPushButton *pushButtonConnect;
    QPushButton *pushButtonStart;
    QLabel *IPPort;
    QLabel *labelIP;
    QPushButton *pushButtonBackToMenu;
    QTextBrowser *textBrowser1;
    QTextBrowser *textBrowser2;

    void setupUi(QWidget *MultiRoom)
    {
        if (MultiRoom->objectName().isEmpty())
            MultiRoom->setObjectName(QString::fromUtf8("MultiRoom"));
        MultiRoom->resize(967, 563);
        HostButton = new QRadioButton(MultiRoom);
        HostButton->setObjectName(QString::fromUtf8("HostButton"));
        HostButton->setGeometry(QRect(440, 160, 141, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        HostButton->setFont(font);
        HostButton->setLayoutDirection(Qt::LeftToRight);
        HostButton->setAutoFillBackground(false);
        HostButton->setStyleSheet(QString::fromUtf8("QRadioButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QRadioButton:hover { background-color: rgb(0, 170, 255); }"));
        ClientButton = new QRadioButton(MultiRoom);
        ClientButton->setObjectName(QString::fromUtf8("ClientButton"));
        ClientButton->setGeometry(QRect(440, 210, 141, 31));
        ClientButton->setFont(font);
        ClientButton->setContextMenuPolicy(Qt::DefaultContextMenu);
        ClientButton->setStyleSheet(QString::fromUtf8("QRadioButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QRadioButton:hover { background-color: rgb(0, 170, 255); }"));
        textEditIP = new QTextEdit(MultiRoom);
        textEditIP->setObjectName(QString::fromUtf8("textEditIP"));
        textEditIP->setGeometry(QRect(440, 260, 141, 31));
        textEditPort = new QTextEdit(MultiRoom);
        textEditPort->setObjectName(QString::fromUtf8("textEditPort"));
        textEditPort->setGeometry(QRect(440, 300, 141, 31));
        pushButtonBuild = new QPushButton(MultiRoom);
        pushButtonBuild->setObjectName(QString::fromUtf8("pushButtonBuild"));
        pushButtonBuild->setGeometry(QRect(750, 300, 141, 30));
        pushButtonBuild->setFont(font);
        pushButtonBuild->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); } QPushButton:disabled { background-color: rgb(170, 170, 170); }"));
        pushButtonConnect = new QPushButton(MultiRoom);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));
        pushButtonConnect->setGeometry(QRect(750, 260, 141, 30));
        pushButtonConnect->setFont(font);
        pushButtonConnect->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); } QPushButton:disabled { background-color: rgb(170, 170, 170); }"));
        pushButtonStart = new QPushButton(MultiRoom);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));
        pushButtonStart->setGeometry(QRect(440, 350, 141, 30));
        pushButtonStart->setFont(font);
        pushButtonStart->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); } QPushButton:disabled { background-color: rgb(170, 170, 170); }"));
        IPPort = new QLabel(MultiRoom);
        IPPort->setObjectName(QString::fromUtf8("IPPort"));
        IPPort->setGeometry(QRect(350, 300, 71, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Rockwell"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        IPPort->setFont(font1);
        IPPort->setStyleSheet(QString::fromUtf8(""));
        labelIP = new QLabel(MultiRoom);
        labelIP->setObjectName(QString::fromUtf8("labelIP"));
        labelIP->setGeometry(QRect(280, 260, 131, 30));
        labelIP->setFont(font1);
        labelIP->setStyleSheet(QString::fromUtf8(""));
        pushButtonBackToMenu = new QPushButton(MultiRoom);
        pushButtonBackToMenu->setObjectName(QString::fromUtf8("pushButtonBackToMenu"));
        pushButtonBackToMenu->setGeometry(QRect(750, 30, 141, 30));
        pushButtonBackToMenu->setFont(font);
        pushButtonBackToMenu->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); }"));
        textBrowser1 = new QTextBrowser(MultiRoom);
        textBrowser1->setObjectName(QString::fromUtf8("textBrowser1"));
        textBrowser1->setGeometry(QRect(20, 50, 256, 192));
        textBrowser2 = new QTextBrowser(MultiRoom);
        textBrowser2->setObjectName(QString::fromUtf8("textBrowser2"));
        textBrowser2->setGeometry(QRect(20, 320, 256, 192));

        retranslateUi(MultiRoom);

        QMetaObject::connectSlotsByName(MultiRoom);
    } // setupUi

    void retranslateUi(QWidget *MultiRoom)
    {
        MultiRoom->setWindowTitle(QCoreApplication::translate("MultiRoom", "Form", nullptr));
        HostButton->setText(QCoreApplication::translate("MultiRoom", "Play as host", nullptr));
        ClientButton->setText(QCoreApplication::translate("MultiRoom", "Play as client", nullptr));
        pushButtonBuild->setText(QCoreApplication::translate("MultiRoom", "Build", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("MultiRoom", "Connect", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("MultiRoom", "Start!", nullptr));
        IPPort->setText(QCoreApplication::translate("MultiRoom", "Port:", nullptr));
        labelIP->setText(QCoreApplication::translate("MultiRoom", "IP Address:", nullptr));
        pushButtonBackToMenu->setText(QCoreApplication::translate("MultiRoom", "BackToMenu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MultiRoom: public Ui_MultiRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIROOM_H
