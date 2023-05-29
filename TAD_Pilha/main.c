#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Interface.h"

int main()
{
    TPilha p;

    FPVazia(&p);

    MENU(&p);

    return 0;
}
