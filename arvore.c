/*
* Neste arquivo consta nossa arvore binária onde se encontram todos o alfabeto organizado na arvore, de maneira que as consultas realizadas em binário cheguem ao caracter correspondente.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// funcao de criação nos Nodes
MorseNode* criar_node(char caractere) {
    MorseNode *novo = (MorseNode*) malloc(sizeof(MorseNode));
    if (novo != NULL) {
        novo->caractere = caractere;
        novo->esquerda = NULL;
        novo->direita = NULL;
    }
    return novo;
}

// insere um caractere navegando pelos pontos e traços
void inserir(MorseNode *raiz, const char *codigo, char caractere) {
    MorseNode *atual = raiz; // Começa sempre do topo

    for (int i = 0; codigo[i] != '\0'; i++) {
        if (codigo[i] == '.') {
            // se o node da esquerda for inexistente, ele o cria
            if (atual->esquerda == NULL) {
                atual->esquerda = criar_node(' ');
            }
            atual = atual->esquerda; // se move para o filho a esquerda 
        } 
        else if (codigo[i] == '-') {
            // se o node da direita for inexistente, ele o cria
            if (atual->direita == NULL) {
                atual->direita = criar_node(' ');
            }
            atual = atual->direita; // se move para o filho a direita
        }
    }
    // grava o caractere no node alcançado
    atual->caractere = caractere;
}

// decodifica caracter recebido
char decodificar_simbolo(MorseNode *raiz, const char *codigo) {
    MorseNode *atual = raiz;

    for (int i = 0; codigo[i] != '\0'; i++) {
        if (codigo[i] == '.') {
            if (atual->esquerda == NULL) return '?'; // nada nessa direcao
            atual = atual->esquerda;
        } 
        else if (codigo[i] == '-') {
            if (atual->direita == NULL) return '?'; // nada nessa direcao
            atual = atual->direita;
        }
    }

    // retorna o caractere armazenado naquele node
    return atual->caractere;
}

// Libera a memória alocada (boa prática essencial em C)
void liberar_arvore(MorseNode *raiz) {
    if (raiz == NULL) return;
    liberar_arvore(raiz->esquerda);
    liberar_arvore(raiz->direita);
    free(raiz);
}





