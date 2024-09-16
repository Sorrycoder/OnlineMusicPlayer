#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QMouseEvent>
#include<QMenu>
#include <QFileDialog>
#include<QStandardPaths>
#include <QTimer>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //专辑图片
    btnAni = new MyPushButton("");
    btnAni->setParent(ui->groupBox_pic);

    //btnAni->move(this->width()*0.3+11, this->height() * 0.2+40);
    connect(btnAni,&MyPushButton::clicked,this,&MainWidget::getLyric);
    //歌词
    lyricDialog=new LyricDialog;
    lyricDialog->setParent(this);

    //lyricDialog->show();
    lyricDialog->move((this->width()-lyricDialog->width())/2+7,(this->height()-lyricDialog->height())/2);



    //创建数据库
    //如果有默认数据库就连接，没有就新建
    if(QSqlDatabase::contains("sql_default_connection"))
    {
        db=QSqlDatabase::database("sql_default_connection");
    }
    else
    {
        db=QSqlDatabase::addDatabase("QSQLITE");//添加数据库，得到默认链接
        db.setDatabaseName("mp3listdatabase.db");
    }

    if(!db.open())//打开数据库
    {
        QMessageBox::critical(nullptr,"打开数据库错误",db.lastError().text());
    }
    else
    {
        QSqlQuery query;
        //利用QSqlQuery创建searchlist和historysong两个表

        QString sql="create table if not exists searchlist(id integer,songname text,name text,orgin text,hash text)";

        if(!query.exec(sql))
        {
            QMessageBox::critical(nullptr,"创建搜索表错误",db.lastError().text());
        }

        //歌曲历史
        sql="create table if not exists historysong(songname text,name text,orgin text,id integer,hash text)";
        if(!query.exec(sql))
        {
            QMessageBox::critical(nullptr,"创建历史痕迹表错误",db.lastError().text());
        }
        //查询历史数据表中的插入歌曲数据
        sql="select *from historysong;";//
        if(!query.exec(sql))
        {
            QMessageBox::critical(nullptr,"查询历史失败",db.lastError().text());
        }

        while(query.next())//循环查询获取歌曲和歌手
        {
            QString songname,name;
            QSqlRecord rec=query.record();//获取一条记录
            int songnamekey=rec.indexOf("songname");
            int namekey=rec.indexOf("name");
            songname=query.value(songnamekey).toString();
            name=query.value(namekey).toString();
            //qDebug()<<songname;
            //qDebug()<<name;
            QString strshow=songname+"--"+name;
            QListWidgetItem *item=new QListWidgetItem(strshow);
            ui->listWidget_History->addItem(item);

        }
    }

    //播放媒体实例化
    player=new QMediaPlayer;
    QAudioOutput *audioOutput=new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    //当前播放label
    ui->label_currentPlay->setAttribute(Qt::WA_TransparentForMouseEvents);//过滤鼠标事件
    //换歌时，播放时长变化
    connect(player,&QMediaPlayer::durationChanged,this,&MainWidget::updateTotalTime);
    //播放进度条和事件
    connect(player,&QMediaPlayer::positionChanged,this,&MainWidget::updateDuration);

    //双击列表播放
    connect(ui->listWidget_Search,&QListWidget::doubleClicked,this,&MainWidget::playSearchMusic);
    connect(ui->listWidget_History,&QListWidget::doubleClicked,this,&MainWidget::playHistoryMusic);
    //媒体状态变化
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &MainWidget::onMediaStatusChanged);
    //更换皮肤
    QAction *actDefault=new QAction(QIcon(":/images/defaultBackground.png"),"默认皮肤");
    connect(actDefault,&QAction::triggered,this,&MainWidget::backgroundDefault);
    QAction *actSetting=new QAction(QIcon(":/images/backgroundSetting.png"),"选择皮肤");
    connect(actSetting,&QAction::triggered,this,&MainWidget::backgroundSetting);
    menuSkin=new QMenu(this);
    menuSkin->addAction(actDefault);
    menuSkin->addAction(actSetting);
    connect(ui->btnSkin,&QPushButton::clicked,[=](){
        menuSkin->exec(QCursor::pos());
    });
    backgroundDefault();

}

