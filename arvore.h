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

// funcoes de manipulacao e navegacao na arvore
MorseNode* criar_node(char caracter);
void inserir(MorseNode *raiz, const char *codigo, char caracter);
MorseNode* buscar_node(MorseNode *raiz, char caracter);
void subir_arvore(MorseNode *atual, char *buffer, int *pos);
void inverter_string(char *str);
int codificar_caractere_pela_arvore(MorseNode *raiz, char c, char *buffer_saida);
char decodificar_simbolo(MorseNode *raiz, const char *codigo);
void exibir_arvore(MorseNode *raiz);
void liberar_arvore(MorseNode *raiz);

// funcoes de processamento completo de mensagens
void decodificar_texto_morse(MorseNode *raiz, const char *linha, char *resultado, char *erros);
void codificar_texto_para_morse(MorseNode *raiz, const char *texto);

#endif
