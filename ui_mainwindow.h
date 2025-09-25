/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *musicList;
    QSlider *volumeSlider;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *prevButton;
    QPushButton *playPauseButton;
    QPushButton *nextButton;
    QPushButton *modeButton;
    QPushButton *listButton;
    QLabel *musicNameLabel;
    QSlider *progressSlider;
    QLabel *currentTimeLabel;
    QLabel *totalTimeLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1193, 731);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        musicList = new QListWidget(centralwidget);
        musicList->setObjectName("musicList");
        musicList->setGeometry(QRect(800, 20, 361, 511));
        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setGeometry(QRect(760, 490, 16, 160));
        volumeSlider->setOrientation(Qt::Orientation::Vertical);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(120, 610, 611, 71));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        prevButton = new QPushButton(widget);
        prevButton->setObjectName("prevButton");

        horizontalLayout->addWidget(prevButton);

        playPauseButton = new QPushButton(widget);
        playPauseButton->setObjectName("playPauseButton");

        horizontalLayout->addWidget(playPauseButton);

        nextButton = new QPushButton(widget);
        nextButton->setObjectName("nextButton");

        horizontalLayout->addWidget(nextButton);

        modeButton = new QPushButton(widget);
        modeButton->setObjectName("modeButton");

        horizontalLayout->addWidget(modeButton);

        listButton = new QPushButton(widget);
        listButton->setObjectName("listButton");

        horizontalLayout->addWidget(listButton);

        musicNameLabel = new QLabel(centralwidget);
        musicNameLabel->setObjectName("musicNameLabel");
        musicNameLabel->setGeometry(QRect(20, 610, 92, 49));
        progressSlider = new QSlider(centralwidget);
        progressSlider->setObjectName("progressSlider");
        progressSlider->setGeometry(QRect(170, 570, 501, 22));
        progressSlider->setMaximum(1000);
        progressSlider->setOrientation(Qt::Orientation::Horizontal);
        currentTimeLabel = new QLabel(centralwidget);
        currentTimeLabel->setObjectName("currentTimeLabel");
        currentTimeLabel->setGeometry(QRect(100, 570, 69, 19));
        totalTimeLabel = new QLabel(centralwidget);
        totalTimeLabel->setObjectName("totalTimeLabel");
        totalTimeLabel->setGeometry(QRect(680, 570, 69, 19));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1193, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        prevButton->setText(QString());
        playPauseButton->setText(QString());
        nextButton->setText(QString());
        modeButton->setText(QString());
        listButton->setText(QString());
        musicNameLabel->setText(QCoreApplication::translate("MainWindow", "\346\234\252\346\222\255\346\224\276", nullptr));
        currentTimeLabel->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        totalTimeLabel->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
