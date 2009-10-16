TEMPLATE = app
TARGET = QChurchView
QT += core \
    gui \
    phonon
HEADERS += qfrmconfigslidepadrao.h \
    qoutputwindow.h \
    zconf.h \
    zlib.h \
    zutil.h \
    QfileQts.h \
    QfileQts.h \
    QfileQts.h \
    QfileQvs.h \
    CConfig.h \
    qfrmconfigdirs.h \
    qtabmain.h \
    qchurchview.h
SOURCES += qfrmconfigslidepadrao.cpp \
    qoutputwindow.cpp \
    zutil.c \
    QfileQts.cpp \
    QfileQvs.cpp \
    tinystr.cpp \
    tinyxml.cpp \
    tinyxmlerror.cpp \
    tinyxmlparser.cpp \
    CConfig.cpp \
    qfrmconfigdirs.cpp \
    qtabmain.cpp \
    main.cpp \
    qchurchview.cpp
FORMS += qfrmconfigslidepadrao.ui \
    qfrmconfigdirs.ui \
    qtabmain.ui \
    qchurchview.ui
RESOURCES += Img.qrc
