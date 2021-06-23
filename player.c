#include "player.h"
#include <string.h>
//Funções
//Imprimindo barra de stats
void ImprimiStats(int vida, int fome, int idade, float forca, float fortuna){
    printf("\nVIDA:     %d/100  |", vida);
    printf("                       IDADE: %d/%d", idade, IDADE_MAX);
    printf("\nFOME:     %d/100  |", fome);
    printf("\nFORCA:    %2.2f    |\n", forca);
    printf("\nFORTUNA:  %.2f\n", fortuna);
}

void DeletaItem(int posicao){
//Item padrao nulo inventario
    strcpy(inventario_player[posicao].item, "" );
    inventario_player[posicao].tipo = NULL;
    inventario_player[posicao].forca = 0;
    inventario_player[posicao].fome =  0;
    inventario_player[posicao].valor = 0;
}

void ImprimiInventario(){

    system("cls");
    printf("------------------EQUIPAMENTO--------------------\n");
    printf("-------------------------------------------------\n");
    for(int i =0; i < EQUIPAMENTO_TM; i++){
       printf("|Equip: %s --> FORCA +%d\n", equipamento_player[i].item, equipamento_player[i].forca);

    }
    printf("\n------------------INVENTARIO--------------------\n");
    printf("------------------------------------------------\n");
    for(int i =0; i < INVENTARIO_TM; i++){
       printf("|Item %d: %s\n", i,inventario_player[i].item);

    }
    printf("---------------------------------------------------\n");
    printf("10 - SAIR DO INVENTARIO\n");
    printf("---------------------------------------------------\n");
    printf("Para opcoes do ITEM digite o numero dele\n");
}

void AlteraStats(){

    //Jogador vai ficando com fome a cada rodada
  if(player.fome != 0)player.fome -= 0.25;
 //Se fome  chegar a 0 começa a perder vida
  if(player.fome == 0) player.vida -= 5;

 //Idade do jogador
 if(player.idade != IDADE_MAX)
 {
    player.idade += 1;
 }
}

void AbriInventario(){
      //Loop para o inventario
         int invent_rodando = 1;
         while(invent_rodando)
         {

             //Imprimi o inventario
             ImprimiInventario();
                //Pegando o item que o usuario escolheu
               int item_slc;
               //Pegando a açao que o  usuario escolher
                int escolha_acao;

                scanf("%d", &item_slc);
                //Se digitar 10 sai do inventario
                if(item_slc == 10)
                {
                    invent_rodando = 0;//SAI DO INVENTARIO
                }else{
                    if(strlen(inventario_player[item_slc].item) != 0)
                        {   //AÇOES SE O ITEM FOR DO TIPO ARMADURA OU ARMA
                            if(inventario_player[item_slc].tipo == ARMADURA || inventario_player[item_slc].tipo == ARMA)
                            {
                                int tipo = inventario_player[item_slc].tipo;//PARA GUARDAR O TIPO DO EQUIPAMENTO ESCOLHIDO

                                system("cls");
                                printf("-------------------------------------------------\n");
                                printf("USANDO: %s --> FORCA: +%d\n", equipamento_player[tipo].item, equipamento_player[tipo].forca);
                                printf("-------------------------------------------------\n");
                                printf("ITEM: %s  --> FORCA: +%d\n", inventario_player[item_slc].item, inventario_player[item_slc].forca);
                                printf("-------------------------------------------------\n\n");
                                printf("-----------------\n");
                                printf("1 - EQUIPAR\n");
                                printf("2 - JOGAR FORA\n");
                                printf("3 - VOLTAR\n");
                                printf("-----------------");
                                scanf("%d", &escolha_acao);
                                    switch(escolha_acao)
                                    {
                                    case 1:
                                    //Struct temporaria
                                    strcpy(temp_inventario.item, equipamento_player[tipo].item);
                                    temp_inventario.forca = equipamento_player[tipo].forca;
                                    temp_inventario.tipo  = equipamento_player[tipo].tipo;
                                    //#########################################################
                                    //Tirando a força do item anterior
                                    player.forca -= equipamento_player[tipo].forca;

                                    //Equipando
                                    strcpy(equipamento_player[tipo].item ,inventario_player[item_slc].item );
                                    equipamento_player[tipo].forca = inventario_player[item_slc].forca;
                                    equipamento_player[tipo].tipo = inventario_player[item_slc].tipo;
                                    player.forca += equipamento_player[tipo].forca;

                                    //Jogando o item do equipamento para o inventario
                                    inventario_player[item_slc]= temp_inventario;


                                    break;
                                    case 2:
                                        DeletaItem(item_slc);
                                    break;
                                    }

                            //AÇOES SE O ITEM FOR DO TIPO CONSUMIVEL
                            }else if(inventario_player[item_slc].tipo == CONSUMIVEL)
                            {
                                system("cls");
                                printf("-------------------------------------------------\n");
                                printf("%s --> + %d FOME\n", inventario_player[item_slc].item, inventario_player[item_slc].fome);
                                printf("-------------------------------------------------\n");
                                printf("-----------------\n");
                                printf("1 - USAR\n");
                                printf("2 - JOGAR FORA\n");
                                printf("3 - FECHAR\n");
                                printf("-----------------\n");

                                scanf("%d", &escolha_acao);

                                    switch(escolha_acao)
                                    {
                                        case 1:
                                            player.fome += inventario_player[item_slc].fome;
                                            if(player.fome >100)
                                            {
                                                player.fome  = 100;
                                            }
                                            //Exluindo item do inventario
                                            DeletaItem(item_slc);
                                        break;

                                        case 2:
                                            //Exluindo item do inventario
                                            DeletaItem(item_slc);
                                        break;
                                        case 3:

                                        break;
                                        default:
                                            printf("DEAFAULt");
                                    }
                                }
                        }else{
                                printf("ESSE ESPAÇO ESTA VAZIO!\n");
                                system("pause");
                             }

                   }

         }
}

int VerificaInventario(){
    int conta_inventario =0;
     int acao_inventario;
    //Conta se inventario ta cheio
    for(int i=0; i< INVENTARIO_TM; i++)
    {
        if(strlen(inventario_player[i].item) != 0)
        {
            conta_inventario = conta_inventario + 1;

        }
    }


        if(conta_inventario == INVENTARIO_TM)
        {
            printf("SEU INVETARIO ESTA CHEIO, O QUE DESEJA FAZER?:\n");
            printf("1 - EXCLUIR ITENS DO INVENTARIO\n");
            printf("2 - IGNORAR ITEM  GANHO\n");
            scanf("%d", &acao_inventario);
        }
        //Executa as açoes
        if(acao_inventario == 1){
            AbriInventario();

        }else if (acao_inventario == 2)
        {

        }

        //Conta novamenteo inventario apos a açao
        conta_inventario = 0;//Reseta para a contagem
        for(int i=0; i< INVENTARIO_TM; i++)
            {
                if(strlen(inventario_player[i].item) != 0)
                {
                    conta_inventario = conta_inventario + 1;

                }
            }


    return conta_inventario;
}

int RetornaSlotInvent(){
    for(int i =0; i<INVENTARIO_TM; i++)
        {
          //Verifica qual posição vazia para adcionar o item
            if(strlen(inventario_player[i].item) == 0 )
              {
                  int slot = i;
                  i = 10;
              }
        }
}

