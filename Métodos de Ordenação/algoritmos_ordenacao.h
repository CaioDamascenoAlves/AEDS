#ifndef ALGORITMOS_ORDENACAO_H_INCLUDED
#define ALGORITMOS_ORDENACAO_H_INCLUDED
typedef struct item{
int Chave;
int *A;
}TipoItem;


typedef struct indice{
    int index;
}TipoIndice;

void Selecao(int A[], int n);
void Insercao(int A[], int n);
void Bubblesort(int A[], int n);
void shellSort(int A[], int siz);
void heapsort(int a[], int n);
void Swap(int *a, int *b);
int Partition(int arr[], int low, int high);
void quicksort(int arr[], int low, int high);
#endif // ALGORITMOS_ORDENACAO_H_INCLUDED
