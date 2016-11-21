/********************************************************************************
** Form generated from reading UI file 'geometry.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEOMETRY_H
#define UI_GEOMETRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeometryClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GeometryClass)
    {
        if (GeometryClass->objectName().isEmpty())
            GeometryClass->setObjectName(QStringLiteral("GeometryClass"));
        GeometryClass->resize(600, 400);
        menuBar = new QMenuBar(GeometryClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        GeometryClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GeometryClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GeometryClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GeometryClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GeometryClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GeometryClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GeometryClass->setStatusBar(statusBar);

        retranslateUi(GeometryClass);

        QMetaObject::connectSlotsByName(GeometryClass);
    } // setupUi

    void retranslateUi(QMainWindow *GeometryClass)
    {
        GeometryClass->setWindowTitle(QApplication::translate("GeometryClass", "Geometry", 0));
    } // retranslateUi

};

namespace Ui {
    class GeometryClass: public Ui_GeometryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEOMETRY_H
