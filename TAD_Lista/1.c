#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct
{

    int codigo;
    char nome[20];
    char descricao[20];
    float preco;
    float peso;

} TProduto;

typedef struct celula
{

    TProduto item;
    struct celula* prox;

} TCelula;

typedef struct
{

    TCelula* primeiro;
    TCelula* ultimo;
    int tamanho;

} TLista;

void FLVazia (TLista *Lista)
{

    Lista-> primeiro =
        (TCelula*)malloc(sizeof(TCelula));
    Lista->ultimo= Lista->primeiro;
    Lista->primeiro->prox=NULL;
    Lista->tamanho=0;
}

void Inserir(TProduto *x, TLista *Lista)
{

    Lista -> ultimo -> prox = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> ultimo -> prox;
    Lista -> ultimo -> item = *x;
    Lista -> ultimo -> prox = NULL;
    Lista -> tamanho++;

}

void Imprimir(TLista Lista)
{

    TCelula* Aux;
    Aux = Lista.primeiro -> prox;

    while(Aux != NULL)
    {

        printf("%d\n", Aux -> item.codigo);
        Aux = Aux -> prox;

    }
}

int Vazia(TLista Lista)
{

    return(Lista.primeiro == Lista.ultimo);
}

void LerProduto(TProduto *x)
{
    printf("Digite o código do produto: ");
    scanf("%d", &x -> codigo);
    getchar();

    printf("Digite o nome do produto: ");
    fflush(stdin);
    fgets(x -> nome,20,stdin);

    printf("Digite a descrição do produto: ");
    fflush(stdin);
    fgets(x -> descricao,20, stdin);

    printf("Digite o preço do produto: ");
    scanf("%f", &x -> preco);
    getchar();

    printf("Digite o peso do produto: ");
    scanf("%f", &x -> peso);
    getchar();

}

int main(){

    setlocale(LC_ALL, "Portuguese");

    TLista lista;

    TProduto toddy;

    FLVazia(&lista);

    LerProduto(&toddy);




    return 0;
}
