#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmos_ordenacao.h"

int main()
{
    int  n = 100000;
   int i, num[n];


    srand (time(NULL));

    for (i = 0;i<n; i++){
        num[i] = rand();
    }

    quicksort(num,0,n-1);

    printf("\n\n");

    for(i = 0;i<n;i++){
        printf("%d ",num[i]);
    }
    printf("\n");


    return 0;
}
