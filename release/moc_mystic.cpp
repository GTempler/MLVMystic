/****************************************************************************
** Meta object code from reading C++ file 'mystic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mystic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mystic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Mystic_t {
    QByteArrayData data[16];
    char stringdata[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Mystic_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Mystic_t qt_meta_stringdata_Mystic = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 24),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 25),
QT_MOC_LITERAL(4, 59, 23),
QT_MOC_LITERAL(5, 83, 21),
QT_MOC_LITERAL(6, 105, 24),
QT_MOC_LITERAL(7, 130, 25),
QT_MOC_LITERAL(8, 156, 25),
QT_MOC_LITERAL(9, 182, 23),
QT_MOC_LITERAL(10, 206, 10),
QT_MOC_LITERAL(11, 217, 5),
QT_MOC_LITERAL(12, 223, 6),
QT_MOC_LITERAL(13, 230, 10),
QT_MOC_LITERAL(14, 241, 10),
QT_MOC_LITERAL(15, 252, 10)
    },
    "Mystic\0on_convertButton_clicked\0\0"
    "on_actionImport_triggered\0"
    "on_removeButton_clicked\0on_pushButton_clicked\0"
    "on_actionAbout_triggered\0"
    "on_MLVradioButton_clicked\0"
    "on_RAWradioButton_clicked\0"
    "on_pushButton_2_clicked\0MLVConvert\0"
    "char*\0inFile\0outRAWFile\0outDNGFile\0"
    "RAWConvert\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mystic[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08,
       3,    0,   65,    2, 0x08,
       4,    0,   66,    2, 0x08,
       5,    0,   67,    2, 0x08,
       6,    0,   68,    2, 0x08,
       7,    0,   69,    2, 0x08,
       8,    0,   70,    2, 0x08,
       9,    0,   71,    2, 0x08,
      10,    3,   72,    2, 0x08,
      15,    2,   79,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 11, 0x80000000 | 11,   12,   13,   14,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 11,   12,   14,

       0        // eod
};

void Mystic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Mystic *_t = static_cast<Mystic *>(_o);
        switch (_id) {
        case 0: _t->on_convertButton_clicked(); break;
        case 1: _t->on_actionImport_triggered(); break;
        case 2: _t->on_removeButton_clicked(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_actionAbout_triggered(); break;
        case 5: _t->on_MLVradioButton_clicked(); break;
        case 6: _t->on_RAWradioButton_clicked(); break;
        case 7: _t->on_pushButton_2_clicked(); break;
        case 8: _t->MLVConvert((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< char*(*)>(_a[3]))); break;
        case 9: _t->RAWConvert((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject Mystic::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Mystic.data,
      qt_meta_data_Mystic,  qt_static_metacall, 0, 0}
};


const QMetaObject *Mystic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mystic::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Mystic.stringdata))
        return static_cast<void*>(const_cast< Mystic*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Mystic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
