#ifndef LISTA_H_INCLUDEDfile:
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef struct {
  int codigo;
  /*
     outros componentes
     de produto
  */
} TProduto;

typedef struct celula {
  TProduto item;
  struct celula* prox;
} TCelula;

typedef struct {
  TCelula* primeiro;
  TCelula* ultimo;
  int tamanho;
} TLista;

void FLVazia(TLista *Lista);
int Vazia(TLista Lista);
void Inserir(TProduto x, TLista *Lista);
TCelula* Pesquisar(TLista Lista, TProduto Item);
void Excluir(TLista *Lista, TProduto *Item);
void Imprimir(TLista Lista);
void Liberar (TLista* Lista);
void Ler(TProduto *Item);
void ListasIguais(TLista *Lista1, TLista *Lista2);
TCelula* buscarCelula(int i, TLista *lst1);
void exclui_elemento(TLista *Lista, int dado);
void removeElementosIguais(TLista *Lista);
#endif // LISTA_H_INCLUDED
