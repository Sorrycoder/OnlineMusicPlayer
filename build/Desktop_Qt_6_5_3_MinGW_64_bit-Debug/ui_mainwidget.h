/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_Search;
    QPushButton *btnSearch;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnLast;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btnPlay;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnNext;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnRepeat;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSound;
    QSlider *SliderSound;
    QLabel *label_voice;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_currentTime;
    QLabel *label_5;
    QLabel *label_totalTime;
    QSlider *SliderProgress;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QLabel *label_Album;
    QLabel *label_4;
    QLabel *label_lyric;
    QLabel *label_currentPlay;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnClearHistory;
    QPushButton *btnAbout;
    QPushButton *btnSkin;
    QPushButton *pushButton;
    QPushButton *btnQuit;
    QGroupBox *groupBox_pic;
    QGridLayout *gridLayout;
    QListWidget *listWidget_History;
    QListWidget *listWidget_Search;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName("MainWidget");
        MainWidget->resize(800, 600);
        MainWidget->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/music_player.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWidget->setWindowIcon(icon);
        groupBox = new QGroupBox(MainWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 50, 800, 50));
        groupBox->setMinimumSize(QSize(800, 50));
        groupBox->setMaximumSize(QSize(800, 50));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 30));
        label->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font.setPointSize(14);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("\n"
"            background-color: rgba(255, 255, 255, 50); \n"
"            color: white;\n"
"            border: none;\n"
""));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        lineEdit_Search = new QLineEdit(groupBox);
        lineEdit_Search->setObjectName("lineEdit_Search");
        lineEdit_Search->setMinimumSize(QSize(0, 30));
        lineEdit_Search->setMaximumSize(QSize(16777215, 30));
        lineEdit_Search->setFont(font);

        horizontalLayout_2->addWidget(lineEdit_Search);

        btnSearch = new QPushButton(groupBox);
        btnSearch->setObjectName("btnSearch");
        btnSearch->setMinimumSize(QSize(0, 30));
        btnSearch->setMaximumSize(QSize(16777215, 30));
        btnSearch->setFont(font);
        btnSearch->setStyleSheet(QString::fromUtf8("\n"
"            background-color: rgba(255, 255, 255, 50); \n"
"            color: white;\n"
"            border: none;\n"
"\n"
"            "));

        horizontalLayout_2->addWidget(btnSearch);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 1);
        layoutWidget = new QWidget(MainWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 550, 801, 52));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(20, 0, 6, 0);
        btnLast = new QPushButton(layoutWidget);
        btnLast->setObjectName("btnLast");
        btnLast->setMinimumSize(QSize(0, 50));
        btnLast->setCursor(QCursor(Qt::PointingHandCursor));
        btnLast->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"            background-color: rgba(0, 0, 255, 0); /* \351\200\217\346\230\216\350\203\214\346\231\257 */\n"
"            color: white;\n"
"            border: none;\n"
"            }"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/play-previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLast->setIcon(icon1);
        btnLast->setIconSize(QSize(32, 32));

        horizontalLayout_5->addWidget(btnLast);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        btnPlay = new QPushButton(layoutWidget);
        btnPlay->setObjectName("btnPlay");
        btnPlay->setCursor(QCursor(Qt::PointingHandCursor));
        btnPlay->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"            background-color: rgba(0, 0, 255, 0); /* \351\200\217\346\230\216\350\203\214\346\231\257 */\n"
"            color: white;\n"
"            border: none;\n"
"            }"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlay->setIcon(icon2);
        btnPlay->setIconSize(QSize(48, 48));

        horizontalLayout_5->addWidget(btnPlay);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        btnNext = new QPushButton(layoutWidget);
        btnNext->setObjectName("btnNext");
        btnNext->setCursor(QCursor(Qt::PointingHandCursor));
        btnNext->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"            background-color: rgba(0, 0, 255, 0); /* \351\200\217\346\230\216\350\203\214\346\231\257 */\n"
"            color: white;\n"
"            border: none;\n"
"            }"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/play-next.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNext->setIcon(icon3);
        btnNext->setIconSize(QSize(32, 32));

        horizontalLayout_5->addWidget(btnNext);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        btnRepeat = new QPushButton(layoutWidget);
        btnRepeat->setObjectName("btnRepeat");
        btnRepeat->setCursor(QCursor(Qt::PointingHandCursor));
        btnRepeat->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"            background-color: rgba(0, 0, 255, 0); /* \351\200\217\346\230\216\350\203\214\346\231\257 */\n"
