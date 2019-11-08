/********************************************************************************
** Form generated from reading UI file 'multiplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIPLAYER_H
#define UI_MULTIPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Multiplayer
{
public:
    QPushButton *pushButtonBackToMenu;
    QProgressBar *progressBarTimer;
    QProgressBar *progressBarTimer_Opp;
    QLabel *labeltime;
    QLabel *labeltime_Opp;
    QProgressBar *progressBarProgess;
    QProgressBar *progressBarProgess_Opp;
    QPushButton *pushButtonCheat;
    QLabel *labelprog;
    QLabel *labelprog_Opp;
    QLabel *labellose;
    QLabel *labellose2;

    void setupUi(QWidget *Multiplayer)
    {
        if (Multiplayer->objectName().isEmpty())
            Multiplayer->setObjectName(QString::fromUtf8("Multiplayer"));
        Multiplayer->resize(1122, 691);
        pushButtonBackToMenu = new QPushButton(Multiplayer);
        pushButtonBackToMenu->setObjectName(QString::fromUtf8("pushButtonBackToMenu"));
        pushButtonBackToMenu->setGeometry(QRect(720, 50, 121, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        pushButtonBackToMenu->setFont(font);
        pushButtonBackToMenu->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); }"));
        progressBarTimer = new QProgressBar(Multiplayer);
        progressBarTimer->setObjectName(QString::fromUtf8("progressBarTimer"));
        progressBarTimer->setGeometry(QRect(50, 50, 641, 30));
        progressBarTimer->setStyleSheet(QString::fromUtf8(""));
        progressBarTimer->setMaximum(60);
        progressBarTimer->setValue(60);
        progressBarTimer->setTextVisible(false);
        progressBarTimer_Opp = new QProgressBar(Multiplayer);
        progressBarTimer_Opp->setObjectName(QString::fromUtf8("progressBarTimer_Opp"));
        progressBarTimer_Opp->setGeometry(QRect(50, 110, 641, 30));
        progressBarTimer_Opp->setStyleSheet(QString::fromUtf8("QProgressBar::chunk {   background-color: #05B8CC; }"));
        progressBarTimer_Opp->setMaximum(60);
        progressBarTimer_Opp->setValue(60);
        progressBarTimer_Opp->setTextVisible(false);
        labeltime = new QLabel(Multiplayer);
        labeltime->setObjectName(QString::fromUtf8("labeltime"));
        labeltime->setGeometry(QRect(270, 50, 261, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Rockwell"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        labeltime->setFont(font1);
        labeltime->setStyleSheet(QString::fromUtf8(""));
        labeltime_Opp = new QLabel(Multiplayer);
        labeltime_Opp->setObjectName(QString::fromUtf8("labeltime_Opp"));
        labeltime_Opp->setGeometry(QRect(250, 110, 301, 31));
        labeltime_Opp->setFont(font1);
        labeltime_Opp->setStyleSheet(QString::fromUtf8(""));
        progressBarProgess = new QProgressBar(Multiplayer);
        progressBarProgess->setObjectName(QString::fromUtf8("progressBarProgess"));
        progressBarProgess->setGeometry(QRect(1010, 220, 131, 30));
        progressBarProgess->setStyleSheet(QString::fromUtf8(""));
        progressBarProgess->setMaximum(1);
        progressBarProgess->setValue(0);
        progressBarProgess->setTextVisible(false);
        progressBarProgess_Opp = new QProgressBar(Multiplayer);
        progressBarProgess_Opp->setObjectName(QString::fromUtf8("progressBarProgess_Opp"));
        progressBarProgess_Opp->setGeometry(QRect(1010, 290, 131, 30));
        progressBarProgess_Opp->setStyleSheet(QString::fromUtf8(""));
        progressBarProgess_Opp->setMaximum(1);
        progressBarProgess_Opp->setValue(0);
        progressBarProgess_Opp->setTextVisible(false);
        pushButtonCheat = new QPushButton(Multiplayer);
        pushButtonCheat->setObjectName(QString::fromUtf8("pushButtonCheat"));
        pushButtonCheat->setGeometry(QRect(730, 110, 100, 30));
        pushButtonCheat->setFont(font);
        pushButtonCheat->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(170, 85, 0); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(0, 170, 255); }"));
        labelprog = new QLabel(Multiplayer);
        labelprog->setObjectName(QString::fromUtf8("labelprog"));
        labelprog->setGeometry(QRect(1010, 190, 161, 23));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Rockwell"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        labelprog->setFont(font2);
        labelprog->setStyleSheet(QString::fromUtf8(""));
        labelprog_Opp = new QLabel(Multiplayer);
        labelprog_Opp->setObjectName(QString::fromUtf8("labelprog_Opp"));
        labelprog_Opp->setGeometry(QRect(1010, 260, 161, 23));
        labelprog_Opp->setFont(font2);
        labelprog_Opp->setStyleSheet(QString::fromUtf8(""));
        labellose = new QLabel(Multiplayer);
        labellose->setObjectName(QString::fromUtf8("labellose"));
        labellose->setGeometry(QRect(850, 50, 161, 31));
        labellose->setFont(font2);
        labellose->setStyleSheet(QString::fromUtf8(""));
        labellose2 = new QLabel(Multiplayer);
        labellose2->setObjectName(QString::fromUtf8("labellose2"));
        labellose2->setGeometry(QRect(870, 70, 161, 31));
        labellose2->setFont(font2);
        labellose2->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(Multiplayer);

        QMetaObject::connectSlotsByName(Multiplayer);
    } // setupUi

    void retranslateUi(QWidget *Multiplayer)
    {
        Multiplayer->setWindowTitle(QCoreApplication::translate("Multiplayer", "Form", nullptr));
        pushButtonBackToMenu->setText(QCoreApplication::translate("Multiplayer", "BackToMenu", nullptr));
        progressBarTimer->setFormat(QCoreApplication::translate("Multiplayer", "%p sec", nullptr));
        progressBarTimer_Opp->setFormat(QCoreApplication::translate("Multiplayer", "%p sec", nullptr));
        labeltime->setText(QCoreApplication::translate("Multiplayer", "Your Remaining Time", nullptr));
        labeltime_Opp->setText(QCoreApplication::translate("Multiplayer", "Enemy's Remaining Time", nullptr));
#if QT_CONFIG(tooltip)
        progressBarProgess->setToolTip(QCoreApplication::translate("Multiplayer", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        progressBarProgess->setFormat(QCoreApplication::translate("Multiplayer", "%p sec", nullptr));
        progressBarProgess_Opp->setFormat(QCoreApplication::translate("Multiplayer", "%p sec", nullptr));
        pushButtonCheat->setText(QCoreApplication::translate("Multiplayer", "Cheat", nullptr));
        labelprog->setText(QCoreApplication::translate("Multiplayer", "Your Progress", nullptr));
        labelprog_Opp->setText(QCoreApplication::translate("Multiplayer", "Enemy's Progress", nullptr));
        labellose->setText(QCoreApplication::translate("Multiplayer", "\342\206\220Click and", nullptr));
        labellose2->setText(QCoreApplication::translate("Multiplayer", " you lose!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Multiplayer: public Ui_Multiplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLAYER_H
