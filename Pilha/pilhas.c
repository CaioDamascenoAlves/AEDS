#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"

void FPVazia(TPilha *Pilha){
  Pilha->topo = (TCelula*)
      malloc(sizeof(TCelula));
  Pilha->fundo = Pilha->topo;
  Pilha->topo->prox = NULL;
  Pilha->tamanho = 0;
}

int Vazia(TPilha Pilha){
 return (Pilha.topo == Pilha.fundo);
}

void Empilhar(TProduto x,TPilha *Pilha){
  TCelula* Aux;
  Aux = (TCelula*)
         malloc(sizeof(TCelula));
  Pilha->topo->item = x;
  Aux->prox = Pilha->topo;
  Pilha->topo = Aux;
  Pilha->tamanho++;
}


void Desempilhar(TPilha *Pilha,TProduto *Item){
  TCelula* q;
  if (Vazia(*Pilha)) {
      printf("Erro: lista vazia\n");
      return 0;
  }
  q = Pilha->topo;
  Pilha->topo = q->prox;
  *Item = q->prox->item;
  free(q);
  Pilha->tamanho--;
}

void Imprimir(TPilha *Pilha){
    TPilha PilhaAux;
    TProduto Item;
    FPVazia(&PilhaAux);

    while(!Vazia(*Pilha)){
        Desempilhar(Pilha, &Item);
        printf("\nImprimindo Pilha\n");
        printf(" :%d ",Item.codigo);
        Empilhar(Item,&PilhaAux);
    }

    while(!Vazia(PilhaAux)){

        Desempilhar(&PilhaAux, &Item);
        Empilhar(Item,Pilha);
    }
    Liberar (&PilhaAux);
}

void Liberar(TPilha *Pilha){
    TProduto Item;
    while(!Vazia(*Pilha)){
        Desempilhar(Pilha, &Item);
    }
    free(Pilha->topo);
}

int Tamanho(TPilha Pilha){
 return (Pilha.tamanho);
}

void inveter_Duas_Aux(TPilha * Pilha){
    TProduto ItemAux;
    TPilha aux;
    TPilha aux2;
    FPVazia(&aux);
    FPVazia(&aux2);

    do{
        Desempilhar(Pilha,&ItemAux);
        Empilhar(ItemAux,&aux);
    }while(!Vazia(*Pilha));

    do{
        Desempilhar(&aux,&ItemAux);
        Empilhar(ItemAux,&aux2);
    }while(!Vazia(aux));

    do{
        Desempilhar(&aux2,&ItemAux);
        Empilhar(ItemAux,Pilha);
    }while(!Vazia(aux2));

    Liberar(&aux);
    Liberar(&aux2);

}
void inverter_Com_Fila(TPilha * Pilha){
    TFila FilaAux;
    TProduto ItemAux;
    FFVazia(&FilaAux);

    do{
        Desempilhar(Pilha,&ItemAux);
        Enfileirar(ItemAux,&FilaAux);
    }while(!Vazia(*Pilha));

    do{
        Desenfileirar(&FilaAux,&ItemAux);
        Empilhar(ItemAux,Pilha);
    }while(!VaziaFila(FilaAux));

    LiberarFila(&FilaAux);
}

void inverter_Uma_Pilha_Uma_Aux(TPilha *Pilha){
    TPilha PilhaAux;
    TProduto ItemAux,x,y;
    FPVazia(&PilhaAux);
    int n=0,i=0;
    n = Pilha->tamanho;
    printf("\n%d",n);

    while(n!=0){
        Desempilhar(Pilha,&ItemAux);
        x = ItemAux;
        y = x;
        i++;
        while(Pilha->tamanho == n-i){
            Desempilhar(Pilha,&ItemAux);
            Empilhar(ItemAux,&PilhaAux);
        }
        Empilhar(y,Pilha);
        while(!Vazia(PilhaAux)){
            Desempilhar(&PilhaAux,&ItemAux);
            Empilhar(ItemAux,Pilha);
        }
        Desempilhar(Pilha,&ItemAux);
        x = ItemAux;
        y = x;
        while(Pilha->tamanho == n-i){
            Desempilhar(Pilha,&ItemAux);
            Empilhar(ItemAux,&PilhaAux);
        }
        Empilhar(y,Pilha);
        while(!Vazia(PilhaAux)){
            Desempilhar(&PilhaAux,&ItemAux);
            Empilhar(ItemAux,Pilha);
        }
        n--;
        i++;

    }
    Liberar(&PilhaAux);

}
void transferePilha(TPilha * Pilha1,TPilha *Pilha2){
    TProduto ItemAux,x,y;
    int n=0,i=0;
    n = Pilha1->tamanho;
    printf("\n%d",n);

    while(!Vazia(*Pilha1)){
        Desempilhar(Pilha1,&ItemAux);
        Empilhar(ItemAux,Pilha2);
    }
    while(n!=0){
        Desempilhar(Pilha2,&ItemAux);
        x = ItemAux;
        y = x;
        i++;
        while(Pilha2->tamanho == n-i){
            Desempilhar(Pilha2,&ItemAux);
            Empilhar(ItemAux,Pilha1);
        }
        Empilhar(y,Pilha2);
        while(!Vazia(*Pilha1)){
            Desempilhar(Pilha1,&ItemAux);
            Empilhar(ItemAux,Pilha2);
        }
        Desempilhar(Pilha2,&ItemAux);
        x = ItemAux;
        y = x;
        while(Pilha2->tamanho == n-i){
            Desempilhar(Pilha2,&ItemAux);
            Empilhar(ItemAux,Pilha1);
        }
        Empilhar(y,Pilha2);
        while(!Vazia(*Pilha1)){
            Desempilhar(Pilha1,&ItemAux);
            Empilhar(ItemAux,Pilha2);
        }
        n--;
        i++;

    }
     while(!Vazia(*Pilha2)){
        Desempilhar(Pilha2,&ItemAux);
        Empilhar(ItemAux,Pilha1);
    }
    while(!Vazia(*Pilha1)){
        Desempilhar(Pilha1,&ItemAux);
        Empilhar(ItemAux,Pilha2);
    }
}
void FFVazia(TFila *Fila){
    Fila -> frente = (TCelula*) malloc(sizeof(TCelula));
    Fila -> tras = Fila -> frente;
    Fila -> frente -> prox = NULL;
    Fila -> tamanho = 0;

}
int VaziaFila(TFila Fila){

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
    if(!VaziaFila(*Fila)){
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

void ImprimirFila(TFila* Fila){
 TFila FilaAux;
 TProduto Item;
 FFVazia(&FilaAux);
 do{
     Desenfileirar(Fila,&Item);
     printf("\nImprimindo Fila\n");
     printf(" :%d ",Item.codigo);
     Enfileirar(Item,&FilaAux);

 }while(!VaziaFila(*Fila));

 do{
        Desenfileirar(&FilaAux,&Item);
        Enfileirar(Item,&Fila);
 }while(!VaziaFila(FilaAux));

 Liberar(&FilaAux);

}
void LiberarFila(TFila *Fila){
    TProduto Item;
    while(!VaziaFila(*Fila)){
        Desenfileirar(Fila, &Item);
    }
    free(Fila->frente);
    printf("\nFila Liberada!\n");

}







