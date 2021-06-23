#include "mapa.h"
#include "time.h"
//Função para criar o mapa
 char CriarMapa(){

    //Inicializa para pegar dados da data e hora para gerar numero randomico
    srand (time(NULL));
    int nm_aleatorio;
      for(int x =0; x < LARGURA; x++)
      {
        for(int y=0; y < ALTURA; y++)
        {
          //Condição para preencher borda de cima (top)
          if(x >= 0 && x <4 && y >= 0 && y < LARGURA  )
          {
                matriz[x][y]= BLOQUEIO;

          //Condição para preencher a borda lateral esquerda (left)
          }else if(x >= 0 && y >= 0 && y < 8){

               matriz[x][y]= BLOQUEIO;

          //Condição para preencher a borda lateral direita (right)
          }else if(x >= 4   && y >= ALTURA -8 && y < ALTURA){

               matriz[x][y]= BLOQUEIO;

          //Condição para preencher a borda de baixo (bottom)
          }else if(x >= ALTURA -4  && y >= 0 && y < ALTURA){

               matriz[x][y]= BLOQUEIO;

           //Começa a gerar o mapa aleatorio
          }else{

            nm_aleatorio = rand()%30 +1;
            if(nm_aleatorio >= 0 && nm_aleatorio <= 10)
            {
              matriz[x][y] = FLORESTA;

            }else if(nm_aleatorio >= 11 && nm_aleatorio <= 20)
            {
              matriz[x][y] = PLANICE;

            }else if(nm_aleatorio == 21)
            {
              matriz[x][y] = MONTANHA;

            }else if(nm_aleatorio >= 22 && nm_aleatorio <= 27)
            {
              matriz[x][y] = LAGO;

            }else if (nm_aleatorio == 28)
            {
              matriz[x][y] = NPC;

            }else if(nm_aleatorio == 29)
            {
              matriz[x][y] = INIMIGO;

            }else if(nm_aleatorio == 30)
            {
              matriz[x][y] = TESOURO;
            }
        }
        }//Segundo for
      } //Primeiro for


}//Fim da função

//Função para imprimir
void imprimi(){

  for(int x=0; x < LARGURA; x++)
  {
    for(int y=0; y < ALTURA; y++)
    {
      printf("%c ", matriz[x][y]);
    }
    printf("\n");
  }
}

//Função para imprimir minimapa do player
void imprimiMiniMap(int y, int x){
    //Movimentação
    // Vai movimentar de acordo com a posição do player
     int mov_y = y + 4; //Imprimi 4 de altura
     int mov_x = x + 8;//Imprimi 8 de largura
    system("cls");
      imprimiLinha();
      printf("\n");
       for( y= y-4; y <= mov_y; y++)
       {
         for( x =x-8; x <= mov_x; x++)
            {

               printf("%c ", matriz[y][x]);

             }
             //Usado para resetar a posiçao para ele percorre todos  caracteres da linha
             x = x-9;

          printf("\n");
       }
       //RESETA O Y
       y = y -5;

  imprimiLinha();
 }

void imprimiLinha(){
  //Barra
   for(int bar =0; bar < 40; bar++)
  {
    printf("__");
  }
}

