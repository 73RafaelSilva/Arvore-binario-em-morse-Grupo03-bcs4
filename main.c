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
 *    2.0 - voltar
 *
 *  3 - Mostrar arvore
 *
 *  0 - Sair
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "plantacao.h"
#include "fileservice.h"

// limpa o terminal respeitando o sistema operacional
void limpar_tela(void) {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

// limpa as entradas do teclado das variáveis
void limpar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// declara funcoes a chamar no correr do codiguin
void menu_terminal(MorseNode *raiz);
void menu_arquivos(MorseNode *raiz);

// codiguin de decodificacao via terminal varrendo a arvore da raiz ate o caracer esperado, a partir das instruções em morse
void executar_decodificar_terminal(MorseNode *raiz) {
    char linha[1024];
    printf("\nDigite a sequencia Morse (ex: ... --- ... ou --- .-.. .- / -- ..- -. -.. ---):\n> ");

    if (fgets(linha, sizeof(linha), stdin) == NULL) {
        printf("Erro ao ler entrada.\n");
        return;
    }

    linha[strcspn(linha, "\n")] = '\0';

    if (strlen(linha) == 0) {
        printf("Nenhuma sequencia informada.\n");
        return;
    }

    char resultado[1024];
    char erros[256];

    decodificar_texto_morse(raiz, linha, resultado, erros);

    printf("\nTexto decodificado: %s\n", resultado);

    if (strlen(erros) > 0) {
        printf("\n");
        for (int i = 0; erros[i] != '\0'; i++) {
            printf("[Aviso: caractere invalido '%c' ignorado]\n", erros[i]);
        }
    }
}

// codiguin de codificar, varrendo arvore, achando caracter e subindo ate a raiz para descobrir o caminho do morse
void executar_codificar_terminal(MorseNode *raiz) {
    char texto[512];
    printf("\nDigite o texto para codificar: ");

    if (fgets(texto, sizeof(texto), stdin) == NULL) {
        printf("Erro ao ler entrada.\n");
        return;
    }

    texto[strcspn(texto, "\n")] = '\0';
    if (strlen(texto) == 0) {
        printf("Nenhum texto informado.\n");
        return;
    }

    printf("\nTexto em Morse:\n");
    codificar_texto_para_morse(raiz, texto);
}

void executar_decodificar_arquivo(MorseNode *raiz) {
    decodificar_arquivo_morse(raiz, "morse.txt");
}

void executar_codificar_arquivo(MorseNode *raiz) {
    codificar_arquivo_texto(raiz, "texto.txt");
}

void executar_mostrar_arvore(MorseNode *raiz) {
    exibir_arvore(raiz);
}

// menu princpal de onde o codiguin gira em torno 
int main(void) {
    limpar_tela();
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
            limpar_tela();
            printf("\nOpcao invalida! Digite apenas numeros.\n");
            limpar_buffer();
            continue;
        }
        limpar_buffer();

        limpar_tela();

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
                printf("Encerrando a aplicacao...\n");
                break;
            default:
                printf("Opcao inexistente. Tente novamente.\n");
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
            limpar_tela();
            printf("\nOpcao invalida! Digite apenas numeros.\n");
            limpar_buffer();
            continue;
        }
        limpar_buffer();

        limpar_tela();

        switch (opcao) {
            case 1:
                executar_decodificar_terminal(raiz);
                break;
            case 2:
                executar_codificar_terminal(raiz);
                break;
            case 0:
                printf("Retornando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
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
            limpar_tela();
            printf("\nOpcao invalida! Digite apenas numeros.\n");
            limpar_buffer();
            continue;
        }
        limpar_buffer();

        limpar_tela();

        switch (opcao) {
            case 1:
                executar_decodificar_arquivo(raiz);
                break;
            case 2:
                executar_codificar_arquivo(raiz);
                break;
            case 0:
                printf("Retornando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

    } while (opcao != 0);
}
