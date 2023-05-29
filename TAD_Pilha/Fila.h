#ifndef Fila_HEADER
#define Fila_HEADER

#include <stdio.h>
#include <stdlib.h>

#include "Util.h"

typedef struct fila{

    TCelula *frente;
    TCelula *tras;
    int tamanho;

}TFila;

//Funções

void FFVazia(TFila *Fila);

int FVazia(TFila Fila);

void Enfileirar(TProduto x, TFila *Fila);

void Desinfileirar(TFila *Fila, TProduto *Item);

void ImprimirSemFilaExtra(TFila *Fila);

void ImprimirComFilaExtra(TFila *Fila);

void PesquisarFila(TFila *Fila, TProduto *item);

void ExcluirFila(TFila *Fila);

void InverteElementos(int k, TFila *fila);

#endif // Lista_Header;
