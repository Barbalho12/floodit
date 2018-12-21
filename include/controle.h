#ifndef controle_h
#define controle_h

#include "interface.h"
#include "file.h"

/**
 * Incremento das rodadas
 * @param flood Ponteiro para um registro do tipo Floodit
 * @return void
 */
void contrRodada(Floodit *flood);

/**
 * Verifica se a matriz é homogênea
 * @param flood Ponteiro para um registro do tipo Floodit
 * @return Retorna 1 se a matriz for heterogênea ou 0 caso contrário
 */
int contrFlooded(Floodit *flood);

/**
 * Verifica se o jogador venceu o jogo
 * @param flood Ponteiro para um registro do tipo Floodit
 * @return Retorna 1 se venceu ou 0 caso contrário
 */
int contrVitoria(Floodit *flood);

/**
 * Verifica se o jogador perdeu o jogo
 * @param flood Ponteiro para um registro do tipo Floodit
 * @return Retorna 1 se perdeu ou 0 caso contrário
 */
int contrDerrota(Floodit *flood);

/**
 * Controle de salvar um estado do jogo
 * @param flood Ponteiro para um registro do tipo Floodit
 * @return void
 */
void contrSaveChekpointTemp(Interface *jogo);

/**
 * Controle de carregar um estado do jogo
 * @param flood Ponteiro para um registro do tipo Floodit
 * @return void
 */
void contrLoadChekpointTemp(Interface *jogo);

/**
 * Controle de limpar todos os estados do jogo
 * @param flood Ponteiro para um registro do tipo Floodit
 * @return void
 */
void contrClearChekpointTemp(Interface *jogo);

 /**
 * Controle da opção de Carregar um jogo do arquivo
 * @param flood Ponteiro para um registro do tipo Floodit
 * @return Retorna 1 se carregou do arquivo ou 0 caso o arquivo não exista
 */
int contrLoad(Floodit *flood);

/**
 * Controle da opção de Salvar jogo em arquivo
 * @param flood Ponteiro para um registro do tipo Floodit
 * @return void
 */
void contrSave(Floodit *flood);

/**
 * Controle da opção de Sair do jogo
 * @param flood Ponteiro para um registro do tipo Floodit
 * @return void
 */
void contrSaida(Floodit *flood);

/**
 * Controle da inicalização de uma nova interface gráfica
 * @param flood Ponteiro para um registro do tipo Interface
 * @param modo Valor booleano para modo de criação de novo jogo (arquivo existente ou novo)
 * @return void
 */
void contrNewgame(Interface *jogo, gboolean modo);

/**
 * Controla as opções dos botões de cores, e exibi os processos de vitória ou derrota
 * @param jogo Ponteiro que recebe o endereço do registro de Interface
 * @param cor Cor do butão clicado
 * @return void
 */
void contrButtonAction (Interface *jogo, Cores cor);
#endif