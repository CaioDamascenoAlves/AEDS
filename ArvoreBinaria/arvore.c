#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void Iniciar(TCelula **no){
    *no = NULL;
}

TCelula *criaNo(TItem Item){
    TCelula *no = (TCelula*) malloc(sizeof(TCelula));
    no->pai = NULL;
    no->esq = NULL;
    no->dir = NULL;
    no->item = Item;
    return no;
}

void Inserir(TCelula **x, TCelula *pai, TItem Item){
    if((*x) == NULL){
        (*x) = criaNo(Item);
        if(pai != NULL)
            (*x)->pai = pai;
        return;
    }
    if((*x)->item.chave > Item.chave){
        Inserir(&(*x)->esq, (*x), Item);
        return;
    }
    if ((*x)->item.chave <= Item.chave)
        Inserir(&(*x)->dir, (*x), Item);
}


TCelula* Pesquisar(TCelula *x, TItem Item){
    if((x == NULL)||(x->item.chave == Item.chave))
        return x;
    if(Item.chave < x->item.chave)
        return Pesquisar(x->esq,Item);
    else if(Item.chave > x->item.chave)
        return Pesquisar(x->dir, Item);
}


void Central(TCelula *x){
    if (x != NULL){
     Central(x->esq);
     printf("%d ",x->item.chave);
     Central(x->dir);
    }
}
void Central_Iterativa(TCelula *x){
    TItem ItemAux,ItemAux2;
    TPilha PilhaAux,PilhaAux2;
    FPVazia(&PilhaAux);
    FPVazia(&PilhaAux2);
    TCelula* y,*z;
    y = x;
    ItemAux.chave = y->item.chave;
    Empilhar(ItemAux,&PilhaAux);
     while(y->esq!= NULL){
        y = y->esq;
        ItemAux.chave = y->item.chave;
        Empilhar(ItemAux,&PilhaAux);
     }
     while (!Vazia(PilhaAux)){
        Desempilhar(&PilhaAux,&ItemAux);
        y->item.chave = ItemAux.chave;
        printf("%d ",ItemAux.chave);
        if(y->dir!=NULL){
        y = y->dir;
        ItemAux.chave = y->item.chave;
        Empilhar(ItemAux,&PilhaAux);
        }
    }
    while(x->dir!= NULL){
        x= x->dir;
        y = x;
        ItemAux.chave = x->item.chave;
        Empilhar(ItemAux,&PilhaAux);
        if(y->esq!=NULL){
            y = y->esq;
            ItemAux2.chave = y->item.chave;
        }
    }
        while(!Vazia(PilhaAux)){
            Desempilhar(&PilhaAux,&ItemAux);
            Empilhar(ItemAux,&PilhaAux2);
        }
        Empilhar(ItemAux2,&PilhaAux2);
        while(!Vazia(PilhaAux2)){
            Desempilhar(&PilhaAux2,&ItemAux);
            printf("%d ",ItemAux.chave);
        }
        Liberar(&PilhaAux);Liberar(&PilhaAux2);
}

void PreOrdem(TCelula *x){
    if (x != NULL){
     printf("%d ",x->item.chave);
     PreOrdem(x->esq);
     PreOrdem(x->dir);
    }
}
void PreOrdem_Iterativa(TCelula *x){
    TPilha PilhaAux;
    TItem ItemAux;
    FPVazia(&PilhaAux);
    TCelula * y;
    y=x;
    ItemAux.chave = x->item.chave;
    printf("%d ",ItemAux.chave);

    while(y->esq!=NULL){
        y= y->esq;
        ItemAux.chave = y->item.chave;
        Empilhar(ItemAux,&PilhaAux);
        printf("%d ",ItemAux.chave);
        if(y->dir!=NULL){
            y=y->dir;
            ItemAux.chave = y->item.chave;
            Empilhar(ItemAux,&PilhaAux);
            printf("%d ",ItemAux.chave);
        }
    }
    while(!Vazia(PilhaAux)){
        Desempilhar(&PilhaAux,&ItemAux);
    }
    while(x->dir!=NULL){
        x= x->dir;
        ItemAux.chave = x->item.chave;
        Empilhar(ItemAux,&PilhaAux);
        printf("%d ",ItemAux.chave);
        if(x->esq!=NULL){
           x=x->esq;
            ItemAux.chave = x->item.chave;
            Empilhar(ItemAux,&PilhaAux);
            printf("%d ",ItemAux.chave);
            x= x->pai;
        }
    }
    Liberar(&PilhaAux);
}

