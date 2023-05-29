#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"
#include "Fila.h"
#include <math.h>
#include <ctype.h>

void FPVazia(TPilha *Pilha)
{

    Pilha->topo = (TCelula*)malloc(sizeof(TCelula));

    Pilha->fundo = Pilha->topo;
    Pilha->topo->prox = NULL;
    Pilha->tamanho = 0;

}

int PVazia(TPilha Pilha)
{

    return (Pilha.topo == Pilha.fundo);
}

void Empilha(TProduto x, TPilha *Pilha)
{

    TCelula *Aux;

    Aux = (TCelula*)malloc(sizeof(TCelula));

    Pilha->topo->item = x;

    Aux->prox = Pilha->topo;
    Pilha->topo = Aux;
    Pilha->tamanho++;

}

void Desempilha(TPilha *Pilha, TProduto *Item)
{

    TCelula *q;

    if(PVazia(*Pilha))
    {

        printf("Erro: Pilha vazia\n");

        return;
    }

    q = Pilha->topo;
    Pilha->topo = q->prox;
    *Item = q->prox->item;
    free(q);

    Pilha->tamanho--;
}

int Pesquisar(TPilha *Pilha, TProduto *x)
{

    TPilha p2;
    FPVazia(&p2);

    int FLAG = 0;

    TProduto y;

    while(!Vazia(*Pilha))
    {

        Desempilha(Pilha, &y);

        if(strcmp(x->nome, y.nome) == 0)
        {

            *x = y;
            FLAG = 1;
        }

        Empilha(y, &p2);

    }

    while(!Vazia(p2))
    {

        Desempilha(&p2, &y);
        Empilha(y, Pilha);

    }

    free(p2.topo);

    if(FLAG)
    {

        return 1;

    }
    else
    {

        x->codigo = -1;
        return 0;

    }

}

void LerProdutoSoCodigo(TProduto *x)
{
    printf("\nDISCO: ");
    scanf("%d", &x -> codigo);
    getchar();

}

void ExcluirPilha(TPilha *Pilha)
{

    TCelula *q;

    while(Pilha->topo != Pilha->fundo)
    {

        q = Pilha->topo;
        Pilha->topo = q->prox;
        free(q);
    }

    free(Pilha->topo);
}

void ImprimirPilha(TPilha *P1)
{

    TProduto x;
    TPilha p2;

    FPVazia(&p2);

    while(!Vazia(*P1))
    {

        Desempilha(P1, &x);
        ImprimirProduto(x);
        Empilha(x, &p2);

    }

    while(!Vazia(p2))
    {

        Desempilha(&p2, &x);
        Empilha(x, P1);

    }

    free(p2.topo);

}

void ImprimirPilhaCodigo(TPilha *P1)
{

    TProduto x;
    TPilha p2;

    FPVazia(&p2);

    while(!Vazia(*P1))
    {

        Desempilha(P1, &x);
        printf("%d", x.codigo);
        printf("\n");
        Empilha(x, &p2);

    }

    while(!Vazia(p2))
    {

        Desempilha(&p2, &x);
        Empilha(x, P1);

    }

    free(p2.topo);

}

void InverteElementos(int k, TFila *fila)
{

    int i = 0;

    TProduto p1;

    TFila FAux;
    FFVazia(&FAux);
    TPilha PAux;
    FPVazia(&PAux);
    TPilha PFinal;
    FPVazia(&PFinal);

    for(i=0; i<k; i++)
    {

        Desinfileirar(fila, &p1);
        Enfileirar(p1, &FAux);

    }

    while(!Vazia(*fila))
    {

        Desinfileirar(fila,&p1);
        Empilha(p1, &PAux);

    }

    while(!PVazia(PAux))
    {

        Desempilha(&PAux, &p1);
        Empilha(p1, &PFinal);
    }

    while(!Vazia(FAux))
    {

        Desinfileirar(&FAux, &p1);
        Empilha(p1, &PFinal);
    }

    printf("\n===== I M P R E S S Ã O  D A  P I L H A  C O M  E L E M E N T O S  I N V E R T I D O S =====\n");

    ImprimirPilha(&PFinal);

    ExcluirFila(&FAux);
    ExcluirPilha(&PAux);
    ExcluirPilha(&PFinal);

}

