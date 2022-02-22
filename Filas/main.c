#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
int main()
{
    TProduto Item;

    TFila fila1;FFVazia(&fila1);
    TFila fila2;FFVazia(&fila2);
    TFila fila3;FFVazia(&fila3);

    int i;
    int n = 3;

    for(i = 0; i< 3 ;i++){
        fflush(stdin);
        printf("\nItem Fila 1\n");
        Ler(&Item);
        Enfileirar(Item,&fila1);
   }
    for(i = 0; i< 3 ;i++){
        fflush(stdin);
        printf("\nItem Fila 2\n");
        Ler(&Item);
        Enfileirar(Item,&fila2);
   }

   Uniao(&fila1,&fila2,&fila3);

   Liberar(&fila1);
   Liberar(&fila2);
   Liberar(&fila3);

    return 0;
}
