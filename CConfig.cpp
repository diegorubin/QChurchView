/*
 * CConfig.cpp
 *
 *  Created on: Feb 11, 2009
 *      Author: diego
 */

#include "CConfig.h"

CConfig::CConfig() {

}

CConfig::~CConfig() {
	// TODO Auto-generated destructor stub
}

bool CConfig::Save(string arquivo_config){

	// cria o xml que contera as informacoes para conexao
	TiXmlDocument config;
	TiXmlDeclaration *dcl = new TiXmlDeclaration("1.0","","");
	TiXmlElement *elem_diretorios = new TiXmlElement("diretorios");

	//adiciona endereco ao arquivo de configuracao
	TiXmlElement *elem_slides = new TiXmlElement("dirSlides");
	TiXmlText *txt_slides = new TiXmlText(dirSlides.c_str());
	elem_slides->LinkEndChild(txt_slides);
	elem_diretorios->LinkEndChild(elem_slides);

	//adiciona diretorio de temas ao arquivo de configuracao
	TiXmlElement *elem_temas = new TiXmlElement("dirTemas");
	TiXmlText *txt_temas = new TiXmlText(dirTemas.c_str());
	elem_temas->LinkEndChild(txt_temas);
	elem_diretorios->LinkEndChild(elem_temas);

	//adiciona diretorio de letras ao arquivo de configuracao
	TiXmlElement *elem_letras = new TiXmlElement("dirLetras");
	TiXmlText *txt_letras = new TiXmlText(dirLetras.c_str());
	elem_letras->LinkEndChild(txt_letras);
	elem_diretorios->LinkEndChild(elem_letras);

	//adiciona diretorio pregadores arquivo de configuracao
	TiXmlElement *elem_pregadores = new TiXmlElement("dirPregadores");
	TiXmlText *txt_pregadores = new TiXmlText(dirPregadores.c_str());
	elem_pregadores->LinkEndChild(txt_pregadores);
	elem_diretorios->LinkEndChild(elem_pregadores);

	//adiciona diretorio de videos arquivo de configuracao
	TiXmlElement *elem_videos = new TiXmlElement("dirVideos");
	TiXmlText *txt_videos = new TiXmlText(dirVideos.c_str());
	elem_videos->LinkEndChild(txt_videos);
	elem_diretorios->LinkEndChild(elem_videos);

	//adiciona padroes
	TiXmlElement *elem_padroes = new TiXmlElement("padroes");

	//fundo padrao
	TiXmlElement *elem_fundo = new TiXmlElement("fundo");
	TiXmlText *txt_fundo = new TiXmlText(imgFundo.c_str());
	elem_fundo->LinkEndChild(txt_fundo);
	elem_padroes->LinkEndChild(elem_fundo);

	config.LinkEndChild(dcl);
	config.LinkEndChild(elem_diretorios);
	config.LinkEndChild(elem_padroes);

	return config.SaveFile(arquivo_config.c_str());

}

bool CConfig::Load(string arquivo_config){
	TiXmlDocument config(arquivo_config.c_str());

	if(config.LoadFile()){ //o arquivo existe
		TiXmlHandle hDb(&config);
		TiXmlElement *pElem;
		TiXmlHandle hRoot(0);
		pElem = hDb.FirstChildElement().Element();
		hRoot = TiXmlHandle(pElem);

		pElem = hRoot.FirstChildElement().Element();//pElem esta no dirSlides
		if(pElem->GetText())//condicao para que o GetText seja diferente de NULL
			dirSlides = pElem->GetText();
		pElem=pElem->NextSiblingElement(); //desce um filho
		if(pElem->GetText())
			dirTemas = pElem->GetText();
		pElem=pElem->NextSiblingElement();
		if(pElem->GetText())
			dirLetras = pElem->GetText();
		pElem=pElem->NextSiblingElement();
		if(pElem->GetText())
			dirPregadores = pElem->GetText();
		pElem=pElem->NextSiblingElement();
		if(pElem->GetText())
			dirVideos = pElem->GetText();

		hRoot = hDb.FirstChildElement("padroes");
		pElem = hRoot.FirstChildElement().Element();
		if(pElem->GetText())
			imgFundo = pElem->GetText();

		return true;
	}
	else
		return false;

}
