#ifndef __ITEM_H__
#define __ITEM_H__

//Cadastro de Itens

typedef struct Itens{
    int id, forca, tipo;
    char item[35];
    float fome, idade, vida, valor;

}Itens;

//---
struct Itens itens[20];


#endif // __ITEM_H__
