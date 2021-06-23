#include <stdio.h>
#include "player.h"
#include "item.h"

//Função para passar valores do tesouro (por referencia)
void tesouro(Player *player, Inventario *inventario_player){
    int tesouro_aleatorio;
    tesouro_aleatorio = rand()%4;

    switch(tesouro_aleatorio)
    {
    case 0:
        printf("Voce encontrou 50 de GOLD. \n");
        player->fortuna += 50;
    break;
    case 1:
        printf("Voce encontrou 10 de GOLD. \n");
        player->fortuna += 10;
    break;
    case 2:
         printf("Voce encontrou 100 de GOLD. \n");
         player->fortuna += 100;
    break;
    case 3:
        printf("Voce encontrou um PAO DE FORMA! \n");
        for(int i =0; i<INVENTARIO_TM; i++)
        {
         //Verifica qual posição vazia para adcionar o item
          if(strlen(inventario_player[i].item) == 0 )
          {
            strcpy(inventario_player[i].item, "PAO DE FORMA" );
            inventario_player[i].tipo = CONSUMIVEL;
            inventario_player[i].fome = 30;

            i = 10;

          }
        }

    break;
    case 4:
    break;
    }
    system("pause");
}
