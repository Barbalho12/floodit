#ifndef file_h
#define file_h

#define FILE_CHECKPOINT "files/checkpoint.txt"

#include <stdio.h>
#include "table.h"

/**
 * Carrega um checkpoint armazenado em um arquivo txt
 * @param *flood Ponteiro para a matriz do jogo
 * @return valor booleano da existência do arquivo
 */
int carregarJogo(Floodit *flood);

/**
 * Salva um jogo em um arquivo txt
 * @param *flood Ponteiro para a matriz do jogo
 * @return void
 */
void salvaJogo(Floodit *flood);

#endif