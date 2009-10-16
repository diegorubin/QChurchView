/*
 * QfileQts.h
 *
 *  Created on: Feb 17, 2009
 *      Author: diego
 */

#ifndef QFILEQTS_H_
#define QFILEQTS_H_

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include "tinyxml.h"
#include "zlib.h"

#define separador "|"

using namespace std;

enum QtsTipo {
	Imagem,
	Video
};

enum QtsPosTexto{
	Esquerda,
	Centralizado,
	Direita
};

class QfileQts {
public:
	QfileQts(string temporario);
	virtual ~QfileQts();

	void setTipo(QtsTipo tipo) { Tipo = tipo; }
	void setTitulo(string titulo) { Titulo = titulo; }
	void setArquivo(string arquivo);
	void setThumb(string thumb) { Thumb = thumb; }
	void setDescricao(string descricao) { Descricao = descricao; }
	void setCorPadrao(string cor) { CorPadrao = cor; }
	void setxTitulo(int x) { xTitulo = x; }
	void setyTitulo(int y) { yTitulo = y; }
	void settpTitulo(int tp) { tpTitulo = tp; }
	void setxInicio(int x) { xInicio = x; }
	void setyInicio(int y) { yInicio = y; }
	void settpInicio(int tp) { tpInicio = tp; }
	void setPosTexto(QtsPosTexto pos) { posTexto = pos; }
	void setTemporario(string temporario) { Temporario = temporario; }

	QtsTipo getTipo() { return Tipo; }
	string getTitulo() { return Titulo; }
	string getExtensao() { return Extensao; }
	string getArquivo() { return Arquivo; }
	string getThumb() { return Thumb; }
	string getDescricao() { return Descricao; }
	string getCorPadrao() { return CorPadrao; }
	int getxTitulo() { return xTitulo; }
	int getyTitulo() { return yTitulo; }
	int gettpTitulo() { return tpTitulo; }
	int getxInicio() { return xInicio; }
	int getyInicio() { return yInicio; }
	int gettpInicio() { return tpInicio; }
	QtsPosTexto getPosTexto() { return posTexto; }
	string getTemporario() { return Temporario; }

	bool salvar(string destino);
	bool abrir(string arquivo);


private:
	//infs
	QtsTipo Tipo;
	string Titulo;
	string Extensao;
	string Arquivo;
	string Descricao;
	string Thumb;
	string CorPadrao;
	//pos
	int xTitulo;
	int yTitulo;
	int tpTitulo;
	int xInicio;
	int yInicio;
	int tpInicio;
	QtsPosTexto posTexto;

	string Temporario;
	int tamanho_arquivo;
	int tamanho_thumb;

	bool gerar_infxml(string destino);
	bool abrir_infxml(string arquivo);
	string nome_arquivo(string caminho);
	string substituir_espaco(string nome);
	void gerar_qts(string destino);
	void abrir_qts(string arquivo);

	long calcularTamanhoArquivo(FILE *arquivo);

};

#endif /* QFILEQTS_H_ */
