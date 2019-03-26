/****************************************************************************
** Meta object code from reading C++ file 'tournament.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/tournament.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tournament.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tournament_t {
    QByteArrayData data[22];
    char stringdata0[221];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tournament_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tournament_t qt_meta_stringdata_Tournament = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Tournament"
QT_MOC_LITERAL(1, 11, 11), // "gameStarted"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "ChessGame*"
QT_MOC_LITERAL(4, 35, 4), // "game"
QT_MOC_LITERAL(5, 40, 6), // "number"
QT_MOC_LITERAL(6, 47, 10), // "whiteIndex"
QT_MOC_LITERAL(7, 58, 10), // "blackIndex"
QT_MOC_LITERAL(8, 69, 12), // "gameFinished"
QT_MOC_LITERAL(9, 82, 8), // "finished"
QT_MOC_LITERAL(10, 91, 5), // "start"
QT_MOC_LITERAL(11, 97, 4), // "stop"
QT_MOC_LITERAL(12, 102, 13), // "startNextGame"
QT_MOC_LITERAL(13, 116, 8), // "writePgn"
QT_MOC_LITERAL(14, 125, 8), // "PgnGame*"
QT_MOC_LITERAL(15, 134, 3), // "pgn"
QT_MOC_LITERAL(16, 138, 10), // "gameNumber"
QT_MOC_LITERAL(17, 149, 8), // "writeEpd"
QT_MOC_LITERAL(18, 158, 13), // "onGameStarted"
QT_MOC_LITERAL(19, 172, 14), // "onGameFinished"
QT_MOC_LITERAL(20, 187, 15), // "onGameDestroyed"
QT_MOC_LITERAL(21, 203, 17) // "onGameStartFailed"

    },
    "Tournament\0gameStarted\0\0ChessGame*\0"
    "game\0number\0whiteIndex\0blackIndex\0"
    "gameFinished\0finished\0start\0stop\0"
    "startNextGame\0writePgn\0PgnGame*\0pgn\0"
    "gameNumber\0writeEpd\0onGameStarted\0"
    "onGameFinished\0onGameDestroyed\0"
    "onGameStartFailed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tournament[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   74,    2, 0x06 /* Public */,
       8,    4,   83,    2, 0x06 /* Public */,
       9,    0,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   93,    2, 0x0a /* Public */,
      11,    0,   94,    2, 0x0a /* Public */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    2,   96,    2, 0x08 /* Private */,
      17,    1,  101,    2, 0x08 /* Private */,
      18,    1,  104,    2, 0x08 /* Private */,
      19,    1,  107,    2, 0x08 /* Private */,
      20,    1,  110,    2, 0x08 /* Private */,
      21,    1,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int, QMetaType::Int,    4,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int, QMetaType::Int,    4,    5,    6,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 14, QMetaType::Int,   15,   16,
    QMetaType::Bool, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void Tournament::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tournament *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gameStarted((*reinterpret_cast< ChessGame*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->gameFinished((*reinterpret_cast< ChessGame*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->finished(); break;
        case 3: _t->start(); break;
        case 4: _t->stop(); break;
        case 5: _t->startNextGame(); break;
        case 6: { bool _r = _t->writePgn((*reinterpret_cast< PgnGame*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->writeEpd((*reinterpret_cast< ChessGame*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->onGameStarted((*reinterpret_cast< ChessGame*(*)>(_a[1]))); break;
        case 9: _t->onGameFinished((*reinterpret_cast< ChessGame*(*)>(_a[1]))); break;
        case 10: _t->onGameDestroyed((*reinterpret_cast< ChessGame*(*)>(_a[1]))); break;
        case 11: _t->onGameStartFailed((*reinterpret_cast< ChessGame*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Tournament::*)(ChessGame * , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tournament::gameStarted)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Tournament::*)(ChessGame * , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tournament::gameFinished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Tournament::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tournament::finished)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Tournament::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Tournament.data,
    qt_meta_data_Tournament,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tournament::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tournament::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tournament.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Tournament::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Tournament::gameStarted(ChessGame * _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Tournament::gameFinished(ChessGame * _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Tournament::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
