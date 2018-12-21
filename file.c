#include "include/file.h"

int carregarJogo(Floodit *flood){
	FILE *arq;
	arq = fopen(FILE_CHECKPOINT, "r");
	if(arq != NULL){
	
		fscanf(arq, "%i.%i.%i.", &(flood->rodada), &(flood->qtdRodada), &(flood->orderMatriz));
		fclose(arq);
		char cores[flood->orderMatriz*flood->orderMatriz+1];
		
		FILE *arq2;
		arq2 = fopen(FILE_CHECKPOINT, "r");
		fscanf(arq2, "%i.%i.%i.%s", &(flood->rodada), &(flood->qtdRodada), &(flood->orderMatriz), cores);
		fclose(arq2);
		
		int i, j, a;
		for(i = 0, a = 0; i<flood->orderMatriz; i++){
			for(j = 0; j<flood->orderMatriz; j++, a++){
				flood->matriz[i][j] = cores[a] - 48;
			}
		}
		return 1;
	}else
		fclose(arq);
	return 0;
}

void salvaJogo(Floodit *flood){
	FILE *arq;
	arq = fopen(FILE_CHECKPOINT, "w");
	fprintf(arq, "");
	fclose(arq);
	
	FILE *arq2;
	arq2 = fopen(FILE_CHECKPOINT, "wa");

	//Armazenamento da rodada
	putc((flood->rodada/10) + 48, arq2);// = (flood->rodada/10) + 48; //Armazena o dígito das dezenas
	putc((flood->rodada%10) + 48 , arq2); //Armazena o dígito das unidades
	putc('.',arq2); //Término do número da rodada
	
	putc((flood->qtdRodada/10) + 48, arq2); //Armazena o dígito das dezenas
	putc((flood->qtdRodada%10) + 48,arq2); //Armazena o dígito das unidades
	putc('.',arq2); //Término do número da 
	
	putc((flood->orderMatriz/10) + 48, arq2); //Armazena o dígito das dezenas
	putc((flood->orderMatriz%10) + 48, arq2); //Armazena o dígito das unidades
	putc('.', arq2); //Término do número da rodada
	
	int i, j;
	for(i = 0; i < flood->orderMatriz; i++){
		for(j = 0; j < flood->orderMatriz; j++){
			putc(flood->matriz[i][j] + 48, arq2);
		}
	}
	fclose(arq2);
}