"            color: white;\n"
"            border: none;\n"
"            }"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/single.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRepeat->setIcon(icon4);
        btnRepeat->setIconSize(QSize(32, 32));

        horizontalLayout_5->addWidget(btnRepeat);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        btnSound = new QPushButton(layoutWidget);
        btnSound->setObjectName("btnSound");
        btnSound->setCursor(QCursor(Qt::PointingHandCursor));
        btnSound->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"            background-color: rgba(0, 0, 255, 0); /* \351\200\217\346\230\216\350\203\214\346\231\257 */\n"
"            color: white;\n"
"            border: none;\n"
"            }"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/sound-on.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSound->setIcon(icon5);
        btnSound->setIconSize(QSize(32, 32));

        horizontalLayout_5->addWidget(btnSound);

        SliderSound = new QSlider(layoutWidget);
        SliderSound->setObjectName("SliderSound");
        SliderSound->setMinimumSize(QSize(0, 20));
        SliderSound->setCursor(QCursor(Qt::PointingHandCursor));
        SliderSound->setStyleSheet(QString::fromUtf8("QSlider::horizontal {\n"
"    border: none;\n"
"    height: 8px;\n"
"    margin: 0px;\n"
"    padding: 0px;\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: none;\n"
"   \n"
"	background-color: rgb(0, 0, 0);\n"
"    height: 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5,\n"
"        stop:0.4 rgb(199, 12, 12), stop:0.5 white); /* \347\231\275\350\211\262\345\234\206\345\275\242\346\273\221\345\235\227\357\274\214\344\270\255\351\227\264\347\272\242\350\211\262 */\n"
"    border: none;\n"
"    width: 20px; /* \350\276\203\345\244\247\347\232\204\347\231\275\350\211\262\345\234\206\345\275\242 */\n"
"    height: 20px;\n"
"    margin: -6px 0px; /* \350\260\203\346\225\264\346\273\221\345\235\227\347\233\270\345\257\271\344\272\216\346\273\221\350\275\250\347\232\204\344\275\215\347\275\256 */\n"
"    border-radius: 10px; /* \345\234\206\345\275\242\346\273\221\345\235\227 */\n"
"}\n"
""
                        "\n"
"QSlider::sub-page:horizontal {\n"
"    \n"
"	background-color: rgb(199, 12, 12);\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    \n"
"	background-color: rgb(0, 0, 0);\n"
"    border-radius: 4px;\n"
"}"));
        SliderSound->setMaximum(100);
        SliderSound->setValue(30);
        SliderSound->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(SliderSound);

        label_voice = new QLabel(layoutWidget);
        label_voice->setObjectName("label_voice");
        label_voice->setMinimumSize(QSize(30, 0));
        label_voice->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_voice->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_voice);

        layoutWidget1 = new QWidget(MainWidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(680, 500, 91, 52));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_currentTime = new QLabel(layoutWidget1);
        label_currentTime->setObjectName("label_currentTime");
        label_currentTime->setMinimumSize(QSize(0, 50));
        label_currentTime->setStyleSheet(QString::fromUtf8("\n"
"            background-color: rgba(255, 255, 255, 0); \n"
"            color: white;\n"
"            border: none;\n"
""));

        horizontalLayout_3->addWidget(label_currentTime);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(1, 0));
        label_5->setMaximumSize(QSize(10, 16777215));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_5);

        label_totalTime = new QLabel(layoutWidget1);
        label_totalTime->setObjectName("label_totalTime");
        label_totalTime->setStyleSheet(QString::fromUtf8("\n"
"            background-color: rgba(255, 255, 255, 0); \n"
"            color: white;\n"
"            border: none;\n"
""));

        horizontalLayout_3->addWidget(label_totalTime);

        SliderProgress = new QSlider(MainWidget);
        SliderProgress->setObjectName("SliderProgress");
        SliderProgress->setGeometry(QRect(0, 500, 651, 50));
        SliderProgress->setMinimumSize(QSize(0, 50));
        SliderProgress->setMaximumSize(QSize(16777215, 50));
        SliderProgress->setCursor(QCursor(Qt::PointingHandCursor));
        SliderProgress->setStyleSheet(QString::fromUtf8("QSlider::horizontal {\n"
"    border: none;\n"
"    height: 8px;\n"
"    margin: 0px;\n"
"    padding: 0px;\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: none;\n"
"   \n"
"	background-color: rgb(0, 0, 0);\n"
"    height: 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5,\n"
"        stop:0.4 rgb(199, 12, 12), stop:0.5 white); /* \347\231\275\350\211\262\345\234\206\345\275\242\346\273\221\345\235\227\357\274\214\344\270\255\351\227\264\347\272\242\350\211\262 */\n"
"    border: none;\n"
"    width: 20px; /* \350\276\203\345\244\247\347\232\204\347\231\275\350\211\262\345\234\206\345\275\242 */\n"
"    height: 20px;\n"
"    margin: -6px 0px; /* \350\260\203\346\225\264\346\273\221\345\235\227\347\233\270\345\257\271\344\272\216\346\273\221\350\275\250\347\232\204\344\275\215\347\275\256 */\n"
"    border-radius: 10px; /* \345\234\206\345\275\242\346\273\221\345\235\227 */\n"
"}\n"
""
                        "\n"
"QSlider::sub-page:horizontal {\n"
"    \n"
"	background-color: rgb(199, 12, 12);\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    \n"
"	background-color: rgb(25, 25, 25);\n"
"    border-radius: 4px;\n"
"}"));
        SliderProgress->setMaximum(100);
        SliderProgress->setOrientation(Qt::Horizontal);
        layoutWidget2 = new QWidget(MainWidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(0, 100, 801, 52));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(0, 50));
        label_2->setMaximumSize(QSize(16777215, 50));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_2);

        label_Album = new QLabel(layoutWidget2);
        label_Album->setObjectName("label_Album");
        label_Album->setMinimumSize(QSize(0, 50));
        label_Album->setMaximumSize(QSize(16777215, 50));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font2.setPointSize(19);
        label_Album->setFont(font2);
        label_Album->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_Album->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_Album);

        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(0, 50));
        label_4->setMaximumSize(QSize(16777215, 50));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_4);

        label_lyric = new QLabel(MainWidget);
        label_lyric->setObjectName("label_lyric");
        label_lyric->setGeometry(QRect(0, 450, 801, 50));
        label_lyric->setMinimumSize(QSize(0, 50));
        label_lyric->setMaximumSize(QSize(16777215, 50));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246")});
        font3.setPointSize(24);
        label_lyric->setFont(font3);
        label_lyric->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(199, 12, 12);"));
        label_lyric->setAlignment(Qt::AlignCenter);
        label_currentPlay = new QLabel(MainWidget);
        label_currentPlay->setObjectName("label_currentPlay");
        label_currentPlay->setGeometry(QRect(91, 1, 431, 50));
        label_currentPlay->setMinimumSize(QSize(0, 50));
        label_currentPlay->setMaximumSize(QSize(10000, 50));
        label_currentPlay->setFont(font);
        label_currentPlay->setStyleSheet(QString::fromUtf8("\n"
"            background-color: rgba(255, 255, 255, 0); \n"
"            color: white;\n"
"            border: none;\n"
""));
        widget = new QWidget(MainWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(600, 0, 201, 52));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnClearHistory = new QPushButton(widget);
        btnClearHistory->setObjectName("btnClearHistory");
        btnClearHistory->setMinimumSize(QSize(0, 50));
        btnClearHistory->setMaximumSize(QSize(16777215, 50));
        btnClearHistory->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"            background-color: rgba(0, 0, 255, 0); /* \351\200\217\346\230\216\350\203\214\346\231\257 */\n"
