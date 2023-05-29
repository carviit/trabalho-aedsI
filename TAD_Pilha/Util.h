#ifndef Util_HEADER
#define Util_HEADER

#include <stdio.h>
#include <stdlib.h>

//Estruturas

typedef struct item{

    int codigo;
    char nome[100];
    float peso;
    float preco;
    char descricao[100];
    char o[2];

}TProduto;

typedef struct celula{

    TProduto item;
    struct celula *prox;

}TCelula;

void ImprimirProduto(TProduto x);

void LerProduto(TProduto *x);

#endif
