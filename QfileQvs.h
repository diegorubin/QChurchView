/*
 * QfileQvs.h
 *
 *  Created on: Feb 13, 2009
 *      Author: diego
 */

#ifndef QFILEQVS_H_
#define QFILEQVS_H_

#include <iostream>
#include <list>
#include "tinyxml.h"

using namespace std;

class QfileQvs {
public:
	QfileQvs();
	virtual ~QfileQvs();

	bool gerar_qvs(string saida);

private:

	//dados da inf_slide.xml
	string tema;
	int numSlides;

	//dados do conteudo.xml
	list<string> textos;

	void gerar_infxml();
	void gerar_conteudoxml();


};

#endif /* QFILEQVS_H_ */
