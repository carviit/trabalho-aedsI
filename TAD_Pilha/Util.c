#include <stdio.h>
#include <stdlib.h>

#include "Util.h"

void ImprimirProduto(TProduto x)
{
    printf("\nCódigo: %d", x.codigo);
    printf("\nNome: %s", x.nome);
    printf("Descrição: %s", x.descricao);
    printf("Preço: R$ %.2f", x.preco);
    printf("\nPeso: %.2f g", x.peso);

    printf("\n");
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
