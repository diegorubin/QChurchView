/****************************************************************************
** Meta object code from reading C++ file 'qtabmain.h'
**
** Created: Thu Sep 3 15:58:01 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qtabmain.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtabmain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QTabMain[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      50,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      35,    9,    9,    9, 0x08,
      59,    9,    9,    9, 0x08,
      77,    9,    9,    9, 0x08,
      92,    9,    9,    9, 0x08,
     107,    9,    9,    9, 0x08,
     123,    9,    9,    9, 0x08,
     140,    9,    9,    9, 0x08,
     156,    9,    9,    9, 0x08,
     175,    9,    9,    9, 0x08,
     192,    9,    9,    9, 0x08,
     217,    9,    9,    9, 0x08,
     240,    9,    9,    9, 0x08,
     265,  261,    9,    9, 0x08,
     285,    9,    9,    9, 0x08,
     299,    9,    9,    9, 0x08,
     313,    9,    9,    9, 0x08,
     334,    9,    9,    9, 0x08,
     363,  357,    9,    9, 0x08,
     382,  357,    9,    9, 0x08,
     401,  357,    9,    9, 0x08,
     419,  357,    9,    9, 0x08,
     439,  437,    9,    9, 0x08,
     457,  437,    9,    9, 0x08,
     474,    9,    9,    9, 0x08,
     490,    9,    9,    9, 0x08,
     508,    9,    9,    9, 0x08,
     522,    9,    9,    9, 0x08,
     547,    9,    9,    9, 0x08,
     574,  357,    9,    9, 0x08,
     594,  357,    9,    9, 0x08,
     614,  357,    9,    9, 0x08,
     633,  357,    9,    9, 0x08,
     652,  357,    9,    9, 0x08,
     674,  357,    9,    9, 0x08,
     696,    9,    9,    9, 0x08,
     714,    9,    9,    9, 0x08,
     730,    9,    9,    9, 0x08,
     747,    9,    9,    9, 0x08,
     765,    9,    9,    9, 0x08,
     789,    9,    9,    9, 0x08,
     804,    9,    9,    9, 0x08,
     822,    9,    9,    9, 0x08,
     834,    9,    9,    9, 0x08,
     854,    9,    9,    9, 0x0a,
     875,    9,    9,    9, 0x0a,
     894,    9,    9,    9, 0x0a,
     914,    9,    9,    9, 0x0a,
     938,    9,    9,    9, 0x0a,
     951,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QTabMain[] = {
    "QTabMain\0\0adicionar_apresentacao()\0"
    "carregar_apresentacao()\0adicionar_letra()\0"
    "editar_letra()\0salvar_letra()\0"
    "remover_letra()\0renomear_letra()\0"
    "carregar_tema()\0atualizar_titulo()\0"
    "adicionar_tema()\0adicionar_tema_arquivo()\0"
    "adicionar_tema_thumb()\0adicionar_tema_cor()\0"
    "cor\0trocar_cor(QString)\0editar_tema()\0"
    "salvar_tema()\0trocar_filtro_tema()\0"
    "trocar_posicao_texto()\0value\0"
    "mover_xtitulo(int)\0mover_ytitulo(int)\0"
    "mover_xtexto(int)\0mover_ytexto(int)\0"
    "i\0fonte_titulo(int)\0fonte_texto(int)\0"
    "mudanca_texto()\0adicionar_slide()\0"
    "slide_atual()\0finalizar_apresentacao()\0"
    "adicionar_pregador_fundo()\0"
    "mover_pxtitulo(int)\0mover_pytitulo(int)\0"
    "mover_pxtexto(int)\0mover_pytexto(int)\0"
    "mover_pxpregador(int)\0mover_pypregador(int)\0"
    "adicionar_video()\0limpar_videos()\0"
    "remover_videos()\0executar_videos()\0"
    "atualizar_dados_video()\0trocar_video()\0"
    "playpause_video()\0ant_video()\0"
    "sincronizar_video()\0recarregar_musicas()\0"
    "recarregar_temas()\0recarregar_letras()\0"
    "recarregar_pregadores()\0prox_video()\0"
    "stop_video()\0"
};

const QMetaObject QTabMain::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_QTabMain,
      qt_meta_data_QTabMain, 0 }
};

const QMetaObject *QTabMain::metaObject() const
{
    return &staticMetaObject;
}

void *QTabMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QTabMain))
        return static_cast<void*>(const_cast< QTabMain*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int QTabMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: adicionar_apresentacao(); break;
        case 1: carregar_apresentacao(); break;
        case 2: adicionar_letra(); break;
        case 3: editar_letra(); break;
        case 4: salvar_letra(); break;
        case 5: remover_letra(); break;
        case 6: renomear_letra(); break;
        case 7: carregar_tema(); break;
        case 8: atualizar_titulo(); break;
        case 9: adicionar_tema(); break;
        case 10: adicionar_tema_arquivo(); break;
        case 11: adicionar_tema_thumb(); break;
        case 12: adicionar_tema_cor(); break;
        case 13: trocar_cor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: editar_tema(); break;
        case 15: salvar_tema(); break;
        case 16: trocar_filtro_tema(); break;
        case 17: trocar_posicao_texto(); break;
        case 18: mover_xtitulo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: mover_ytitulo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: mover_xtexto((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: mover_ytexto((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: fonte_titulo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: fonte_texto((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: mudanca_texto(); break;
        case 25: adicionar_slide(); break;
        case 26: slide_atual(); break;
        case 27: finalizar_apresentacao(); break;
        case 28: adicionar_pregador_fundo(); break;
        case 29: mover_pxtitulo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: mover_pytitulo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: mover_pxtexto((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: mover_pytexto((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: mover_pxpregador((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: mover_pypregador((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: adicionar_video(); break;
        case 36: limpar_videos(); break;
        case 37: remover_videos(); break;
        case 38: executar_videos(); break;
        case 39: atualizar_dados_video(); break;
        case 40: trocar_video(); break;
        case 41: playpause_video(); break;
        case 42: ant_video(); break;
        case 43: sincronizar_video(); break;
        case 44: recarregar_musicas(); break;
        case 45: recarregar_temas(); break;
        case 46: recarregar_letras(); break;
        case 47: recarregar_pregadores(); break;
        case 48: prox_video(); break;
        case 49: stop_video(); break;
        default: ;
        }
        _id -= 50;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
