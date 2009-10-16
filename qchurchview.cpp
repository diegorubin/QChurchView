#include "qchurchview.h"

QChurchView::QChurchView(QWidget *parent)
    : QMainWindow(parent),
    winSaida(this,Qt::Window),
    btnVideos("USE ANTES DE VIDEOS"),
    btnLista("Lista de Musicas"),
    btnPadrao("Slide Padrao"),
    btnPregador("Slide do Pregador"),
    lblSlide("<b>Slide Atual:</b>"),
    frmConfigDirs(this),
    frmConfigSlidePadrao(this)
{
	ui.setupUi(this);

	winSaida.move(2000,0);
	winSaida.show();

	tabMain.setOutPutWindow(&winSaida);

	if(!configuracao.Load(ArquivoConfiguracao().toStdString()))
		msgBox.critical(this,"ERRO:"+ArquivoConfiguracao(),"Nao foi encontrado o arquivo "+ArquivoConfiguracao());



	//montar menu com os botoes principais
	QHBoxLayout *menuLayout = new QHBoxLayout;
	menuLayout->addWidget(&btnVideos);
	menuLayout->addWidget(&btnLista);
	menuLayout->addWidget(&btnPadrao);
	menuLayout->addWidget(&btnPregador);

	QVBoxLayout *mainLayout = new QVBoxLayout;

	mainLayout->addLayout(menuLayout);
	mainLayout->addWidget(&tabMain);
	tabMain.set_dirSlides(configuracao.getDirSlides());
	tabMain.recarregar_musicas();
	tabMain.set_dirTemas(configuracao.getDirTemas());
	tabMain.recarregar_temas();
	tabMain.set_dirLetras(configuracao.getDirLetras());
	tabMain.recarregar_letras();
	tabMain.set_dirVideos(configuracao.getDirVideos());
        tabMain.set_dirPregadores(configuracao.getDirPregadores());
        tabMain.recarregar_pregadores();
	ui.centralwidget->setLayout(mainLayout);

        //barra de status
        ui.statusbar->addWidget(&lblSlide);
        ui.statusbar->addWidget(&lblSlideAtual);
        tabMain.setLabelSlideAtual(&lblSlideAtual);

	//conexao dos sinais
	//menu principal
	connect(ui.actionTextos,SIGNAL(activated()),this,SLOT(ArquivoImportarTextos()));
	connect(ui.actionSair,SIGNAL(activated()),this,SLOT(ArquivoSair()));
	connect(ui.actionDiretorios,SIGNAL(activated()),this,SLOT(ConfiguracoesDiretorios()));
	connect(ui.actionSlidePadrao,SIGNAL(activated()),this,SLOT(ConfiguracoesSlidePadrao()));
	connect(ui.actionSobreQt,SIGNAL(activated()),this,SLOT(AjudaSobreQt()));
	connect(ui.actionSobre,SIGNAL(activated()),this,SLOT(AjudaSobre()));

	connect(&btnPadrao,SIGNAL(clicked()),this,SLOT(SlidePadrao()));

	connect(winSaida.getVideoMediaObject(),SIGNAL(finished()),&tabMain, SLOT(prox_video()));
}

QChurchView::~QChurchView()
{
	QDir *dir_tmp = new QDir("/tmp/QChurchView/");
	if(dir_tmp->exists()){
		QDir::cleanPath("/tmp/QChurchView/");
	}
}

void QChurchView::ArquivoImportarTextos(){
	QStringList arquivo = dlgArquivo.getOpenFileNames(this,"Arquivos Texto",QDir::homePath());
	if(!arquivo.isEmpty()){
		for(int i =0; i < arquivo.size(); i++){
			QFile *novo = new QFile(arquivo.at(i));
			if(!novo->copy(QString::fromStdString(configuracao.getDirLetras())+QInputDialog::getText(this,"Importando:"+arquivo.at(i),"Novo Nome")))
				msgBox.critical(this,"Erro:Importacao de Arquivo de Texto", "Nao foi possivel importar o arquivo " + arquivo.at(i));
		}
		tabMain.recarregar_letras();
	}

}

