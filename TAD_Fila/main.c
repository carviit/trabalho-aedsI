#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

int main()
{
    TFila Fila;

    FFVazia(&Fila);

    MENU(&Fila);

    ExcluirFila(&Fila);

    return 0;
}
