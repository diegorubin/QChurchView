#include "qfrmconfigdirs.h"

QfrmConfigDirs::QfrmConfigDirs(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnDirSlides,SIGNAL(clicked()),this,SLOT(AbrirDirSlides()));
	connect(ui.btnDirTemas,SIGNAL(clicked()),this,SLOT(AbrirDirTemas()));
	connect(ui.btnDirLetras,SIGNAL(clicked()),this,SLOT(AbrirDirLetras()));
	connect(ui.btnDirPregadores,SIGNAL(clicked()),this,SLOT(AbrirDirPregadores()));
	connect(ui.btnDirVideos,SIGNAL(clicked()),this,SLOT(AbrirDirVideos()));
	connect(ui.btnSalvar,SIGNAL(clicked()),parent,SLOT(SalvarDiretorios()));
	connect(ui.btnCancelar,SIGNAL(clicked()),this,SLOT(Cancelar()));
}

QfrmConfigDirs::~QfrmConfigDirs()
{

}

void QfrmConfigDirs::AbrirDirSlides(){
	QString tmp = QFileDialog::getExistingDirectory(this,"Selecione Diretorio Com os Slides",QDir::homePath());
        if(!tmp.endsWith("/"))
		tmp.append("/");
	ui.edtDirSlides->setText(tmp);


}

void QfrmConfigDirs::AbrirDirTemas(){
	QString tmp = QFileDialog::getExistingDirectory(this,"Selecione Diretorio Com os Temas",QDir::homePath());
	if(!tmp.endsWith("/"))
		tmp.append("/");
	ui.edtDirTemas->setText(tmp);
}

void QfrmConfigDirs::AbrirDirLetras(){
	QString tmp = QFileDialog::getExistingDirectory(this,"Selecione Diretorio Com as Letras",QDir::homePath());
	if(!tmp.endsWith("/"))
		tmp.append("/");
	ui.edtDirLetras->setText(tmp);
}

void QfrmConfigDirs::AbrirDirPregadores(){
	QString tmp = QFileDialog::getExistingDirectory(this,"Selecione Diretorio Com os Temas para Pregadores",QDir::homePath());
	if(!tmp.endsWith("/"))
		tmp.append("/");
	ui.edtDirPregadores->setText(tmp);
}

void QfrmConfigDirs::AbrirDirVideos(){
	QString tmp = QFileDialog::getExistingDirectory(this,"Selecione Diretorio Com Videos",QDir::homePath());
	if(!tmp.endsWith("/"))
		tmp.append("/");
	ui.edtDirVideos->setText(tmp);
}

void QfrmConfigDirs::Cancelar(){
	this->close();
}
