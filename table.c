#include "include/table.h"

Cores aleatorio(Cores a, Cores b){
    return (rand() % (b+1))+a;
}

void montaMatriz(Floodit *flood){
    
    /*Semente de inicialização do random()*/
    srand((unsigned)time(NULL));
	
	int valueMaxColor = flood->orderMatriz*flood->orderMatriz/QTD_CORES; 
	int contColorMax = 0;
	int contColor[QTD_CORES] = {0};
	
    int i, j;
    for (i = 0; i < flood->orderMatriz; i++){
        for (j = 0; j < flood->orderMatriz; j++){
            
            /*Atribuição de cores (caracteres) aleatórias a cada índice da matriz (R, G, B, Y, P ou W)
			De maneira uniforme a quantidade de cada cor não excederá em 1 em relação as outras cores.*/
			int a, b;	
			do{
				a = aleatorio(R, W); 
				b = aleatorio(R, W);
				if (contColor[b] > contColor[a])
					flood->matriz[i][j] = a;
				else
					flood->matriz[i][j] = b;
			}while (contColor[flood->matriz[i][j]] > valueMaxColor || (contColor[flood->matriz[i][j]] == valueMaxColor && contColorMax==4) );
			/*Só depois que todos ficarem iguais em numero de cores, é que as outras cores serão atribuidas ao demais de maior quantidade.*/
			contColor[flood->matriz[i][j]]++;
			if (contColor[flood->matriz[i][j]] > valueMaxColor){
				contColorMax++;
			}
        }
    }
}

void caminhoDeRato(Floodit *flood, int row, int col){
    if((col < flood->orderMatriz && col >= 0) && (row < flood->orderMatriz && row >= 0)){
        if (flood->matriz[row][col] == flood->index00){
			flood->matriz[row][col] = flood->newColor;
			caminhoDeRato(flood, row, col+1);
            caminhoDeRato(flood, row, col-1);
            caminhoDeRato(flood, row+1, col);
            caminhoDeRato(flood, row-1, col);
        }
    }
}