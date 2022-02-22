#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED


typedef struct item{
int codigo;
}TProduto;

typedef struct celula{
    TProduto item;
    struct celula* prox;
}TCelula;

typedef struct fila{
    TCelula* frente;
    TCelula * tras;
    int tamanho;

}TFila;

void FFVazia(TFila *Fila);
int Vazia(TFila Fila);
void Ler (TProduto *Item);
void Enfileirar(TProduto x, TFila *Fila);
void Desenfileirar(TFila *Fila,TProduto *Item);
void Imprimir(TFila *Fila);
void DiferencaConjuntos(TFila *Fila1,TFila *Fila2,TFila *Fila3);
void Uniao(TFila *Fila,TFila *Fila2,TFila *Fila3);
void Intersecao(TFila *Fila1, TFila *Fila2,TFila *Fila3);
void Remover_N_Ezimo(TFila *Fila,int n);
void Liberar(TFila *Fila);

#endif // FILA_H_INCLUDED
