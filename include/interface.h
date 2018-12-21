#ifndef interface_h
#define interface_h

#define MENSAGEM_VITORIA "Parabéns, Você venceu!\nDeseja iniciar um novo Jogo (sim) ou sair da partida(não)\n"
#define MENSAGEM_DERROTA "Game Over!\nDeseja iniciar um novo Jogo (sim) ou sair da partida(não)\n"
#define MENSAGEM_NEWGAME "Deseja iniciar um outro jogo? Seu jogo atual será perdido."
#define MENSAGEM_LOADGAME "Deseja carregar jogo de arquivo? Seu jogo atual será perdido."
#define MENSAGEM_LOADGAME_SUCESSO "Jogo Carregado com sucesso!"
#define MENSAGEM_LOADGAME_ERRO "Erro ao carregar Jogo!"
#define MENSAGEM_SAVEGAME "Se houver jogo salvo anteriormente, ele será perdido.\nDeseja salvar jogo atual?"
#define MENSAGEM_SAVEGAME_SUCESSO "Jogo Salvo com Sucesso!"
#define MENSAGEM_QUITGAME "Deseja salvar antes de sair?"

#define FILE_IMG_RED "files//red.png"
#define FILE_IMG_GREEN "files//green.png"
#define FILE_IMG_BLUE "files//blue.png"
#define FILE_IMG_YELLOW "files//yellow.png"
#define FILE_IMG_PURPLE "files//purpura.png"
#define FILE_IMG_WHITE "files//white.png"

#define FILE_IMG_NEW "files//newgame.png"
#define FILE_IMG_LOAD "files//load.png"
#define FILE_IMG_SAVE "files//save.png"
#define FILE_IMG_QUIT "files//quit.png"
#define FILE_IMG_BACK "files//back.png"

#define FILE_IMG_ICON "files//icon.png"
#include "table.h"
#include <gtk/gtk.h>
#include <stdio.h>

typedef struct {
	GtkWidget *label[25][25];	/*Matriz de Labels com cada cor*/
	int tableInit;   			/*Booelan garante que o tabuleiro será iniciado e depois só modificado.*/
	Floodit *flood;				/*Ponteiro do Jogo*/
	GtkWidget *janela;
	Cores checkpointsTemp[50][25][25];
	int contPointTemp;
	
	GtkWidget *gridLabel;		/*Grid para matriz de labels*/
	GtkWidget *labelRodada;		/*Grid para label de rodada*/
} Interface;

/**
 * Exibi o grid de cores, de acordo com valores da matriz de cores em Floodit
 * @param jogo Ponteiro que recebe o endereço do registro de Interface
 * @return void
 */
void gridColorir(Interface *jogo);

/**
 * Exibi a rodada no label superior
 * @param jogo Ponteiro que recebe o endereço do registro de Interface
 * @return void
 */
void showRodada(Interface *jogo);

/**
 * Cria uma janela de opçao ou exibição para perguntar, alertar ou informar algo ao usuário
 * @param message Ponteiro de mensagem passada para exibição
 * @param buttonOption tipo de botões para exibição, 'Sim', 'não', 'ok' por exemplo  
 * @return opção do usuario
 */
int interfaceDialogMessage(const gchar *message, GtkButtonsType buttonOption);

/**
 * Cria uma janela
 * @param janela Ponteiro do wideget da janela
 * @param title Titulo da janela
 * @param pos Posição da janela
 * @param resize valor booleano para permissão de modificação do tamanho da janela
 * @param image ícone da janela
 * @param border valor inteiro da borda
 * @return void
 */
void createJanela(GtkWidget *janela, gchar title[15], GtkWindowPosition pos, gboolean resize, const gchar image[20], gint border);

/**
 * Executa Ação ao clicar no butão de cor Vermelho
 * @param button Ponteiro de referência do butão clicado
 * @param data recebe o Registro do jogo do tipo Interface
 * @return void
 */
void action_buttonRed(GtkButton *button, gpointer data);
/**
 * Executa Ação ao clicar no butão de cor Verde
 * @param button Ponteiro de referência do butão clicado
 * @param data recebe o Registro do jogo do tipo Interface
 * @return void
 */
void action_buttonGreen(GtkButton *button, gpointer data);
/**
 * Executa Ação ao clicar no butão de cor Azul
 * @param button Ponteiro de referência do butão clicado
 * @param data recebe o Registro do jogo do tipo Interface
 * @return void
 */
void action_buttonBlue(GtkButton *button, gpointer data);
/**
 * Executa Ação ao clicar no butão de cor Amarelo
 * @param button Ponteiro de referência do butão clicado
 * @param data recebe o Registro do jogo do tipo Interface
 * @return void
 */
void action_buttonYellow(GtkButton *button, gpointer data);

/**
 * Executa Ação ao clicar no butão de cor Roxa
 * @param button Ponteiro de referência do butão clicado
 * @param data recebe o Registro do jogo do tipo Interface
 * @return void
 */
void action_buttonPurple(GtkButton *button, gpointer data);

/**
 * Executa Ação ao clicar no butão de cor Branca
 * @param button Ponteiro de referência do butão clicado
 * @param data recebe o Registro do jogo do tipo Interface
 * @return void
 */
void action_buttonWhite(GtkButton *button, gpointer data);

/**
 * Executa Ação ao clicar no butão para criação de novo Jogo
 * @param button Ponteiro de referência do butão clicado
 * @param data recebe o Registro do jogo do tipo Interface
 * @return void
 */
void action_buttonNewGame(GtkButton *button, gpointer data);

/**
 * Executa Ação ao clicar no butão para sair do jogo
 * @param button Ponteiro de referência do butão clicado
 * @param data recebe o Registro do jogo do tipo Interface
 * @return void
 */
void action_buttonQuit(GtkButton *button, gpointer data);

/**
 * Executa Ação ao clicar no butão para salvar o jogo
 * @param button Ponteiro de referência do butão clicado
 * @param data recebe o Registro do jogo do tipo Interface
 * @return void
 */
void action_buttonSave(GtkButton *button, gpointer data);

/**
 * Executa Ação ao clicar no butão para carregar jogo do arquivo
 * @param button Ponteiro de referência do butão clicado
 * @param data recebe o Registro do jogo do tipo Interface
 * @return void
 */
void action_buttonLoad(GtkButton *button, gpointer data);

/**
 * Executa Ação ao clicar no butão para desfazer uma jogada
 * @param button Ponteiro de referência do butão clicado
 * @param data recebe o Registro do jogo do tipo Interface
 * @return void
 */
void action_buttonBackPoint(GtkButton *button, gpointer data);

/**
 * Insere um elemento em Grid, declarando atributos e as posições do grid
 * @param eWidiget Ponteiro de elemento a ser inserido
 * @param imag nome do arquivo de imagem a ser inserido, no caso dos botões de cores
 * @param grid Ponteiro do grid que o elemento será inserido
 * @param left alinhamento do elemento a esquerda no grid
 * @param top alinhamento do elemento no topo no grid
 * @param width quantidade de colunas do elemento
 * @param height alinhamento de linhas do elemento
 * @return void
 */
void insertWidgetInGrid(GtkWidget *eWidiget, char imag[30], GtkWidget *grid, int left, int top, int width, int height);

/**
 * Inicializa os componentes gráficos do jogo e dá inicio o loop de eventos para comunicação com o usuário
 * @param jogo Ponteiro que recebe o endereço do registro de Interface
 * @return void
 */
void interfaceInit (Interface *jogo);

#endif
