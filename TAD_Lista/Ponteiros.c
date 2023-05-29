#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define TAM 10

typedef struct produto
{

    char nome[100];
    int quantidade;
    float preco;

} TipoProduto;

int main(){

    setlocale(LC_ALL, "Portuguese");

    int i;

    TipoProduto *ptr;

    ptr = (TipoProduto*) calloc(TAM,sizeof(TipoProduto));

    for(i = 0; i < TAM; i++){

        printf("%x\n", &ptr+i);

        printf("\n%p\n", ptr+i);


    }









    free(ptr);

    return 0;
}
