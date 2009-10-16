/*
 * CConfig.h
 *
 *  Created on: Feb 11, 2009
 *      Author: diego
 */

#ifndef CCONFIG_H_
#define CCONFIG_H_

#include <iostream>
#include "tinyxml.h"

using namespace std;

class CConfig {
public:
	CConfig();
	virtual ~CConfig();

	string getDirSlides() { return dirSlides; }
	string getDirTemas() { return dirTemas; }
	string getDirLetras() { return dirLetras; }
	string getDirPregadores() { return dirPregadores; }
	string getDirVideos() { return dirVideos; }
	string getImgFundo() {return imgFundo;}

	void setDirSlides(string slides) { dirSlides = slides; }
	void setDirTemas(string temas) { dirTemas = temas; }
	void setDirLetras(string letras) { dirLetras = letras; }
	void setDirPregadores(string pregadores) { dirPregadores = pregadores; }
	void setDirVideos(string videos) { dirVideos = videos; }
	void setImgFundo(string fundo) { imgFundo = fundo; }
	bool Save(string arquivo_configuracao);
	bool Load(string arquivo_configuracao);

private:
	//diretorios
	string dirSlides;
	string dirTemas;
	string dirLetras;
	string dirPregadores;
	string dirVideos;
	//padroes
	string imgFundo;

};

#endif /* CCONFIG_H_ */