MainWidget::~MainWidget()
{
    delete ui;
}



//搜索音乐---酷狗
void MainWidget::on_btnSearch_clicked()
{
    //把搜索到的列表清空
    ui->listWidget_Search->clear();

    //清理数据库已经存储的数据
    QSqlQuery query;
    QString sql="delete from searchlist;";
    if(!query.exec(sql))
    {
        QMessageBox::critical(0,"SQL错误","delete from searchlist错误",db.lastError().text());
    }
    //根据音乐名称发起请求
    QString url=kugouSearchApi+QString("format=json&keyword=%1&page=1&pagesize=100&showtype=1").arg(ui->lineEdit_Search->text());
    qDebug()<<url;
    httpAccess(url);
    QByteArray jsonData;
    QEventLoop loop;//QEventLoop异步提取返回的json内容
    auto c=connect(this,&MainWidget::finish,[&](const QByteArray &data)//[&]引用捕获，可修改外部值
                     {
                         jsonData=data;
                         loop.exit(1);
                     });
    loop.exec();
    disconnect(c);

    //解析网页回复的数据，把搜到的音乐信息存在数据库里
    hashJsonAnalysis(jsonData);
}

//访问http网页
void MainWidget::httpAccess(QString url)
{

    manager=new QNetworkAccessManager(this);
    QNetworkRequest res(url);
    reply=manager->get(res);
    //等待回应读取数据
    connect(manager,&QNetworkAccessManager::finished,this,&MainWidget::netReply);
}

//读取网络数据
void MainWidget::netReply(QNetworkReply *reply)
{

    int status=reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();//获取响应码
    reply->attribute(QNetworkRequest::RedirectionTargetAttribute);//自动处理重定向
    if(reply->error()==QNetworkReply::NoError&&status==200){
        QByteArray data= reply->readAll();
        emit finish(data);
    }else{//出错了
        QMessageBox::warning(nullptr,"搜索歌曲","请求数据失败",QMessageBox::Ok);
    }
    reply->deleteLater();


}

void MainWidget::hashJsonAnalysis(QByteArray Jsondata)
{

    QJsonDocument doc=QJsonDocument::fromJson(Jsondata);
    if(doc.isObject())//最外层一个obj
    {
        QJsonObject objRoot=doc.object();
        if(objRoot.contains("data"))//key为data的项是obj
        {
            QJsonObject objdata=objRoot.value("data").toObject();
            if(objdata.contains("info"))//data里有个info数组
            {
                QJsonArray arrayInfo=objdata.value("info").toArray();
                for(int i=0;i<arrayInfo.count();i++)//info数组里存储的是obj
                {
                    QString songname,singername,orgin,hash;//提取信息
                    QJsonObject album=arrayInfo[i].toObject();
                    if(album.contains("album_id"))
                    {
                        orgin=ui->lineEdit_Search->text();
                    }
                    if(album.contains("songname"))
                    {
                        songname=album.value("songname").toString();
                    }
                    if(album.contains("singername"))
                    {
                        singername=album.value("singername").toString();
                    }
                    if(album.contains("hash"))
                    {
                        hash=album.value("hash").toString();
                        //qDebug()<<"hash:"<<hash;
                    }

                    QSqlQuery query;
                    QString sql = QString("insert into searchlist values(%1,'%2','%3','%4','%5');")
                                      .arg(QString::number(i))
                                      .arg(songname)
                                      .arg(singername)
                                      .arg(orgin)
                                      .arg(hash);
                    if(!query.exec(sql))
                    {
                        QMessageBox::critical(nullptr,"searchlist插入失败",db.lastError().text());
                    }

                    //将解析的音乐名称存入listWidget_Search空间里显示
                    QString show=songname+"--"+singername;
                    QListWidgetItem *item=new QListWidgetItem(show);
                    ui->listWidget_Search->addItem(item);
                }

            }
        }
    }
}

