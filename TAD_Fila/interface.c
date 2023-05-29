#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void MSG_MENU()
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. ENFILEIRAR");
    printf("  \n\t2. DESINFILEIRAR");
    printf("  \n\t3. IMPRIMIR FILA");
    printf("  \n\t4. PESQUISAR");
    printf("  \n\t5. VERIFICAR A IGUALDADE DA FILA INSERIDA E OUTRA FILA");
    printf("  \n\t6. REMOVER N-ÉSIMO ITEM");
    printf("  \n\t7. INTERSEÇÃO DA FILA INSERIDA COM OUTRA FILA");
    printf("  \n\t8. DIFERENÇA DA FILA INSERIDA COM OUTRA FILA ");
    printf("  \n\t9. FIM");
}

void MENU(TFila *Fila){

    TProduto p1;
    TProduto Paux;
    int opcao=0;
    int i;

    do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao)
        {
            case 1:

                LerProduto(&p1);

                Enfileirar(p1, Fila);

                printf("\n=====>   Produto ENFILEIRADO com sucesso   <=====\n");

                system("PAUSE");

                break;

            case 2:

                if(Fila->tras == Fila->frente){

                    printf(">>>>> Não há PRODUTOS na FILA <<<<<");

                }else{

                    Desinfileirar(Fila,&Paux);

                    printf("======== D A D O S   D O   P R O D U T O   D E S I N F I L E I R A D O ======== \n");

                    ImprimirProduto(Paux);

                }

                system("PAUSE");
                break;

            case 3:

                if(!Vazia(*Fila)){

                    printf("\n========== I M P R E S S Ã O  D A  F I L A ==========\n");

                    ImprimirSemFilaExtra(Fila);

                }else{

                    printf(">>>>>>> A FILA ESTÁ VAZIA <<<<<<<");

                }

                system("PAUSE");

                break;

            case 4:

                printf("\nDigite o nome do produto que  deseja pesquisar: ");
                fflush(stdin);
                fgets(Paux.nome, 20, stdin);

                PesquisarFila(Fila,&Paux);

                if(Paux.codigo != -1){

                    printf("\n>>>>> P R O D U T O  E N C O N T R A D O <<<<<\n");

                    ImprimirProduto(Paux);

                }else{

                    printf("\n>>>>> P R O D U T O  N Ã O  E N C O N T R A D O <<<<<\n");

                }

                system("PAUSE");
                break;

            case 5:

                TFila FComp;
                FFVazia(&FComp);

                printf("\n========= C R I A Ç Ã O  D A  F I L A  P A R A  C O M P A R A Ç Ã O =========\n");

                do{

                    LerProduto(&p1);
                    Enfileirar(p1,&FComp);

                    printf("\nDeseja ENFILEIRAR mais produtos na LISTA?\n\n");

                    printf("1 ----- SIM");
                    printf("\n2 ----- NÃO");

                    printf("\n\nOPÇÃO: ");
                    scanf("%d", &i);
                    getchar();

                }while(i!=2);

                if(DuasFilasIguais(Fila, &FComp)){

                    printf("\n>>>>> AS FILAS SÃO IGUAIS <<<<<");

                    printf("\n\n============== F I L A  1 ==============");
                    ImprimirSemFilaExtra(Fila);
                    printf("\n============== F I L A  2 ==============");
                    ImprimirSemFilaExtra(&FComp);

                }else{

                    printf("\n>>>>> AS FILAS SÃO DIFERENTES <<<<<");

                    printf("\n\n============== F I L A  1 ==============");
                    ImprimirSemFilaExtra(Fila);
                    printf("\n============== F I L A  2 ==============");
                    ImprimirSemFilaExtra(&FComp);

                }

                ExcluirFila(&FComp);

                system("PAUSE");
                break;

            case 6:

                printf("Digite a posição do item que você deseja remover: ");
                scanf("%d", &i);

                if(i<1 || i>Fila->tamanho){

                    printf(">>>> Posição NÃO EXISTE na FILA inserida <<<<");

                }else{

                    RemovereNesimoItem(Fila, i);

                    printf("========= I M P R E S S Ã O  D A  F I L A  A T U A L I Z A D A =========\n");

                    ImprimirSemFilaExtra(Fila);

                }

                system("PAUSE");
                break;

            case 7:

                TFila F;
                TFila FFinal;

                FFVazia(&FFinal);
                FFVazia(&F);

                printf("\n========= C R I A Ç Ã O  D A  F I L A  P A R A  C O M P A R A Ç Ã O =========\n");

                do{

                    LerProduto(&p1);
                    Enfileirar(p1,&F);

                    printf("\nDeseja ENFILEIRAR mais produtos na LISTA?\n\n");

                    printf("1 ----- SIM");
                    printf("\n2 ----- NÃO");

                    printf("\n\nOPÇÃO: ");
                    scanf("%d", &i);
                    getchar();

                }while(i!=2);

                InteresecaoDeFilas(Fila, &F, &FFinal);

                system("PAUSE");
                break;

            case 8:

                TFila Fteste;
                TFila Ffinal;

                FFVazia(&Ffinal);
                FFVazia(&Fteste);

                printf("\n========= C R I A Ç Ã O  D A  F I L A  P A R A  C O M P A R A Ç Ã O =========\n");

                do{

                    LerProduto(&p1);
                    Enfileirar(p1,&Fteste);

                    printf("\nDeseja ENFILEIRAR mais produtos na LISTA?\n\n");

                    printf("1 ----- SIM");
                    printf("\n2 ----- NÃO");

                    printf("\n\nOPÇÃO: ");
                    scanf("%d", &i);
                    getchar();

                }while(i!=2);

                DiferencaDeFilas(Fila, &Fteste, &Ffinal);

                system("PAUSE");
                break;

            case 9:

                system("PAUSE");
                break;

            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 9);

}
