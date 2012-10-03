/********************************************************************************
** Form generated from reading UI file 'ProtoViewer.ui'
**
** Created: Tue Oct 2 21:38:53 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTOVIEWER_H
#define UI_PROTOVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProtoViewer
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProtoViewer)
    {
        if (ProtoViewer->objectName().isEmpty())
            ProtoViewer->setObjectName(QString::fromUtf8("ProtoViewer"));
        ProtoViewer->resize(400, 300);
        menuBar = new QMenuBar(ProtoViewer);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ProtoViewer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProtoViewer);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ProtoViewer->addToolBar(mainToolBar);
        centralWidget = new QWidget(ProtoViewer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ProtoViewer->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ProtoViewer);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ProtoViewer->setStatusBar(statusBar);

        retranslateUi(ProtoViewer);

        QMetaObject::connectSlotsByName(ProtoViewer);
    } // setupUi

    void retranslateUi(QMainWindow *ProtoViewer)
    {
        ProtoViewer->setWindowTitle(QApplication::translate("ProtoViewer", "ProtoViewer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProtoViewer: public Ui_ProtoViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTOVIEWER_H