//双击搜索列表
void MainWidget::playSearchMusic()
{
    //获取双击歌曲索引
    int row=ui->listWidget_Search->currentRow();
    //qDebug()<<"row= "<<row;
    currentSongIndex = row;
    SourceType=false;
    //数据库里查询
    QSqlQuery query;
    QString sql=QString("select *from searchlist where id=%1;").arg(row);

    if(!query.exec(sql))
    {
        QMessageBox::critical(this,"查询搜索数据库错误",query.lastError().text());
        return;
    }

    //选中音乐放入历史记录表并更新ui
    QString songname,name,orgin,hash;
    int id;
    while(query.next())
    {
        QSqlRecord rec=query.record();
        int songnamekey=rec.indexOf("songname");
        int namekey=rec.indexOf("name");
        int orginkey=rec.indexOf("orgin");
        int idkey=rec.indexOf("id");
        int hashkey=rec.indexOf("hash");
        songname=query.value(songnamekey).toString();
        name=query.value(namekey).toString();
        orgin=query.value(orginkey).toString();
        id=query.value(idkey).toInt();
        hash=query.value(hashkey).toString();
        //qDebug()<<songname;
        //qDebug()<<name;
        //qDebug()<<orgin;
        if(query.next()==NULL)
        {
            sql=QString("insert into historysong values('%1','%2','%3','%4','%5')")
                      .arg(songname)
                      .arg(name)
                      .arg(orgin)
                      .arg(id)
                      .arg(hash);
            if(!query.exec(sql))
            {
                QMessageBox::critical(this,"insert into historysong错误",db.lastError().text());
            }

            //把解析的音乐信息保存在listWidget_History里
            QString show=songname+"--"+name;
            QListWidgetItem *item=new QListWidgetItem(show);
            ui->listWidget_History->addItem(item);
        }


    }
    downloadPlayer(row,orgin);
    // 更新当前播放的歌曲名，专辑图等ui
    QListWidgetItem *item = ui->listWidget_History->item(ui->listWidget_History->count() - 1);
    if (item) {
        ui->label_currentPlay->setText("当前播放："+item->text());
    }
    btnAni->setButton(currentPic);
    ui->label_Album->setText(currentAlbum);
    ui->btnPlay->setIcon(QIcon(":/images/pause.png"));
}

//音乐下载和播放
void MainWidget::downloadPlayer(int id,QString orgin)
{
    QString url=kugouSongApi+QString("&name=%1&n=%2").arg(orgin).arg(id + 1);

    qDebug() << url;
    //发起http请求
    httpAccess(url);

    //捕获数据
    QByteArray JsonData;
    QEventLoop loop;
    auto d = connect(this, &MainWidget::finish, [&](const QByteArray &data) {
        JsonData = data;
        loop.exit();
    });
    loop.exec();
    disconnect(d);

    // 解析音乐信息，返回播放地址url
    QString music = musicJsonAnalysis(JsonData);

    //qDebug()<<currentPic;
    // 检查音乐url是否为空
    if (music.isEmpty()) {
        QMessageBox::critical(this,"解析错误","无法找到播放源");
        return;
    }
    //播放设置
    player->setSource(QUrl(music));
    //设置音量
    player->audioOutput()->setVolume(30);
    ui->SliderSound->setValue(30);
    //循环模式
    if(this->loopMode){
        player->setLoops(QMediaPlayer::Infinite);
    }else{
        player->setLoops(1);
    }
    //播放
    player->play();
    btnAni->click();
}
//解析音乐信息，获得播放地址
QString MainWidget::musicJsonAnalysis(QByteArray JsonData)
{
    QJsonDocument doc=QJsonDocument::fromJson(JsonData);
    //qDebug()<<QString::fromUtf8(JsonData);
    if(doc.isObject())
    {
        QJsonObject objRoot=doc.object();
        if(objRoot["code"]!=0)
        {
            QMessageBox::critical(this,"musicJsonAnalysis","提取api错误",db.lastError().text());
            return"";
        }
        if(objRoot.contains("data"))
        {
            QJsonObject jsondata=objRoot.value("data").toObject();
            if(jsondata.contains("cover"))
            {
                currentPic=jsondata.value("cover").toString();
                //qDebug()<<"cover:"<<jsondata.value("cover").toString();
            }
            if(jsondata.contains("album"))
            {
                currentAlbum=jsondata.value("album").toString();
                //qDebug()<<"cover:"<<jsondata.value("album").toString();
            }
            if(jsondata.contains("src"))
            {
                //qDebug()<<"src:"<<jsondata.value("src").toString();
                return jsondata.value("src").toString();
            }
        }
    }
}

