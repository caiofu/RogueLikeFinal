#ifndef __PLAYER_H__
#define __PLAYER_H__

//Tamanho do inventario e equipamento
#define INVENTARIO_TM   10
#define EQUIPAMENTO_TM   2

//INVETARIO CHEIO
#define CHEIO    1

//IDADE
#define IDADE_MAX     60

//Tipos de itens
#define  POCAO        1
#define  CONSUMIVEL   2
#define  VENDA        3

//EQUIPAMENTO
#define  ARMA       0
#define  ARMADURA   1

typedef struct Equipamento{
      int id, forca, tipo;
      char  item[35];
      float fome, idade, vida, valor;


}Equipamento;

//Inventario
typedef struct Inventario{
      char  item[35];
      int  id, forca, tipo;
      float fome, idade, vida, valor;

}Inventario;

//Player
typedef struct Player{
  char nome[50];
  int vida;
  float fome;
  int idade;
  int forca;
  int camisa;
  int calca;
  char arma[35];
  float fortuna;

}Player;

//Definindo o tamanho do inventario (vetor de struct)
   struct Inventario temp_inventario; //Inventario temporario para fazer a troca de itens
   struct Inventario inventario_player[INVENTARIO_TM];
   struct Equipamento equipamento_player[EQUIPAMENTO_TM];
   struct Player player;

//Funções
//Imprimindo barra de stats
void ImprimiStats(int vida, int fome, int idade, float forca, float fortuna);

void ImprimiInventario();

void AlteraStats();

void DeletaItem(int posicao);

void AbriInventario();

int VerificaInventario(); //Verifica se esta cheio

int RetornaSlotInvent(); //Retorna o slot vazio do inventario para poder gravar


#endif // __PLAYER_H__
