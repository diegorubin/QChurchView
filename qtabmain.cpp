#include "qtabmain.h"

QTabMain::QTabMain(QWidget *parent)
    : QTabWidget(parent),
    qtsTema("/tmp/QChurchView/"),
    csTema("/tmp/QChurchView/tabApresentacao/")
{
	textOpened = false;
	textChanged = false;

	xTitulo = 68;
	yTitulo = 43;
	FonteTitulo = 11;

	xTexto = 68;
	yTexto = 43;
	FonteTexto = 11;

        pxTitulo = 68;
        pyTitulo = 43;
        pFonteTitulo = 11;

        pxTexto = 68;
        pyTexto = 43;
        pFonteTexto = 11;

        pxPregador = 68;
        pyPregador = 43;
        pFontePregador = 11;

	filtrosArquivo = "Arquivo de imagem (*.jpg *.png)";

	ui.setupUi(this);

	//tab videos
	play = false;
	vWidget.setParent(ui.frmVideo);
	vWidget.move(60,10);
	vWidget.resize(267,200);
	vWidget.show();

	slrVideo.setParent(ui.frmVideo);
	slrVideo.move(20,220);
	slrVideo.resize(332,16);
	slrVideo.setMediaObject(&mediaObejct);
	slrVideo.show();

	mediaObejct.setTickInterval(10);

	Phonon::createPath(&mediaObejct,&vWidget);

	connect(ui.btnAdicionarLetra,SIGNAL(clicked()),this,SLOT(adicionar_letra()));
	connect(ui.btnAdicionarMusica,SIGNAL(clicked()),this,SLOT(adicionar_apresentacao()));
	connect(ui.btnRecarregarLetra,SIGNAL(clicked()),this,SLOT(recarregar_letras()));
	connect(ui.btnSalvar,SIGNAL(clicked()),this,SLOT(salvar_letra()));
	connect(ui.btnRemoverLetra,SIGNAL(clicked()),this,SLOT(remover_letra()));
	connect(ui.btnRenomearLetra,SIGNAL(clicked()),this,SLOT(renomear_letra()));

	connect(ui.lstLetras,SIGNAL(itemSelectionChanged()),this,SLOT(editar_letra()));
	connect(ui.lstTemas,SIGNAL(itemSelectionChanged()),this,SLOT(carregar_tema()));
	connect(ui.lstEdicaoMusicas,SIGNAL(itemSelectionChanged()),this, SLOT(carregar_apresentacao()));
	connect(ui.lstArquivosTemas,SIGNAL(itemSelectionChanged()),this,SLOT(editar_tema()));
	connect(ui.lstVideos,SIGNAL(itemDoubleClicked ( QListWidgetItem* )),this, SLOT(executar_videos()));

	connect(ui.edtTituloApresentacao,SIGNAL(textChanged(const QString)),this, SLOT(atualizar_titulo()));

	connect(ui.pteLetra,SIGNAL(textChanged()),this,SLOT(mudanca_texto()));
	connect(ui.pteLetra,SIGNAL(cursorPositionChanged()),this,SLOT(slide_atual()));

	connect(ui.btnNovoSlide,SIGNAL(clicked()),this,SLOT(adicionar_slide()));
	connect(ui.btnFimSlide,SIGNAL(clicked()),this,SLOT(finalizar_apresentacao()));
	connect(ui.btnTemaArquivo,SIGNAL(clicked()),this, SLOT(adicionar_tema_arquivo()));
	connect(ui.btnTemaThumb,SIGNAL(clicked()),this, SLOT(adicionar_tema_thumb()));
	connect(ui.btnTemaCor,SIGNAL(clicked()),this, SLOT(adicionar_tema_cor()));
	connect(ui.btnAdiconarTema,SIGNAL(clicked()),this,SLOT(adicionar_tema()));
	connect(ui.btnTemaSalvar,SIGNAL(clicked()),this,SLOT(salvar_tema()));
	connect(ui.btnAdicionarVideo,SIGNAL(clicked()),this,SLOT(adicionar_video()));
	connect(ui.btnLimparVideos,SIGNAL(clicked()),this,SLOT(limpar_videos()));
	connect(ui.btnRemoverVideos,SIGNAL(clicked()),this,SLOT(remover_videos()));
	connect(ui.btnVideoPlay,SIGNAL(clicked()),this,SLOT(playpause_video()));
	connect(ui.btnVideoProx,SIGNAL(clicked()),this,SLOT(prox_video()));
	connect(ui.btnVideoAnt,SIGNAL(clicked()),this,SLOT(ant_video()));
	connect(ui.btnVideoStop,SIGNAL(clicked()),this,SLOT(stop_video()));
	connect(ui.btnVideoSincronizar,SIGNAL(clicked()),this, SLOT(sincronizar_video()));
        connect(ui.btnAbrirFundoPregador,SIGNAL(clicked()),this,SLOT(adicionar_pregador_fundo()));

	connect(ui.rdbImagem,SIGNAL(clicked()),this,SLOT(trocar_filtro_tema()));
	connect(ui.rdbVideo,SIGNAL(clicked()),this,SLOT(trocar_filtro_tema()));
	connect(ui.rdbCentralizado,SIGNAL(clicked()),this,SLOT(trocar_posicao_texto()));
	connect(ui.rdbDireita,SIGNAL(clicked()),this,SLOT(trocar_posicao_texto()));
	connect(ui.rdbEsquerda,SIGNAL(clicked()),this,SLOT(trocar_posicao_texto()));

	connect(ui.hsrTitulo,SIGNAL(valueChanged(int )),this, SLOT(mover_xtitulo(int )));
	connect(ui.vsrTitulo,SIGNAL(valueChanged(int )),this, SLOT(mover_ytitulo(int )));
	connect(ui.hsrTexto,SIGNAL(valueChanged(int )),this, SLOT(mover_xtexto(int )));
	connect(ui.vsrTexto,SIGNAL(valueChanged(int )),this, SLOT(mover_ytexto(int )));
        connect(ui.hsrTituloPregador,SIGNAL(valueChanged(int )),this, SLOT(mover_pxtitulo(int )));
        connect(ui.vsrTituloPregador,SIGNAL(valueChanged(int )),this, SLOT(mover_pytitulo(int )));
        connect(ui.hsrTextoPregador,SIGNAL(valueChanged(int )),this, SLOT(mover_pxtexto(int )));
        connect(ui.vsrTextoPregador,SIGNAL(valueChanged(int )),this, SLOT(mover_pytexto(int )));
        connect(ui.hsrPregadorPregador,SIGNAL(valueChanged(int )),this, SLOT(mover_pxpregador(int )));
        connect(ui.vsrPregadorPregador,SIGNAL(valueChanged(int )),this, SLOT(mover_pypregador(int )));

	connect(ui.spnTamanhoTitulo,SIGNAL(valueChanged(int)), this, SLOT(fonte_titulo(int )));
	connect(ui.spnTamanhoTexto,SIGNAL(valueChanged(int)), this, SLOT(fonte_texto(int )));


	connect(&mediaObejct,SIGNAL(currentSourceChanged ( const Phonon::MediaSource )),this,SLOT(trocar_video()) );
	connect(&mediaObejct,SIGNAL(tick ( qint64)),this,SLOT(atualizar_dados_video()));
}

QTabMain::~QTabMain()
{

}

void QTabMain::recarregar_musicas(){
	ui.lstMusicas->clear();
	ui.lstEdicaoMusicas->clear();
	if(!(dirSlides == "")){
		QDir slides(dirSlides);
			if(!slides.exists()){
				dlgErro.critical(this,"Erro:Diretorio de Slides","Diretorio especificado nas configuracoes nao existe");
			}
			else{
				QDirIterator it(slides);
				while(it.hasNext()){
					it.next();
					if(it.fileName() != "." && it.fileName() != ".."){
						ui.lstMusicas->addItem(it.fileName());
						ui.lstEdicaoMusicas->addItem(it.fileName());
					}
				}
			}
	}

}

void QTabMain::recarregar_temas(){
	ui.lstTemas->clear();
	ui.lstArquivosTemas->clear();
	if(!(dirTemas == "")){
		QDir temas(dirTemas);
		QStringList arquivos_qts;
		arquivos_qts << "*.qts";
		temas.setNameFilters(arquivos_qts);
		if(!temas.exists()){
			dlgErro.critical(this,"Erro:Diretorio de Temas","Diretorio especificado nas configuracoes nao existe");
		}
		else{
			QDirIterator it(temas);
			while(it.hasNext()){
				it.next();
				if(it.fileName() != "." && it.fileName() != ".." ){
					ui.lstTemas->addItem(it.fileName());
					ui.lstArquivosTemas->addItem(it.fileName());
				}
			}
		}
	}
}