//双击历史播放列表
void MainWidget::playHistoryMusic()
{
    //获取双击歌曲索引
    currentSongIndex=ui->listWidget_History->currentRow();
    SourceType=true;
    //qDebug()<<"currentSongIndex="<<currentSongIndex;
    //数据库里查询
    QSqlQuery query;
    QString sql=QString("select *from historysong where rowid=%1;").arg(currentSongIndex+1);
    //qDebug()<<"sql="<<sql;
    if(!query.exec(sql))
    {
        QMessageBox::critical(nullptr,"查询历史数据库错误",db.lastError().text());
        return;
    }
    QString orgin;
    int id;
    while(query.next())
    {
        QSqlRecord rec=query.record();
        int orginkey=rec.indexOf("orgin");
        int idkey=rec.indexOf("id");
        orgin=query.value(orginkey).toString();
        id=query.value(idkey).toInt();

    }
    //qDebug()<<"id="<<id;
    downloadPlayer(id,orgin);
    // 更新当前播放的歌曲名,歌词等信息
    QListWidgetItem *item = ui->listWidget_History->item(currentSongIndex);
    if (item) {
        ui->label_currentPlay->setText("当前播放："+item->text());
    }
    //qDebug()<<currentPic;
    ui->btnPlay->setIcon(QIcon(":/images/pause.png"));
    btnAni->setButton(currentPic);
    ui->label_Album->setText(currentAlbum);



}

//播放/暂停
void MainWidget::on_btnPlay_clicked()
{
    if(player->playbackState()==QMediaPlayer::PlayingState)
    {
        player->pause();
        ui->btnPlay->setIcon(QIcon(":/images/play.png"));
    }else if(player->playbackState()==QMediaPlayer::PausedState)
    {
        player->play();
        ui->btnPlay->setIcon(QIcon(":/images/pause.png"));
    }
}

//上一曲
void MainWidget::on_btnLast_clicked()
{
    currentSongIndex--;
    SourceType=true;
    if (currentSongIndex <= 0) {
        currentSongIndex = ui->listWidget_History->count()-1; // 如果超出列表范围，回到末尾
    }
    QSqlQuery query;
    QString sql=QString("select *from historysong where rowid=%1;").arg(currentSongIndex+1);

    qDebug()<<"sql="<<sql;
    if (!query.exec(sql)) {
        QMessageBox::critical(nullptr, "上一曲失败", db.lastError().text());
    }
    QString orgin;
    int id;
    while(query.next())
    {
        QSqlRecord rec=query.record();
        int orginkey=rec.indexOf("orgin");
        int idkey=rec.indexOf("id");
        orgin=query.value(orginkey).toString();
        id=query.value(idkey).toInt();
    }
    downloadPlayer(id,orgin);
    // 更新当前播放的歌曲名
    QListWidgetItem *item = ui->listWidget_History->item(currentSongIndex);
    if (item)
    {
        ui->label_currentPlay->setText("当前播放："+item->text());
    }
    btnAni->setButton(currentPic);
    ui->label_Album->setText(currentAlbum);

    //更新播放按钮
    ui->btnPlay->setIcon(QIcon(":/images/pause.png"));
}

