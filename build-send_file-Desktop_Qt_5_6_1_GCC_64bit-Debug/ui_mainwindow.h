/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *server_push;
    QLabel *server_display;
    QPushButton *pushButton;
    QTextEdit *DIR;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *port;
    QTextEdit *server_ip;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QTextEdit *input_port;
    QTextEdit *input_ip;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(999, 471);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        server_push = new QPushButton(centralWidget);
        server_push->setObjectName(QStringLiteral("server_push"));
        server_push->setGeometry(QRect(610, 60, 99, 27));
        server_display = new QLabel(centralWidget);
        server_display->setObjectName(QStringLiteral("server_display"));
        server_display->setGeometry(QRect(730, 60, 221, 31));
        server_display->setFrameShape(QFrame::NoFrame);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 210, 99, 27));
        DIR = new QTextEdit(centralWidget);
        DIR->setObjectName(QStringLiteral("DIR"));
        DIR->setGeometry(QRect(170, 210, 621, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(240, 140, 471, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 300, 67, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 350, 71, 21));
        port = new QTextEdit(centralWidget);
        port->setObjectName(QStringLiteral("port"));
        port->setGeometry(QRect(170, 290, 81, 31));
        server_ip = new QTextEdit(centralWidget);
        server_ip->setObjectName(QStringLiteral("server_ip"));
        server_ip->setGeometry(QRect(170, 340, 211, 31));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(540, 300, 181, 41));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(240, 0, 471, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 60, 67, 17));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(260, 60, 81, 16));
        input_port = new QTextEdit(centralWidget);
        input_port->setObjectName(QStringLiteral("input_port"));
        input_port->setGeometry(QRect(110, 60, 101, 31));
        input_ip = new QTextEdit(centralWidget);
        input_ip->setObjectName(QStringLiteral("input_ip"));
        input_ip->setGeometry(QRect(350, 60, 221, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 999, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        server_push->setText(QApplication::translate("MainWindow", "Start Server", 0));
        server_display->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Open Dir", 0));
        label->setText(QApplication::translate("MainWindow", "----------------------------------------Client WIndow---------------------------------------------", 0));
        label_2->setText(QApplication::translate("MainWindow", "Port:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Server's IP:", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Send", 0));
        label_4->setText(QApplication::translate("MainWindow", "----------------------------------------Server Window-----------------------------------------", 0));
        label_5->setText(QApplication::translate("MainWindow", "Port:", 0));
        label_6->setText(QApplication::translate("MainWindow", "Server's IP", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
