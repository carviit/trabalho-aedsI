#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

void FFVazia(TFila *Fila)
{

    Fila->frente =(TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho=0;

}

int Vazia(TFila Fila)
{
    return (Fila.frente == Fila.tras);
}

void Enfileirar(TProduto x, TFila *Fila)
{

    Fila->tras->prox = (TCelula*)malloc(sizeof(TCelula));

    Fila->tras = Fila->tras->prox;
    Fila->tras->item = x;
    Fila->tras->prox = NULL;
    Fila->tamanho++;

}

void Desinfileirar(TFila *Fila, TProduto *Item)
{

    TCelula *aux;

    if(!Vazia(*Fila))
    {

        aux = Fila->frente->prox;
        Fila->frente->prox = aux->prox;
        *Item = aux->item;

        free(aux);

        if(Fila->frente->prox == NULL)
        {

            Fila->tras = Fila->frente;
        }

        Fila->tamanho--;
    }
}

void ImprimirSemFilaExtra(TFila *Fila)
{

    TProduto x;
    int n, i;

    n = Fila->tamanho;

    for(i = 0; i<n; i++)
    {

        Desinfileirar(Fila, &x);
        ImprimirProduto(x);
        Enfileirar(x, Fila);
    }
}

void ImprimirComFilaExtra(TFila *Fila)
{

    TProduto x;

    TFila F2;

    FFVazia(&F2);

    while(!Vazia(*Fila))
    {

        Desinfileirar(Fila, &x);
        ImprimirProduto(x);
        Enfileirar(x, &F2);
    }

    while(!Vazia(F2))
    {

        Desinfileirar(&F2, &x);
        Enfileirar(x, Fila);

    }

    ExcluirFila(&F2);

}

void PesquisarFila(TFila *Fila, TProduto *item)
{

    TProduto x;

    int n, i, resultado;
    int FLAG =0;

    n = Fila->tamanho;

    for(i=0; i<n; i++)
    {

        Desinfileirar(Fila,&x) ;

        resultado = strcmp(x.nome, item->nome);

        Enfileirar(x, Fila);

        if(resultado == 0)
        {
            FLAG = 1;
            *item = x;
        }
    }

    if(FLAG == 0)
    {

        item->codigo = -1;
    }

}

void ExcluirFila(TFila *Fila)
{
    TCelula *atual = Fila->frente;
    TCelula *prox = NULL;

    while (atual != NULL)
    {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }

    Fila->frente = NULL;
    Fila->tras = NULL;
    Fila->tamanho = 0;

}
