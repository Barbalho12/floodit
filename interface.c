#include "include/interface.h"
#include "include/controle.h"

void gridColorir(Interface *jogo){
	int i,j;
	for (i = 0; i < jogo->flood->orderMatriz; i++){
		for (j = 0; j < jogo->flood->orderMatriz; j++){
			if(!jogo->tableInit)
			jogo->label[i][j] = gtk_label_new("       ");
			gchar *estilo;
			switch(jogo->flood->matriz[i][j]){
				case R:
					estilo = "<span background=\"red\">      </span>";
					break;
				case G:
					estilo = "<span background=\"green\">      </span>";
					break;
				case B:
					estilo = "<span background=\"blue\" >      </span>";
					break;
				case Y:
					estilo = "<span background=\"yellow\">      </span>";
					break;
				case P:
					estilo = "<span background=\"purple\">      </span>";
					break;
				case W:
					estilo = "<span background=\"white\">      </span>";
					break;	
			}
			gtk_label_set_markup (GTK_LABEL (jogo->label[i][j]), estilo);
			if(!jogo->tableInit)
				gtk_grid_attach(GTK_GRID(jogo->gridLabel), jogo->label[i][j],j,i,1,1);
		}
	}
}

void showRodada(Interface *jogo){
	Floodit *flood = jogo->flood;
	contrRodada(flood);
	gchar rod[] = "00";
	int r = flood->rodada;
	if (r > 9){
		rod[0] = (r/10)+48;
		rod[1] = ((r%10)+48);
	}else
		rod[1] = r+48;	
	gtk_label_set_text(GTK_LABEL(jogo->labelRodada), rod);
}

int interfaceDialogMessage(const gchar *message, GtkButtonsType buttonOption){
    GtkWidget *dialog; 
    g_warning("%s", message);
    dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_OTHER, buttonOption, message);
    gtk_window_set_title(GTK_WINDOW(dialog), "Informação");
	gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    int option = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
	return option + 9;
}

void createJanela(GtkWidget *janela, gchar title[15], GtkWindowPosition pos, gboolean resize, const gchar image[20], gint border){
    //Configurações da Janela
	gtk_window_set_title(GTK_WINDOW(janela),title);
	gtk_window_set_position(GTK_WINDOW(janela), pos);
	gtk_window_set_resizable(GTK_WINDOW(janela), resize);
	if (image!="")
		gtk_window_set_default_icon_from_file(image,NULL);
	gtk_container_set_border_width(GTK_CONTAINER(janela),border);
	
}

void action_buttonRed(GtkButton *button, gpointer data) {
	contrButtonAction(data, R);
}
void action_buttonGreen(GtkButton *button, gpointer data) {
	contrButtonAction(data, G);
}
void action_buttonBlue(GtkButton *button, gpointer data) {
	contrButtonAction(data, B);
}
void action_buttonYellow(GtkButton *button, gpointer data) {
	contrButtonAction(data, Y);
}
void action_buttonPurple(GtkButton *button, gpointer data) {
	contrButtonAction(data, P);
}
void action_buttonWhite(GtkButton *button, gpointer data) {
	contrButtonAction(data, W);
}
void action_buttonNewGame(GtkButton *button, gpointer data) {
	
	Interface *jogo = data;
	if (interfaceDialogMessage(MENSAGEM_NEWGAME, GTK_BUTTONS_YES_NO)){
		contrNewgame(jogo, 1);
	}
}
void action_buttonQuit(GtkButton *button, gpointer data) {
	Interface *jogo = data;
	contrSaida(jogo->flood);
}
void action_buttonSave(GtkButton *button, gpointer data) {
	Interface *jogo = data;
	contrSave(jogo->flood);
}
void action_buttonLoad(GtkButton *button, gpointer data) {
	Interface *jogo = data;
	if (contrLoad(jogo->flood))
		contrNewgame(jogo, 0);
}
void action_buttonBackPoint(GtkButton *button, gpointer data) {
	Interface *jogo = data;
	if(jogo->flood->rodada > 0 && jogo->flood->rodada< jogo->flood->qtdRodada){
		contrLoadChekpointTemp(jogo);
		jogo->flood->rodada--;
		showRodada(jogo);
		gridColorir(jogo);
	}
}
void insertWidgetInGrid(GtkWidget *eWidiget, char imag[30], GtkWidget *grid, int left, int top, int width, int height){
	gtk_grid_attach (GTK_GRID(grid), eWidiget, left, top, width, height);
	if (imag != ""){
		GtkWidget *image = gtk_image_new_from_file(imag);
		gtk_button_set_image (GTK_BUTTON(eWidiget), image);
	}
}