//下一曲
void MainWidget::on_btnNext_clicked()
{
    currentSongIndex++;
    SourceType=true;
    if (currentSongIndex >= ui->listWidget_History->count()) {
        currentSongIndex = 0; // 如果超出列表范围，回到第一首
    }
    //数据库里查询
    QSqlQuery query;
    QString sql=QString("select *from historysong where rowid=%1;").arg(currentSongIndex+1);
    //qDebug()<<sql;
    if(!query.exec(sql))
    {
        QMessageBox::critical(nullptr,"查询错误","下一曲错误",db.lastError().text());
        return;
    }
    QString orgin;
    int id;
    while(query.next())
    {
        QSqlRecord rec=query.record();
        int orginkey=rec.indexOf("orgin");
        int idkey=rec.indexOf("id");
        orgin=query.value(orginkey).toString();
        id=query.value(idkey).toInt();
    }
    downloadPlayer(id,orgin);
    // 更新当前播放的歌曲名
    QListWidgetItem *item = ui->listWidget_History->item(currentSongIndex);
    if (item) {
        ui->label_currentPlay->setText("当前播放："+item->text());
    }
    btnAni->setButton(currentPic);
    ui->label_Album->setText(currentAlbum);

    //更新播放按钮
    ui->btnPlay->setIcon(QIcon(":/images/pause.png"));
    //qDebug()<<"currentSongIndex:"<<currentSongIndex;
}

//循环模式
void MainWidget::on_btnRepeat_clicked()
{
    loopMode = !loopMode; // 切换循环模式
    if(loopMode)
    {// 如果单曲循环
        player->setLoops(QMediaPlayer::Infinite);
        ui->btnRepeat->setIcon(QIcon(":/images/single.png")); // 设置按钮图标
    }else
    {//列表循环
        player->setLoops(1);
        ui->btnRepeat->setIcon(QIcon(":/images/list.png")); // 设置按钮图标
    }
}

//滑动控制音量
void MainWidget::on_SliderSound_valueChanged(int value)
{
    player->audioOutput()->setVolume(value/100.0);
    ui->label_voice->setText(QString::number(value));
}

//静音
void MainWidget::on_btnSound_clicked()
{
    bool flag=player->audioOutput()->isMuted();//当前是否静音
    player->audioOutput()->setMuted(!flag);//和当前相反
    if(flag)//当前静音,转成有声
    {
        ui->btnSound->setIcon(QIcon(":/images/sound-on.png"));
        ui->SliderSound->setEnabled(true);
    }else
    {
        ui->btnSound->setIcon(QIcon(":/images/sound-off.png"));
        //ui->SliderSound->setValue(0);
        ui->SliderSound->setEnabled(false);
    }
}
//拖动进度条
void MainWidget::on_SliderProgress_valueChanged(int value)//播放进度控制,用flag控制不用频繁调用setPosition
{
    if(i==false)
        player->setPosition(qint64(value));

    updateLyricIndex(value);

    int mins = value / 60000; // 转换成分钟
    int secs = (value % 60000) / 1000;
    QString time = QString("%1:%2")
                       .arg(mins, 2, 10, QChar('0')) // 分钟，两位数
                       .arg(secs, 2, 10, QChar('0')); // 秒数，两位数
    ui->label_currentTime->setText(time);

}
void MainWidget::on_SliderProgress_sliderPressed()
{
    i=false;

}
void MainWidget::on_SliderProgress_sliderReleased()
{
    i=true;
}

//清理播放记录
void MainWidget::on_btnClearHistory_clicked()
{
    QSqlQuery query;
    QString dropSql = "drop table if exists historysong";
    QString createSql = "create table if not exists historysong(songname text,name text,orgin text,id integer,hash text)";
    //删除表
    if (!query.exec(dropSql)) {
        QMessageBox::critical(nullptr, "删除历史表错误", query.lastError().text());
        return;
    }
    //重新创建表
    if (!query.exec(createSql)) {
        QMessageBox::critical(nullptr, "创建历史表错误", query.lastError().text());
        return;
    }
    //更新UI
    ui->listWidget_History->clear();
    QListWidgetItem *item = ui->listWidget_History->item(currentSongIndex);
    if (item) {
        ui->label_currentPlay->setText("当前播放：");
    }
}

