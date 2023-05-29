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

void ImprimirProduto(TProduto x)
{
    printf("\nCódigo: %d", x.codigo);
    printf("\nNome: %s", x.nome);
    printf("Descrição: %s", x.descricao);
    printf("Preço: R$ %.2f", x.preco);
    printf("\nPeso: %.2f g", x.peso);

    printf("\n");
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

void LerProduto(TProduto *x)
{
    printf("\nDigite o código do produto: ");
    scanf("%d", &x -> codigo);
    getchar();

    printf("\nDigite o nome do produto: ");
    fflush(stdin);
    fgets(x -> nome,20,stdin);

    printf("\nDigite a descrição do produto: ");
    fflush(stdin);
    fgets(x -> descricao,20, stdin);

    printf("\nDigite o preço do produto: R$ ");
    scanf("%f", &x -> preco);
    getchar();

    printf("\nDigite o peso do produto (g): ");
    scanf("%f", &x -> peso);
    getchar();

}

int DuasFilasIguais(TFila *F1, TFila *F2)
{

    TFila F1Aux;
    TProduto p;
    int teste = 1;

    FFVazia(&F1Aux);

    if(F1->tamanho!=F2->tamanho)
    {

        return 0;

    }
    else
    {

        while(F1->tamanho!=0)
        {

            Desinfileirar(F1,&p);

            Enfileirar(p, &F1Aux);

        }

        while(F1Aux.tamanho!=0)
        {

            Desinfileirar(&F1Aux,&p);

            Enfileirar(p, F1);

            PesquisarFila(F2,&p);

            if(p.codigo == -1)
            {

                teste = 0;
            }

        }

        return teste;

    }

}

void RemovereNesimoItem(TFila *Fila, int n)
{

    TFila FAux;

    FFVazia(&FAux);

    TProduto Paux;

    int x = 1;

    while(Fila->tamanho!=0)
    {

        Desinfileirar(Fila, &Paux);

            if(x == n && Fila->tamanho > 0)
            {
                Desinfileirar(Fila, &Paux);
            }

            if(x <= Fila->tamanho + 1)

            {
                Enfileirar(Paux, &FAux);
            }

        x++;
    }

    while(FAux.tamanho!=0)
    {

        Desinfileirar(&FAux,&Paux);
        Enfileirar(Paux, Fila);

    }

    ExcluirFila(&FAux);
}

void InteresecaoDeFilas(TFila *F1, TFila *F2, TFila *FResul){

    TFila F1aux;
    TFila F2aux;
    TProduto Paux;
    TProduto p1;

    FFVazia(&F1aux);
    FFVazia(&F2aux);

    while(F1->tamanho!=0){

        Desinfileirar(F1, &Paux);
        Enfileirar(Paux, &F1aux);

    }

    while(F1aux.tamanho!=0){

        Desinfileirar(&F1aux, &Paux);

        p1 = Paux;

        PesquisarFila(F2, &Paux);

        if(Paux.codigo != -1){

            Enfileirar(Paux, FResul);
            Enfileirar(Paux, F1);

        }else{

            Enfileirar(p1, F1);

        }

    }

    printf("\n=========== FILA 1 ===========");

    ImprimirSemFilaExtra(F1);

    printf("\n=========== FILA 2 ===========");

    ImprimirSemFilaExtra(F2);

    if(Vazia(*FResul)){

        printf("\n>>>>>>>>> NÃO HÁ ELEMENTOS  DE INTERSEÇÃO EM AMBAS AS FILAS <<<<<<<<<");

    }else{

    printf("\n=========== FILA RESULTADO ===========");

    ImprimirSemFilaExtra(FResul);

    }

}

void DiferencaDeFilas(TFila *F1, TFila *F2, TFila *FResul){

    TFila F1aux;
    TFila F2aux;
    TProduto Paux;
    TProduto p1;

    FFVazia(&F1aux);
    FFVazia(&F2aux);

    while(F1->tamanho!=0){

        Desinfileirar(F1, &Paux);
        Enfileirar(Paux, &F1aux);

    }

    while(F1aux.tamanho!=0){

        Desinfileirar(&F1aux, &Paux);

        p1 = Paux;

        PesquisarFila(F2, &Paux);

        if(Paux.codigo == -1){

            Enfileirar(p1, FResul);
            Enfileirar(p1, F1);

        }else{

            Enfileirar(p1, F1);

        }

    }

    printf("\n=========== FILA 1 ===========");

    ImprimirSemFilaExtra(F1);

    printf("\n=========== FILA 2 ===========");

    ImprimirSemFilaExtra(F2);

    if(Vazia(*FResul)){

        printf("\n>>>>>>>>> NÃO HÁ ELEMENTOS  DE DIFERNÇA EM AMBAS AS FILAS <<<<<<<<<");

    }else{

    printf("\n=========== FILA RESULTADO ===========");

    ImprimirSemFilaExtra(FResul);

    }

}

void EnQueue(TFilaPrioridade *Fila, TProduto x){

     // Não consegui fazer.

}

void DeQueue(TFilaPrioridade *fila, TProduto x){

    // Não consegui fazer.


}
