/********************************************************************************
** Form generated from reading ui file 'qfrmconfigslidepadrao.ui'
**
** Created: Thu Sep 3 15:57:21 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QFRMCONFIGSLIDEPADRAO_H
#define UI_QFRMCONFIGSLIDEPADRAO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QfrmConfigSlidePadraoClass
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QLabel *lblFundo;
    QPushButton *btnAbrirImagem;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnSalvarImagem;
    QPushButton *btnCancelar;

    void setupUi(QDialog *QfrmConfigSlidePadraoClass)
    {
        if (QfrmConfigSlidePadraoClass->objectName().isEmpty())
            QfrmConfigSlidePadraoClass->setObjectName(QString::fromUtf8("QfrmConfigSlidePadraoClass"));
        QfrmConfigSlidePadraoClass->resize(545, 492);
        gridLayout = new QGridLayout(QfrmConfigSlidePadraoClass);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(QfrmConfigSlidePadraoClass);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 523, 394));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setMargin(11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lblFundo = new QLabel(scrollAreaWidgetContents);
        lblFundo->setObjectName(QString::fromUtf8("lblFundo"));

        gridLayout_2->addWidget(lblFundo, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 3);

        btnAbrirImagem = new QPushButton(QfrmConfigSlidePadraoClass);
        btnAbrirImagem->setObjectName(QString::fromUtf8("btnAbrirImagem"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnAbrirImagem->sizePolicy().hasHeightForWidth());
        btnAbrirImagem->setSizePolicy(sizePolicy);
        QFont font;
        font.setUnderline(false);
        font.setStrikeOut(false);
        btnAbrirImagem->setFont(font);

        gridLayout->addWidget(btnAbrirImagem, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        btnSalvarImagem = new QPushButton(QfrmConfigSlidePadraoClass);
        btnSalvarImagem->setObjectName(QString::fromUtf8("btnSalvarImagem"));

        gridLayout->addWidget(btnSalvarImagem, 2, 0, 1, 1);

        btnCancelar = new QPushButton(QfrmConfigSlidePadraoClass);
        btnCancelar->setObjectName(QString::fromUtf8("btnCancelar"));

        gridLayout->addWidget(btnCancelar, 2, 2, 1, 1);


        retranslateUi(QfrmConfigSlidePadraoClass);
        QObject::connect(btnCancelar, SIGNAL(clicked()), QfrmConfigSlidePadraoClass, SLOT(close()));

        QMetaObject::connectSlotsByName(QfrmConfigSlidePadraoClass);
    } // setupUi

    void retranslateUi(QDialog *QfrmConfigSlidePadraoClass)
    {
        QfrmConfigSlidePadraoClass->setWindowTitle(QApplication::translate("QfrmConfigSlidePadraoClass", "Slide Padr\303\243o", 0, QApplication::UnicodeUTF8));
        lblFundo->setText(QString());
        btnAbrirImagem->setText(QApplication::translate("QfrmConfigSlidePadraoClass", "Abrir Imagem", 0, QApplication::UnicodeUTF8));
        btnSalvarImagem->setText(QApplication::translate("QfrmConfigSlidePadraoClass", "Salvar", 0, QApplication::UnicodeUTF8));
        btnCancelar->setText(QApplication::translate("QfrmConfigSlidePadraoClass", "Cancelar", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(QfrmConfigSlidePadraoClass);
    } // retranslateUi

};

namespace Ui {
    class QfrmConfigSlidePadraoClass: public Ui_QfrmConfigSlidePadraoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFRMCONFIGSLIDEPADRAO_H
