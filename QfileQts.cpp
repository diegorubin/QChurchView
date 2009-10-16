/*
 * QfileQts.cpp
 *
 *  Created on: Feb 17, 2009
 *      Author: diego
 */

#include "QfileQts.h"

QfileQts::QfileQts(string temporario) {
	Temporario = temporario;

}

QfileQts::~QfileQts() {
	// TODO Auto-generated destructor stub
}

void QfileQts::setArquivo(string arquivo){
	Arquivo = arquivo;
	Extensao = Arquivo.substr(Arquivo.length()-4,Arquivo.length());
}

bool QfileQts::gerar_infxml(string destino){
	FILE *tmp;

	// cria o xml que contera as informacoes para conexao
	TiXmlDocument inf;
	TiXmlDeclaration *dcl = new TiXmlDeclaration("1.0","","");
	TiXmlElement *titulo = new TiXmlElement("titulo");
	TiXmlText *txt_titulo = new TiXmlText(Titulo.c_str());
	titulo->LinkEndChild(txt_titulo);


	//adiciona inf gerais
	TiXmlElement *gerais = new TiXmlElement("gerais");

	TiXmlElement *tipo = new TiXmlElement("tipo");
	TiXmlText *txt_tipo = new TiXmlText("");
	switch(Tipo){
		case Imagem:
			txt_tipo->SetValue("0");
			break;
		case Video:
			txt_tipo->SetValue("1");
			break;
	}
	tipo->LinkEndChild(txt_tipo);
	gerais->LinkEndChild(tipo);

	TiXmlElement *extensao = new TiXmlElement("extensao");
	TiXmlText *txt_extensao = new TiXmlText(Extensao.c_str());
	extensao->LinkEndChild(txt_extensao);
	gerais->LinkEndChild(extensao);

	TiXmlElement *arquivo = new TiXmlElement("arquivo");
	tmp = fopen(Arquivo.c_str(),"r");
	arquivo->SetAttribute("tamanho",calcularTamanhoArquivo(tmp));
	TiXmlText *txt_arquivo = new TiXmlText(nome_arquivo(Arquivo).c_str());
	arquivo->LinkEndChild(txt_arquivo);
	gerais->LinkEndChild(arquivo);

	TiXmlElement *thumb = new TiXmlElement("thumb");
	tmp = fopen(Thumb.c_str(),"r");
	thumb->SetAttribute("tamanho",calcularTamanhoArquivo(tmp));
	TiXmlText *txt_thumb = new TiXmlText(nome_arquivo(Thumb).c_str());
	thumb->LinkEndChild(txt_thumb);
	gerais->LinkEndChild(thumb);

	TiXmlElement *descricao = new TiXmlElement("descricao");
	TiXmlText *txt_descricao = new TiXmlText(Descricao.c_str());
	descricao->LinkEndChild(txt_descricao);
	gerais->LinkEndChild(descricao);

	TiXmlElement *cor = new TiXmlElement("cor_padrao");
	TiXmlText *txt_cor = new TiXmlText(CorPadrao.c_str());
	cor->LinkEndChild(txt_cor);
	gerais->LinkEndChild(cor);

	TiXmlElement *posicao = new TiXmlElement("posicao");

	TiXmlElement *postitulo = new TiXmlElement("pos_titulo");
	postitulo->SetAttribute("x",xTitulo);
	postitulo->SetAttribute("y",yTitulo);
	postitulo->SetAttribute("tamanho",tpTitulo);
	posicao->LinkEndChild(postitulo);

	TiXmlElement *posinicio = new TiXmlElement("pos_texto");
	posinicio->SetAttribute("x",xInicio);
	posinicio->SetAttribute("y",yInicio);
	posinicio->SetAttribute("tamanho",tpInicio);
	switch(posTexto){
		case Esquerda:
			posinicio->SetAttribute("posicao_texto","0");
			break;
		case Centralizado:
			posinicio->SetAttribute("posicao_texto","1");
			break;
		case Direita:
			posinicio->SetAttribute("posicao_texto","2");
			break;
	}
	posicao->LinkEndChild(posinicio);


	inf.LinkEndChild(dcl);
	inf.LinkEndChild(titulo);
	inf.LinkEndChild(gerais);
	inf.LinkEndChild(posicao);

	destino.append("inf_tema.xml");
	return inf.SaveFile(destino.c_str());
}

bool QfileQts::abrir_infxml(string arquivo){
	TiXmlDocument infxml(arquivo.c_str());

	if(infxml.LoadFile()){ //o arquivo existe
		TiXmlHandle hDb(&infxml);
		TiXmlElement *pElem;
		TiXmlHandle hRoot(0);

		pElem = hDb.FirstChildElement("titulo").Element();
		Titulo = pElem->GetText();

		pElem = hDb.FirstChildElement("gerais").Element();
		hRoot = TiXmlHandle(pElem);
		pElem = hRoot.FirstChildElement().Element();
		switch(atoi(pElem->GetText())){
		case 0:
			Tipo = Imagem;
			break;
		case 1:
			Tipo = Video;
			break;
		}
		pElem = pElem->NextSiblingElement();

		Extensao = pElem->GetText();
		pElem = pElem->NextSiblingElement();

		Arquivo = pElem->GetText();
		tamanho_arquivo = atoi(pElem->Attribute("tamanho"));
		pElem = pElem->NextSiblingElement();

		Thumb = pElem->GetText();
		tamanho_thumb = atoi(pElem->Attribute("tamanho"));
		pElem = pElem->NextSiblingElement();

		Descricao = pElem->GetText();
		pElem = pElem->NextSiblingElement();

		CorPadrao = pElem->GetText();
		pElem = pElem->NextSiblingElement();

		pElem = hDb.FirstChildElement("posicao").Element();
		hRoot = TiXmlHandle(pElem);
		pElem = hRoot.FirstChildElement().Element();

		xTitulo = atoi(pElem->Attribute("x"));
		yTitulo = atoi(pElem->Attribute("y"));
		tpTitulo = atoi(pElem->Attribute("tamanho"));
		pElem = pElem->NextSiblingElement();

		xInicio = atoi(pElem->Attribute("x"));
		yInicio = atoi(pElem->Attribute("y"));
		tpInicio = atoi(pElem->Attribute("tamanho"));
		switch(atoi(pElem->Attribute("posicao_texto"))){
		case 0:
			posTexto = Esquerda;
			break;
		case 1:
			posTexto = Centralizado;
			break;
		case 2:
			posTexto = Direita;
			break;
		}

		return true;
	}
	else
		return false;
}

string QfileQts::nome_arquivo(string caminho){

	int comeco;
	comeco = caminho.length();
	string tmp;
	while (tmp != "/"){
		comeco--;
		tmp = caminho.substr(comeco,1);
	}
	comeco++;
	return caminho.substr(comeco,caminho.length());
}
bool QfileQts::salvar(string destino){
	bool resultado = true;

	resultado = gerar_infxml(destino);
	gerar_qts(destino);

	return resultado;
}

string QfileQts::substituir_espaco(string nome){
	for(unsigned int i=0; i <= nome.length(); i++)
		if(nome.substr(i,1) == " ")
			nome.replace(i,1,"_");
	return nome;
}

void QfileQts::gerar_qts(string destino){

	gzFile gzArquivo;
	ifstream iArquivo;
	char c;

	string tmp = destino + substituir_espaco(Titulo)+".qts";

	gzArquivo = gzopen(tmp.c_str(),"wb");

	tmp = destino + "inf_tema.xml";
	iArquivo.open(tmp.c_str());

	while(iArquivo.good()){
		c = iArquivo.get();
		if (iArquivo.good())
		      gzputc(gzArquivo,c);
	}
	iArquivo.close();

	remove(tmp.c_str());

	gzputs(gzArquivo,separador);

	tmp = Arquivo;
	iArquivo.open(tmp.c_str());

	while(iArquivo.good()){
		c = iArquivo.get();
		if (iArquivo.good())
			  gzputc(gzArquivo,c);
	}
	iArquivo.close();

	tmp = Thumb;
	iArquivo.open(tmp.c_str());

	while(iArquivo.good()){
		c = iArquivo.get();
		if (iArquivo.good())
			  gzputc(gzArquivo,c);
	}
	iArquivo.close();

	gzclose(gzArquivo);
}

void QfileQts::abrir_qts(string arquivo){
	gzFile gzArquivo;
	ofstream oArquivo;

	string destino = Temporario;
	string tmp;
	string cmp;

	char c;
	int img;

	gzArquivo = gzopen(arquivo.c_str(),"rb");
	tmp = destino + "inf_tema.xml";
	oArquivo.open(tmp.c_str(),std::ios::out);
	while(cmp != "|"){
		c = gzgetc(gzArquivo);
		cmp = c;
		if(cmp != "|")
			oArquivo << cmp;
	}
	oArquivo.close();
	abrir_infxml(tmp);

	tmp = destino + Arquivo;
	oArquivo.open(tmp.c_str());
	img = 0;
	while (img < tamanho_arquivo){
		c = gzgetc(gzArquivo);
		if(img <= tamanho_arquivo)
			oArquivo << c;
		img++;
	}
	oArquivo.close();

	tmp = destino + Thumb;
	oArquivo.open(tmp.c_str());
	img = 0;
	while (img < tamanho_thumb){
		c = gzgetc(gzArquivo);
		if(img <= tamanho_thumb)
			oArquivo << c;
		img++;
	}
	oArquivo.close();

	gzclose(gzArquivo);


}

bool QfileQts::abrir(string arquivo){
	FILE *tmp;
	tmp = fopen(arquivo.c_str(),"rb");
	long tamanho = calcularTamanhoArquivo(tmp);
	fclose(tmp);

	if(tamanho != 0){
		abrir_qts(arquivo);
		return true;
	}
	else
		return false;
}

long QfileQts::calcularTamanhoArquivo(FILE *arquivo) {

    // guarda o estado ante de chamar a fun��o fseek
    long posicaoAtual = ftell(arquivo);
    // guarda tamanho do arquivo
    long tamanho;

    // calcula o tamanho
    fseek(arquivo, 0, SEEK_END);
    tamanho = ftell(arquivo);

    // recupera o estado antigo do arquivo
    fseek(arquivo, posicaoAtual, SEEK_SET);

    return tamanho;
}

