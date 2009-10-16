/********************************************************************************
** Form generated from reading ui file 'qchurchview.ui'
**
** Created: Thu Sep 3 15:57:21 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QCHURCHVIEW_H
#define UI_QCHURCHVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QChurchViewClass
{
public:
    QAction *actionSair;
    QAction *actionSobre;
    QAction *actionDiretorios;
    QAction *actionSobreQt;
    QAction *actionTextos;
    QAction *actionSlidePadrao;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuArquivo;
    QMenu *menuImportar;
    QMenu *menuAjuda;
    QMenu *menuConfiguracoes;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QChurchViewClass)
    {
        if (QChurchViewClass->objectName().isEmpty())
            QChurchViewClass->setObjectName(QString::fromUtf8("QChurchViewClass"));
        QChurchViewClass->resize(916, 669);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QChurchViewClass->sizePolicy().hasHeightForWidth());
        QChurchViewClass->setSizePolicy(sizePolicy);
        actionSair = new QAction(QChurchViewClass);
        actionSair->setObjectName(QString::fromUtf8("actionSair"));
        actionSobre = new QAction(QChurchViewClass);
        actionSobre->setObjectName(QString::fromUtf8("actionSobre"));
        actionDiretorios = new QAction(QChurchViewClass);
        actionDiretorios->setObjectName(QString::fromUtf8("actionDiretorios"));
        actionSobreQt = new QAction(QChurchViewClass);
        actionSobreQt->setObjectName(QString::fromUtf8("actionSobreQt"));
        actionTextos = new QAction(QChurchViewClass);
        actionTextos->setObjectName(QString::fromUtf8("actionTextos"));
        actionSlidePadrao = new QAction(QChurchViewClass);
        actionSlidePadrao->setObjectName(QString::fromUtf8("actionSlidePadrao"));
        centralwidget = new QWidget(QChurchViewClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QChurchViewClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QChurchViewClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 916, 27));
        menuArquivo = new QMenu(menubar);
        menuArquivo->setObjectName(QString::fromUtf8("menuArquivo"));
        menuImportar = new QMenu(menuArquivo);
        menuImportar->setObjectName(QString::fromUtf8("menuImportar"));
        menuAjuda = new QMenu(menubar);
        menuAjuda->setObjectName(QString::fromUtf8("menuAjuda"));
        menuConfiguracoes = new QMenu(menubar);
        menuConfiguracoes->setObjectName(QString::fromUtf8("menuConfiguracoes"));
        QChurchViewClass->setMenuBar(menubar);
        statusbar = new QStatusBar(QChurchViewClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QChurchViewClass->setStatusBar(statusbar);

        menubar->addAction(menuArquivo->menuAction());
        menubar->addAction(menuConfiguracoes->menuAction());
        menubar->addAction(menuAjuda->menuAction());
        menuArquivo->addSeparator();
        menuArquivo->addAction(menuImportar->menuAction());
        menuArquivo->addSeparator();
        menuArquivo->addAction(actionSair);
        menuImportar->addAction(actionTextos);
        menuAjuda->addAction(actionSobreQt);
        menuAjuda->addAction(actionSobre);
        menuConfiguracoes->addAction(actionDiretorios);
        menuConfiguracoes->addAction(actionSlidePadrao);

        retranslateUi(QChurchViewClass);

        QMetaObject::connectSlotsByName(QChurchViewClass);
    } // setupUi

    void retranslateUi(QMainWindow *QChurchViewClass)
    {
        QChurchViewClass->setWindowTitle(QApplication::translate("QChurchViewClass", "QChurchView", 0, QApplication::UnicodeUTF8));
        actionSair->setText(QApplication::translate("QChurchViewClass", "Sair", 0, QApplication::UnicodeUTF8));
        actionSobre->setText(QApplication::translate("QChurchViewClass", "Sobre...", 0, QApplication::UnicodeUTF8));
        actionDiretorios->setText(QApplication::translate("QChurchViewClass", "Diret\303\263rios", 0, QApplication::UnicodeUTF8));
        actionSobreQt->setText(QApplication::translate("QChurchViewClass", "Sobre Qt...", 0, QApplication::UnicodeUTF8));
        actionTextos->setText(QApplication::translate("QChurchViewClass", "Textos", 0, QApplication::UnicodeUTF8));
        actionSlidePadrao->setText(QApplication::translate("QChurchViewClass", "Slide Padr\303\243o", 0, QApplication::UnicodeUTF8));
        menuArquivo->setTitle(QApplication::translate("QChurchViewClass", "Arquivo", 0, QApplication::UnicodeUTF8));
        menuImportar->setTitle(QApplication::translate("QChurchViewClass", "Importar", 0, QApplication::UnicodeUTF8));
        menuAjuda->setTitle(QApplication::translate("QChurchViewClass", "Ajuda", 0, QApplication::UnicodeUTF8));
        menuConfiguracoes->setTitle(QApplication::translate("QChurchViewClass", "Configura\303\247\303\265es", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QChurchViewClass: public Ui_QChurchViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCHURCHVIEW_H
