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
    struct MorseNode *pai;
} MorseNode;

// funcoes
MorseNode* criar_node(char caracter);
void inserir(MorseNode *raiz, const char *codigo, char caractere);
char decodificar_simbolo(MorseNode *raiz, const char *codigo);
void liberar_arvore(MorseNode *raiz);
int codificar_caractere_pela_arvore(MorseNode *raiz, char c, char *buffer_saida);
void exibir_arvore(MorseNode *raiz);

#endif
