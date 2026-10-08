/*
 * codigo de criacao da tabela de conversao morse que ira popular a arvore nas posicoes corretas 
 *
 * */

#include "morse.h"
#include <ctype.h> // para a funcao toupper() e deixar todos os caracteres maiusculos

// Definição real da variável global na memória
const morse_map TABELA_MORSE[TOTAL_SIMBOLOS] = {
    
    { 'A', ".-"},
    { 'B', "-..."},
    { 'C', "-.-."},
    { 'D', "-.."},
    { 'E', "."},
    { 'F', "..-."},
    { 'G', "--."},
    { 'H', "...."},
    { 'I', ".."},
    { 'J', ".---"},
    { 'K', "-.-"},
    { 'L', ".-.."},
    { 'M', "--"},
    { 'N', "-."},
    { 'O', "---"},
    { 'P', ".--."},
    { 'Q', "--.-"},
    { 'R', ".-."},
    { 'S', "..."},
    { 'T', "-"},
    { 'U', "..-"},
    { 'V', "...-"},
    { 'W', ".--"},
    { 'X', "-..-"},
    { 'Y', "-.--"},
    { 'Z', "--.."},
    { 'a', ".-.-.-"},
    { 'b', ".-.---"},
    { 'c', ".-.--."},
    { 'd', ".-..--"},
    { 'e', ".-..-."},
    { 'f', ".-...-"},
    { 'g', "..----"},
    { 'h', "..---."},
    { 'i', "..--.-"},
    { 'j', "..--.."},
    { 'k', "..--.-."},
    { 'l', "..--.--"},
    { 'm', "..--..-"},
    { 'n', "..--..."},
    { 'o', "..--.---"},
    { 'p', "..--.--."},
    { 'q', "..--.-.-"},
    { 'r', "..--.-.."},
    { 's', "..--.---."},
    { 't', "..--.----"},
    { 'u', "..--.--.-"},
    { 'v', "..--.--.."},
    { 'w', "---.--"},
    { 'x', "---.-."},
    { 'y', "----.."},
    { 'z', "----.-"},
    { '0', "-----"},
    { '1', ".----"},
    { '2', "..---"},
    { '3', "...--"},
    { '4', "....-"},
    { '5', "....."},
    { '6', "-...."},
    { '7', "--..."},
    { '8', "---.."},
    { '9', "----."},
    {62, '+', ".-.-."},
    {63, '/', "-..-."},
    // --- Separador de Palavras ---
    {' ', "/"}
};

// pega o codigo morse dos caracteres pedidos
const char* obter_codigo_morse(char c) {
    char maiusculo = (char)toupper(c);
    for (int i = 0; i < TOTAL_SIMBOLOS; i++) {
        if (TABELA_MORSE[i].caractere == maiusculo) {
            return TABELA_MORSE[i].codigo;
        }
    }
    return NULL; // Caractere não suportado
}
