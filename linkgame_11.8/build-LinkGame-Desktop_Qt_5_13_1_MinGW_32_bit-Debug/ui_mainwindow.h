/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelBGM;
    QPushButton *pushButtonOn;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonSettings;
    QPushButton *pushButtonQuit;
    QPushButton *pushButtonBackToMenu;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1148, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labelBGM = new QLabel(centralwidget);
        labelBGM->setObjectName(QString::fromUtf8("labelBGM"));
        labelBGM->setGeometry(QRect(400, 150, 71, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Rockwell"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelBGM->setFont(font);
        labelBGM->setStyleSheet(QString::fromUtf8(""));
        pushButtonOn = new QPushButton(centralwidget);
        pushButtonOn->setObjectName(QString::fromUtf8("pushButtonOn"));
        pushButtonOn->setGeometry(QRect(550, 150, 100, 28));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        pushButtonOn->setFont(font1);
        pushButtonOn->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); }"));
        pushButtonStart = new QPushButton(centralwidget);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));
        pushButtonStart->setGeometry(QRect(550, 193, 100, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        pushButtonStart->setFont(font2);
        pushButtonStart->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); }"));
        pushButtonSettings = new QPushButton(centralwidget);
        pushButtonSettings->setObjectName(QString::fromUtf8("pushButtonSettings"));
        pushButtonSettings->setGeometry(QRect(550, 251, 100, 30));
        pushButtonSettings->setFont(font2);
        pushButtonSettings->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); }"));
        pushButtonQuit = new QPushButton(centralwidget);
        pushButtonQuit->setObjectName(QString::fromUtf8("pushButtonQuit"));
        pushButtonQuit->setGeometry(QRect(550, 309, 100, 30));
        pushButtonQuit->setFont(font2);
        pushButtonQuit->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); }"));
        pushButtonBackToMenu = new QPushButton(centralwidget);
        pushButtonBackToMenu->setObjectName(QString::fromUtf8("pushButtonBackToMenu"));
        pushButtonBackToMenu->setGeometry(QRect(900, 50, 121, 30));
        pushButtonBackToMenu->setFont(font2);
        pushButtonBackToMenu->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); }"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1148, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelBGM->setText(QCoreApplication::translate("MainWindow", "BGM\357\274\232", nullptr));
        pushButtonOn->setText(QCoreApplication::translate("MainWindow", "OFF", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButtonSettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        pushButtonQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        pushButtonBackToMenu->setText(QCoreApplication::translate("MainWindow", "BackToMenu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
