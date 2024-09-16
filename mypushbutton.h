#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include<QPropertyAnimation>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
class MyPushButton : public QPushButton
{
    Q_OBJECT

public:


    MyPushButton(QString);//显示图片网址

    void setButton(QString);//设置自定义按键


    QNetworkAccessManager *networkManager;


    QString PicUrl;
    QString lyricText;//歌词文本

    QString style="QPushButton {"
        "background-color: rgba(0, 0, 255, 0); /* 透明背景 */"
    "color: white;"
    "border: none;"
                    "}";


signals:




};

#endif // MYPUSHBUTTON_H
