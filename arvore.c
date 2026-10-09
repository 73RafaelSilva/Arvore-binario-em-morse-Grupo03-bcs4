/*
* Neste arquivo consta nossa arvore binária onde se encontram todos o alfabeto organizado na arvore, de maneira que as consultas realizadas em binário cheguem ao caracter correspondente.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include <string.h>

// funcao de criação nos Nodes
MorseNode* criar_node(char caracter) {
    MorseNode *novo = (MorseNode*) malloc(sizeof(MorseNode));
    if (novo != NULL) {
        novo->caracter = caracter;
        novo->esquerda = NULL;
        novo->direita = NULL;
        novo->pai = NULL;
    }
    return novo;
}

// insere um caracter navegando pelos pontos e traços
void inserir(MorseNode *raiz, const char *codigo, char caracter) {
    MorseNode *atual = raiz; // Começa sempre do topo

    for (int i = 0; codigo[i] != '\0'; i++) {
        if (codigo[i] == '.') {
            // se o node da esquerda for inexistente, ele o cria
            if (atual->esquerda == NULL) {
                atual->esquerda = criar_node(' ');
                atual->esquerda->pai = atual;
            }
            atual = atual->esquerda; // se move para o filho a esquerda 
        } 
        else if (codigo[i] == '-') {
            // se o node da direita for inexistente, ele o cria
            if (atual->direita == NULL) {
                atual->direita = criar_node(' ');
                atual->direita->pai = atual;
            }
            atual = atual->direita; // se move para o filho a direita
        }
    }
    // grava o caracter no node alcançado
    atual->caracter = caracter;
}


// varre a arvore em pre-ordem ate encontrar o caracter desejado para cofigicar
MorseNode* buscar_node(MorseNode *raiz, char caracter) {
    if (raiz == NULL) return NULL;

    // verifica node atual
    if (raiz->caracter == caracter) {
        return raiz;
    }

    // verifica subarvore esquerda
    MorseNode *encontrado = buscar_node(raiz->esquerda, caracter);
    if (encontrado != NULL) return encontrado;

    // verifica subarvore direita
    return buscar_node(raiz->direita, caracter);
}

// varre a arvore ao contrário a partir de um node x para decodificar
void subir_arvore(MorseNode *atual, char *buffer, int *pos) {
    // verifia se chegamos a raiz
    if (atual == NULL || atual->pai == NULL) {
        return;
    }

    MorseNode *pai = atual->pai;

    // verifica se o node atual era o filho da esquerda (.) ou direita (-)
    if (pai->esquerda == atual) {
        buffer[(*pos)++] = '.';
    } else if (pai->direita == atual) {
        buffer[(*pos)++] = '-';
    }

    // Chamada recursiva para continuar subindo
    subir_arvore(pai, buffer, pos);
}

// inverte a string no próprio vetor
void inverter_string(char *str) {
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// buffer_saida deve ter espaço para o código (ex: char codigo[16])
int codificar_caractere_pela_arvore(MorseNode *raiz, char c, char *buffer_saida) {
    // busca node na arvore
    MorseNode *node = buscar_node(raiz, c);
    if (node == NULL) {
        buffer_saida[0] = '\0';
        return 0; // caracter nao encontrado
    }

    int pos = 0;
    subir_arvore(node, buffer_saida, &pos);
    buffer_saida[pos] = '\0'; // finaliza

    // inverte saida pois subimos a arvore, e não descemos
    inverter_string(buffer_saida);
    return 1; // sucesso
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

    // retorna o caracter armazenado naquele node
    return atual->caracter;
}

// Libera a memória alocada (boa prática essencial em C)
void liberar_arvore(MorseNode *raiz) {
    if (raiz == NULL) return;
    liberar_arvore(raiz->esquerda);
    liberar_arvore(raiz->direita);
    free(raiz);
}





