#ifndef table_h
#define table_h

#include <time.h>
#include <stdlib.h>
#include "color.h"

/*Ordem da matriz*/
//#define ORDEM_MATRIZ 14

/*Quantidade máxima de jogadas possíveis*/
//#define QTD_RODADAS 25

//Registro da matriz
typedef struct {
	int orderMatriz;
	int qtdRodada;
	int rodada;
    Cores matriz[24][24];
    Cores index00;
    Cores newColor;
} Floodit;

/**
 * Gera valores aleatórios entre a e b
 * @param a Recebe a cor do início do intervalo
 * @param b Recebe a cor do fim do intervalo
 * @return números aleatórios entre a e b.
 */
Cores aleatorio(Cores a, Cores b);

/**
 * Modifica o registro da matriz passada por parâmetro através de ponteiro com valores aleatórios
 * @param flood Ponteiro que recebe o endereço do registro
 * @return void
 */
void montaMatriz(Floodit *flood);

/**
 * Atualização do tabuleiro de forma recursiva, preenchendo os adjacentes de mesma cor
 * @param flood Ponteiro que recebe o endereço do registro
 * @param row linha
 * @param col coluna
 * @return void
 */
void caminhoDeRato(Floodit *flood, int row, int col);
#endif
