/********************************************************************************
** Form generated from reading UI file 'rank.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANK_H
#define UI_RANK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rank
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *rank)
    {
        if (rank->objectName().isEmpty())
            rank->setObjectName(QStringLiteral("rank"));
        rank->resize(800, 600);
        rank->setStyleSheet(QStringLiteral("rank{border-image: url(:/image/THEME_E_BG_1.png);}"));
        centralwidget = new QWidget(rank);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(260, 160, 256, 192));
        QFont font;
        font.setFamily(QStringLiteral("MS Serif"));
        font.setPointSize(18);
        listWidget->setFont(font);
        listWidget->setStyleSheet(QStringLiteral("border-image: url(:/image/back.png);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(340, 380, 121, 41));
        pushButton->setFont(font);
        pushButton->setFlat(true);
        rank->setCentralWidget(centralwidget);
        menubar = new QMenuBar(rank);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        rank->setMenuBar(menubar);
        statusbar = new QStatusBar(rank);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        rank->setStatusBar(statusbar);

        retranslateUi(rank);

        QMetaObject::connectSlotsByName(rank);
    } // setupUi

    void retranslateUi(QMainWindow *rank)
    {
        rank->setWindowTitle(QApplication::translate("rank", "MainWindow", 0));
        pushButton->setText(QApplication::translate("rank", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class rank: public Ui_rank {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANK_H
