/********************************************************************************
** Form generated from reading UI file 'game3d.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME3D_H
#define UI_GAME3D_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game3d
{
public:
    QPushButton *pushButtonPause;
    QProgressBar *progressBarTimer;
    QPushButton *pushButtonBackToMenu;
    QPushButton *pushButtonCheat;

    void setupUi(QWidget *Game3d)
    {
        if (Game3d->objectName().isEmpty())
            Game3d->setObjectName(QString::fromUtf8("Game3d"));
        Game3d->resize(1106, 574);
        pushButtonPause = new QPushButton(Game3d);
        pushButtonPause->setObjectName(QString::fromUtf8("pushButtonPause"));
        pushButtonPause->setGeometry(QRect(120, 41, 100, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        pushButtonPause->setFont(font);
        pushButtonPause->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); }"));
        progressBarTimer = new QProgressBar(Game3d);
        progressBarTimer->setObjectName(QString::fromUtf8("progressBarTimer"));
        progressBarTimer->setGeometry(QRect(370, 41, 500, 30));
        progressBarTimer->setMaximum(60);
        progressBarTimer->setValue(60);
        progressBarTimer->setTextVisible(false);
        pushButtonBackToMenu = new QPushButton(Game3d);
        pushButtonBackToMenu->setObjectName(QString::fromUtf8("pushButtonBackToMenu"));
        pushButtonBackToMenu->setGeometry(QRect(920, 40, 121, 30));
        pushButtonBackToMenu->setFont(font);
        pushButtonBackToMenu->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); }"));
        pushButtonCheat = new QPushButton(Game3d);
        pushButtonCheat->setObjectName(QString::fromUtf8("pushButtonCheat"));
        pushButtonCheat->setGeometry(QRect(570, 10, 100, 30));
        pushButtonCheat->setFont(font);
        pushButtonCheat->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); }"));

        retranslateUi(Game3d);

        QMetaObject::connectSlotsByName(Game3d);
    } // setupUi

    void retranslateUi(QWidget *Game3d)
    {
        Game3d->setWindowTitle(QCoreApplication::translate("Game3d", "Form", nullptr));
        pushButtonPause->setText(QCoreApplication::translate("Game3d", "Pause", nullptr));
        progressBarTimer->setFormat(QCoreApplication::translate("Game3d", "%p sec", nullptr));
        pushButtonBackToMenu->setText(QCoreApplication::translate("Game3d", "BackToMenu", nullptr));
        pushButtonCheat->setText(QCoreApplication::translate("Game3d", "Cheat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game3d: public Ui_Game3d {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME3D_H
