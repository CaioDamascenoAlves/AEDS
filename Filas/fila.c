#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void FFVazia(TFila *Fila){
    Fila -> frente = (TCelula*) malloc(sizeof(TCelula));
    Fila -> tras = Fila -> frente;
    Fila -> frente -> prox = NULL;
    Fila -> tamanho = 0;

}
int Vazia(TFila Fila){

    return (Fila.frente == Fila.tras);
}
void Ler(TProduto *Item){

    printf("Digite o codigo do produto: \n");

    scanf("%d",&Item->codigo);

}
void Enfileirar(TProduto x,  TFila *Fila){
    Fila -> tras -> prox =
     (TCelula*) malloc(sizeof(TCelula));
    Fila -> tras = Fila->tras -> prox;
    Fila -> tras -> item = x;
    Fila -> tras -> prox = NULL;
    Fila -> tamanho++;
}


void Desenfileirar(TFila *Fila,TProduto *Item){
    TCelula* aux;
    if(!Vazia(*Fila)){
        aux = Fila-> frente -> prox;
        Fila-> frente -> prox = aux -> prox;
        *Item = aux -> item;
        free(aux);
        if(Fila -> frente -> prox == NULL){
            Fila-> tras = Fila -> frente;
            Fila-> tamanho--;
        }

    }

}

void Imprimir(TFila* Fila){
 TFila FilaAux;
 TProduto Item;
 FFVazia(&FilaAux);
 do{
     Desenfileirar(Fila,&Item);
     printf("\nImprimindo Fila\n");
     printf(" :%d ",Item.codigo);
     Enfileirar(Item,&FilaAux);

 }while(!Vazia(*Fila));

 do{
        Desenfileirar(&FilaAux,&Item);
        Enfileirar(Item,&Fila);
 }while(!Vazia(FilaAux));

 Liberar(&FilaAux);

}
void Uniao(TFila *Fila,TFila *Fila2,TFila *Fila3){

    TProduto Item,Item2;

    do{

        Desenfileirar(Fila,&Item);
        Desenfileirar(Fila2,&Item2);
        Enfileirar(Item,Fila3);
        Enfileirar(Item2,Fila3);

    }while(!Vazia(*Fila) && !Vazia(*Fila2));

    if(!Vazia(*Fila3))
    {
        printf("\n*IMPRIMINDO OPERACAO:UNIAO DE CONJUNTOS*\n");
        Imprimir(Fila3);
    }
}
void DiferencaConjuntos(TFila *Fila1,TFila *Fila2,TFila *Fila3)
{

    TProduto ItemAux1,ItemAux2;
    TFila FilaAux;

    FFVazia(&FilaAux);

    while(!Vazia(*Fila1)){

        Desenfileirar(Fila1,&ItemAux1);
        while(!Vazia(*Fila2)){
                Desenfileirar(Fila2,&ItemAux2);
                if(ItemAux1.codigo != ItemAux2.codigo)
                {
                    Enfileirar(ItemAux2,Fila3);
                }else if(ItemAux1.codigo == ItemAux2.codigo){
                     Enfileirar(ItemAux2,&FilaAux);
                }

        }

    while(!Vazia(FilaAux)){
        Desenfileirar(&FilaAux,&ItemAux2);
        Enfileirar(ItemAux2,Fila2);
        }
    }

    if(!Vazia(*Fila3)){
    printf("\n*IMPRIMINDO OPERACAO:DIFERENCA DE CONJUNTOS*\n");
    Imprimir(Fila3);
    }else
    printf("\n*Fila 3 esta vazia*\n");

    Liberar(&FilaAux);


}

void Remover_N_Ezimo(TFila *Fila, int n){

     TProduto Item;
     TFila FilaAux;

     FFVazia(&FilaAux);

     do{
        Desenfileirar(Fila,&Item);
        if(Item.codigo == n){
            printf("O n-esimo =%d esta na fila e sera removido",Item.codigo);
        }
        else{
            Enfileirar(Item,&FilaAux);
        }

     }while(!Vazia(*Fila));

     do{

        Desenfileirar(&FilaAux,&Item);
        Enfileirar(Item,&Fila);

     }while(!Vazia(FilaAux));

     Liberar(&FilaAux);

}

void Intersecao(TFila *Fila1, TFila *Fila2,TFila *Fila3){
    TProduto ItemAux,ItemAux2,ItemAux3;
    TFila FilaAux,FilaAux2,FilaAux3;

    FFVazia(&FilaAux);
    FFVazia(&FilaAux2);


    while(!Vazia(*Fila1)){
        Desenfileirar(Fila1,&ItemAux);
        while(!Vazia(*Fila2)){
            Desenfileirar(Fila2,&ItemAux2);
            if(ItemAux.codigo == ItemAux2.codigo){
                Enfileirar(ItemAux2,Fila3);
            }else if(ItemAux.codigo != ItemAux2.codigo){
                Enfileirar(ItemAux2,&FilaAux2);

            }
        }

        while(!Vazia(FilaAux2)){
            Desenfileirar(&FilaAux2,&ItemAux2);
            Enfileirar(ItemAux2,Fila2);
        }
    }

    printf("\n*IMPRIMINDO OPERACAO:INTERSECAO DE CONJUNTOS*\n");
    Imprimir(Fila3);

    Liberar(&FilaAux);
    Liberar(&FilaAux2);
}
void Liberar(TFila *Fila){
    TProduto Item;
    while(!Vazia(*Fila)){
        Desenfileirar(Fila, &Item);
    }
    free(Fila->frente);
    printf("\nFila Liberada!\n");

}
