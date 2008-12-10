/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Dec 10 17:27:17 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      27,   11,   22,   11, 0x08,
      34,   11,   22,   11, 0x08,
      41,   11,   11,   11, 0x08,
      47,   11,   11,   11, 0x08,
      53,   11,   11,   11, 0x08,
      71,   66,   11,   11, 0x08,
      98,   11,   11,   11, 0x08,
     105,   11,   11,   11, 0x08,
     126,   11,   11,   11, 0x08,
     142,   11,   11,   11, 0x08,
     160,   11,   11,   11, 0x08,
     181,  173,   11,   11, 0x08,
     207,  201,   11,   11, 0x08,
     229,   11,   11,   11, 0x08,
     243,  237,   11,   11, 0x08,
     271,  266,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0newFile()\0bool\0save()\0"
    "load()\0add()\0del()\0resizeView()\0text\0"
    "onFindTextChanged(QString)\0find()\0"
    "onSelectionChanged()\0onLabelEdited()\0"
    "onCommentEdited()\0onUndoFind()\0enabled\0"
    "enableSorting(bool)\0shown\0"
    "onFindViewShown(bool)\0about()\0index\0"
    "onFindTypeChanged(int)\0unit\0"
    "onFindUnitChanged(int)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newFile(); break;
        case 1: { bool _r = save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = load();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: add(); break;
        case 4: del(); break;
        case 5: resizeView(); break;
        case 6: onFindTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: find(); break;
        case 8: onSelectionChanged(); break;
        case 9: onLabelEdited(); break;
        case 10: onCommentEdited(); break;
        case 11: onUndoFind(); break;
        case 12: enableSorting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: onFindViewShown((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: about(); break;
        case 15: onFindTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: onFindUnitChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
