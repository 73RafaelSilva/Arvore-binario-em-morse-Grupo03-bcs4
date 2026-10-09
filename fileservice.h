/*
 *  Modulo responsavel pelas operacoes de entrada e saida com arquivos .txt
 *
 * */

#ifndef FILESERVICE_H
#define FILESERVICE_H

#include "arvore.h"

// Le o arquivo morse.txt (linha unica) e decodifica na tela
void decodificar_arquivo_morse(MorseNode *raiz, const char *caminho_arquivo);

// Le o arquivo texto.txt e imprime/codifica em Morse
void codificar_arquivo_texto(MorseNode *raiz, const char *caminho_arquivo);

#endif
