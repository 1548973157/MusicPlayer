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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_2;
    QListWidget *musicList;
    QSpacerItem *verticalSpacer;
    QWidget *bottomPanel;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_8;
    QLabel *musicNameLabel;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *prevButton;
    QPushButton *playPauseButton;
    QPushButton *nextButton;
    QPushButton *modeButton;
    QWidget *horizontalWidget_2;
    QHBoxLayout *mainPanel;
    QLabel *currentTimeLabel;
    QSlider *progressSlider;
    QLabel *totalTimeLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QSlider *volumeSlider;
    QPushButton *listButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(982, 728);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        widget_5 = new QWidget(widget);
        widget_5->setObjectName("widget_5");
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName("widget_2");
        widget_2->setMinimumSize(QSize(50, 0));

        horizontalLayout_3->addWidget(widget_2);

        musicList = new QListWidget(widget_5);
        musicList->setObjectName("musicList");
        musicList->setMinimumSize(QSize(350, 0));
        musicList->setMaximumSize(QSize(350, 16777215));

        horizontalLayout_3->addWidget(musicList);


        verticalLayout->addWidget(widget_5);

        verticalSpacer = new QSpacerItem(20, 247, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        bottomPanel = new QWidget(widget);
        bottomPanel->setObjectName("bottomPanel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bottomPanel->sizePolicy().hasHeightForWidth());
        bottomPanel->setSizePolicy(sizePolicy);
        bottomPanel->setMinimumSize(QSize(0, 120));
        bottomPanel->setMaximumSize(QSize(16777215, 120));
        horizontalLayout_2 = new QHBoxLayout(bottomPanel);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        widget1 = new QWidget(bottomPanel);
        widget1->setObjectName("widget1");
        horizontalLayout_8 = new QHBoxLayout(widget1);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        musicNameLabel = new QLabel(widget1);
        musicNameLabel->setObjectName("musicNameLabel");
        musicNameLabel->setMinimumSize(QSize(100, 0));
        musicNameLabel->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(musicNameLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        widget_3 = new QWidget(widget1);
        widget_3->setObjectName("widget_3");
        widget_3->setMinimumSize(QSize(300, 0));
        widget_3->setMaximumSize(QSize(350, 16777215));
        horizontalLayout_6 = new QHBoxLayout(widget_3);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        prevButton = new QPushButton(widget_3);
        prevButton->setObjectName("prevButton");

        horizontalLayout_6->addWidget(prevButton);

        playPauseButton = new QPushButton(widget_3);
        playPauseButton->setObjectName("playPauseButton");

        horizontalLayout_6->addWidget(playPauseButton);

        nextButton = new QPushButton(widget_3);
        nextButton->setObjectName("nextButton");

        horizontalLayout_6->addWidget(nextButton);

        modeButton = new QPushButton(widget_3);
        modeButton->setObjectName("modeButton");

        horizontalLayout_6->addWidget(modeButton);


        verticalLayout_3->addWidget(widget_3);

        horizontalWidget_2 = new QWidget(widget1);
        horizontalWidget_2->setObjectName("horizontalWidget_2");
        horizontalWidget_2->setMinimumSize(QSize(300, 0));
        horizontalWidget_2->setMaximumSize(QSize(350, 16777215));
        mainPanel = new QHBoxLayout(horizontalWidget_2);
        mainPanel->setObjectName("mainPanel");
        currentTimeLabel = new QLabel(horizontalWidget_2);
        currentTimeLabel->setObjectName("currentTimeLabel");

        mainPanel->addWidget(currentTimeLabel);

        progressSlider = new QSlider(horizontalWidget_2);
        progressSlider->setObjectName("progressSlider");
        progressSlider->setMaximum(1000);
        progressSlider->setOrientation(Qt::Orientation::Horizontal);

        mainPanel->addWidget(progressSlider);

        totalTimeLabel = new QLabel(horizontalWidget_2);
        totalTimeLabel->setObjectName("totalTimeLabel");

        mainPanel->addWidget(totalTimeLabel);


        verticalLayout_3->addWidget(horizontalWidget_2);


        horizontalLayout_8->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        volumeSlider = new QSlider(widget1);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setOrientation(Qt::Orientation::Vertical);

        horizontalLayout_7->addWidget(volumeSlider);

        listButton = new QPushButton(widget1);
        listButton->setObjectName("listButton");

        horizontalLayout_7->addWidget(listButton);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        horizontalLayout_2->addWidget(widget1);


        verticalLayout->addWidget(bottomPanel);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        verticalLayout_2->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 982, 25));
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
        musicNameLabel->setText(QCoreApplication::translate("MainWindow", "\346\234\252\346\222\255\346\224\276", nullptr));
        prevButton->setText(QString());
        playPauseButton->setText(QString());
        nextButton->setText(QString());
        modeButton->setText(QString());
        currentTimeLabel->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        totalTimeLabel->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        listButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
