/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *removeButton;
    QPushButton *addButton;
    QLineEdit *nameEdit;
    QPushButton *searchButton;
    QLineEdit *numberEdit;
    QLineEdit *emailEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTableWidget *tableWidget;
    QLineEdit *searchEdit;
    QMenuBar *menubar;
    QMenu *menuPhone_Book;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName("removeButton");
        removeButton->setGeometry(QRect(370, 480, 95, 29));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(20, 250, 131, 41));
        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setGeometry(QRect(130, 60, 221, 41));
        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(670, 480, 95, 29));
        numberEdit = new QLineEdit(centralwidget);
        numberEdit->setObjectName("numberEdit");
        numberEdit->setGeometry(QRect(130, 120, 221, 41));
        emailEdit = new QLineEdit(centralwidget);
        emailEdit->setObjectName("emailEdit");
        emailEdit->setGeometry(QRect(130, 179, 221, 41));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 70, 81, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 130, 121, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 190, 62, 20));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(370, 30, 401, 441));
        searchEdit = new QLineEdit(centralwidget);
        searchEdit->setObjectName("searchEdit");
        searchEdit->setGeometry(QRect(532, 480, 131, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuPhone_Book = new QMenu(menubar);
        menuPhone_Book->setObjectName("menuPhone_Book");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuPhone_Book->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "REMOVE", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "ADD", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "SEARCH", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Name : ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Phone number : ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "E-mail : ", nullptr));
        menuPhone_Book->setTitle(QCoreApplication::translate("MainWindow", "Phone Book", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
