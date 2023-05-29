#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "lista.h"

int main()
{

    setlocale(LC_ALL, "Portuguese");

    int quantidade, i, codigo;

    TProduto produto;

    printf("Digite a quantidade de produtos a serem inseridos na LISTA: ");
    scanf("%d", &quantidade);

    TLista lista;

    FLVazia(&lista);

    for(i = 0; i < quantidade; i++)
    {
        printf("\n======== C A D A S T R O   D O   P R O D U T O   %d ========\n\n", i+1);

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

        ImprimirProduto(produto);

    }
    else
    {

        printf("\n==== O produto que possui código %d não foi localizado no sistema ====\n", codigo);

    }

    ExcluirImpares(&lista);

    Liberar(&lista);

    return 0;
}
