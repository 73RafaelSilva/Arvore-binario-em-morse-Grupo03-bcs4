/*  
  Neste arquivo consta nossa arvore binária onde se encontram todos o alfabeto organizado na arvore, de maneira que as consultas realizadas em binário cheguem ao caracter correspondente.

  Esta arvore se limita aos caracteres base64

  alfabeto e representação em morse:

     , .-.-
    A, .-
    B, -...
    C, -.-.
    D, -..
    E, .
    F, ..-.
    G, --.
    H, ....
    I, ..
    J, .---
    K, -.-
    L, .-..
    M, --
    N, -.
    O, ---
    P, .--.
    Q, --.-
    R, .-.
    S, ...
    T, -
    U, ..-
    V, ...-
    W, .--
    X, -..-
    Y, -.--
    Z, --..
    0, -----
    1, .----
    2, ..---
    3, ...--
    4, ....-
    5, .....
    6, -....
    7, --...
    8, ---..
    9, ----.
    ., .-.-.-
    ,, --..--
    ?, ..--..
    ', .----.
    !, -.-.--
    (, -.--.
    ), -.--.-
    &, .-...
    :, ---...
    ;, -.-.-.
    =, -...-
    +, .-.-.
    -, -....-
    _, ..--.-
    ", .-..-.
    $, ...-..-
    @, .--.-.
    ¿, ..-.-
    ¡, --...-
    À, .--.-
    Å, .--.-
    Ä, .-.-
    É, ..-..
    Ñ, --.--
    Ö, ---.
    Ü, ..--
    %, ----- -..-. -----
    #, ...-.-
  
*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// funcao de criação nos Nodes
MorseNode* criarNo(char caractere) {
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
                atual->esquerda = criarNo(' ');
            }
            atual = atual->esquerda; // se move para o filho a esquerda 
        } 
        else if (codigo[i] == '-') {
            // se o node da direita for inexistente, ele o cria
            if (atual->direita == NULL) {
                atual->direita = criarNo(' ');
            }
            atual = atual->direita; // se move para o filho a direita
        }
    }
    // grava o caractere no node alcançado
    atual->caractere = caractere;
}

// decodifica caracter recebido
char decodificarSimbolo(MorseNode *raiz, const char *codigo) {
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
void liberarArvore(MorseNode *raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}