void PosOrdem(TCelula *x){
    if (x != NULL){
     PosOrdem(x->esq);
     PosOrdem(x->dir);
     printf("%d ",x->item.chave);
    }
}
void PosOrdem_Iterativo(TCelula *x){
    TPilha PilhaAux,PilhaAux2;
    TItem ItemAux,ItemAux2;
    FPVazia(&PilhaAux);
    FPVazia(&PilhaAux2);
    TCelula * y,*z;
    y = x;
    z= y;
    while(z->esq != NULL){
        z=z->esq;
        ItemAux.chave = z->item.chave;
        Empilhar(ItemAux,&PilhaAux);
        if(z->dir!=NULL){
            z=z->dir;
            ItemAux2.chave = z->item.chave;
            Empilhar(ItemAux2,&PilhaAux2);
            printf("%d ",ItemAux2.chave);
            z = z->pai;
            Desempilhar(&PilhaAux2,&ItemAux2);
        }
    }
    while(!Vazia(PilhaAux)){
        Desempilhar(&PilhaAux,&ItemAux);
         printf("%d ",ItemAux.chave);
    }
    while(x->dir!=NULL){
        x= x->dir;
        ItemAux.chave = x->item.chave;
        Empilhar(ItemAux,&PilhaAux);
        if(x->esq!=NULL){
            x = x->esq;
            ItemAux2.chave = x->item.chave;
            Empilhar(ItemAux2,&PilhaAux2);
            printf("%d ",ItemAux2.chave);
            x= x->pai;
        }

    }
     while(!Vazia(PilhaAux)){
        Desempilhar(&PilhaAux,&ItemAux);
         printf("%d ",ItemAux.chave);
    }
    printf("%d ",y->item.chave);
    Liberar(&PilhaAux);Liberar(&PilhaAux2);
}
void Tree_Search(TCelula *x){
    TPilha PilhaAux;
    TItem ItemAux;
    FPVazia(&PilhaAux);
    TCelula *y;
    y = x;
    printf("%d ",x->item.chave);
    while(x->esq!=NULL&&y->dir!=NULL){
        x = x->esq;
        y = y->dir;
        ItemAux.chave = x->item.chave;
        Empilhar(ItemAux,&PilhaAux);
        //printf("%d ",ItemAux.chave);
        ItemAux.chave = y->item.chave;
        Empilhar(ItemAux,&PilhaAux);
        //printf("%d ",ItemAux.chave);
        if(y->esq!=NULL){
            y=y->esq;
            ItemAux.chave= y->item.chave;
            //printf("%d ",ItemAux.chave);
            Empilhar(ItemAux,&PilhaAux);
            y= y->pai;
        }if(x->dir!=NULL){
            x=x->dir;
            ItemAux.chave= x->item.chave;
            Empilhar(ItemAux,&PilhaAux);
           //printf("%d ",ItemAux.chave);
           // x =x->pai;
        }

    }
    while(!Vazia(PilhaAux)){
        Desempilhar(&PilhaAux,&ItemAux);
        printf("%d ",ItemAux.chave);
    }

}

void PercursoAlternativo(TCelula *x){
    TCelula *y,*z,*w;
    y= Minimo(x);
     printf("%d ",y->item.chave);
    w = Maximo(x);
    printf("%d ",w->item.chave);
    while(w->item.chave>=y->item.chave){
    z = Sucessor(y);
     printf("%d ",z->item.chave);
    }

    }




TCelula* Minimo(TCelula *x){
    if (x == NULL)
        return NULL;
    while(x->esq != NULL){
        x = x->esq;
    }
    return x;
}

TCelula* Maximo(TCelula *x){
    if (x == NULL)
        return NULL;
    while(x->dir != NULL){
        x = x->dir;
    }
    return x;
}

TCelula* Sucessor(TCelula *x){
    if(x == NULL)
        return NULL;
    if(x->dir != NULL)
        return Minimo(x->dir);
    TCelula *y = x->pai;
    while(y != NULL && x == y->dir){
        x = y;
        y = y->pai;
    }
    return y;
}

TCelula* Predecessor(TCelula *x){
    if(x == NULL)
        return x;
    if(x->esq != NULL)
        return Maximo(x->esq);
    TCelula* y = x->pai;
    while(y != NULL && x == y->esq){
        x = y;
        y = y->pai;
    }
    return y;
}
// Substitui subárvore enraizada no nó 'u' pela subárvore enraizada no nó 'v'.
void Transplante(TArvore *Arvore, TCelula **u, TCelula **v){
    if ((*u)->pai == NULL)
        Arvore->raiz = (*v);
    else if((*u) == (*u)->pai->esq)
        (*u)->pai->esq = (*v);
    else
        (*u)->pai->dir = (*v);
    if(*v != NULL)
        (*v)->pai = (*u)->pai;
}

// Retira um nó 'z' na árvore 'Arvore'.
void Retirar(TArvore *Arvore, TCelula **z){
    if (*z == NULL){
        printf("\n>>>>> AVISO: NO' \"z\" E' NULO! <<<<<\n");
        return;
    }
    if((*z)->esq == NULL)
        Transplante(Arvore, z, &(*z)->dir);
    else if((*z)->dir == NULL)
        Transplante(Arvore, z, &(*z)->esq);
    else{
        TCelula *y = Minimo((*z)->dir);
        if(y->pai != (*z)){
            Transplante(Arvore, &y, &y->dir);
            y->dir = (*z)->dir;
            y->dir->pai = y;
        }
        Transplante(Arvore, z, &y);
        y->esq = (*z)->esq;
        y->esq->pai = y;
    }
    free(*z);
    *z = NULL;
}
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

void Empilhar(TItem x,TPilha *Pilha){
  TCelula* Aux;
  Aux = (TCelula*)
         malloc(sizeof(TCelula));
  Pilha->topo->item = x;
  Aux->prox = Pilha->topo;
  Pilha->topo = Aux;
  Pilha->tamanho++;
}

void Desempilhar(TPilha *Pilha,TItem *Item){
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
    TItem Item;
    FPVazia(&PilhaAux);


    // Pop de PIlha e Push em Pilha auxiliar
    while(!Vazia(*Pilha)){
        Desempilhar(Pilha, &Item);
        Empilhar(Item,&PilhaAux);
    }

    while(!Vazia(PilhaAux)){

        Desempilhar(&PilhaAux, &Item);
        printf("\n %d ",Item.chave);
        Empilhar(Item,Pilha);
        printf(" %d",Item.chave);
    }
    Liberar (&PilhaAux);// eliminar a célula cabeça
}

void Liberar(TPilha *Pilha){
    TItem Item;
    while(!Vazia(*Pilha)){
        Desempilhar(Pilha, &Item);
    }
    free(Pilha->topo);
    printf("\n Pilha liberada");
}
