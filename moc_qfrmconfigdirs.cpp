/****************************************************************************
** Meta object code from reading C++ file 'qfrmconfigdirs.h'
**
** Created: Thu Sep 3 15:57:59 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qfrmconfigdirs.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qfrmconfigdirs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QfrmConfigDirs[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      33,   15,   15,   15, 0x08,
      49,   15,   15,   15, 0x08,
      66,   15,   15,   15, 0x08,
      87,   15,   15,   15, 0x08,
     104,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QfrmConfigDirs[] = {
    "QfrmConfigDirs\0\0AbrirDirSlides()\0"
    "AbrirDirTemas()\0AbrirDirLetras()\0"
    "AbrirDirPregadores()\0AbrirDirVideos()\0"
    "Cancelar()\0"
};

const QMetaObject QfrmConfigDirs::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QfrmConfigDirs,
      qt_meta_data_QfrmConfigDirs, 0 }
};

const QMetaObject *QfrmConfigDirs::metaObject() const
{
    return &staticMetaObject;
}

void *QfrmConfigDirs::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QfrmConfigDirs))
        return static_cast<void*>(const_cast< QfrmConfigDirs*>(this));
    return QDialog::qt_metacast(_clname);
}

int QfrmConfigDirs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: AbrirDirSlides(); break;
        case 1: AbrirDirTemas(); break;
        case 2: AbrirDirLetras(); break;
        case 3: AbrirDirPregadores(); break;
        case 4: AbrirDirVideos(); break;
        case 5: Cancelar(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
