#include "lyricdialog.h"
#include "ui_lyricdialog.h"

LyricDialog::LyricDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LyricDialog)
{
    ui->setupUi(this);
    this->setFixedSize(315,300);
    // 设置透明背景
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlag(Qt::FramelessWindowHint); // 去掉窗口边框
    this->setStyleSheet(style);


}

LyricDialog::~LyricDialog()
{
    delete ui;
}
void LyricDialog::setLyric(const QString &lyric) {
    ui->textBrowser->setPlainText(lyric); //
}
