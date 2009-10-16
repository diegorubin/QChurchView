#ifndef QTABMAIN_H
#define QTABMAIN_H

#include <QtGui/QTabWidget>
#include <QDir>
#include <QDirIterator>
#include <QInputDialog>
#include <QProgressDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QColor>
#include <QColorDialog>
#include <QPixmap>
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <dirent.h>

#include <phonon/mediasource.h>
#include <phonon/mediaobject.h>
#include <phonon/videowidget.h>
#include <phonon/seekslider.h>

#include "QfileQts.h"
#include "QfileQvs.h"
#include "qoutputwindow.h"

#include "ui_qtabmain.h"

class QTabMain : public QTabWidget
{
    Q_OBJECT

public:
    QTabMain(QWidget *parent = 0);
    ~QTabMain();

    void set_dirSlides(std::string dirslides){ dirSlides = QString::fromStdString(dirslides);}
    void set_dirTemas(std::string dirtemas){ dirTemas = QString::fromStdString(dirtemas); }
    void set_dirLetras(std::string dirletras) { dirLetras = QString::fromStdString(dirletras); }
    void set_dirPregadores(std::string dirpregadores) {dirPregadores = QString::fromStdString(dirpregadores); }
    void set_dirVideos(std::string dirvideos) { dirVideos = QString::fromStdString(dirvideos); }
    void setOutPutWindow(QOutPutWindow *window) {winSaida = window;}
    void setLabelSlideAtual(QLabel *slide) { lblSlideAtual = slide; }

private:
    Ui::QTabMainClass ui;

    QOutPutWindow *winSaida;

    QString dirSlides;
    QString dirTemas;
    QString dirLetras;
    QString dirVideos;
    QString dirPregadores;
    QString ultimoTexto;
    QString filtrosArquivo;

    QLabel *lblSlideAtual;

    QMessageBox dlgErro;
    QFileDialog dlgArquivos;
    QProgressDialog dlgProgresso;

    QfileQts qtsTema;
    QfileQts csTema;

    QPixmap imgThumb;

    Phonon::VideoWidget vWidget;
    Phonon::MediaObject mediaObejct;
    Phonon::SeekSlider slrVideo;

    bool play;

    int xTitulo;
    int yTitulo;
    int xTexto;
    int yTexto;
    int pxTitulo;
    int pyTitulo;
    int pxTexto;
    int pyTexto;
    int pxPregador;
    int pyPregador;

    int FonteTitulo;
    int FonteTexto;
    int pFonteTitulo;
    int pFonteTexto;
    int pFontePregador;

    bool textChanged;
    bool textOpened;

    int nSlides;
    int aSlide;

    int numero_de_slides();
    int numero_slide_atual(int pos);

private slots:
	virtual void adicionar_apresentacao();
	virtual void carregar_apresentacao();
	virtual void adicionar_letra();
	virtual void editar_letra();
	virtual void salvar_letra();
	virtual void remover_letra();
	virtual void renomear_letra();
	virtual void carregar_tema();
	virtual void atualizar_titulo();

	virtual void adicionar_tema();
	virtual void adicionar_tema_arquivo();
	virtual void adicionar_tema_thumb();
	virtual void adicionar_tema_cor();
	virtual void trocar_cor(QString cor);
	virtual void editar_tema();
	virtual void salvar_tema();

	virtual void trocar_filtro_tema();
	virtual void trocar_posicao_texto();

	virtual void mover_xtitulo(int value);
	virtual void mover_ytitulo(int value);
	virtual void mover_xtexto(int value);
	virtual void mover_ytexto(int value);
	virtual void fonte_titulo(int i);
	virtual void fonte_texto(int i);

	virtual void mudanca_texto();

	virtual void adicionar_slide();
	virtual void slide_atual();
	virtual void finalizar_apresentacao();

        virtual void adicionar_pregador_fundo();

        virtual void mover_pxtitulo(int value);
        virtual void mover_pytitulo(int value);
        virtual void mover_pxtexto(int value);
        virtual void mover_pytexto(int value);
        virtual void mover_pxpregador(int value);
        virtual void mover_pypregador(int value);

	virtual void adicionar_video();
	virtual void limpar_videos();
	virtual void remover_videos();
	virtual void executar_videos();
	virtual void atualizar_dados_video();
	virtual void trocar_video();
	virtual void playpause_video();
	virtual void ant_video();
	virtual void sincronizar_video();

public slots:
	virtual void recarregar_musicas();
	virtual void recarregar_temas();
	virtual void recarregar_letras();
        virtual void recarregar_pregadores();

	virtual void prox_video();
	virtual void stop_video();
};

#endif // QTABMAIN_H
