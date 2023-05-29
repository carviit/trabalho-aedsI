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

    printf("\n=========================== I M P R E S S Ã O    D A    L I S T A =========================== \n");

    TCelula* Aux;
    Aux = Lista.primeiro -> prox;

    while(Aux != NULL)
    {
        ImprimirProduto(Aux -> item);

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

    printf("Digite o preço do produto: R$ ");
    scanf("%f", &x -> preco);
    getchar();

    printf("Digite o peso do produto (g): ");
    scanf("%f", &x -> peso);
    getchar();

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

TCelula *Pesquisar(TLista Lista, TProduto produto)
{

    TCelula *Aux;
    Aux = Lista.primeiro;

    while(Aux -> prox != NULL)
    {

        if(Aux->prox->item.codigo == produto.codigo)
        {

            return Aux;
        }

        Aux = Aux -> prox;

    }

    return NULL;
}

void Excluir(TLista *Lista, TProduto *Item)
{

    TCelula *Aux1, *Aux2;

    Aux1 = Pesquisar(*Lista, *Item);

    if(Aux1!=NULL)
    {

        Aux2 = Aux1 -> prox;
        Aux1 -> prox = Aux2 -> prox;
        *Item = Aux2 -> item;

        if(Aux1 -> prox == NULL)
            Lista -> ultimo = Aux1;

        free(Aux2);

        Lista -> tamanho--;

    }
}

void Liberar(TLista *Lista){

    while(!Vazia(*Lista)){

    Excluir(&Lista, &Lista->ultimo);

    }


}

void ExcluirImpares(TLista *Lista) {

    TCelula *Aux = Lista->primeiro->prox;

    while (Aux != NULL) {

        if (Aux->item.codigo % 2 != 0) {

            TProduto item = Aux->item;

            Excluir(Lista, &item);
        }

        Aux = Aux-> prox;
    }
}

int main()
{

    setlocale(LC_ALL, "Portuguese");

    int quantidade, i, codigo;

    printf("Digite a quantidade de produtos a serem inseridos na LISTA: ");
    scanf("%d", &quantidade);

    TLista lista;

    FLVazia(&lista);

    for(i = 0; i < quantidade; i++)
    {
        printf("\n======== C A D A S T R O   D O   P R O D U T O   %d ========\n\n", i+1);

        TProduto produto;

        LerProduto(&produto);

        Inserir(&produto, &lista);

        printf("\n");

    }

    printf("\n========= B U S C A  D E  P R O D U T O =========\n");

    printf("\nDigite o código do PRODUTO para verificar se o mesmo se encontra no sistema: ");
    scanf("%d", &codigo);

    TProduto p1;

    p1.codigo = codigo;

    if(Pesquisar(lista, p1) != NULL)
    {

        printf("\n===== O produto que possui código %d se encontra CADASTRADO no sistema ====\n", codigo);

        ImprimirProduto(p1);

    }
    else
    {

        printf("\n==== O produto que possui código %d não foi localizado no sistema\n ====\n", codigo);

    }

    ExcluirImpares(&lista);

    Imprimir(lista);

    Liberar(&lista);

    return 0;
}
