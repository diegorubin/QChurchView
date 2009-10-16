#include "qoutputwindow.h"

QOutPutWindow::QOutPutWindow(QWidget *parent,Qt::WindowFlags f)
    : QWidget(parent)
{
	setWindowFlags(f);
        setWindowTitle("QChurchView Out");

	situacao = imagem;

	lblFundo.setParent(this);
	lblFundo.resize(resolucao_x,resolucao_y);
	lblFundo.move(0,0);
	lblFundo.show();

	mvoFundo.setCacheMode(QMovie::CacheNone);


	lblLetra.setParent(this);
	lblLetra.hide();

	lblTitulo.setParent(this);
	lblTitulo.hide();

	vWidget.setParent(this);
	vWidget.resize(resolucao_x,resolucao_y);
	vWidget.hide();

	Phonon::createPath(&mdoVideo,&vWidget);
	Phonon::createPath(&mdoVideo,&audio);
}

QOutPutWindow::~QOutPutWindow()
{

}

void QOutPutWindow::setSource(QString filename)
{
	Phonon::MediaSource *source = new Phonon::MediaSource(filename);
	mdoVideo.setCurrentSource(*source);
}

void QOutPutWindow::VideoPlay()
{
	trocar_situacao(video);
	mdoVideo.play();
}

void QOutPutWindow::VideoPause()
{
	mdoVideo.pause();
}

void QOutPutWindow::VideoSeek(qint64 position)
{
	mdoVideo.seek(position);
}

void QOutPutWindow::trocar_situacao(Casos nova_situacao)
{
	if(situacao != nova_situacao){
		switch(situacao){
		case imagem:
			switch(nova_situacao){
			case imagem_letra:
				lblLetra.show();
				lblTitulo.show();
				break;
			case video:
				lblFundo.hide();
				vWidget.show();
				break;
			case video_letra:
				break;
                        case pregador:
                                lblLetra.show();
                                lblTitulo.show();
                                lblPregador.show();
                                break;
                        case pregador_video:
                                lblLetra.show();
                                lblTitulo.show();
                                lblPregador.show();
                                break;
			}
			break;
		case imagem_letra:
			switch(nova_situacao){
			case imagem:
				lblTitulo.hide();
				lblLetra.hide();
				break;
			case video:
				lblFundo.hide();
				lblTitulo.hide();
				lblLetra.hide();
				vWidget.show();
				break;
			case video_letra:
				break;
                        case pregador:
                                lblPregador.show();
                                break;
                        case pregador_video:
                                lblPregador.show();
                                break;
			}
			break;
		case video:
			switch(nova_situacao){
			case imagem:
				mdoVideo.stop();
				vWidget.hide();
				lblFundo.show();
				break;
			case imagem_letra:
                                mdoVideo.stop();
                                vWidget.hide();
                                lblFundo.show();
				break;
			case video_letra:
				break;
                        case pregador:
                                mdoVideo.stop();
                                vWidget.hide();
                                lblFundo.show();
                                lblTitulo.show();
                                lblLetra.show();
                                lblPregador.show();
                                break;
                        case pregador_video:
                                mdoVideo.stop();
                                vWidget.hide();
                                lblFundo.show();
                                lblTitulo.show();
                                lblLetra.show();
                                lblPregador.show();
                                break;
			}
			break;
		case video_letra:
			switch(nova_situacao){
			case imagem:
				break;
			case imagem_letra:
				break;
			case video:
				break;
                        case pregador:
                                mvoFundo.stop();
                                lblPregador.show();
                                break;
                        case pregador_video:
                                lblPregador.show();
                                break;
			}
			break;
                case pregador:
                        switch(nova_situacao){
                        case imagem:
                                break;
                        case imagem_letra:
                                break;
                        case video:
                                break;
                        case video_letra:
                                break;
                        case pregador_video:
                                lblPregador.show();
                                break;
                        }
                        break;
                case pregador_video:
                        switch(nova_situacao){
                        case imagem:
                                break;
                        case imagem_letra:
                                break;
                        case video:
                                break;
                        case video_letra:
                                break;
                        case pregador:
                                mvoFundo.stop();
                                lblPregador.show();
                                break;
                        }
                        break;
		}
		situacao = nova_situacao;
	}

}

void QOutPutWindow::setImagem(QString filename)
{
	trocar_situacao(imagem);
	imgFundo.load(filename);
	lblFundo.setPixmap(imgFundo);
}
