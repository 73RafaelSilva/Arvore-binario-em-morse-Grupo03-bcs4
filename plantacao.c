/*
 *  Plantacao da nossa arvore com base no material de morse.h
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "plantacao.h"
#include "morse.h"

MorseNode* plantar_arvore_morse(void) {
    // Cria a raiz neutra/vazia da árvore[cite: 6, 7]
    MorseNode *raiz = criar_node(' ');
    if (raiz == NULL) {
        fprintf(stderr, "Erro de alocação de memória ao criar raiz da árvore.\n");
        return NULL;
    }

    // Itera sobre os 64 símbolos definidos na tabela global
    for (int i = 0; i < TOTAL_SIMBOLOS; i++) {
        inserir(raiz, TABELA_MORSE[i].codigo, TABELA_MORSE[i].caractere);
    }

    return raiz;
}
