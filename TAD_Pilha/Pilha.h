#ifndef Pilha_HEADER
#define Pilha_HEADER

#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"
#include "Util.h"

//Estruturas

typedef struct Fila{

    TCelula *fundo;
    TCelula *topo;
    int tamanho;

}TPilha;

//Funções

void FPVazia(TPilha *Pilha);

void Empilha(TProduto x, TPilha *Pilha);

void Desempilha (TPilha *Pilha, TProduto *Item);

int Pesquisar(TPilha *Pilha, TProduto *x);

int PVazia(TPilha Pilha);

void ImprimirPilha(TPilha *P1);

void ImprimirPilhaCodigo(TPilha *P1);

void ConversorDeBases(int n, int base);

void LerProdutoSoCodigo(TProduto *x);

void Jogo(int discos, TPilha *Fonte, TPilha *Destino);

void InverteElementos(int k, TFila *fila);

void ExcluirPilha(TPilha *Pilha);

#endif // Lista_Header;
