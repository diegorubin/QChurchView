#ifndef QCHURCHVIEW_H
#define QCHURCHVIEW_H

#include <QtGui>
#include <QDir>
#include <QFileDialog>
#include <QFile>
#include <QInputDialog>
#include "ui_qchurchview.h"

#include "CConfig.h"
#include "qtabmain.h"
#include "qfrmconfigdirs.h"
#include "qfrmconfigslidepadrao.h"
#include "qoutputwindow.h"

class QChurchView : public QMainWindow
{
    Q_OBJECT

public:
    QChurchView(QWidget *parent = 0);
    ~QChurchView();

    //Classes
    CConfig configuracao;

    void setSlideAtual(QString slide);

private:
    Ui::QChurchViewClass ui;

    QOutPutWindow winSaida;

    //message box
    QMessageBox msgBox;
    QFileDialog dlgArquivo;


    //botoes principais
    QPushButton btnVideos;
    QPushButton btnLista;
    QPushButton btnPadrao;
    QPushButton btnPregador;

    //menu de status
    QLabel lblSlide;
    QLabel lblSlideAtual;

    //forms
    QTabMain tabMain;
    QfrmConfigDirs frmConfigDirs;
    QfrmConfigSlidePadrao frmConfigSlidePadrao;

    QString ArquivoConfiguracao();

private slots:

	//menu principal
	virtual void ArquivoImportarTextos();
	virtual void ArquivoSair();
	virtual void ConfiguracoesDiretorios();
	virtual void ConfiguracoesSlidePadrao();
	virtual void AjudaSobre();
	virtual void AjudaSobreQt();

	//menu secundario
	virtual void SlidePadrao();

public slots:

	virtual void SalvarDiretorios();
	virtual void SalvarSlidePadrao();

};

#endif // QCHURCHVIEW_H
