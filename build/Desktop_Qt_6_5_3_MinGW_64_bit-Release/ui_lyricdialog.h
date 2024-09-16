/********************************************************************************
** Form generated from reading UI file 'lyricdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LYRICDIALOG_H
#define UI_LYRICDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_LyricDialog
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *LyricDialog)
    {
        if (LyricDialog->objectName().isEmpty())
            LyricDialog->setObjectName("LyricDialog");
        LyricDialog->resize(313, 555);
        gridLayout = new QGridLayout(LyricDialog);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(LyricDialog);
        textBrowser->setObjectName("textBrowser");

        gridLayout->addWidget(textBrowser, 0, 0, 1, 1);


        retranslateUi(LyricDialog);

        QMetaObject::connectSlotsByName(LyricDialog);
    } // setupUi

    void retranslateUi(QDialog *LyricDialog)
    {
        LyricDialog->setWindowTitle(QCoreApplication::translate("LyricDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LyricDialog: public Ui_LyricDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LYRICDIALOG_H