//默认皮肤
void MainWidget::backgroundDefault()
{
    QPalette palette=this->palette();
    QPixmap pic;
    pic.load(":/images/skins/skin-1.jpg");//缩放
    pic=pic.scaled(this->size(),Qt::IgnoreAspectRatio,//可改变比例
                     Qt::SmoothTransformation);//平滑缩放
    palette.setBrush(QPalette::Window,QBrush(pic));
    this->setPalette(palette);
}
//自定义皮肤
void MainWidget::backgroundSetting()
{
    //选择图片
    QString  aFilename=QFileDialog::getOpenFileName(this,"请选择自定义背景图片",//默认打开位置为系统图片目录
                                                     QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).first(),"图片(*.jpg *.png)");
    QPalette palette=this->palette();
    QPixmap pic;
    pic.load(aFilename);//缩放
    pic=pic.scaled(this->size(),Qt::IgnoreAspectRatio,//可改变比例
                     Qt::SmoothTransformation);//平滑缩放
    palette.setBrush(QPalette::Window,QBrush(pic));
    this->setPalette(palette);
}
void MainWidget::getLyric()
{
    QString hash;
    if (SourceType) {
        // 从历史表中获取 hash
        QSqlQuery query;
        QString sql = QString("select * from historysong where rowid=%1;").arg(currentSongIndex + 1);
        if (!query.exec(sql)) {
            QMessageBox::critical(nullptr, "查询历史数据库错误", db.lastError().text());
            return;
        }

        while (query.next()) {
            QSqlRecord rec = query.record();
            int hashkey = rec.indexOf("hash");
            hash = query.value(hashkey).toString();
        }
    } else {
        // 从搜索表中获取 hash
        QSqlQuery query;
        QString sql = QString("select * from searchlist where id=%1;").arg(currentSongIndex);
        if (!query.exec(sql)) {
            QMessageBox::critical(nullptr, "查询搜索数据库错误", db.lastError().text());
            return;
        }

        while (query.next()) {
            QSqlRecord rec = query.record();
            int hashkey = rec.indexOf("hash");
            hash = query.value(hashkey).toString();
        }
    }
    // 下载歌词
    downloadLyric(hash);
}
void MainWidget::downloadLyric(QString hash)
{
    QString url =kugoulyricApi+hash;
    //qDebug() <<"downloadLyricurl="<< url;
    //发起http请求
    httpAccess(url);
    //捕获数据
    QByteArray JsonData;
    QEventLoop loop;
    auto e = connect(this, &MainWidget::finish, [&](const QByteArray &data) {
        JsonData = data;
        loop.exit();
    });
    loop.exec();
    disconnect(e);
    //qDebug()<<"JsonData="<<QString::fromUtf8(JsonData);

    //解析获得歌词
    QString lyric = lyricJsonAnalysis(JsonData);

    if (lyric.isEmpty()) {
        QMessageBox::critical(this,"解析错误","无法找到歌词");
        return;
    }
    //qDebug()<<"lyric="<<lyric;

    // 更新歌词对话框内容
    loadLyrics(lyric);
    lyricDialog->setLyric(lyric);
    //lyricDialog->move(this->width()-lyricDialog->width()*0.8+27,this->height()-lyricDialog->height()+25);
    lyricDialog->show(); // 显示歌词对话框（如果之前未显示）

}
QString MainWidget::lyricJsonAnalysis(QByteArray JsonData)
{
    QJsonDocument doc=QJsonDocument::fromJson(JsonData);

    if(doc.isObject())
    {
        QJsonObject objRoot=doc.object();
        if(objRoot["code"]!=0)
        {
            QMessageBox::critical(this,"lyricJsonAnalysis","提取api错误",db.lastError().text());
            return"";
        }
        if(objRoot.contains("data"))
        {
            QJsonObject data=objRoot.value("data").toObject();
            if(data.contains("encode"))
            {
                //qDebug()<<"jsonencode:"<<jsondata.value("encode").toString();
                QJsonObject encode  =data.value("encode").toObject();
                if(encode.contains("context"))
                    //qDebug()<<"context="<<encode.value("context").toString();
                    return encode.value("context").toString();
            }

        }
    }

}

