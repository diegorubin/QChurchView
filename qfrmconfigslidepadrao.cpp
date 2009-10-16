#include "qfrmconfigslidepadrao.h"

QfrmConfigSlidePadrao::QfrmConfigSlidePadrao(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnAbrirImagem,SIGNAL(clicked()),this,SLOT(selecionarImagem()));
	connect(ui.btnSalvarImagem,SIGNAL(clicked()),this->parent(),SLOT(SalvarSlidePadrao()));
}

QfrmConfigSlidePadrao::~QfrmConfigSlidePadrao()
{

}

void QfrmConfigSlidePadrao::abrirImagem(QString filename)
{
	imgFilename = filename;
	imgFundo.load(filename);
	ui.lblFundo->setPixmap(imgFundo);
}

void QfrmConfigSlidePadrao::selecionarImagem()
{
	abrirImagem(QFileDialog::getOpenFileName(this,"Selecione Uma Imagem",QDir::homePath(),"imagens (*.jpg *png)"));
}