void ConversorDeBases(int n, int base)
{

    TPilha PilhaConversora;
    FPVazia(&PilhaConversora);
    TProduto x;

    while(n > 0)
    {

        x.codigo = n % base;

        Empilha(x, &PilhaConversora);

        n = n / base ;
    }

    ImprimirPilhaCodigo(&PilhaConversora);

    ExcluirPilha(&PilhaConversora);

}

void Jogo(int discos, TPilha *Fonte, TPilha *Destino)
{

    TPilha Auxiliar;
    FPVazia(&Auxiliar);
    int movimentos = 1;
    TProduto disco;
    TProduto discoAuxiliar;

    int i;

    for(i = 0; i < discos; i++)
    {

        movimentos *= 2;

    }

    movimentos--;


    for(int i = 1; i <= movimentos; i++)
    {

        if(i % 3 == 1)
        {
            if(PVazia(*Fonte))
            {

                Desempilha(Destino, &disco);
                Empilha(disco, Fonte);

            }
            else
            {

                Desempilha(Fonte, &disco);

                if(disco.codigo<Destino->topo->item.codigo || PVazia(*Destino))
                {


                    Empilha(disco, Destino);

                }
                else
                {


                    Empilha(disco, Fonte);

                    Desempilha(Destino, &disco);
                    Empilha(disco, Fonte);

                }

            }


        }


        if(i % 3 == 2)
        {

            if(PVazia(*Fonte))
            {

                Desempilha(&Auxiliar, &disco);
                Empilha(disco, Fonte);

            }
            else
            {

                Desempilha(Fonte, &disco);

                if(disco.codigo<Auxiliar.topo->item.codigo || PVazia(Auxiliar))
                {

                    Empilha(disco, &Auxiliar);

                }
                else
                {

                    Empilha(disco, Fonte);

                    Desempilha(&Auxiliar, &disco);
                    Empilha(disco, Fonte);

                }

            }


        }

        if(i % 3 == 0)
        {

            if(PVazia(Auxiliar))
            {

                Desempilha(Destino, &disco);
                Empilha(disco, &Auxiliar);

            }
            else
            {

                Desempilha(&Auxiliar, &disco);

                if(disco.codigo<Destino->topo->prox->item.codigo || PVazia(*Destino))
                {


                    Empilha(disco, Destino);

                }
                else
                {


                    Empilha(disco, &Auxiliar);

                    Desempilha(Destino, &disco);
                    Empilha(disco, &Auxiliar);

                }

            }

        }

    }

    ImprimirPilhaCodigo(Destino);

    ExcluirPilha(&Auxiliar);

}

int ContaParentesis(char frase[], int tamanho)
{

    int i;

    int contadorDeAbreFecha = 0;
    char temp[2];

    TPilha P;
    FPVazia(&P);
    TProduto Parentesis;

    for(i = 0; i < tamanho; i++)
    {

        if(frase[i] == '(')
        {

            temp[0] = frase[i];
            temp[1] = '\0';

            strncpy(Parentesis.nome, temp, 2);

            Empilha(Parentesis, &P);

        }

        if(frase[i] == ')' && !PVazia(P))
        {

            Desempilha(&P, &Parentesis);

            contadorDeAbreFecha+=2;

        }

    }

    return contadorDeAbreFecha;

}

void ContaParentesisDuplicados(char frase[], int tamanho)
{

    TPilha P;
    FPVazia(&P);
    int contador = 0;
    TProduto x;

    char temp [2];

    int i;

    for(i = 0; i < tamanho; i++)
    {

        if(frase[i] == '(' || isalpha(frase[i]) || frase[i] == '*' || frase[i] == '+' || frase[i] == '-' || frase[i] == '/')
        {

            temp[0] = frase[i];
            temp[1] = '\0';

            strncpy(x.nome, temp, 2);

            Empilha(x, &P);

        }else if(frase[i] == ')'){

            contador = 0;
            int FLAG = 1;

            while(FLAG)
            {
                Desempilha(&P, &x);

                if((strcmp(x.nome, "(") == 0) || PVazia(P))
                {
                    FLAG = 0;

                }else{

                    contador++;
                }

            }

        }

    }

    if(contador<1)
    {

        printf("Possui parêntesis duplicado");

    }
    else
    {

        printf("Não possui parẽntesis duplicados");
    }

}