void MainWidget::on_btnAbout_clicked()
{
    QMessageBox::about(this,"关于","MP3音乐在线播放\n"
                                     "播放器功能如下:\n"
                                     "上一曲 播放/暂停 下一曲 循环播放\n"
                                     "数据来源:酷狗音乐\n"
                                     "api：星之阁API");
}

//切歌时候更换label
void MainWidget::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia && !loopMode) {//非单曲循环且到末尾
        on_btnNext_clicked();
    }
}
//进度条跟随播放进度
void MainWidget::updateDuration(qint64 value)
{
    ui->SliderProgress->setSliderPosition(value);
}

//媒体总时长变化时/切歌
void MainWidget::updateTotalTime(qint64 duration)
{
    ui->SliderProgress->setMaximum(duration);
    int mins = duration / 60000; // 转换成分钟
    int secs = (duration % 60000) / 1000;
    QString time = QString("%1:%2")
                       .arg(mins, 2, 10, QChar('0')) // 分钟，两位数
                       .arg(secs, 2, 10, QChar('0')); // 秒数，两位数
    ui->label_totalTime->setText(time);
}
//拖动窗口实现
void MainWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        mousepress=true;
    }
    QPoint globalPos=event->globalPos();
    QPoint windowPos=this->pos();
    m_offset=globalPos-windowPos;

}
void MainWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(mousepress==true)
        this->move(event->globalPos()-m_offset);

}
void MainWidget::mouseReleaseEvent(QMouseEvent *event)
{
    mousepress=false;
}

void MainWidget::loadLyrics(QString lyricText) {
    lyrics.clear();
    // 将文本分解为每一行
    QStringList lines = lyricText.split(QRegularExpression("\\r?\\n"));

    foreach (QString line, lines) {
        line = line.trimmed(); // 清除行首行尾的空白和回车符
        if (!line.isEmpty()) {
            //qDebug() << "Line:" << line; // 调试输出每一行

            // 匹配时间戳行
            QRegularExpression regex(R"(\[(\d{2}):(\d{2})\.(\d{2})\](.*))");
            QRegularExpressionMatch match = regex.match(line);
            if (match.hasMatch()) {
                int minutes = match.captured(1).toInt();
                int seconds = match.captured(2).toInt();
                int milliseconds = match.captured(3).toInt();
                QString lyric = match.captured(4).trimmed();
                //qDebug() << "Matched Timestamp:" << minutes << ":" << seconds << "." << milliseconds;
                //qDebug() << "Lyric:" << lyric;

                qint64 timestamp = minutes * 60 * 1000 + seconds * 1000 + milliseconds * 10;//转成毫秒
                lyrics.append(qMakePair(timestamp, lyric));
            }

        }
    }
    //qDebug() << "Loaded lyrics count:" << lyrics.size();
    currentLyricIndex = 0; // 重置歌词索引
}



void MainWidget::updateLyricIndex(int currentTime) {

    while (currentLyricIndex < lyrics.size() && currentTime >= lyrics[currentLyricIndex].first)//当前时间大于当前歌词时间，往后拖进度
        {
            currentLyricIndex++;
        }
    while (currentLyricIndex > 0 && currentTime < lyrics[currentLyricIndex - 1].first)//当前时间小于当前歌词时间，往前拖进度
        {
            currentLyricIndex--;
        }

    // 更新歌词显示
    if (currentLyricIndex > 0) {
        ui->label_lyric->setText(lyrics[currentLyricIndex - 1].second);
    }else
    {
        ui->label_lyric->clear(); //没有歌词，清空显示
    }
}
