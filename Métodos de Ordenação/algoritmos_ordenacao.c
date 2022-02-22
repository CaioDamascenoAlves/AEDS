#include "algoritmos_ordenacao.h"
#define true 1
// Selecion Sort
void Selecao(int *A, int n){
  int i, j, Min;
  int x;
  for (i = 1; i <= n - 1; i++){
      Min = i;
      for (j = i + 1; j <= n; j++)
        if (A[j] < A[Min])
           Min = j;
      x = A[Min];
      A[Min] = A[i];
      A[i] = x;
  }
}

// Insertion Sort algorithm
void Insercao(int *A, int n){
  int i, j;
  int x;
  for (i = 2; i <= n; i++){
      x = A[i];
      j = i - 1;
      A[0] = x;
      while (x < A[j]){
           A[j+1] = A[j];
           j--;
      }
      A[j+1] = x;
    }
}

// Método da Bolha: borbulha os maiores elemento para o final do arranjo
void Bubblesort(int A[], int n){
 int x;
 int i,j;
 for(i = 1; i < n; i++){
  for(j = n; j > i; j--){
     if(A[j] < A[j - 1]){
        x = A[j];
        A[j] = A[j - 1];
        A[j - 1] = x;
     }
  }
 }
}

// Método Shellsort: extensão do Inserção com a sequência h-ordenada
void shellSort(int A[], int siz) {
    int i, j, value;

    int h = 1;
    while(h < siz) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < siz; i++) {
            value = A[i];
            j = i;
            while (j > h-1 && value <= A[j - h]) {
                A[j] = A[j - h];
                j = j - h;
            }
            A[j] = value;
        }
        h = h/3;
    }
}



void heapsort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   while(true) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n <= 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}

// Função partição: realiza o particionamento do Quicksort
int Particao(TipoItem *A, int p, int r){
    TipoItem x,Aux;
    int i,j;
    x = A[r];
    i = p - 1;
    for(j = p; j < r; j++){
        if (A[j].Chave <= x.Chave){
            i = i + 1;
            Aux = A[i];
            A[i] = A[j];
            A[j] = Aux;
        }
    }
    Aux = A[i + 1];
    A[i + 1] = A[r];
    A[r] = Aux;
    return i + 1;
}

// Método Quicksort: função recursiva que divida o Aor em duas metades
void quicksort(int A[], int p, int r){
    int q;
    if(p < r){
        q = Particao(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}
