#include <stdio.h>
#include <stdlib.h>
#include "Interface.h"

void MSG_MENU()
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. EMPILHAR");
    printf("  \n\t2. DESEMPILHAR");
    printf("  \n\t3. IMPRIMIR PILHA");
    printf("  \n\t4. PESQUISAR");
    printf("  \n\t5. COLOCAR UM NÚMERO (N) DE ELEMENTOS DE UMA FILA INVERSO EM UMA PILHA");
    printf("  \n\t6. CONVERTER UM DECIMAL PARA UMA BASE DE 2 a 9");
    printf("  \n\t7. JOGO TORRE DE HANÓI");
    printf("  \n\t8. CONTA PARÊNTESIS ABRE E FECHA");
    printf("  \n\t9. CONTA PARÊNTESIS DUPLICADOS NA EXPRESSÃO");
    printf("  \n\t10.FIM");
}

void MENU(TPilha *Pilha){

    TProduto p1;
    TProduto Paux;
    int opcao =0;
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

                Empilha(p1, Pilha);

                break;

            case 2:

                if(PVazia(*Pilha)){

                    printf(">>>>> Não há PRODUTOS na PILHA <<<<<");

                }else{

                    Desempilha(Pilha, &Paux);

                    printf("======== D A D O S   D O   P R O D U T O   D E S E M P I L H A D O ======== \n");

                    ImprimirProduto(Paux);

                }

                system("PAUSE");
                break;

            case 3:

                if(!PVazia(*Pilha)){

                    printf("\n========== I M P R E S S Ã O  D A  P I L H A ==========\n");

                    ImprimirPilha(Pilha);

                }else{

                    printf(">>>>>>> A PILHA ESTÁ VAZIA <<<<<<<");

                }

                system("PAUSE");

                break;

            case 4:

                printf("\nDigite o nome do produto que  deseja pesquisar: ");
                fflush(stdin);
                fgets(Paux.nome, 20, stdin);

                if(Pesquisar(Pilha, &Paux)){

                    printf("\n>>>>> P R O D U T O  E N C O N T R A D O <<<<<\n");

                    ImprimirProduto(Paux);

                }else{

                    printf("\n>>>>> P R O D U T O  N Ã O  E N C O N T R A D O <<<<<\n");

                }


                system("PAUSE");
                break;

            case 5:

                TProduto p1;

                TFila F; FFVazia(&F);


                printf("\n========= C R I A Ç Ã O  D A  F I L A =========\n");

                do{

                    LerProduto(&p1);
                    Enfileirar(p1,&F);

                    printf("\nDeseja ENFILEIRAR mais produtos na FILA?\n\n");

                    printf("1 ----- SIM");
                    printf("\n2 ----- NÃO");

                    printf("\n\nOPÇÃO: ");
                    scanf("%d", &i);
                    getchar();

                }while(i!=2);

                printf("\nDigite a quantidade de ELEMENTOS que deseja INVERTER: ");
                scanf("%d", &i);

                InverteElementos(i, &F);


                system("PAUSE");
                break;

            case 6:

                int base;

                printf("\nDigite o número que deseja conveter: ");
                scanf("%d", &i);

                printf("\nDigite a base (2 a 9) que deseja converter o número (%d): ", i);
                scanf("%d", &base);

                if(base>=2 && base<=9){


                    printf("\n\t\t\tNúmero: (%d)", i);
                    printf("\n\n\t\t\tBase: (%d)\n", base);

                    printf("\n===== P I L H A  C O M  V A L O R  C O N V E R T I D O =====\n");

                    ConversorDeBases(i, base);

                }else{

                    printf("\n\n>>>>> BASE INCORRETA <<<<<");

                }

                system("PAUSE");
                break;

            case 7:

                TProduto disco;
                TPilha Fonte; FPVazia(&Fonte);
                TPilha Destino; FPVazia((&Destino));

                printf("\nDigite a quantidade de DISCOS desejado: ");

                scanf("%d", &i);

                printf("\n============= C R I A Ç Ã O  D A  P I L H A  F O N T E =============\n");

                printf("\n\n\t>>INSERÇÃO DOS DISCOS DEVE RESPEITAR A REGRA LIFO<<\n");

                int k;

                for(k = 0; k < i; k++){

                    LerProdutoSoCodigo(&disco);

                    Empilha(disco, &Fonte);


                }

                printf("\n============= I M P R E S S Ã O  D A  P I L H A  D E S T I N O =============\n");

                Jogo(i, &Fonte, &Destino);

                ExcluirPilha(&Fonte);
                ExcluirPilha(&Destino);

                system("PAUSE");
                break;

            case 8:

                char frase[100];

                printf("\nDigite a FRASE de PARÊNTESIS para CONTAR: ");
                scanf("%99s", frase);


                printf("O tamanho da maior substring de parêntesis balanceados = (%d)", ContaParentesis(frase, 100));


                system("PAUSE");
                break;

            case 9:

                char expressao[10];

                printf("\nDigite a EXPRESSÃO para verificar se possui parêntesis duplicados: ");
                scanf("%9s", expressao);

                ContaParentesisDuplicados(expressao, 10);

                system("PAUSE");
                break;

            case 10:

                system("PAUSE");
                break;


            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
            } // fim do bloco switch

    } while(opcao != 10);

}
