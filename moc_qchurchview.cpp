/****************************************************************************
** Meta object code from reading C++ file 'qchurchview.h'
**
** Created: Thu Sep 3 15:58:03 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qchurchview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qchurchview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QChurchView[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      37,   12,   12,   12, 0x08,
      51,   12,   12,   12, 0x08,
      77,   12,   12,   12, 0x08,
     104,   12,   12,   12, 0x08,
     117,   12,   12,   12, 0x08,
     132,   12,   12,   12, 0x08,
     146,   12,   12,   12, 0x0a,
     165,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QChurchView[] = {
    "QChurchView\0\0ArquivoImportarTextos()\0"
    "ArquivoSair()\0ConfiguracoesDiretorios()\0"
    "ConfiguracoesSlidePadrao()\0AjudaSobre()\0"
    "AjudaSobreQt()\0SlidePadrao()\0"
    "SalvarDiretorios()\0SalvarSlidePadrao()\0"
};

const QMetaObject QChurchView::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QChurchView,
      qt_meta_data_QChurchView, 0 }
};

const QMetaObject *QChurchView::metaObject() const
{
    return &staticMetaObject;
}

void *QChurchView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QChurchView))
        return static_cast<void*>(const_cast< QChurchView*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QChurchView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ArquivoImportarTextos(); break;
        case 1: ArquivoSair(); break;
        case 2: ConfiguracoesDiretorios(); break;
        case 3: ConfiguracoesSlidePadrao(); break;
        case 4: AjudaSobre(); break;
        case 5: AjudaSobreQt(); break;
        case 6: SlidePadrao(); break;
        case 7: SalvarDiretorios(); break;
        case 8: SalvarSlidePadrao(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
