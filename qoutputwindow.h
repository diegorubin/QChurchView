#ifndef QOUTPUTWINDOW_H
#define QOUTPUTWINDOW_H

#include <QtGui/QWidget>
#include <QtGui/QLabel>
#include <QtGui/QPixmap>
#include <QtGui/QMovie>
#include <phonon/videowidget.h>
#include <phonon/mediaobject.h>
#include <phonon/audiooutput.h>
#include <phonon/mediasource.h>
#include "consts.h"

enum Casos{
    	imagem,
    	imagem_letra,
    	video_letra,
    	video,
        pregador,
	pregador_video
};

class QOutPutWindow : public QWidget
{
    Q_OBJECT

public:
    QOutPutWindow(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~QOutPutWindow();

    void setImagem(QString filename);
    void setLetra(QString letra);
    void setTitulo(QString titulo);
    void setSource(QString filename);
    void VideoPlay();
    void VideoPause();
    void VideoSeek(qint64 position);

    Casos getSituacao(){return situacao;}

    Phonon::MediaObject *getVideoMediaObject(){return &mdoVideo;}

private:
    Casos situacao;

    //widgets
    QLabel lblFundo;
    QLabel lblLetra;
    QLabel lblTitulo;
    QLabel lblPregador;

    QPixmap imgFundo;
    QMovie mvoFundo;

    Phonon::MediaObject mdoVideo;
    Phonon::VideoWidget vWidget;
    Phonon::AudioOutput audio;

    void trocar_situacao(Casos nova_situacao);

};

#endif // QOUTPUTWINDOW_H