void QTabMain::recarregar_letras(){
	textOpened = false;
	textChanged = false;
	ui.pteLetra->clear();
	ui.lstLetras->clear();
	if(!(dirLetras == "")){
		QDir letras(dirLetras);
		if(!letras.exists()){
			dlgErro.critical(this,"Erro:Diretorio de Letras","Diretorio especificado nas configuracoes nao existe");
		}
		else{
			QDirIterator it(letras);
			while(it.hasNext()){
				it.next();
				if(it.fileName() != "." && it.fileName() != "..")
					ui.lstLetras->addItem(it.fileName());
			}
		}
	}
	ui.btnRemoverLetra->setEnabled(false);
	ui.btnRenomearLetra->setEnabled(false);

}

void QTabMain::recarregar_pregadores(){
    ui.cmbTemasPregadores->clear();
    ui.lstTemasPregadores->clear();
    if(!(dirPregadores == "")){
        QDir pregadores(dirPregadores);
        if(!pregadores.exists()){
            dlgErro.critical(this,"Erro:Diretorio de Temas para Pregadores","Diretorio especificado nas configuracoes nao existe");
        }
        else{
            QDirIterator it(pregadores);
            while(it.hasNext()){
                it.next();
                if(it.fileName() != "." && it.fileName() != ".."){
                    ui.lstTemasPregadores->addItem(it.fileName());
                    ui.cmbTemasPregadores->addItem(it.fileName());
                }
            }
        }
    }
}

void QTabMain::adicionar_letra(){
	if(dirLetras == ""){
                dlgErro.critical(this,"Erro:Diretorio de Letras","Informe primeiramente o diretorio onde estao ou estarao as letras ou textos");
	}
	else{
		QString letra = QInputDialog::getText(this,"Adicionar Letra","Nome do arquivo");
		if(letra != ""){
			std::ofstream nLetra;

			std::string temp = dirLetras.toStdString();
			temp.append(letra.toStdString());
			nLetra.open(temp.c_str(),std::ios::out);
			nLetra.close();
			recarregar_letras();
			QList<QListWidgetItem* > tmpItem;
			tmpItem = ui.lstLetras->findItems(letra,Qt::MatchExactly);
			ui.lstLetras->setCurrentItem(tmpItem.at(0));
		}

	}
}

