#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
int main()
{
    TProduto Item;
    TLista lista;
    FLVazia(&lista);
    int iE = 3;
    int i;
    for(i=0;i<8;i++){
        fflush(stdin);
        printf("Item lista 1");
        Ler(&Item);
        Inserir(Item, &lista);

    }

    Pesquisar_iEsimoTamanho(&lista, iE);
    Imprimir(lista);
    Liberar(&lista);

    return 0;
}