"            color: white;\n"
"            border: none;\n"
"            }\n"
"            QPushButton:hover {\n"
"              background-color: rgba(255, 165, 0, 128);   /* \346\202\254\345\201\234\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"            }\n"
"            QPushButton:pressed {\n"
"              background-color: rgba(255, 100, 0, 192);     /* \346\214\211\344\270\213\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"            }"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClearHistory->setIcon(icon6);
        btnClearHistory->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(btnClearHistory);

        btnAbout = new QPushButton(widget);
        btnAbout->setObjectName("btnAbout");
        btnAbout->setMinimumSize(QSize(0, 50));
        btnAbout->setCursor(QCursor(Qt::PointingHandCursor));
        btnAbout->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"            background-color: rgba(0, 0, 255, 0); /* \351\200\217\346\230\216\350\203\214\346\231\257 */\n"
"            color: white;\n"
"            border: none;\n"
"            }\n"
"            QPushButton:hover {\n"
"              background-color: rgba(255, 165, 0, 128);   /* \346\202\254\345\201\234\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"            }\n"
"            QPushButton:pressed {\n"
"              background-color: rgba(255, 100, 0, 192);     /* \346\214\211\344\270\213\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"            }"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAbout->setIcon(icon7);
        btnAbout->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(btnAbout);

        btnSkin = new QPushButton(widget);
        btnSkin->setObjectName("btnSkin");
        btnSkin->setMinimumSize(QSize(0, 50));
        btnSkin->setCursor(QCursor(Qt::PointingHandCursor));
        btnSkin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"            background-color: rgba(0, 0, 255, 0); /* \351\200\217\346\230\216\350\203\214\346\231\257 */\n"
