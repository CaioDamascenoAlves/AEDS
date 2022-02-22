#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"

int main()
{
    TProduto Item1,Item2;
    TPilha pilha1;
    FPVazia(&pilha1);
    TPilha pilha2;
    FPVazia(&pilha2);
    TPilha pilha3;
    FPVazia(&pilha3);
    char exp [50] = {" 51 13 12 * +"};


    //printf("Resultado de %s: %f\n",exp,resolver_exprecao(exp));

    int i = 0,k = 0;

    do{
        printf("Pilha 1 \n");
        printf("Digite o codigo do produto: \n");
        fflush(stdin);
        scanf("%d",&Item1.codigo);
        Empilhar(Item1,&pilha1);
        i++;
    }while(i<MAX-2);

    do{
        printf("Pilha 2 \n");
        printf("Digite o codigo do produto: \n");
        fflush(stdin);
        scanf("%d",&Item2.codigo);
        Empilhar(Item2,&pilha2);
        k++;
    }while(k<MAX-1);

    //inveter_Duas_Aux(&pilha1);
    //inverter_Com_Fila(&pilha1);
    //inverter_Uma_Aux(&pilha1);
    //transferePilha(&pilha1,&pilha2);
    //Imprimir(&pilha1);
   // Imprimir(&pilha2);


    //inverter_Uma_Pilha(&pilha1);
    //transferePilha(&pilha1,&pilha2);
    Imprimir(&pilha3);

    Liberar(&pilha1);
    Liberar(&pilha2);
    Liberar(&pilha3);
    return 0;
}