void QTabMain::editar_letra(){
	if(textChanged){
		if(dlgErro.question(this,"Salvar Alteracao?","Voce deseja salvas as alteracoes no texto?",QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes)
			salvar_letra();
	}
	textOpened = false;
	ui.pteLetra->clear();
	QString sarquivo = dirLetras;
	QListWidgetItem *item = ui.lstLetras->currentItem();
	ultimoTexto = item->text();
	ui.lblInfNTexto->setText(item->text());
	sarquivo.append(item->text());

	QFile arquivo(sarquivo);
	arquivo.open(QIODevice::ReadOnly | QIODevice::Text);
	while (!arquivo.atEnd()) {
		ui.pteLetra->insertPlainText(QString::fromUtf8(arquivo.readAll()));
	}
	arquivo.close();
	textChanged = false;
	textOpened = true;
	ui.lblSalvar->setText("");
	ui.btnRemoverLetra->setEnabled(true);
	ui.btnRenomearLetra->setEnabled(true);
	ui.lblInfNTexto->setText(ultimoTexto);
	ui.lblTotalSlides->setText(QString::number(numero_de_slides()));

}

void QTabMain::salvar_letra(){
	ui.lblSalvar->setText("");
	textChanged = false;
	QString sarquivo = dirLetras;
	sarquivo.append(ultimoTexto);

	QFile arquivo(sarquivo);
	arquivo.open(QIODevice::Truncate|QIODevice::WriteOnly|QIODevice::Text);

	arquivo.write(ui.pteLetra->toPlainText().toUtf8());
	arquivo.close();
}

void QTabMain::mudanca_texto(){
	if(textOpened){
		textChanged = true;
		ui.lblSalvar->setText("<span style=\" font-style:italic; color:#ff0000;\">Arquivo N&atilde;o Salvo</span>");
		nSlides = numero_de_slides();
		ui.lblTotalSlides->setText(QString::number(nSlides));
	}
}

void QTabMain::remover_letra(){
	if(dlgErro.question(this,"Remover "+ultimoTexto,"Voce realmente deseja remover texto selecionado?",QMessageBox::Yes,QMessageBox::No)== QMessageBox::Yes){
		if(QFile::remove(dirLetras+ultimoTexto)){
			recarregar_letras();
		}
	}
}

void QTabMain::renomear_letra(){
	QString novo_nome = QInputDialog::getText(this,"Renomear Arquivo:"+ultimoTexto,"Novo nome:");
	if(novo_nome != ""){
		QFile *arquivo = new QFile(dirLetras+ultimoTexto);
		if(!arquivo->rename(dirLetras+novo_nome))
			dlgErro.critical(this,"Erro:Renomear Letra","Nao foi possivel renomear letra selecionada");
		recarregar_letras();
		QList<QListWidgetItem* > tmpItem;
		tmpItem = ui.lstLetras->findItems(novo_nome,Qt::MatchExactly);
		ui.lstLetras->setCurrentItem(tmpItem.at(0));
	}
}

void QTabMain::adicionar_slide(){
	ui.pteLetra->insertPlainText("\n<-trocaslide->\n");
}

int QTabMain::numero_de_slides(){
	QString texto = ui.pteLetra->toPlainText();
	int j = 0;
	int slide = 1;

	while ((j = texto.indexOf("<-trocaslide->", j)) != -1) {
		 ++j;
		 slide++;
	}
	return slide;
}

void QTabMain::slide_atual(){
	int pos = ui.pteLetra->textCursor().position();
	ui.lblSlideAtual->setText(QString::number(numero_slide_atual(pos)));
}

int QTabMain::numero_slide_atual(int pos){
	QString texto = ui.pteLetra->toPlainText();
	texto.remove(pos,texto.size());
	int j = 0;
	int slide = 1;

	while ((j = texto.indexOf("<-trocaslide->", j)) != -1) {
		 ++j;
		 slide++;
	}
	return slide;
}

void QTabMain::finalizar_apresentacao(){
	ui.pteLetra->appendPlainText("<-fim->");
}

void QTabMain::adicionar_tema_arquivo(){
	if(ui.rdbImagem->isChecked())
		ui.edtTemaArquivo->setText(dlgArquivos.getOpenFileName(this,"Arquivo de imagem",QDir::homePath(),filtrosArquivo));
	else
		ui.edtTemaArquivo->setText(dlgArquivos.getOpenFileName(this,"Arquivo de video",QDir::homePath(),filtrosArquivo));
}

void QTabMain::adicionar_tema_thumb(){
	ui.edtTemaThumb->setText(dlgArquivos.getOpenFileName(this,"Abrir arquivo para o tema",QDir::homePath(),"imagens(*.jpg)"));
	imgThumb.load(ui.edtTemaThumb->text());
	ui.lblTemaImageVis->setPixmap(imgThumb);
}

void QTabMain::trocar_filtro_tema(){
	if(ui.rdbImagem->isChecked()){
		filtrosArquivo = "Arquivo de imagem (*.jpg *.png)";
	}
	else
		filtrosArquivo = "Arquivo de video (*.mpg *.avi)";
}

void QTabMain::adicionar_tema_cor(){
	QColor color;
	if(ui.edtTemaCor->text().isEmpty())
		color = QColorDialog::getColor(Qt::white,this);
	else
		color = QColorDialog::getColor(ui.edtTemaCor->text(),this);
	if(color.isValid()){
		trocar_cor(color.name());
	}
}

void QTabMain::trocar_cor(QString cor){
	ui.edtTemaCor->setText(cor);
	ui.lblTemaTituloVis->setText("<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:"+QString::number(FonteTitulo)+"pt; text-decoration: underline; color:"+cor+";\">Titulo</span></p>");
	ui.lblTemaTextoVis->setText("<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:"+QString::number(FonteTexto)+"pt; font-style:italic; color:"+cor+";\">Texto do Slide</span></p><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:"+QString::number(FonteTexto)+"pt; font-style:italic; color:"+cor+";\">Ficara mais ou menos assim</p>");
}

void QTabMain::trocar_posicao_texto(){
	if(ui.rdbCentralizado->isChecked()){
		ui.lblTemaTextoVis->setAlignment(Qt::AlignHCenter);
		ui.hsrTexto->setEnabled(false);
		ui.lblXTexto->setEnabled(false);
	}
	else if(ui.rdbDireita->isChecked()){
		ui.lblTemaTextoVis->setAlignment(Qt::AlignRight);
		ui.hsrTexto->setEnabled(false);
		ui.lblXTexto->setEnabled(false);
	}
	else{
		ui.lblTemaTextoVis->setAlignment(Qt::AlignLeft);
		ui.hsrTexto->setEnabled(true);
		ui.lblXTexto->setEnabled(true);
	}
}

void QTabMain::mover_xtitulo(int value){
	xTitulo = value + 68;
	ui.lblTemaTituloVis->move(xTitulo,yTitulo);

	ui.lblXTitulo->setText(QString::number(int(value*4.82)));

}

void QTabMain::mover_ytitulo(int value){
	yTitulo = 243 - value;
	ui.lblTemaTituloVis->move(xTitulo,yTitulo);

	ui.lblYTitulo->setText(QString::number(int((200-value)*5.12)));

}

void QTabMain::mover_xtexto(int value){
	xTexto = value + 68;
	ui.lblTemaTextoVis->move(xTexto,yTexto);
	ui.lblXTexto->setText(QString::number(int (value*4.82)));
}

void QTabMain::mover_ytexto(int value){
	yTexto = 243 - value;
	ui.lblTemaTextoVis->move(xTexto,yTexto);
	ui.lblYTexto->setText(QString::number(int ((200-value)*5.12)));
}

void QTabMain::mover_pxtitulo(int value){
        pxTitulo = value + 68;
        ui.lblPregadorTituloVis->move(pxTitulo,pyTitulo);

}

void QTabMain::mover_pytitulo(int value){
        pyTitulo = 243 - value;
        ui.lblPregadorTituloVis->move(pxTitulo,pyTitulo);
}

void QTabMain::mover_pxtexto(int value){
        pxTexto = value + 68;
        ui.lblPregadorTextoVis->move(pxTexto,pyTexto);
}

void QTabMain::mover_pytexto(int value){
        pyTexto = 243 - value;
        ui.lblPregadorTextoVis->move(pxTexto,pyTexto);
}

void QTabMain::mover_pxpregador(int value){
    pxPregador = value + 68;
    ui.lblPregadorPregadorVis->move(pxPregador,pyPregador);
}

void QTabMain::mover_pypregador(int value){
    pyPregador = 243 - value;
    ui.lblPregadorPregadorVis->move(pxPregador,pyPregador);
}

void QTabMain::adicionar_tema(){
	ui.grbTemaInformacoes->setEnabled(true);
	ui.grbTemaVis->setEnabled(true);
}

void QTabMain::editar_tema(){

	ui.grbTemaInformacoes->setEnabled(true);
	ui.grbTemaVis->setEnabled(true);

	QString tmp = dirTemas + ui.lstArquivosTemas->currentItem()->text();
	if(qtsTema.abrir(tmp.toStdString())){
		//jogando informacoes no form
		//tipo
		switch(qtsTema.getTipo()){
		case Imagem:
			ui.rdbImagem->setChecked(true);
			break;
		case Video:
			ui.rdbVideo->setChecked(true);
			break;
		}
		//titulo
		ui.edtTemaTitulo->setText(QString::fromStdString(qtsTema.getTitulo()));
		//arquivo
		ui.edtTemaArquivo->setText(QString::fromStdString(qtsTema.getTemporario()+qtsTema.getArquivo()));
		//thumb
		ui.edtTemaThumb->setText(QString::fromStdString(qtsTema.getTemporario()+qtsTema.getThumb()));
		imgThumb.load(QString::fromStdString(qtsTema.getTemporario()+qtsTema.getThumb()));
		ui.lblTemaImageVis->setPixmap(imgThumb);
		//cor
		trocar_cor(QString::fromStdString(qtsTema.getCorPadrao()));
		//posicao texto
		switch(qtsTema.getPosTexto()){
		case Esquerda:
			ui.rdbEsquerda->setChecked(true);
			ui.hsrTexto->setSliderPosition(qtsTema.getxInicio()/4.8);
			break;
		case Centralizado:
			ui.rdbCentralizado->setChecked(true);
			break;
		case Direita:
			ui.rdbDireita->setChecked(true);
			break;
		}
		ui.vsrTexto->setSliderPosition(200-(qtsTema.getyInicio()/5.1));
		ui.hsrTitulo->setSliderPosition(qtsTema.getxTitulo()/4.8);
		ui.vsrTitulo->setSliderPosition(200-(qtsTema.getyTitulo()/5.1));
		ui.spnTamanhoTexto->setValue(qtsTema.gettpInicio());
		ui.spnTamanhoTitulo->setValue(qtsTema.gettpTitulo());
		//descricao
		ui.pteTemaDescricao->setPlainText(QString::fromStdString(qtsTema.getDescricao()));
	}
	else{
		ui.rdbImagem->setChecked(true);
		ui.lblTemaImageVis->clear();
		ui.edtTemaArquivo->clear();
		ui.edtTemaTitulo->clear();
		ui.edtTemaThumb->clear();
		ui.edtTemaCor->clear();
		ui.pteTemaDescricao->clear();
		ui.spnTamanhoTexto->setValue(0);
		ui.spnTamanhoTitulo->setValue(0);
		ui.hsrTexto->setValue(0);
		ui.vsrTexto->setValue(80);
		ui.hsrTitulo->setValue(80);
		ui.vsrTitulo->setValue(200);
		ui.rdbCentralizado->setChecked(true);
		trocar_cor("#0000ff");
	}
}

void QTabMain::salvar_tema(){
	if(dirTemas == ""){
		dlgErro.critical(this,"Erro:Diretorio de Temas","Informe primeiramente o diretorio onde est�o ou estar�o os temas");
	}
	else{
		if(ui.rdbImagem->isChecked())
			qtsTema.setTipo(Imagem);
		else
			qtsTema.setTipo(Video);

		qtsTema.setArquivo(ui.edtTemaArquivo->text().toStdString());
		qtsTema.setTitulo(ui.edtTemaTitulo->text().toStdString());
		qtsTema.setThumb(ui.edtTemaThumb->text().toStdString());
		qtsTema.setDescricao(ui.pteTemaDescricao->toPlainText().toStdString());
		qtsTema.setCorPadrao(ui.edtTemaCor->text().toStdString());
		qtsTema.setxTitulo(ui.lblXTitulo->text().toInt());
		qtsTema.setyTitulo(ui.lblYTitulo->text().toInt());
		qtsTema.setxInicio(ui.lblXTexto->text().toInt());
		qtsTema.setyInicio(ui.lblYTexto->text().toInt());
		qtsTema.settpTitulo(ui.spnTamanhoTitulo->value());
		qtsTema.settpInicio(ui.spnTamanhoTexto->value());

		if(ui.rdbCentralizado->isChecked()){
			qtsTema.setPosTexto(Centralizado);
		}
		else if(ui.rdbDireita->isChecked()){
			qtsTema.setPosTexto(Direita);
		}
		else{
			qtsTema.setPosTexto(Esquerda);
		}
		qtsTema.salvar(dirTemas.toStdString());

		recarregar_temas();
	}
}

void QTabMain::fonte_texto(int i){
	FonteTexto = int( i/4.82);
	trocar_cor(ui.edtTemaCor->text());
	ui.lblTemaTextoVis->setScaledContents(true);

}

void QTabMain::fonte_titulo(int i){
	FonteTitulo = int( i/4.82);
	trocar_cor(ui.edtTemaCor->text());
}

void QTabMain::carregar_tema(){
	csTema.abrir((dirTemas + ui.lstTemas->currentItem()->text()).toStdString());
	ui.lblInfNTema->setText(QString::fromStdString(csTema.getTitulo()));
	imgThumb.load(QString::fromStdString(csTema.getTemporario() + csTema.getThumb()));
	ui.lblVisImage->setPixmap(imgThumb);
	ui.lblVisTitulo->move((int) (csTema.getxTitulo()/4.82),(int) (csTema.getyTitulo()/5.1));
	ui.lblVisTitulo->setText("<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:"+QString::number((int) (csTema.gettpTitulo()/4.82))+"pt; text-decoration: underline; color:"+QString::fromStdString(csTema.getCorPadrao())+";\">" + ui.edtTituloApresentacao->text() +"</span></p>");
}

void QTabMain::atualizar_titulo(){
	ui.lblVisTitulo->setText("<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:"+QString::number((int) (csTema.gettpTitulo()/4.82))+"pt; text-decoration: underline; color:"+QString::fromStdString(csTema.getCorPadrao())+";\">" + ui.edtTituloApresentacao->text() +"</span></p>");
	ui.lblVisTitulo->resize((int) (ui.edtTituloApresentacao->text().length()*12),ui.lblVisTitulo->height());
}

void QTabMain::adicionar_apresentacao(){
	if(dirSlides == ""){
		dlgErro.critical(this,"Erro:Diretorio de Slides","Informe primeiramente o diretorio onde est�o ou estar�o os slides");
	}
	else{
		QString slide = QInputDialog::getText(this,"Adicionar Apresentacao","Nome do arquivo");
		if(slide != ""){
			std::ofstream nSlide;

			std::string temp = dirSlides.toStdString();
			slide.append(".qvs");
			temp.append(slide.toStdString());
			nSlide.open(temp.c_str(),std::ios::out);
			nSlide.close();
			recarregar_musicas();
			QList<QListWidgetItem* > tmpItem;
			tmpItem = ui.lstEdicaoMusicas->findItems(slide,Qt::MatchExactly);
			ui.lstEdicaoMusicas->setCurrentItem(tmpItem.at(0));
		}

	}
}

void QTabMain::carregar_apresentacao(){
	ui.btnSalvarApresentacao->setEnabled(true);
}

void QTabMain::adicionar_video(){
	ui.lstVideos->addItems(dlgArquivos.getOpenFileNames(this,"Abrir Videos",dirVideos));
}

void QTabMain::limpar_videos(){
	ui.lstVideos->clear();
}

void QTabMain::remover_videos(){
	qDeleteAll(ui.lstVideos->selectedItems());
}

void QTabMain::executar_videos(){
	if(!ui.lstVideos->selectedItems().empty()){
		play = true;
		winSaida->setSource(ui.lstVideos->selectedItems().at(0)->text());
		Phonon::MediaSource *source = new Phonon::MediaSource(ui.lstVideos->selectedItems().at(0)->text());
		mediaObejct.setCurrentSource(*source);
		mediaObejct.play();
		winSaida->VideoPlay();
	}
}

void QTabMain::atualizar_dados_video(){
        ui.lblVideoAtual->setText(QString::number((int)  (mediaObejct.currentTime()/60000)) + ":" +QString::number((int) (mediaObejct.currentTime()/600)));
	ui.lblVideoFim->setText(QString::number((int)  (mediaObejct.totalTime()/60000)) + ":" +QString::number((int) (mediaObejct.totalTime()/600)));
}

void QTabMain::trocar_video(){
	ui.lblVideoCorrente->setText(mediaObejct.currentSource().fileName());
        lblSlideAtual->setText("Video (<i>" + mediaObejct.currentSource().fileName() + "</i>)");
}

void QTabMain::playpause_video(){
	if(play){
		mediaObejct.pause();
		winSaida->VideoPause();
		ui.btnVideoPlay->setText("play");
		play = false;
	}
	else{
		mediaObejct.play();
		winSaida->VideoPlay();
		ui.btnVideoPlay->setText("pause");
		play = true;
	}

}

void QTabMain::ant_video(){
	QList<QListWidgetItem*> busca = ui.lstVideos->findItems(mediaObejct.currentSource().fileName(),Qt::MatchExactly);
	if(!busca.empty()){
		QListWidgetItem *tmp = busca.at(0);
		int row = ui.lstVideos->row(tmp);
		if(row > 0){
			tmp = ui.lstVideos->item(row-1);
			ui.lstVideos->setCurrentItem(tmp);
			executar_videos();
		}
	}
}

void QTabMain::prox_video(){
	QList<QListWidgetItem*> busca = ui.lstVideos->findItems(mediaObejct.currentSource().fileName(),Qt::MatchExactly);
	if(!busca.empty()){
		QListWidgetItem *tmp = busca.at(0);
		int row = ui.lstVideos->row(tmp);
		if(row < ui.lstVideos->count()-1){
			tmp = ui.lstVideos->item(row+1);
			ui.lstVideos->setCurrentItem(tmp);
			executar_videos();
		}
	}

}

void QTabMain::sincronizar_video()
{
	winSaida->VideoSeek(mediaObejct.currentTime());
}

void QTabMain::stop_video()
{
	mediaObejct.stop();
	ui.lblVideoCorrente->setText("<i>Parado</i>");
	ui.lstVideos->clearSelection();
}

void QTabMain::adicionar_pregador_fundo(){
    if(ui.rdbPregadorImagem->isChecked())
            ui.edtPregadorFundo->setText(dlgArquivos.getOpenFileName(this,"Arquivo de imagem",QDir::homePath(),filtrosArquivo));
    else
            ui.edtPregadorFundo->setText(dlgArquivos.getOpenFileName(this,"Arquivo de video",QDir::homePath(),filtrosArquivo));
 }