"            color: white;\n"
"            border: none;\n"
"            }\n"
"            QPushButton:hover {\n"
"              background-color: rgba(255, 165, 0, 128);   /* \346\202\254\345\201\234\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"            }\n"
"            QPushButton:pressed {\n"
"              background-color: rgba(255, 100, 0, 192);     /* \346\214\211\344\270\213\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"            }"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/skin.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSkin->setIcon(icon8);
        btnSkin->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(btnSkin);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 50));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"            background-color: rgba(0, 0, 255, 0); /* \351\200\217\346\230\216\350\203\214\346\231\257 */\n"
"            color: white;\n"
"            border: none;\n"
"            }\n"
"            QPushButton:hover {\n"
"              background-color: rgba(255, 165, 0, 128);   /* \346\202\254\345\201\234\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"            }\n"
"            QPushButton:pressed {\n"
"              background-color: rgba(255, 100, 0, 192);     /* \346\214\211\344\270\213\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"            }"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/min.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon9);
        pushButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(pushButton);

        btnQuit = new QPushButton(widget);
        btnQuit->setObjectName("btnQuit");
        btnQuit->setMinimumSize(QSize(0, 50));
        btnQuit->setCursor(QCursor(Qt::PointingHandCursor));
        btnQuit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"            background-color: rgba(0, 0, 255, 0); /* \351\200\217\346\230\216\350\203\214\346\231\257 */\n"
"            color: white;\n"
"            border: none;\n"
"            }\n"
"            QPushButton:hover {\n"
"              background-color: rgba(255, 165, 0, 128);   /* \346\202\254\345\201\234\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"            }\n"
"            QPushButton:pressed {\n"
"              background-color: rgba(255, 100, 0, 192);     /* \346\214\211\344\270\213\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"            }"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnQuit->setIcon(icon10);
        btnQuit->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(btnQuit);

        groupBox_pic = new QGroupBox(MainWidget);
        groupBox_pic->setObjectName("groupBox_pic");
        groupBox_pic->setGeometry(QRect(250, 150, 300, 300));
        groupBox_pic->setMinimumSize(QSize(300, 300));
        groupBox_pic->setMaximumSize(QSize(300, 300));
        groupBox_pic->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        gridLayout = new QGridLayout(groupBox_pic);
        gridLayout->setObjectName("gridLayout");
        listWidget_History = new QListWidget(MainWidget);
        listWidget_History->setObjectName("listWidget_History");
        listWidget_History->setGeometry(QRect(565, 150, 235, 300));
        listWidget_History->setMinimumSize(QSize(235, 300));
        listWidget_History->setMaximumSize(QSize(235, 300));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        listWidget_History->setFont(font4);
        listWidget_History->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"selection-background-color: orange;\n"
"}\n"
"QListWidget::item:selected {\n"
"    /* \351\200\211\344\270\255\351\241\271\347\233\256\346\240\267\345\274\217 */\n"
"\n"
"	background-color: rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
"\n"
"}\n"
"QListWidget::item:hover {\n"
"    /* \346\202\254\346\265\256\351\241\271\347\233\256\346\240\267\345\274\217 */\n"
"\n"
"	text-decoration: underline;\n"
"	background-color: rgb(180, 180, 180);\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: transparent;\n"
"    width: 15px;\n"
"    margin: 15px 3px 15px 3px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: rgb(40, 40, 40); /* \350\256\276\347\275\256\346\273\232\345\212\250\346\235\241\351\242\234\350\211\262 */\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    background: none;\n"
"    "
                        "height: 0px;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"    background: none;\n"
"}"));
        listWidget_Search = new QListWidget(MainWidget);
        listWidget_Search->setObjectName("listWidget_Search");
        listWidget_Search->setGeometry(QRect(0, 150, 250, 300));
        listWidget_Search->setMinimumSize(QSize(250, 300));
        listWidget_Search->setMaximumSize(QSize(250, 300));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        listWidget_Search->setFont(font5);
        listWidget_Search->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"selection-background-color: orange;\n"
