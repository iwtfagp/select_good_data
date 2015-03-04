/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QwtPlot *qwtPlot;
    QwtPlot *qwtPlot_2;
    QwtPlot *qwtPlot_3;
    QwtPlot *qwtPlot_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton_max;
    QRadioButton *radioButton_min;
    QPushButton *pushButton_read_file;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(944, 582);
        MainWindow->setMinimumSize(QSize(500, 250));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        qwtPlot = new QwtPlot(centralWidget);
        qwtPlot->setObjectName(QStringLiteral("qwtPlot"));
        qwtPlot->setMinimumSize(QSize(400, 200));
        qwtPlot->setMaximumSize(QSize(300, 250));

        gridLayout->addWidget(qwtPlot, 0, 0, 1, 1);

        qwtPlot_2 = new QwtPlot(centralWidget);
        qwtPlot_2->setObjectName(QStringLiteral("qwtPlot_2"));
        qwtPlot_2->setMinimumSize(QSize(400, 200));
        qwtPlot_2->setMaximumSize(QSize(300, 250));

        gridLayout->addWidget(qwtPlot_2, 0, 1, 1, 1);

        qwtPlot_3 = new QwtPlot(centralWidget);
        qwtPlot_3->setObjectName(QStringLiteral("qwtPlot_3"));
        qwtPlot_3->setMinimumSize(QSize(400, 200));
        qwtPlot_3->setMaximumSize(QSize(300, 250));

        gridLayout->addWidget(qwtPlot_3, 1, 0, 1, 1);

        qwtPlot_4 = new QwtPlot(centralWidget);
        qwtPlot_4->setObjectName(QStringLiteral("qwtPlot_4"));
        qwtPlot_4->setMinimumSize(QSize(400, 200));
        qwtPlot_4->setMaximumSize(QSize(300, 250));

        gridLayout->addWidget(qwtPlot_4, 1, 1, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        radioButton_max = new QRadioButton(groupBox);
        radioButton_max->setObjectName(QStringLiteral("radioButton_max"));
        radioButton_max->setChecked(true);

        gridLayout_2->addWidget(radioButton_max, 1, 0, 1, 1);

        radioButton_min = new QRadioButton(groupBox);
        radioButton_min->setObjectName(QStringLiteral("radioButton_min"));

        gridLayout_2->addWidget(radioButton_min, 2, 0, 1, 1);

        pushButton_read_file = new QPushButton(groupBox);
        pushButton_read_file->setObjectName(QStringLiteral("pushButton_read_file"));

        gridLayout_2->addWidget(pushButton_read_file, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 2, 2, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 944, 22));
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
        groupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        radioButton_max->setText(QApplication::translate("MainWindow", "Max", 0));
        radioButton_min->setText(QApplication::translate("MainWindow", "Min", 0));
        pushButton_read_file->setText(QApplication::translate("MainWindow", "ReadFile", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
