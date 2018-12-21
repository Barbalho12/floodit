#include "include/file.h"
// gcc newGame.c color.c table.c file.c -o newGame

int main(int argc, const char * argv[]) { 
    Floodit flood;
	flood.orderMatriz = 14;
	flood.qtdRodada = 25;
    montaMatriz(&flood);
    flood.rodada = 0;
    salvaJogo(&flood);
    return 0;
}