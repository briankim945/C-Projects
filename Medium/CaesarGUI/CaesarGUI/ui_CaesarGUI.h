/********************************************************************************
** Form generated from reading UI file 'CaesarGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAESARGUI_H
#define UI_CAESARGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CaesarGUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CaesarGUIClass)
    {
        if (CaesarGUIClass->objectName().isEmpty())
            CaesarGUIClass->setObjectName(QString::fromUtf8("CaesarGUIClass"));
        CaesarGUIClass->resize(600, 400);
        menuBar = new QMenuBar(CaesarGUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        CaesarGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CaesarGUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CaesarGUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(CaesarGUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        CaesarGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CaesarGUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CaesarGUIClass->setStatusBar(statusBar);

        retranslateUi(CaesarGUIClass);

        QMetaObject::connectSlotsByName(CaesarGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *CaesarGUIClass)
    {
        CaesarGUIClass->setWindowTitle(QApplication::translate("CaesarGUIClass", "CaesarGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CaesarGUIClass: public Ui_CaesarGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAESARGUI_H
