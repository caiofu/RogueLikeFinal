#ifndef __MAPA_H__
#define __MAPA_H__


//Defini��es do Mapa
#define FLORESTA  'Y'
#define MONTANHA  '^'
#define PLANICE   '.'
#define LAGO      '~'
#define TESOURO   '$'
#define INIMIGO   'I'
#define NPC       'P'
#define BLOQUEIO  '|'
#define ALTURA     95
#define LARGURA    95
#define POSICAO_PLAYER_Y  12
#define POSICAO_PLAYER_X  20

//Variavel para posi��o
int posicao_y;
int posicao_x;
int verifica_parede_y;
int verifica_parede_x;
//Criar a matriz do mapa
 char matriz[LARGURA][ALTURA];


//Fun��o para criar o mapa
 char CriarMapa();//Fim da fun��o



//Fun��o para imprimir minimapa do player
void imprimiMiniMap(int y, int x);

void imprimiLinha();


#endif // __MAPA_H__
