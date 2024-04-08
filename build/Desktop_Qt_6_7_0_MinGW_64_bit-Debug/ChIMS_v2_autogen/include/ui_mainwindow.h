/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionO3_IP_Address;
    QAction *actionNOy_IP_Address;
    QAction *actionRH_T_COM_port;
    QWidget *centralwidget;
    QChartView *NOy_ChartView;
    QGroupBox *groupBox;
    QPushButton *startExperiment_button;
    QLineEdit *instrumentUser;
    QLineEdit *experimentName;
    QLabel *label;
    QLabel *label_2;
    QLCDNumber *lcdClock;
    QDial *dial_2;
    QChartView *Gases_ChartView;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QLabel *RH_label;
    QLabel *label_14;
    QLabel *T_label;
    QLabel *label_12;
    QLabel *O3_label;
    QLabel *label_13;
    QLabel *NO_label;
    QLabel *label_16;
    QLabel *NOy_label;
    QLabel *label_9;
    QLabel *DIFF_label;
    QLabel *label_6;
    QLabel *label_4;
    QDial *dial_3;
    QDial *dial;
    QMenuBar *menubar;
    QMenu *menuHome;
    QMenu *menuSettings;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1006, 728);
        actionO3_IP_Address = new QAction(MainWindow);
        actionO3_IP_Address->setObjectName("actionO3_IP_Address");
        actionNOy_IP_Address = new QAction(MainWindow);
        actionNOy_IP_Address->setObjectName("actionNOy_IP_Address");
        actionRH_T_COM_port = new QAction(MainWindow);
        actionRH_T_COM_port->setObjectName("actionRH_T_COM_port");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        NOy_ChartView = new QChartView(centralwidget);
        NOy_ChartView->setObjectName("NOy_ChartView");
        NOy_ChartView->setGeometry(QRect(10, 520, 821, 192));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 0, 821, 91));
        startExperiment_button = new QPushButton(groupBox);
        startExperiment_button->setObjectName("startExperiment_button");
        startExperiment_button->setGeometry(QRect(699, 40, 101, 24));
        startExperiment_button->setCursor(QCursor(Qt::PointingHandCursor));
        instrumentUser = new QLineEdit(groupBox);
        instrumentUser->setObjectName("instrumentUser");
        instrumentUser->setGeometry(QRect(20, 50, 131, 24));
        experimentName = new QLineEdit(groupBox);
        experimentName->setObjectName("experimentName");
        experimentName->setGeometry(QRect(180, 50, 371, 24));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 30, 101, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 30, 121, 16));
        lcdClock = new QLCDNumber(groupBox);
        lcdClock->setObjectName("lcdClock");
        lcdClock->setGeometry(QRect(560, 30, 131, 51));
        lcdClock->setStyleSheet(QString::fromUtf8(""));
        lcdClock->setFrameShape(QFrame::NoFrame);
        lcdClock->setFrameShadow(QFrame::Plain);
        lcdClock->setDigitCount(8);
        lcdClock->setSegmentStyle(QLCDNumber::Flat);
        dial_2 = new QDial(centralwidget);
        dial_2->setObjectName("dial_2");
        dial_2->setGeometry(QRect(830, 630, 50, 64));
        Gases_ChartView = new QChartView(centralwidget);
        Gases_ChartView->setObjectName("Gases_ChartView");
        Gases_ChartView->setGeometry(QRect(10, 100, 821, 431));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(840, 0, 141, 621));
        verticalLayoutWidget = new QWidget(groupBox_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 19, 141, 601));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("font: 900 11pt \"Segoe UI\" rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_7, 0, Qt::AlignHCenter);

        RH_label = new QLabel(verticalLayoutWidget);
        RH_label->setObjectName("RH_label");
        RH_label->setStyleSheet(QString::fromUtf8("color:rgb(0,0,255);\n"
"font: 600 18pt \"Segoe UI\";"));

        verticalLayout->addWidget(RH_label, 0, Qt::AlignHCenter);

        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName("label_14");
        label_14->setStyleSheet(QString::fromUtf8("font: 900 11pt \"Segoe UI\" rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_14, 0, Qt::AlignHCenter);

        T_label = new QLabel(verticalLayoutWidget);
        T_label->setObjectName("T_label");
        T_label->setStyleSheet(QString::fromUtf8("font: 600 18pt \"Segoe UI\"; color:rgb(255, 0, 0);"));

        verticalLayout->addWidget(T_label, 0, Qt::AlignHCenter);

        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName("label_12");
        label_12->setStyleSheet(QString::fromUtf8("font: 900 11pt \"Segoe UI\" rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_12, 0, Qt::AlignHCenter);

        O3_label = new QLabel(verticalLayoutWidget);
        O3_label->setObjectName("O3_label");
        O3_label->setStyleSheet(QString::fromUtf8("font: 600 18pt \"Segoe UI\"; color:rgb(0, 200, 0);"));

        verticalLayout->addWidget(O3_label, 0, Qt::AlignHCenter);

        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName("label_13");
        label_13->setStyleSheet(QString::fromUtf8("font: 900 11pt \"Segoe UI\" rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_13, 0, Qt::AlignHCenter);

        NO_label = new QLabel(verticalLayoutWidget);
        NO_label->setObjectName("NO_label");
        NO_label->setStyleSheet(QString::fromUtf8("font: 600 18pt \"Segoe UI\"; color:rgb(255, 170, 0);"));

        verticalLayout->addWidget(NO_label, 0, Qt::AlignHCenter);

        label_16 = new QLabel(verticalLayoutWidget);
        label_16->setObjectName("label_16");
        label_16->setStyleSheet(QString::fromUtf8("font: 900 11pt \"Segoe UI\" rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_16, 0, Qt::AlignHCenter);

        NOy_label = new QLabel(verticalLayoutWidget);
        NOy_label->setObjectName("NOy_label");
        NOy_label->setStyleSheet(QString::fromUtf8("font: 600 18pt \"Segoe UI\"; color:rgb(140,70, 70);"));

        verticalLayout->addWidget(NOy_label, 0, Qt::AlignHCenter);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8("font: 900 11pt \"Segoe UI\" rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_9, 0, Qt::AlignHCenter);

        DIFF_label = new QLabel(verticalLayoutWidget);
        DIFF_label->setObjectName("DIFF_label");
        DIFF_label->setStyleSheet(QString::fromUtf8("font: 600 18pt \"Segoe UI\"; color: rgb(85, 85, 255);"));

        verticalLayout->addWidget(DIFF_label, 0, Qt::AlignHCenter);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("font: 900 11pt \"Segoe UI\" rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_6, 0, Qt::AlignHCenter);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("font: 900 14pt \"Segoe UI\" rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_4, 0, Qt::AlignHCenter);

        dial_3 = new QDial(centralwidget);
        dial_3->setObjectName("dial_3");
        dial_3->setGeometry(QRect(950, 630, 50, 64));
        dial = new QDial(centralwidget);
        dial->setObjectName("dial");
        dial->setGeometry(QRect(890, 630, 50, 64));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1006, 21));
        menuHome = new QMenu(menubar);
        menuHome->setObjectName("menuHome");
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName("menuSettings");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuHome->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menuSettings->addAction(actionO3_IP_Address);
        menuSettings->addAction(actionNOy_IP_Address);
        menuSettings->addAction(actionRH_T_COM_port);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionO3_IP_Address->setText(QCoreApplication::translate("MainWindow", "O3 IP Address", nullptr));
        actionNOy_IP_Address->setText(QCoreApplication::translate("MainWindow", "NOy IP Address", nullptr));
        actionRH_T_COM_port->setText(QCoreApplication::translate("MainWindow", "RH/T COM port", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Experiment Details", nullptr));
        startExperiment_button->setText(QCoreApplication::translate("MainWindow", "Start Recording", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Instrument User", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Experiment Name", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Current Data", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Humidity (%)", nullptr));
        RH_label->setText(QCoreApplication::translate("MainWindow", "40", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Temperature (C)", nullptr));
        T_label->setText(QCoreApplication::translate("MainWindow", "25.1", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "O3 (ppb)", nullptr));
        O3_label->setText(QCoreApplication::translate("MainWindow", "20.00", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "NO (ppb)", nullptr));
        NO_label->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "NOy (ppb)", nullptr));
        NOy_label->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "DIFF (ppb)", nullptr));
        DIFF_label->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Lights", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "off", nullptr));
        menuHome->setTitle(QCoreApplication::translate("MainWindow", "Home", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
