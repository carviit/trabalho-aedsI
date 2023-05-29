#ifndef Fista_HEADER
#define Fista_HEADER
#include <stdio.h>
#include <stdlib.h>

//Estruturas

typedef struct item{

    int codigo;
    char nome[100];
    float peso;
    float preco;
    char descricao[100];
    int prioridade;

}TProduto;

typedef struct celula{

    TProduto item;
    struct celula *prox;

}TCelula;

typedef struct Fila{

    TCelula *frente;
    TCelula *tras;
    int tamanho;

}TFila;

typedef struct FilaPrioridade{

    TFila F1;
    TFila F2;
    TFila F3;

}TFilaPrioridade;

//Funções

void FFVazia(TFila *Fila);

int Vazia(TFila Fila);

void Enfileirar(TProduto x, TFila *Fila);

void Desinfileirar(TFila *Fila, TProduto *Item);

void ImprimirProduto(TProduto x);

void ImprimirSemFilaExtra(TFila *Fila);

void ImprimirComFilaExtra(TFila *Fila);

void PesquisarFila(TFila *Fila, TProduto *item);

void ExcluirFila(TFila *Fila);

void LerProduto(TProduto *x);

int DuasFilasIguais(TFila *F1, TFila *F2);

void RemovereNesimoItem(TFila *Fila, int n);

void InteresecaoDeFilas(TFila *F1, TFila *F2, TFila *FResul);

#endif // Lista_Header;
