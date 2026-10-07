/*
 *  neste arquivo contem a estrutura de navegação que sera utilizada no projeto
 *
 *  Como definido no escopo, entradas de . para a esquerda e - para a direita   
 *
 * */

#ifndef ARVORE_H
#define ARVORE_H

// criarNo
typedef struct MorseNode {
    char caracter;
    struct MorseNode *esquerda;
    struct MorseNode *direita;
} MorseNode;

// funcoes
MorseNode* criarNo(char caractere);
void inserir(MorseNode *raiz, const char *codigo, char caractere);
char decodificarSimbolo(MorseNode *raiz, const char *codigo);
void liberarArvore(MorseNode *raiz);

#endif
