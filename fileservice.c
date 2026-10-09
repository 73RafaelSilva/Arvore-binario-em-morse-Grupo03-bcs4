/*
 *  Implementacao da leitura e processamento de arquivos de texto e Morse
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileservice.h"

// decodifica arquivo com uma unica linha em Morse
void decodificar_arquivo_morse(MorseNode *raiz, const char *caminho_arquivo) {
    FILE *arquivo = fopen(caminho_arquivo, "r");
    if (arquivo == NULL) {
        printf("\n[Erro] Nao foi possivel abrir o arquivo '%s'. Verifique se ele existe na pasta.\n", caminho_arquivo);
        return;
    }

    char linha[4096];
    if (fgets(linha, sizeof(linha), arquivo) == NULL) {
        printf("\n[Aviso] O arquivo '%s' esta vazio.\n", caminho_arquivo);
        fclose(arquivo);
        return;
    }
    fclose(arquivo);

    // Remove quebra de linha do final
    linha[strcspn(linha, "\r\n")] = '\0';

    if (strlen(linha) == 0) {
        printf("\n[Aviso] Arquivo contem apenas linhas em branco.\n");
        return;
    }

    // buffers para resultado e controle de caracteres invalidos
    char resultado[4096];
    int res_idx = 0;

    char erros[512];
    int erros_idx = 0;

    char token[16];
    int token_idx = 0;

    for (int i = 0; linha[i] != '\0'; i++) {
        char c = linha[i];

        if (c == '.' || c == '-') {
            if (token_idx < 15) {
                token[token_idx++] = c;
            }
        } 
        else if (c == ' ') {
            if (token_idx > 0) {
                token[token_idx] = '\0';
                resultado[res_idx++] = decodificar_simbolo(raiz, token);
                token_idx = 0;
            }
        } 
        else if (c == '/') {
            if (token_idx > 0) {
                token[token_idx] = '\0';
                resultado[res_idx++] = decodificar_simbolo(raiz, token);
                token_idx = 0;
            }
            resultado[res_idx++] = ' ';
        }
        else {
            if (erros_idx < 511) {
                erros[erros_idx++] = c;
            }
        }
    }

    if (token_idx > 0) {
        token[token_idx] = '\0';
        resultado[res_idx++] = decodificar_simbolo(raiz, token);
    }

    resultado[res_idx] = '\0';
    erros[erros_idx] = '\0';

    printf("\n=== CONTEUDO DECODIFICADO DO ARQUIVO ===\n");
    printf("%s\n", resultado);

    if (erros_idx > 0) {
        printf("\n");
        for (int i = 0; i < erros_idx; i++) {
            printf("[Aviso: caractere invalido '%c' ignorado no arquivo]\n", erros[i]);
        }
    }
}

// codifica arquivo de texto legivel para Morse
void codificar_arquivo_texto(MorseNode *raiz, const char *caminho_arquivo) {
    FILE *arquivo = fopen(caminho_arquivo, "r");
    if (arquivo == NULL) {
        printf("\n[Erro] Nao foi possivel abrir o arquivo '%s'. Verifique se ele existe na pasta.\n", caminho_arquivo);
        return;
    }

    printf("\n=== CONTEUDO CODIFICADO DO ARQUIVO ===\n");

    char linha[1024];
    char buffer_codigo[16];
    int leu_algo = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        leu_algo = 1;
        linha[strcspn(linha, "\r\n")] = '\0';

        for (int i = 0; linha[i] != '\0'; i++) {
            if (linha[i] == ' ') {
                printf("/ ");
            } else {
                if (codificar_caractere_pela_arvore(raiz, linha[i], buffer_codigo)) {
                    printf("%s ", buffer_codigo);
                } else {
                    printf("? ");
                }
            }
        }
        printf("\n");
    }

    if (!leu_algo) {
        printf("[Aviso] O arquivo '%s' esta vazio.\n", caminho_arquivo);
    }

    fclose(arquivo);
}