"}\n"
"QListWidget::item:selected {\n"
"    /* \351\200\211\344\270\255\351\241\271\347\233\256\346\240\267\345\274\217 */\n"
"\n"
"	background-color: rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
"\n"
"}\n"
"QListWidget::item:hover {\n"
"    /* \346\202\254\346\265\256\351\241\271\347\233\256\346\240\267\345\274\217 */\n"
"\n"
"	text-decoration: underline;\n"
"	background-color: rgb(180, 180, 180);\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: transparent;\n"
"    width: 15px;\n"
"    margin: 15px 3px 15px 3px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: rgb(40, 40, 40); /* \350\256\276\347\275\256\346\273\232\345\212\250\346\235\241\351\242\234\350\211\262 */\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    background: none;\n"
"    "
                        "height: 0px;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"    background: none;\n"
"}"));

        retranslateUi(MainWidget);
        QObject::connect(btnQuit, &QPushButton::clicked, MainWidget, qOverload<>(&QWidget::close));
        QObject::connect(pushButton, &QPushButton::clicked, MainWidget, qOverload<>(&QWidget::showMinimized));

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "MainWidget", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWidget", "\346\220\234\347\264\242\346\255\214\346\233\262\345\220\215\347\247\260", nullptr));
        lineEdit_Search->setText(QCoreApplication::translate("MainWidget", "\345\221\250\346\235\260\344\274\246", nullptr));
#if QT_CONFIG(tooltip)
        btnSearch->setToolTip(QCoreApplication::translate("MainWidget", "\347\202\271\345\207\273\346\220\234\347\264\242\346\203\263\345\220\254\347\232\204\346\255\214\346\233\262\345\220\247", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSearch->setText(QCoreApplication::translate("MainWidget", "\346\220\234 \347\264\242...", nullptr));
#if QT_CONFIG(tooltip)
        btnLast->setToolTip(QCoreApplication::translate("MainWidget", "\344\270\212\344\270\200\346\233\262", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLast->setText(QString());
#if QT_CONFIG(tooltip)
        btnPlay->setToolTip(QCoreApplication::translate("MainWidget", "\346\222\255\346\224\276/\346\232\202\345\201\234", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPlay->setText(QString());
#if QT_CONFIG(tooltip)
        btnNext->setToolTip(QCoreApplication::translate("MainWidget", "\344\270\213\344\270\200\346\233\262", nullptr));
#endif // QT_CONFIG(tooltip)
        btnNext->setText(QString());
#if QT_CONFIG(tooltip)
        btnRepeat->setToolTip(QCoreApplication::translate("MainWidget", "\345\210\207\346\215\242\345\276\252\347\216\257\346\250\241\345\274\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnRepeat->setText(QString());
#if QT_CONFIG(tooltip)
        btnSound->setToolTip(QCoreApplication::translate("MainWidget", "\351\237\263\351\207\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSound->setText(QString());
        label_voice->setText(QCoreApplication::translate("MainWidget", "30", nullptr));
        label_currentTime->setText(QCoreApplication::translate("MainWidget", "00:00", nullptr));
        label_5->setText(QCoreApplication::translate("MainWidget", "/", nullptr));
        label_totalTime->setText(QCoreApplication::translate("MainWidget", "00:00", nullptr));
        label_2->setText(QCoreApplication::translate("MainWidget", "\346\220\234\347\264\242\346\255\214\346\233\262", nullptr));
        label_Album->setText(QCoreApplication::translate("MainWidget", "\344\270\223\350\276\221", nullptr));
        label_4->setText(QCoreApplication::translate("MainWidget", "\346\222\255\346\224\276\345\216\206\345\217\262", nullptr));
        label_lyric->setText(QString());
        label_currentPlay->setText(QCoreApplication::translate("MainWidget", "\345\275\223\345\211\215\346\222\255\346\224\276\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnClearHistory->setToolTip(QCoreApplication::translate("MainWidget", "\346\270\205\347\251\272\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
        btnClearHistory->setText(QString());
#if QT_CONFIG(tooltip)
        btnAbout->setToolTip(QCoreApplication::translate("MainWidget", "\345\205\263\344\272\216", nullptr));
#endif // QT_CONFIG(tooltip)
        btnAbout->setText(QString());
#if QT_CONFIG(tooltip)
        btnSkin->setToolTip(QCoreApplication::translate("MainWidget", "\346\233\264\346\215\242\347\232\256\350\202\244", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSkin->setText(QString());
        pushButton->setText(QString());
#if QT_CONFIG(tooltip)
        btnQuit->setToolTip(QCoreApplication::translate("MainWidget", "<html><head/><body><p>\345\205\263\351\227\255</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnQuit->setText(QString());
        groupBox_pic->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
