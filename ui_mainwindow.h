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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QwtPlot *qwtPlot_left_hip;
    QwtPlot *qwtPlot_right_hip;
    QwtPlot *qwtPlot_left_knee;
    QwtPlot *qwtPlot_right_knee;
    QwtPlot *qwtPlot_All;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLCDNumber *lcdNumber_LeftHip;
    QLabel *label_2;
    QLabel *label_5;
    QLCDNumber *lcdNumber_LeftKnee;
    QLCDNumber *lcdNumber_RightHip;
    QLabel *label_6;
    QLCDNumber *lcdNumber_RightKnee;
    QPushButton *pushButton_calibration;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_open_dir;
    QTreeView *treeView;
    QRadioButton *radioButton_max;
    QPushButton *pushButton_generate;
    QRadioButton *radioButton_min;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1006, 723);
        MainWindow->setMinimumSize(QSize(500, 250));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        qwtPlot_left_hip = new QwtPlot(centralWidget);
        qwtPlot_left_hip->setObjectName(QStringLiteral("qwtPlot_left_hip"));
        qwtPlot_left_hip->setMinimumSize(QSize(350, 150));
        qwtPlot_left_hip->setMaximumSize(QSize(300, 200));
        qwtPlot_left_hip->setMouseTracking(false);
        qwtPlot_left_hip->setAutoFillBackground(false);
        qwtPlot_left_hip->setFrameShadow(QFrame::Plain);
        qwtPlot_left_hip->setAutoReplot(false);

        gridLayout_3->addWidget(qwtPlot_left_hip, 0, 0, 1, 1);

        qwtPlot_right_hip = new QwtPlot(centralWidget);
        qwtPlot_right_hip->setObjectName(QStringLiteral("qwtPlot_right_hip"));
        qwtPlot_right_hip->setMinimumSize(QSize(350, 150));
        qwtPlot_right_hip->setMaximumSize(QSize(300, 200));

        gridLayout_3->addWidget(qwtPlot_right_hip, 0, 1, 1, 1);

        qwtPlot_left_knee = new QwtPlot(centralWidget);
        qwtPlot_left_knee->setObjectName(QStringLiteral("qwtPlot_left_knee"));
        qwtPlot_left_knee->setMinimumSize(QSize(350, 150));
        qwtPlot_left_knee->setMaximumSize(QSize(300, 200));

        gridLayout_3->addWidget(qwtPlot_left_knee, 1, 0, 2, 1);

        qwtPlot_right_knee = new QwtPlot(centralWidget);
        qwtPlot_right_knee->setObjectName(QStringLiteral("qwtPlot_right_knee"));
        qwtPlot_right_knee->setMinimumSize(QSize(350, 150));
        qwtPlot_right_knee->setMaximumSize(QSize(300, 200));

        gridLayout_3->addWidget(qwtPlot_right_knee, 1, 1, 2, 1);

        qwtPlot_All = new QwtPlot(centralWidget);
        qwtPlot_All->setObjectName(QStringLiteral("qwtPlot_All"));
        qwtPlot_All->setMinimumSize(QSize(400, 100));

        gridLayout_3->addWidget(qwtPlot_All, 3, 0, 1, 2);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lcdNumber_LeftHip = new QLCDNumber(groupBox_2);
        lcdNumber_LeftHip->setObjectName(QStringLiteral("lcdNumber_LeftHip"));

        gridLayout->addWidget(lcdNumber_LeftHip, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        lcdNumber_LeftKnee = new QLCDNumber(groupBox_2);
        lcdNumber_LeftKnee->setObjectName(QStringLiteral("lcdNumber_LeftKnee"));

        gridLayout->addWidget(lcdNumber_LeftKnee, 3, 1, 1, 1);

        lcdNumber_RightHip = new QLCDNumber(groupBox_2);
        lcdNumber_RightHip->setObjectName(QStringLiteral("lcdNumber_RightHip"));

        gridLayout->addWidget(lcdNumber_RightHip, 2, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        lcdNumber_RightKnee = new QLCDNumber(groupBox_2);
        lcdNumber_RightKnee->setObjectName(QStringLiteral("lcdNumber_RightKnee"));

        gridLayout->addWidget(lcdNumber_RightKnee, 4, 1, 1, 1);

        pushButton_calibration = new QPushButton(groupBox_2);
        pushButton_calibration->setObjectName(QStringLiteral("pushButton_calibration"));

        gridLayout->addWidget(pushButton_calibration, 0, 0, 1, 2);


        gridLayout_3->addWidget(groupBox_2, 3, 2, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_open_dir = new QPushButton(groupBox);
        pushButton_open_dir->setObjectName(QStringLiteral("pushButton_open_dir"));

        gridLayout_2->addWidget(pushButton_open_dir, 0, 0, 1, 1);

        treeView = new QTreeView(groupBox);
        treeView->setObjectName(QStringLiteral("treeView"));

        gridLayout_2->addWidget(treeView, 1, 0, 1, 1);

        radioButton_max = new QRadioButton(groupBox);
        radioButton_max->setObjectName(QStringLiteral("radioButton_max"));
        radioButton_max->setCheckable(true);
        radioButton_max->setChecked(false);

        gridLayout_2->addWidget(radioButton_max, 4, 0, 1, 1);

        pushButton_generate = new QPushButton(groupBox);
        pushButton_generate->setObjectName(QStringLiteral("pushButton_generate"));

        gridLayout_2->addWidget(pushButton_generate, 2, 0, 1, 1);

        radioButton_min = new QRadioButton(groupBox);
        radioButton_min->setObjectName(QStringLiteral("radioButton_min"));
        radioButton_min->setChecked(true);

        gridLayout_2->addWidget(radioButton_min, 5, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 2, 3, 1);

        MainWindow->setCentralWidget(centralWidget);
        qwtPlot_left_hip->raise();
        qwtPlot_right_hip->raise();
        qwtPlot_left_knee->raise();
        qwtPlot_right_knee->raise();
        qwtPlot_All->raise();
        groupBox->raise();
        groupBox_2->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1006, 22));
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
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Initial Position", 0));
        label->setText(QApplication::translate("MainWindow", "LeftHip", 0));
        label_2->setText(QApplication::translate("MainWindow", "RightHip", 0));
        label_5->setText(QApplication::translate("MainWindow", "LeftKnee", 0));
        label_6->setText(QApplication::translate("MainWindow", "RightKnee", 0));
        pushButton_calibration->setText(QApplication::translate("MainWindow", "Calibration", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Operation Panel", 0));
        pushButton_open_dir->setText(QApplication::translate("MainWindow", "Open Dir", 0));
        radioButton_max->setText(QApplication::translate("MainWindow", "Max", 0));
        pushButton_generate->setText(QApplication::translate("MainWindow", "Generate", 0));
        radioButton_min->setText(QApplication::translate("MainWindow", "Min", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
