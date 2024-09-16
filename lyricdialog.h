#ifndef LYRICDIALOG_H
#define LYRICDIALOG_H

#include <QDialog>

namespace Ui {
class LyricDialog;
}

class LyricDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LyricDialog(QWidget *parent = nullptr);
    ~LyricDialog();

    void setLyric(const QString &lyric); // 设置歌词内容


private:
    Ui::LyricDialog *ui;

    QString style=
        "QScrollBar:vertical {"
        "    border: none;"
        "    background: transparent;"
        "    width: 15px;"
        "    margin: 15px 3px 15px 3px;"
        "}"
        "QScrollBar::handle:vertical {"
        "    background: rgb(30,30,30); /* 设置滚动条颜色为黑色 */"
        "    min-height: 20px;"
        "}"
        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
        "    background: none;"
        "    height: 0px;"
        "}"
        "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
        "    background: none;"
        "}"
        "QTextBrowser {"
        " background-color: rgba(255, 255, 255, 0); "
        "color: rgb(200,200,200); "
        "border: none; }"
        ;
};

#endif // LYRICDIALOG_H