void interfaceInit (Interface *jogo){	
	GtkWidget *conteudo;
	
	GtkWidget *gridButtonCor;
	GtkWidget *gridButtonOption;
	GtkWidget *gridRodada;
	
	GtkWidget *b_red;
	GtkWidget *b_green;
	GtkWidget *b_blue;
	GtkWidget *b_yellow;
	GtkWidget *b_purple;
	GtkWidget *b_white;
	GtkWidget *b_newGame;
	GtkWidget *b_load;
	GtkWidget *b_save;
	GtkWidget *b_quit;
	GtkWidget *b_backPoint;
	
	GtkWidget *separador;
	
	//Acima dos processos em execução
    jogo->janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	createJanela(jogo->janela, "Floodit", GTK_WIN_POS_CENTER, TRUE, FILE_IMG_ICON, 20);
	
	//Cria uma nova caixa de conteudo
	conteudo = gtk_box_new(TRUE, 0);
	
	//Adiciona a caixa de conteudo na janela do programa
	gtk_container_add(GTK_CONTAINER(jogo->janela), conteudo);
	
	
	/*Cria Grid de Labels para Rodada*/
	gridRodada = gtk_grid_new();
	gtk_box_pack_start(GTK_BOX(conteudo), gridRodada, FALSE, FALSE, 5);
	/*Cria Label estático "Rodadas: "*/
	insertWidgetInGrid(gtk_label_new("Rodadas: "), "", gridRodada, 1, 0, 1, 1);
	
	/*Cria Label de rodadas "*/
	gchar rodada[3] = {(jogo->flood->rodada/10) + 48,(jogo->flood->rodada%10) + 48, '\0'};
	jogo->labelRodada = gtk_label_new(rodada);
	insertWidgetInGrid(jogo->labelRodada, "", gridRodada, 2, 0, 1, 1);
	
	gchar limtRodada[4] = {'/',((jogo->flood->qtdRodada/10) + 48),((jogo->flood->qtdRodada%10) + 48), '\0'};
	insertWidgetInGrid(gtk_label_new(limtRodada), "", gridRodada, 3, 0, 1, 1);
	
	
	/*Cria Grid de Cores*/
	jogo->gridLabel = gtk_grid_new();
	gtk_box_pack_start(GTK_BOX(conteudo), jogo->gridLabel, FALSE, FALSE, 20);
	
	/*Gera tabela  Aleatória de cores*/
	jogo->tableInit = 0;
	gridColorir(jogo);
	jogo->tableInit = 1;
	
	/*Cria Grid para armazenar os botões de cores*/
	gridButtonCor = gtk_grid_new();
	gtk_box_pack_start(GTK_BOX(conteudo), gridButtonCor, FALSE, FALSE, 10);
	
	/*Butão RED*/
	b_red = gtk_button_new();
	insertWidgetInGrid(b_red, FILE_IMG_RED, gridButtonCor, 0, 1, 1, 2);
	
	/*Butão Green*/
	b_green = gtk_button_new();
	insertWidgetInGrid(b_green, FILE_IMG_GREEN, gridButtonCor, 1, 1, 1, 2);
	
	/*Butão BLUE*/
	b_blue = gtk_button_new();
	insertWidgetInGrid(b_blue, FILE_IMG_BLUE, gridButtonCor, 2, 1, 1, 2);
		
	/*Butão YELLOW*/
	b_yellow = gtk_button_new();
	insertWidgetInGrid(b_yellow, FILE_IMG_YELLOW, gridButtonCor, 3, 1, 1, 2);
	
	/*Butão PURPLE*/
	b_purple = gtk_button_new();
	insertWidgetInGrid(b_purple,FILE_IMG_PURPLE, gridButtonCor, 4, 1, 1, 2);
	
	/*Butão WHITE*/
	b_white = gtk_button_new();
	insertWidgetInGrid(b_white, FILE_IMG_WHITE, gridButtonCor, 5, 1, 1, 2);
	
	/*Separador entre Botões de Cores e os Opções*/
	separador = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
	gtk_box_pack_start(GTK_BOX(conteudo), separador, FALSE, TRUE, 10);
	
	/*Cria Grid para armazenar os botões de Opção*/
	gridButtonOption = gtk_grid_new();
	gtk_box_pack_start(GTK_BOX(conteudo), gridButtonOption, FALSE, FALSE, 0);
	
	/*Butão newGame*/
	b_newGame = gtk_button_new_with_label("  Novo  "); 
	insertWidgetInGrid(b_newGame,FILE_IMG_NEW,gridButtonOption, 0, 2, 1, 2);	
	
	/*Butão Carregar*/
	b_load = gtk_button_new_with_label("Carregar");	
	insertWidgetInGrid(b_load,FILE_IMG_LOAD,gridButtonOption, 1, 2, 1, 2);
	
	/*Butão Salvar*/
	b_save = gtk_button_new_with_label(" Salvar "); 
	insertWidgetInGrid(b_save,FILE_IMG_SAVE, gridButtonOption, 2, 2, 1, 2);
	
	/*Butão Sair*/
	b_quit = gtk_button_new_with_label("  Sair  "); 
	insertWidgetInGrid(b_quit,FILE_IMG_QUIT, gridButtonOption, 3, 2, 1, 2);
	
	/*Butão Desfazer*/
	b_backPoint = gtk_button_new_with_label("Desfazer"); 
	insertWidgetInGrid(b_backPoint,FILE_IMG_BACK, gridButtonOption, 4, 2, 1, 2);
		
	//Interrupçoes de Cada butão de Cores
	g_signal_connect(G_OBJECT(b_red), "clicked", G_CALLBACK(action_buttonRed), jogo);
	g_signal_connect(G_OBJECT(b_green), "clicked", G_CALLBACK(action_buttonGreen), jogo);
    g_signal_connect(G_OBJECT(b_blue), "clicked", G_CALLBACK(action_buttonBlue), jogo);
    g_signal_connect(G_OBJECT(b_yellow), "clicked", G_CALLBACK(action_buttonYellow), jogo);
    g_signal_connect(G_OBJECT(b_purple), "clicked", G_CALLBACK(action_buttonPurple), jogo);
    g_signal_connect(G_OBJECT(b_white), "clicked", G_CALLBACK(action_buttonWhite), jogo);
	
	//Interrupçoes de Cada butão de Opções
	g_signal_connect(G_OBJECT(b_newGame), "clicked", G_CALLBACK(action_buttonNewGame), jogo);
	g_signal_connect(G_OBJECT(b_load), "clicked", G_CALLBACK(action_buttonLoad), jogo);
    g_signal_connect(G_OBJECT(b_save), "clicked", G_CALLBACK(action_buttonSave), jogo);
	g_signal_connect(G_OBJECT(b_quit), "clicked", G_CALLBACK(action_buttonQuit), jogo);
	g_signal_connect(G_OBJECT(b_backPoint), "clicked", G_CALLBACK(action_buttonBackPoint), jogo);
	
	//interrupção de fechamento da janela
	g_signal_connect(G_OBJECT(jogo->janela),"delete_event",G_CALLBACK(contrSaida),jogo->flood);
	
	//inicializa os objetos
	gtk_widget_show_all(jogo->janela);
	
	//Inicia o loop de eventos
	gtk_main();
}
