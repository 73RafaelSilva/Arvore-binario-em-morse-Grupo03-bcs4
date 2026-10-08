/*
 *  Criacao da lib que representa o obejto da nossa tambela de codigos morse
 *
 * */

#ifndef MORSE_H
#define MORSE_H

// declara molde da struct
typedef struct {
    char caractere;
    const char *codigo;
} morse_map;

// limita a 64 caracteres, já que estamos usando o alfabeto de base 64
#define TOTAL_SIMBOLOS 64;


// declara existencia do MorseMap com TOTAL_SIMBOLOS posições
extern const morse_map TABELA_MORSE[TOTAL_SIMBOLOS];

// Protótipo de função para buscar o código de um caractere
const char* obter_codigo_morse(char c);

#endif
