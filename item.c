#include <stdio.h>
#include "player.h"
#include "item.h"

//Cadastro de items
void CadastrandoItens(){
 //ARMAS E ARMADURAS
     //ESPADA DE BRONZE
    itens[0].id = 0;
    itens[0].forca = 5;
    itens[0].tipo = ARMA;
    itens[0].valor = 2;
    strcpy(itens[0].item, "ESPADA DE BRONZE" );

    //ESPADA DE PRATA
    itens[1].id = 1;
    itens[1].forca = 7;
    itens[1].tipo = ARMA;
    itens[1].valor = 5;
    strcpy(itens[1].item, "ESPADA DE PRATA" );

    //ESPADA DE OURO
    itens[2].id = 2;
    itens[2].forca = 10;
    itens[2].tipo = ARMA;
    itens[2].valor = 10;
    strcpy(itens[2].item, "ESPADA DE OURO" );

    //ESPADA DE AÇO VALERIANO
    itens[3].id = 3;
    itens[3].forca = 15;
    itens[3].tipo = ARMA;
    itens[3].valor = 50;
    strcpy(itens[3].item, "ESPADA DE OURO" );

    //ARMADURA DE BRONZE
    itens[4].id = 4;
    itens[4].forca = 2;
    itens[4].tipo = ARMADURA;
    itens[4].valor = 4;
    strcpy(itens[4].item, "ARMADURA DE BRONZE" );

    //ARMADURA DE PRATA
    itens[5].id = 5;
    itens[5].forca = 4;
    itens[5].tipo = ARMADURA;
    itens[5].valor = 6;
    strcpy(itens[5].item, "ARMADURA DE PRATA" );

    //ARMADURA DE OURO
    itens[6].id = 6;
    itens[6].forca = 6;
    itens[6].tipo = ARMADURA;
    itens[6].valor = 8;
    strcpy(itens[6].item, "ARMADURA DE OURO" );

//CONSUMIVEIS
    //PAO DE FORMA
    itens[7].id = 7;
    itens[7].fome = 10;
    itens[7].tipo = CONSUMIVEL;
    strcpy(itens[7].item, "PAO DE FORMA" );

    //ENERGETICO
    itens[8].id = 8;
    itens[8].fome = 10;
    itens[8].vida = 30;
    itens[8].tipo = CONSUMIVEL;
    strcpy(itens[8].item, "ENERGETICO" );

    //POÇÃO DA JUVENTUDE
    itens[9].id = 9;
    itens[9].vida = 10;
    itens[9].idade = 30;
    itens[9].tipo = CONSUMIVEL;
    strcpy(itens[9].item, "POCAO DA JUVENTUDE" );

    //SANDUICHE DE PRESUNTO
    itens[10].id = 10;
    itens[10].fome = 30;
    itens[10].tipo = CONSUMIVEL;
    strcpy(itens[10].item, "SANDUICHE DE PRESUNTO" );

    //ESPINAFRE
    itens[11].id = 11;
    itens[11].fome = 50;
    itens[11].tipo = CONSUMIVEL;
    strcpy(itens[11].item, "ESPINAFRE" );

    //BOLINHO DE ARROZ
    itens[12].id = 12;
    itens[12].fome = 20;
    itens[12].tipo = CONSUMIVEL;
    strcpy(itens[12].item, "BOLINHO DE ARROZ" );

    //POÇAO
    itens[13].id = 13;
    itens[13].vida = 25;
    itens[13].tipo = CONSUMIVEL;
    strcpy(itens[13].item, "POCAO" );

//VENDA
    //PEDRA PRECIOSA
    itens[14].id = 14;
    itens[14].valor = 90;
    itens[14].tipo = VENDA;
    strcpy(itens[14].item, "PEDRA PRECIOSA" );

    //COLAR
    itens[15].id = 15;
    itens[15].valor = 40;
    itens[15].tipo = VENDA;
    strcpy(itens[15].item, "COLAR" );

    //BARRA DE OURO
    itens[16].id = 16;
    itens[16].valor = 120;
    itens[16].tipo = VENDA;
    strcpy(itens[16].item, "BARRA DE OURO" );

    //CRISTAL
    itens[17].id = 17;
    itens[17].valor = 20;
    itens[17].tipo = VENDA;
    strcpy(itens[17].item, "CRISTAL" );

    //AMULETO DE OURO
    itens[18].id = 18;
    itens[18].valor = 150;
    itens[18].tipo = VENDA;
    strcpy(itens[18].item, "AMULETO DE OURO" );

    //JADE
    itens[19].id = 19;
    itens[19].valor = 200;
    itens[19].tipo = VENDA;
    strcpy(itens[19].item, "JADE" );

    //PULSEIRA DE MADEIRA
    itens[20].id = 20;
    itens[20].valor = 10;
    itens[20].tipo = VENDA;
    strcpy(itens[15].item, "PULSEIRA DE MADEIRA" );

}


