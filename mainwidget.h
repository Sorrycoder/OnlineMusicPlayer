#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<QPainter>

#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>

#include<QEventLoop>

#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>

#include<QMediaPlayer>
#include<QAudioOutput>


#include<QDebug>

#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QSqlRecord>

#include<QMessageBox>

#include<QMenu>
#include"mypushbutton.h"
#include "LyricDialog.h"
#include <QMutex>

static QString kugouSearchApi ="http://mobilecdn.kugou.com/api/v3/search/song?";//歌单api
static QString kugouSongApi="https://api.xingzhige.com/API/Kugou_GN_new/?&page=1&pagesize=100";//歌源api
static QString kugoulyricApi="https://api.xingzhige.com//API/lyrc/?type=kugou&id=";//歌词api

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWidget;
}
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
signals:
    //携带json数据
    void finish(QByteArray);
public:


    //音乐下载和播放
    void downloadPlayer(int ,QString);
    //访问http网页
    void httpAccess(QString);
    //读取返回数据
    void netReply(QNetworkReply *);
    //解析搜索结果
    void hashJsonAnalysis(QByteArray);
    //解析音乐信息，提取音乐文件
    QString musicJsonAnalysis(QByteArray);

private slots:
    //应用程序关于信息
    void on_btnAbout_clicked();
    //搜索音乐---fromKugou
    void on_btnSearch_clicked();
    //播放进度条
    void on_SliderProgress_valueChanged(int value);
    void on_SliderProgress_sliderPressed();
    void on_SliderProgress_sliderReleased();
    //音量调节
    void on_SliderSound_valueChanged(int value);
    //上一曲
    void on_btnLast_clicked();
    //播放/暂停
    void on_btnPlay_clicked();
    //下一曲
    void on_btnNext_clicked();
    //循环播放模式
    void on_btnRepeat_clicked();
    //静音
    void on_btnSound_clicked();


    //双击音乐播放
    void playSearchMusic();//双击搜索列表
    void playHistoryMusic();//双击历史播放列表

    //更新播放的进度条和显示的时间
    void updateDuration(qint64);
    //换歌时更新总时长和
    void updateTotalTime(qint64);
    //清空播放历史
    void on_btnClearHistory_clicked();
    //媒体状态判断循环模式槽函数
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);

    //更换皮肤
    void backgroundDefault();//默认皮肤
    void backgroundSetting();//自定义皮肤

    //显示歌词
    //查询数据库获取歌词hash
    void getLyric();
    //下载歌词
    void downloadLyric(QString);
    //歌词json解析
    QString lyricJsonAnalysis(QByteArray);
    //正则表达式提取歌词
    void loadLyrics(QString );
    //歌词显示在ui上
    void updateLyricIndex(int currentTime);



private:
    Ui::MainWidget *ui;
    //窗口移动时候，鼠标和左上角偏移
    QPoint m_offset;
    //网络控制器
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    //播放媒体
    QMediaPlayer *player;
    //sqlite数据库
    QSqlDatabase db;
    //更换皮肤菜单
    QMenu *menuSkin;
    //专辑图片
    MyPushButton *btnAni;
    //歌词窗口
    LyricDialog *lyricDialog;



    bool i=true;//是否按下进度条

    bool mousepress;//鼠标是否按下

    bool loopMode=true; // 表示是否处于单曲循环模式,
    int currentSongIndex=0; // 记录当前播放的歌曲索引

    QString currentPic;//记录当前pic


    bool SourceType;//记录当前是搜索还是历史表，更新歌词用

    QList<QPair<qint64, QString>> lyrics;//存储歌词QList
    int currentLyricIndex = 0; // 当前歌词索引
    QString currentAlbum;//当前专辑名



protected:
    virtual void mousePressEvent(QMouseEvent *event) override;

    virtual void mouseMoveEvent(QMouseEvent *event) override;

    virtual void mouseReleaseEvent(QMouseEvent *event) override;

    //virtual void paintEvent(QPaintEvent *event) override;



};
#endif // MAINWIDGET_H
