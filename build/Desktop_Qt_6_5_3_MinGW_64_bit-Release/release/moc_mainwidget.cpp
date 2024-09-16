/****************************************************************************
** Meta object code from reading C++ file 'mainwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwidget.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWidgetENDCLASS = QtMocHelpers::stringData(
    "MainWidget",
    "finish",
    "",
    "on_btnAbout_clicked",
    "on_btnSearch_clicked",
    "on_SliderProgress_valueChanged",
    "value",
    "on_SliderProgress_sliderPressed",
    "on_SliderProgress_sliderReleased",
    "on_SliderSound_valueChanged",
    "on_btnLast_clicked",
    "on_btnPlay_clicked",
    "on_btnNext_clicked",
    "on_btnRepeat_clicked",
    "on_btnSound_clicked",
    "playSearchMusic",
    "playHistoryMusic",
    "updateDuration",
    "updateTotalTime",
    "on_btnClearHistory_clicked",
    "onMediaStatusChanged",
    "QMediaPlayer::MediaStatus",
    "status",
    "backgroundDefault",
    "backgroundSetting",
    "getLyric",
    "downloadLyric",
    "lyricJsonAnalysis",
    "loadLyrics",
    "updateLyricIndex",
    "currentTime"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWidgetENDCLASS_t {
    uint offsetsAndSizes[62];
    char stringdata0[11];
    char stringdata1[7];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[21];
    char stringdata5[31];
    char stringdata6[6];
    char stringdata7[32];
    char stringdata8[33];
    char stringdata9[28];
    char stringdata10[19];
    char stringdata11[19];
    char stringdata12[19];
    char stringdata13[21];
    char stringdata14[20];
    char stringdata15[16];
    char stringdata16[17];
    char stringdata17[15];
    char stringdata18[16];
    char stringdata19[27];
    char stringdata20[21];
    char stringdata21[26];
    char stringdata22[7];
    char stringdata23[18];
    char stringdata24[18];
    char stringdata25[9];
    char stringdata26[14];
    char stringdata27[18];
    char stringdata28[11];
    char stringdata29[17];
    char stringdata30[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWidgetENDCLASS_t qt_meta_stringdata_CLASSMainWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWidget"
        QT_MOC_LITERAL(11, 6),  // "finish"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 19),  // "on_btnAbout_clicked"
        QT_MOC_LITERAL(39, 20),  // "on_btnSearch_clicked"
        QT_MOC_LITERAL(60, 30),  // "on_SliderProgress_valueChanged"
        QT_MOC_LITERAL(91, 5),  // "value"
        QT_MOC_LITERAL(97, 31),  // "on_SliderProgress_sliderPressed"
        QT_MOC_LITERAL(129, 32),  // "on_SliderProgress_sliderReleased"
        QT_MOC_LITERAL(162, 27),  // "on_SliderSound_valueChanged"
        QT_MOC_LITERAL(190, 18),  // "on_btnLast_clicked"
        QT_MOC_LITERAL(209, 18),  // "on_btnPlay_clicked"
        QT_MOC_LITERAL(228, 18),  // "on_btnNext_clicked"
        QT_MOC_LITERAL(247, 20),  // "on_btnRepeat_clicked"
        QT_MOC_LITERAL(268, 19),  // "on_btnSound_clicked"
        QT_MOC_LITERAL(288, 15),  // "playSearchMusic"
        QT_MOC_LITERAL(304, 16),  // "playHistoryMusic"
        QT_MOC_LITERAL(321, 14),  // "updateDuration"
        QT_MOC_LITERAL(336, 15),  // "updateTotalTime"
        QT_MOC_LITERAL(352, 26),  // "on_btnClearHistory_clicked"
        QT_MOC_LITERAL(379, 20),  // "onMediaStatusChanged"
        QT_MOC_LITERAL(400, 25),  // "QMediaPlayer::MediaStatus"
        QT_MOC_LITERAL(426, 6),  // "status"
        QT_MOC_LITERAL(433, 17),  // "backgroundDefault"
        QT_MOC_LITERAL(451, 17),  // "backgroundSetting"
        QT_MOC_LITERAL(469, 8),  // "getLyric"
        QT_MOC_LITERAL(478, 13),  // "downloadLyric"
        QT_MOC_LITERAL(492, 17),  // "lyricJsonAnalysis"
        QT_MOC_LITERAL(510, 10),  // "loadLyrics"
        QT_MOC_LITERAL(521, 16),  // "updateLyricIndex"
        QT_MOC_LITERAL(538, 11)   // "currentTime"
    },
    "MainWidget",
    "finish",
    "",
    "on_btnAbout_clicked",
    "on_btnSearch_clicked",
    "on_SliderProgress_valueChanged",
    "value",
    "on_SliderProgress_sliderPressed",
    "on_SliderProgress_sliderReleased",
    "on_SliderSound_valueChanged",
    "on_btnLast_clicked",
    "on_btnPlay_clicked",
    "on_btnNext_clicked",
    "on_btnRepeat_clicked",
    "on_btnSound_clicked",
    "playSearchMusic",
    "playHistoryMusic",
    "updateDuration",
    "updateTotalTime",
    "on_btnClearHistory_clicked",
    "onMediaStatusChanged",
    "QMediaPlayer::MediaStatus",
    "status",
    "backgroundDefault",
    "backgroundSetting",
    "getLyric",
    "downloadLyric",
    "lyricJsonAnalysis",
    "loadLyrics",
    "updateLyricIndex",
    "currentTime"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  164,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  167,    2, 0x08,    3 /* Private */,
       4,    0,  168,    2, 0x08,    4 /* Private */,
       5,    1,  169,    2, 0x08,    5 /* Private */,
       7,    0,  172,    2, 0x08,    7 /* Private */,
       8,    0,  173,    2, 0x08,    8 /* Private */,
       9,    1,  174,    2, 0x08,    9 /* Private */,
      10,    0,  177,    2, 0x08,   11 /* Private */,
      11,    0,  178,    2, 0x08,   12 /* Private */,
      12,    0,  179,    2, 0x08,   13 /* Private */,
      13,    0,  180,    2, 0x08,   14 /* Private */,
      14,    0,  181,    2, 0x08,   15 /* Private */,
      15,    0,  182,    2, 0x08,   16 /* Private */,
      16,    0,  183,    2, 0x08,   17 /* Private */,
      17,    1,  184,    2, 0x08,   18 /* Private */,
      18,    1,  187,    2, 0x08,   20 /* Private */,
      19,    0,  190,    2, 0x08,   22 /* Private */,
      20,    1,  191,    2, 0x08,   23 /* Private */,
      23,    0,  194,    2, 0x08,   25 /* Private */,
      24,    0,  195,    2, 0x08,   26 /* Private */,
      25,    0,  196,    2, 0x08,   27 /* Private */,
      26,    1,  197,    2, 0x08,   28 /* Private */,
      27,    1,  200,    2, 0x08,   30 /* Private */,
      28,    1,  203,    2, 0x08,   32 /* Private */,
      29,    1,  206,    2, 0x08,   34 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::QString, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,   30,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWidget, std::true_type>,
        // method 'finish'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'on_btnAbout_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnSearch_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SliderProgress_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_SliderProgress_sliderPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SliderProgress_sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SliderSound_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_btnLast_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnPlay_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnNext_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnRepeat_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnSound_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playSearchMusic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playHistoryMusic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateDuration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'updateTotalTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'on_btnClearHistory_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onMediaStatusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMediaPlayer::MediaStatus, std::false_type>,
        // method 'backgroundDefault'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'backgroundSetting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getLyric'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'downloadLyric'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'lyricJsonAnalysis'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'loadLyrics'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'updateLyricIndex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finish((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 1: _t->on_btnAbout_clicked(); break;
        case 2: _t->on_btnSearch_clicked(); break;
        case 3: _t->on_SliderProgress_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_SliderProgress_sliderPressed(); break;
        case 5: _t->on_SliderProgress_sliderReleased(); break;
        case 6: _t->on_SliderSound_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->on_btnLast_clicked(); break;
        case 8: _t->on_btnPlay_clicked(); break;
        case 9: _t->on_btnNext_clicked(); break;
        case 10: _t->on_btnRepeat_clicked(); break;
        case 11: _t->on_btnSound_clicked(); break;
        case 12: _t->playSearchMusic(); break;
        case 13: _t->playHistoryMusic(); break;
        case 14: _t->updateDuration((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 15: _t->updateTotalTime((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 16: _t->on_btnClearHistory_clicked(); break;
        case 17: _t->onMediaStatusChanged((*reinterpret_cast< std::add_pointer_t<QMediaPlayer::MediaStatus>>(_a[1]))); break;
        case 18: _t->backgroundDefault(); break;
        case 19: _t->backgroundSetting(); break;
        case 20: _t->getLyric(); break;
        case 21: _t->downloadLyric((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 22: { QString _r = _t->lyricJsonAnalysis((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 23: _t->loadLyrics((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 24: _t->updateLyricIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWidget::*)(QByteArray );
            if (_t _q_method = &MainWidget::finish; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void MainWidget::finish(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
