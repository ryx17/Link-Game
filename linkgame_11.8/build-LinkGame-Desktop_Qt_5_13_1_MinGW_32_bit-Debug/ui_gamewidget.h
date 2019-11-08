/********************************************************************************
** Form generated from reading UI file 'gamewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGET_H
#define UI_GAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWidget
{
public:
    QPushButton *pushButtonPause;
    QProgressBar *progressBarTimer;
    QPushButton *pushButtonBackToMenu;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName(QString::fromUtf8("GameWidget"));
        GameWidget->resize(961, 111);
        pushButtonPause = new QPushButton(GameWidget);
        pushButtonPause->setObjectName(QString::fromUtf8("pushButtonPause"));
        pushButtonPause->setGeometry(QRect(70, 41, 100, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        pushButtonPause->setFont(font);
        pushButtonPause->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); }"));
        progressBarTimer = new QProgressBar(GameWidget);
        progressBarTimer->setObjectName(QString::fromUtf8("progressBarTimer"));
        progressBarTimer->setGeometry(QRect(220, 41, 500, 30));
        progressBarTimer->setMaximum(60);
        progressBarTimer->setValue(60);
        progressBarTimer->setTextVisible(false);
        pushButtonBackToMenu = new QPushButton(GameWidget);
        pushButtonBackToMenu->setObjectName(QString::fromUtf8("pushButtonBackToMenu"));
        pushButtonBackToMenu->setGeometry(QRect(770, 40, 121, 30));
        pushButtonBackToMenu->setFont(font);
        pushButtonBackToMenu->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); }"));

        retranslateUi(GameWidget);

        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        GameWidget->setWindowTitle(QCoreApplication::translate("GameWidget", "Form", nullptr));
        pushButtonPause->setText(QCoreApplication::translate("GameWidget", "Pause", nullptr));
        progressBarTimer->setFormat(QCoreApplication::translate("GameWidget", "%p sec", nullptr));
        pushButtonBackToMenu->setText(QCoreApplication::translate("GameWidget", "BackToMenu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
