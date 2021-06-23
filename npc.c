
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "item.h"

void npc(){
    int conta_inventario; //Variavel de verificaçao do inventario
    int aleatorio_npc;
    //Para sortear a fala do NPC
    aleatorio_npc = 3;//rand()%4;

    switch (aleatorio_npc)
    {
    case 0:
        printf("||| Joao diz:\n");
        printf("            Fiquei sabendo que ao norte existe varios tesouros caros..\n\n");
        printf("                                        Pressione qualque tecla..");
        break;
    case 1:
        printf("Caro amigo esse e o 1");
        break;
    case 2:
        printf("Vejo que voce esta muito cansado toma aqui essa poção...\n");
        break;
    case 3:

        //FAZER UMA  ISSO TUDO NA FUNÇAO ? ..
        conta_inventario = 0;
        conta_inventario = VerificaInventario();

        if(conta_inventario != INVENTARIO_TM)
        {
            printf("NPC DIZ:\n");
            printf("VOCE GANHOU UMA ESPADA DE PRATA \n");

            //Verifica qual slot do inventario esta vazio para adicionar o item
                int slot = RetornaSlotInvent();
                strcpy(inventario_player[slot].item, itens[1].item );
                inventario_player[slot].tipo = itens[1].tipo;
                inventario_player[slot].forca = itens[1].forca;
        }


        break;
    case 4:
        printf("AMIGO E O 4");
        break;
    }
system("pause");
}