void QChurchView::ArquivoSair(){
	this->close();
}

void QChurchView::ConfiguracoesDiretorios(){
	frmConfigDirs.ui.edtDirSlides->setText(QString::fromStdString(configuracao.getDirSlides()));
	frmConfigDirs.ui.edtDirTemas->setText(QString::fromStdString(configuracao.getDirTemas()));
	frmConfigDirs.ui.edtDirLetras->setText(QString::fromStdString(configuracao.getDirLetras()));
	frmConfigDirs.ui.edtDirPregadores->setText(QString::fromStdString(configuracao.getDirPregadores()));
	frmConfigDirs.ui.edtDirVideos->setText(QString::fromStdString(configuracao.getDirVideos()));
	frmConfigDirs.show();
}

void QChurchView::ConfiguracoesSlidePadrao(){
	frmConfigSlidePadrao.abrirImagem(QString::fromStdString(configuracao.getImgFundo()));
	frmConfigSlidePadrao.show();
}

void QChurchView::AjudaSobre(){
	msgBox.about(this,"QChurchView","Software para uso em apresentacoes em datashow.\n\nDesenvolvido por: Diego Rubin\nrubin.diego[at]gmail.com");
}

void QChurchView::AjudaSobreQt(){
	msgBox.aboutQt(this,"Sobre o Qt");
}

QString QChurchView::ArquivoConfiguracao()
{
	QString arquivo = QDir::home().path();
	arquivo.append("/.QChurchView/");

	QDir diretorio(arquivo);
	diretorio.mkdir(arquivo);
	arquivo.append("qchurchview.cfg");

	return arquivo;
}
void QChurchView::SalvarDiretorios(){


	configuracao.setDirSlides(frmConfigDirs.ui.edtDirSlides->text().toStdString());
	tabMain.set_dirSlides(frmConfigDirs.ui.edtDirSlides->text().toStdString());
	tabMain.recarregar_musicas();
	configuracao.setDirLetras(frmConfigDirs.ui.edtDirLetras->text().toStdString());
	tabMain.set_dirLetras(frmConfigDirs.ui.edtDirLetras->text().toStdString());
	tabMain.recarregar_letras();
	configuracao.setDirTemas(frmConfigDirs.ui.edtDirTemas->text().toStdString());
	tabMain.set_dirTemas(frmConfigDirs.ui.edtDirTemas->text().toStdString());
	tabMain.recarregar_temas();
	configuracao.setDirPregadores(frmConfigDirs.ui.edtDirPregadores->text().toStdString());
        tabMain.set_dirPregadores(frmConfigDirs.ui.edtDirPregadores->text().toStdString());
        tabMain.recarregar_pregadores();
	configuracao.setDirVideos(frmConfigDirs.ui.edtDirVideos->text().toStdString());
	tabMain.set_dirVideos(frmConfigDirs.ui.edtDirVideos->text().toStdString());

	if(!configuracao.Save(ArquivoConfiguracao().toStdString()))
		msgBox.critical(this,"ERRO:"+ArquivoConfiguracao(),"Nao foi possivel salvar o arquivo de configuracao");
	frmConfigDirs.close();
}

void QChurchView::SalvarSlidePadrao(){
	configuracao.setImgFundo(frmConfigSlidePadrao.getImgFilename().toStdString());
	if(!configuracao.Save(ArquivoConfiguracao().toStdString()))
		msgBox.critical(this,"ERRO:"+ArquivoConfiguracao(),"Nao foi possivel salvar o arquivo de configuracao");
	frmConfigSlidePadrao.close();
}

void QChurchView::SlidePadrao()
{
	if(winSaida.getSituacao() == video){
		tabMain.stop_video();
	}
	winSaida.setImagem(QString::fromStdString(configuracao.getImgFundo()));
        setSlideAtual(QString::fromUtf8("Slide Padrão (<i>") + QString::fromStdString(configuracao.getImgFundo())+"</i>)");

}

void QChurchView::setSlideAtual(QString slide)
{
    lblSlideAtual.setText(slide);
}
