#include <stdlib.h>
#include <stdio.h>
#include "listas.h"
#define MAX 10

void FLVazia(TLista *Lista){
  Lista -> primeiro =
       (TCelula *) malloc(sizeof(TCelula));
  Lista -> ultimo = Lista -> primeiro;
  Lista -> primeiro -> prox = NULL;
  Lista -> tamanho = 0;
}

int Vazia(TLista Lista){
  return (Lista.primeiro == Lista.ultimo);
}

void Inserir(TProduto x, TLista *Lista){
  Lista -> ultimo -> prox =
        (TCelula *) malloc(sizeof(TCelula));
  Lista -> ultimo = Lista -> ultimo -> prox;
  Lista -> ultimo -> item = x;
  Lista -> ultimo -> prox = NULL;
  Lista -> tamanho++;
}

TCelula* Pesquisar(TLista Lista, TProduto Item){
   TCelula* Aux;
   Aux = Lista.primeiro;
   while(Aux->prox != NULL){
      if(Aux->prox->item.codigo == Item.codigo)
        printf("\n Item encontrado: %d\n",Item.codigo);
         return Aux;
      Aux = Aux->prox;
   }
   return NULL;
}

void Excluir(TLista *Lista, TProduto *Item){
  /* Obs.: o item a ser retirado e o apontado por p */
  TCelula *Aux1, *Aux2;
  Aux1 = Pesquisar(*Lista, *Item);
  if (Aux1 != NULL) {
     Aux2 = Aux1->prox;
     Aux1->prox = Aux2 -> prox;
     *Item = Aux2->item;
     if (Aux1->prox == NULL)
        Lista->ultimo = Aux1;
     free(Aux2);
     Lista->tamanho--;
  }
}

void Imprimir(TLista Lista){
  TCelula* Aux;
  Aux = Lista.primeiro -> prox;
  while (Aux != NULL){
    printf("%d\n", Aux->item.codigo);
    Aux = Aux -> prox;
  }
}

void Liberar(TLista* Lista){
     TProduto Item;
     while(!Vazia(*Lista)){
        Excluir(Lista,&Item);
     }
     free(Lista->primeiro);
     printf("\nLista Liberada!\n");
}

void Ler(TProduto *Item){
    printf("\nDigite o codigo do produto: \n");
    scanf("%d",&Item->codigo);
}
void ListasIguais(TLista *Lista1, TLista *Lista2){
    TProduto ItemAux1,ItemAux2;
    if(Lista1->tamanho != Lista2->tamanho){
        printf("\nListas com tamanhos diferentes");
    }else{
        printf("\nListas com tamanhos iguais");
    do{
        Excluir(Lista1,&ItemAux1);
        Excluir(Lista2,&ItemAux2);
        if(ItemAux1.codigo == ItemAux2.codigo){
            printf("\nElementos com valores iguais em ambas listas");
        }else
            printf("\nLista com elementos de valores diferentes");

    }while(!Vazia(*Lista1));
    }
}


void removeElementosIguais(TLista *Lista){

    TProduto ItemAux,ItemAux2;
    TLista ListaAux;
    FLVazia(&ListaAux);
    ItemAux2.codigo = Lista->primeiro->prox->item.codigo;
    Inserir(ItemAux2,&ListaAux);
    while(!Vazia(*Lista)){
        Excluir(Lista,&ItemAux);
        if(ItemAux.codigo != ItemAux2.codigo){
        ItemAux2.codigo = ItemAux.codigo;
        Inserir(ItemAux,&ListaAux);
        }
    }
    while(!Vazia(ListaAux)){
        Excluir(&ListaAux,&ItemAux);
        Inserir(ItemAux,Lista);
    }
    Liberar(&ListaAux);
}
void Pesquisar_iEsimoTamanho(TLista *Lista, int iEsimo){

    TProduto Item;
    TLista ListaAux;
    while(!Vazia(*Lista)){
        Excluir(Lista,&Item);
        Inserir(Item, &ListaAux);
        if(Lista->tamanho == iEsimo){
            printf("\ni-esimo elemento na lista: %d", Item.codigo);
        }

    }
    do{

        Excluir(&ListaAux,&Item);
        Inserir(Item,Lista);

    }while(!Vazia(ListaAux));

    Liberar(&ListaAux);

}
