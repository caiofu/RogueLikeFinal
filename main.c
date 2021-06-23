  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #include <string.h>
  #include "player.h"
  #include "mapa.h"
  #include "item.h"


  //Variavel para Movimentação
  char tecla[10];

  //Variavel temporaria para guarda posiçao de elemento
  int temp_elemento;

  //Variavel do Loop principal do jogo
  int JogoRodando = 1; //1 para verdadeiro 0 para falso

  //Variavel posição para posiçao do player (declarada na pagina player)
   posicao_y = POSICAO_PLAYER_Y;
   posicao_x = POSICAO_PLAYER_X;


  int main(){
  //Gerando o Mapa
     CriarMapa();
  //Cria os Itens
     CadastrandoItens();

  //Posição da Casa
  //Primeira posicao altura (colula) e Segunda largura (linha)
    matriz[POSICAO_PLAYER_Y][POSICAO_PLAYER_X-1] = '#';
  //Guarda o que tem nesssa posição na variavel temporaria
    temp_elemento = matriz[POSICAO_PLAYER_Y][POSICAO_PLAYER_X];

  //Colocando player na posiçao estabelecida
    matriz[POSICAO_PLAYER_Y][POSICAO_PLAYER_X] = '@';

  //Valores Iniciais Player
    player.idade = 0;
    player.vida = 100;
    player.fome = 100;
    player.forca = 5;
    printf("\n");

   //Itens iniciais do player
   //########### EQUIPAMENTO INICIAL ###############
     //ESPADA DE BRONZE
     //equipamento_player[0] = itens[0];
    strcpy(equipamento_player[0].item, itens[0].item );
    equipamento_player[0].tipo  = itens[0].tipo;
    equipamento_player[0].forca = itens[0].forca;
    equipamento_player[0].valor = itens[0].valor;

    //Ja somando a força da espada
    player.forca +=  equipamento_player[0].forca;


     //ARMADURA DE BRONZE
    strcpy(equipamento_player[1].item, itens[4].item );
    equipamento_player[1].tipo  = itens[4].tipo;
    equipamento_player[1].forca = itens[4].forca;
    equipamento_player[1].valor = itens[4].valor;

    //Ja somando a força da camisa
    player.forca +=  equipamento_player[1].forca;

   //############# ITENS INICIALS INVENTARIO ###############
    //BOLINHO DE ARROZ
    strcpy(inventario_player[0].item, itens[12].item );
    inventario_player[0].tipo = itens[12].tipo;
    inventario_player[0].fome = itens[12].fome;

  //Imprimeindo o Mapa
    imprimiMiniMap(posicao_y, posicao_x);
  //Imprimi barra de stats do player
    ImprimiStats(player.vida, player.fome, player.idade, player.forca, player.fortuna);
    imprimiLinha();
  //#################### Fim da geração do Mapa


  while(JogoRodando == 1){

  //Movimentação do Player
      printf("\n");
      scanf("%s", &tecla);

  //Guarda o elemento atual na variavel temporaria
     if(temp_elemento != NULL)
        {
            matriz[posicao_y][posicao_x] = temp_elemento;
        }

     if(strcmp(tecla,"w") == 0 || strcmp(tecla,"W") == 0){
           if(matriz[posicao_y-1][posicao_x] != '|')
                posicao_y--; AlteraStats();

    }else if(strcmp(tecla,"s") == 0 || strcmp(tecla,"S")== 0){
            if(matriz[posicao_y+1][posicao_x] != '|')
                posicao_y++; AlteraStats();

    }else if(strcmp(tecla,"a") == 0 || strcmp(tecla,"A")== 0){
            if(matriz[posicao_y][posicao_x-1] != '|')
                posicao_x--; AlteraStats();

    }else if(strcmp(tecla,"d") == 0 || strcmp(tecla,"D")== 0){
            if(matriz[posicao_y][posicao_x+1] != '|')
                posicao_x++; AlteraStats();

    }else if (strcmp(tecla,"!I")==0 || strcmp(tecla,"!i")==0){
          AbriInventario();
     //############### EQUIPAMENTO
    }else if(strcmp(tecla,"!E")==0 || strcmp(tecla,"!e")==0){

    }
//################ NPC
if(matriz[posicao_y][posicao_x] == NPC){
   //Substitui o NPC por planice para nao pegar novamnete
   matriz[posicao_y][posicao_x] = '.';
    //Funçao que sorteia um npc
    npc();

//############### TESOURO
  }else if(matriz[posicao_y][posicao_x] == TESOURO)
  {
    //Substitui o TESOURO por planice para nao pegar novamnete
    matriz[posicao_y][posicao_x] = '.';
    //Funçao que sorteia um tesouro
    tesouro(&player, &inventario_player);

  }

    //Guarda o o que esta na posiçao queo player vai esta na varaivel
    temp_elemento = matriz[posicao_y][posicao_x];
    //Substitui pelo player
    matriz[posicao_y][posicao_x] = '@';



   imprimiMiniMap( posicao_y, posicao_x);
   ImprimiStats(player.vida, player.fome,player.idade, player.forca, player.fortuna);
   imprimiLinha();


  }//Fim do While

  }

