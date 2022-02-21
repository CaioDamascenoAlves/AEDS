#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main()
{
    TArvore Arvore;

    Iniciar(&Arvore.raiz);
    //printf("\np = %p\n", Arvore.raiz);

    TItem x;
    x.chave = 15;
    Inserir(&Arvore.raiz,NULL,x);
    x.chave  = 10;
    Inserir(&Arvore.raiz,NULL,x);
    x.chave = 20;
    Inserir(&Arvore.raiz,NULL,x);
    x.chave = 7;
    Inserir(&Arvore.raiz,NULL,x);
    x.chave = 17;
    Inserir(&Arvore.raiz,NULL,x);
    x.chave = 13;
    Inserir(&Arvore.raiz,NULL,x);
     x.chave = 25;
    Inserir(&Arvore.raiz,NULL,x);
      x.chave = 14;
    Inserir(&Arvore.raiz,NULL,x);
       x.chave = 1;
    Inserir(&Arvore.raiz,NULL,x);

    TCelula *y;
    y=Maximo(Arvore.raiz);
    if(y != NULL)
        printf("\nMaximo: %d\n",y->item.chave);
    y=Minimo(Arvore.raiz);
    if(y != NULL)
        printf("\nMinimo: %d\n",y->item.chave);

    printf("\nRaiz: %d\n",Arvore.raiz->item.chave);

    x.chave=7;
    printf("\nPesquisando pelo elemento %d...\n",x.chave);
    y=Pesquisar(Arvore.raiz, x);
    if (y != NULL)
        printf("\nElemento %d encontrado!\n",y->item.chave);
    else
        printf("\nELEMENTO NAO ENCONTRADO...\n");
    y=Sucessor(y);
    if(y != NULL)
        printf("\nSucessor: %d\n",y->item.chave);

    y=Predecessor(y);
    if(y != NULL)
        printf("\nPredecessor: %d\n",y->item.chave);

    printf("\nPai da raiz: %p\n", Arvore.raiz->pai);
    TCelula *no;
    x.chave = 15;
    printf("\nPesquisando pelo elemento %d para retira-lo da arvore...\n",x.chave);
    y=Pesquisar(Arvore.raiz, x);
    if (y != NULL){
        printf("\nElemento %d encontrado!\n",y->item.chave);
        Retirar(&Arvore, &y);
        printf("\nElemento %d removido da arvore! Agora seu ponteiro e' %p...\n",x.chave,y);
        printf("\n");
    }
    else
        printf("\nELEMENTO NAO ENCONTRADO...\n");

    x.chave=7;
    printf("\nPesquisando pelo elemento %d...\n",x.chave);
    y=Pesquisar(Arvore.raiz, x);
    if (y != NULL)
        printf("\nElemento %d encontrado!\n",y->item.chave);
    else
        printf("\nELEMENTO NAO ENCONTRADO...\n");

    printf("\n(a) Caminhamento in-ordem:\t");
    Central(Arvore.raiz);
    printf("\n");
    printf("\n(a) Caminhamento in-ordem iterativo:\t");
    Central_Iterativa(Arvore.raiz);
    printf("\n");
    printf("\n(b) Caminhamento pre-ordem:\t");
    PreOrdem(Arvore.raiz);
    printf("\n");
    printf("\n(b) Caminhamento pre-ordem iterativo:\t");
    PreOrdem_Iterativa(Arvore.raiz);
    printf("\n");
    printf("\n(c) Caminhamento pos-ordem:\t");
    PosOrdem(Arvore.raiz);
    printf("\n");
    printf("\n(c) Caminhamento pos-ordem iterativo:\t");
    PosOrdem_Iterativo(Arvore.raiz);
    printf("\n");
    printf("\n(c) Tree_Search:\t");
    Tree_Search(Arvore.raiz);
    printf("\n");
    printf("\n(7) Percurso Alternativo:\t");
    PercursoAlternativo(Arvore.raiz);
    printf("\n");
    printf("\nFilho direito da raiz: %d\n", Arvore.raiz->dir->item.chave);

    return 0;
}
