#ifndef PILHAS_H_INCLUDED
#define PILHAS_H_INCLUDED
#define MAX 5
typedef struct {
  int codigo;
  /* outros componentes */
} TProduto;

typedef struct celula {
  TProduto item;
  struct celula* prox;
} TCelula;

typedef struct {
  TCelula *fundo;
  TCelula *topo;
  int tamanho;
} TPilha;

typedef struct fila{
    TCelula* frente;
    TCelula * tras;
    int tamanho;
}TFila;

void FPVazia(TPilha *Pilha);
int Vazia(TPilha Pilha);
void Empilhar(TProduto x,TPilha *Pilha);
void Desempilhar(TPilha *Pilha,TProduto *Item);
void Imprimir(TPilha *Pilha);
void Liberar(TPilha *Pilha);
int Tamanho(TPilha Pilha);
void inveter_Duas_Aux (TPilha * Pilha);
void inverter_Com_Fila(TPilha * Pilha);
void inverter_Uma_Pilha_Uma_Aux(TPilha *Pilha);
void transferePilha(TPilha * Pilha1,TPilha *Pilha2);

//Cabecalho TAD Fila
void FFVazia(TFila *Fila);
int VaziaFila(TFila Fila);
void Enfileirar(TProduto x, TFila *Fila);
void Desenfileirar(TFila *Fila,TProduto *Item);
void ImprimirFila(TFila* Fila);
void LiberarFila(TFila *Fila);

#endif // PILHAS_H_INCLUDED
