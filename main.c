/*
 *  Código de navegação do projeto, responsável unicamente pela escolha do modulo a executar e chamada de códigos
 *  Entre os modulos, o menu de navegação vira um loop das opçoes
 *  
 *  --- MENU ---
 *  
 *  1 - cifra e decifra via terminal
 *    1.1 - decifrar morse via terminal
 *    1.2 - cifrar texto para morse via terminal
 *    1.0 - voltar
 *
 *  2 cifra e decifra arquivo
 *    2.1 - decifrar morse de arquivo
 *    2.2 - cifrar texto para morse de arquivo
 *    2.0 - volar
 *
 *  3 - Mostrar arvore
 *
 *  0 - Sair
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "plantacao.h"

// --- ESQUELETOS DAS FUNÇÕES QUE IMPLEMENTAREMOS DEPOIS ---
void menu_terminal(MorseNode *raiz);
void menu_arquivos(MorseNode *raiz);
void limpar_buffer(void);

// Stubs para o menu de terminal
void executar_decodificar_terminal(MorseNode *raiz) {
    (void)raiz; // Evita warning de parâmetro não utilizado no momento
    printf("\n[STUB] Opcao 1.1: Decodificar Morse digitado.\n");
}

void executar_codificar_terminal(MorseNode *raiz) {
    (void)raiz;
    printf("\n[STUB] Opcao 1.2: Codificar texto digitado.\n");
}

// Stubs para o menu de arquivos
void executar_decodificar_arquivo(MorseNode *raiz) {
    (void)raiz;
    printf("\n[STUB] Opcao 2.1: Decodificar arquivo 'morse.txt'.\n");
}

void executar_codificar_arquivo(MorseNode *raiz) {
    (void)raiz;
    printf("\n[STUB] Opcao 2.2: Codificar arquivo 'texto.txt'.\n");
}

// Stub para exibir a árvore (Requisito obrigatório do PDF)
void executar_mostrar_arvore(MorseNode *raiz) {
    (void)raiz;
    printf("\n[STUB] Opcao 3: Mostrar diagrama da arvore no terminal.\n");
}

// limpa as entradas do teclado das váriáveis
void limpar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// menu princpal de onde o codigo gira em torno 
int main(void) {
    printf("Iniciando o sistema...\n");
    MorseNode *raiz = plantar_arvore_morse();

    if (raiz == NULL) {
        fprintf(stderr, "Erro critico: Falha ao carregar a arvore Morse.\n");
        return 1;
    }

    int opcao_principal = -1;

    do {
        printf("\n====================================\n");
        printf("           MENU PRINCIPAL           \n");
        printf("====================================\n");
        printf("1. Trabalhar com entrada no terminal\n");
        printf("2. Trabalhar com arquivos (.txt)\n");
        printf("3. Mostrar arvore binaria\n");
        printf("0. Encerrar\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao_principal) != 1) {
            printf("\nOpcao invalida! Digite apenas numeros.\n");
            limpar_buffer();
            continue;
        }
        limpar_buffer();

        switch (opcao_principal) {
            case 1:
                menu_terminal(raiz);
                break;
            case 2:
                menu_arquivos(raiz);
                break;
            case 3:
                executar_mostrar_arvore(raiz);
                break;
            case 0:
                printf("\nEncerrando a aplicacao...\n");
                break;
            default:
                printf("\nOpcao inexistente. Tente novamente.\n");
                break;
        }

    } while (opcao_principal != 0);

    liberar_arvore(raiz);
    printf("Memoria liberada. Ate logo!\n");

    return 0;
}

// menu direcionado quando se quer trabalhar com entradas via terminal
void menu_terminal(MorseNode *raiz) {
    int opcao = -1;

    do {
        printf("\n------------------------------------\n");
        printf("        ENTRADA VIA TERMINAL        \n");
        printf("------------------------------------\n");
        printf("1. Decodificar Morse digitado (Morse -> Texto)\n");
        printf("2. Codificar texto digitado (Texto -> Morse)\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nOpcao invalida! Digite apenas numeros.\n");
            limpar_buffer();
            continue;
        }
        limpar_buffer();

        switch (opcao) {
            case 1:
                executar_decodificar_terminal(raiz);
                break;
            case 2:
                executar_codificar_terminal(raiz);
                break;
            case 0:
                printf("\nRetornando ao menu principal...\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }

    } while (opcao != 0);
}

// menu direcionado ao escolher trabalhar com arquivos
void menu_arquivos(MorseNode *raiz) {
    int opcao = -1;

    do {
        printf("\n------------------------------------\n");
        printf("         MODO DE ARQUIVOS           \n");
        printf("------------------------------------\n");
        printf("1. Decodificar 'morse.txt' (Morse -> Texto)\n");
        printf("2. Codificar 'texto.txt' (Texto -> Morse)\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nOpcao invalida! Digite apenas numeros.\n");
            limpar_buffer();
            continue;
        }
        limpar_buffer();

        switch (opcao) {
            case 1:
                executar_decodificar_arquivo(raiz);
                break;
            case 2:
                executar_codificar_arquivo(raiz);
                break;
            case 0:
                printf("\nRetornando ao menu principal...\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }

    } while (opcao != 0);
}
