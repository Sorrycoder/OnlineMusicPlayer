#include "mypushbutton.h"
#include<QDebug>
#include <QMouseEvent>
#include <QPainter>
#include <QSequentialAnimationGroup>

MyPushButton::MyPushButton(QString normalImg)
{

    networkManager=new QNetworkAccessManager(this);
    this->PicUrl=normalImg;
    //加载图片
    this->setButton(this->PicUrl);
    this->setStyleSheet(this->style);

}
void MyPushButton::setButton(QString PicUrl)
{
    // 清除之前的图标

    this->setIcon(QIcon());
    //qDebug()<<picPath;

    // 创建一个请求对象
    QNetworkRequest request(PicUrl);
    // 发起网络请求
    QNetworkReply *reply = networkManager->get(request);

    // 创建一个事件循环，等待网络请求完成
    QEventLoop eventLoop;
    connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();

    // 检查请求是否成功
    if (reply->error() == QNetworkReply::NoError)
    {
        // 将数据转换为QPixmap
        QPixmap pic;
        QByteArray imageData = reply->readAll();
        if (pic.loadFromData(imageData)) {
            // 设置按钮尺寸
            this->setFixedSize(300, 300);
            // 无边框, 圆形
            this->setStyleSheet("QPushButton{border:0px;}");
            // 设置图标
            this->setIcon(QIcon(pic));
            // 设置图标大小
            this->setIconSize(QSize(300, 300));
        }

    }

    // 删除回复对象
    reply->deleteLater();
}


