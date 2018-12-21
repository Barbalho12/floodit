#include "include/controle.h"

void contrRodada(Floodit *flood){
	flood->rodada++;
}

int contrFlooded(Floodit *flood){
	int i, j;
	for(i = 0; i<flood->orderMatriz; i++){
		for(j = 0; j<flood->orderMatriz; j++){
			if(flood->matriz[0][0] != flood->matriz[i][j]){
				return 0;
			}
		}
	}
	return 1;
}

int contrVitoria(Floodit *flood){
	return flood->rodada<=flood->qtdRodada && contrFlooded (flood);
}

int contrDerrota(Floodit *flood){
	return flood->rodada==flood->qtdRodada && !contrFlooded (flood);;
}

void contrSaveChekpointTemp(Interface *jogo){
	jogo->contPointTemp++;
	int i,j;
	for(i = 0; i<jogo->flood->orderMatriz; i++){
		for(j = 0; j<jogo->flood->orderMatriz; j++){
			jogo->checkpointsTemp[jogo->flood->rodada][i][j] = jogo->flood->matriz[i][j];
		}
	}
}

void contrLoadChekpointTemp(Interface *jogo){
	int i,j;
	if(jogo->contPointTemp){
		jogo->flood->rodada--;
		for(i = 0; i<jogo->flood->orderMatriz-1; i++){
			for(j = 0; j<jogo->flood->orderMatriz-1; j++){
				jogo->flood->matriz[i][j] = jogo->checkpointsTemp[jogo->flood->rodada][i][j];
			}
		}
		jogo->contPointTemp--;
	}
}

void contrClearChekpointTemp(Interface *jogo){
	jogo->contPointTemp = 0;
}

int contrLoad(Floodit *flood){
	if(interfaceDialogMessage(MENSAGEM_LOADGAME, GTK_BUTTONS_YES_NO)){
		if(carregarJogo(flood)){
			interfaceDialogMessage(MENSAGEM_LOADGAME_SUCESSO, GTK_BUTTONS_OK);
			
			return 1;
		}else{
			interfaceDialogMessage(MENSAGEM_LOADGAME_ERRO, GTK_BUTTONS_OK);
			return 0;
		}
	}
}

void contrSave(Floodit *flood){
	int option = interfaceDialogMessage(MENSAGEM_SAVEGAME, GTK_BUTTONS_YES_NO);
	if(option){
		salvaJogo(flood);
		interfaceDialogMessage(MENSAGEM_SAVEGAME_SUCESSO, GTK_BUTTONS_OK);
	}
}

void contrSaida(Floodit *flood){
	if(flood->rodada<flood->qtdRodada){
		int option = interfaceDialogMessage(MENSAGEM_QUITGAME, GTK_BUTTONS_YES_NO);
		if(option)
			contrSave(flood);
	}
	exit(0);
}

void contrNewgame(Interface *jogo, gboolean modo){
		Floodit *temFlood = jogo->flood;
		gtk_widget_destroy(GTK_WIDGET(jogo->janela));
		
		Interface newGame; 
		Floodit newFlood; 
		
		if(modo){
			GtkWidget *dialog;
			dialog = gtk_dialog_new ();
			gtk_dialog_add_button (GTK_DIALOG (dialog),"Fácil", 1);
			gtk_dialog_add_button (GTK_DIALOG (dialog),"Médio", 2);
			gtk_dialog_add_button (GTK_DIALOG (dialog),"Difícil", 3);
			gtk_window_set_title(GTK_WINDOW(dialog), "Escolha a dificuldade do Novo Jogo");
			gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
			int opc = gtk_dialog_run (GTK_DIALOG (dialog));
			gtk_widget_destroy(dialog);

			
			
			switch(opc){
				case 1:
					newFlood.orderMatriz = 10;
					newFlood.qtdRodada = 20;
					break;
				case 2:
					newFlood.orderMatriz = 14;
					newFlood.qtdRodada = 25;
					break;
				case 3:
					newFlood.orderMatriz = 24;
					newFlood.qtdRodada = 50;
					break;
				default:
					newFlood.orderMatriz = 14;
					newFlood.qtdRodada = 25;
					break;
			}
			montaMatriz(&newFlood);
			newFlood.rodada = 0;
		}else{
			newFlood = *(jogo->flood);
		}
		
		newGame.flood = &newFlood;
		contrClearChekpointTemp(&newGame);
		interfaceInit(&newGame); 
}

void contrButtonAction (Interface *jogo, Cores cor){
	Floodit *flood = jogo->flood;
	flood->index00 = flood->matriz[0][0];
	if(flood->index00 != cor){
		contrSaveChekpointTemp(jogo);
		showRodada(jogo);
		flood->newColor = cor;
		caminhoDeRato(flood , 0, 0);
		gridColorir(jogo);
		if(contrVitoria(flood) || contrDerrota(flood)){
			contrClearChekpointTemp(jogo);
			int option;
			if (contrVitoria(flood))
				option = interfaceDialogMessage(MENSAGEM_VITORIA, GTK_BUTTONS_YES_NO);
			else
				option = interfaceDialogMessage(MENSAGEM_DERROTA, GTK_BUTTONS_YES_NO);
			if(option){
				montaMatriz(jogo->flood);
				jogo->flood->rodada = -1;
				gridColorir(jogo);
				showRodada(jogo);
			}else
				contrSaida(flood);
		}
	}
}