#include <stdio.h>
#include <locale.h>

typedef struct{

    int codigo;

}TProduto;

typedef struct celula{

    TProduto item;

    struct celula *prox;

}TCelula;

typedef struct{

    TCelula *primeiro;
    TCelula *ultimo;
    int tamanho;

}TLista;

void FLVazia(TLista *Lista){

    Lista -> primeiro = (TCelula *) malloc(sizeof(TCelula));

    Lista -> ultimo = Lista -> primeiro;

    Lista -> primeiro -> prox = NULL;

    Lista -> tamanho = 0;

}

int main(){

    setlocale(LC_ALL, "Portuguese");






    return 0;
}
