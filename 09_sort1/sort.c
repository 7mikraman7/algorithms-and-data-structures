#include <stdio.h>
#include "sort.h"

void PrintArray(int a[], int n, int prechod);

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void PrintArray(int a[], int n, int prechod){
	int j;
	for( j=1; j<=n; j++)printf("%2d ",a[j]);
	printf("\n");
}

void bubbleSort(int a[], int n, int dir){
    for(int i = 1; i <= n; i++){
        for(int j = n; j >= i + 1; j--){
            if ((dir == 1 && a[j-1] > a[j]) || (dir == -1 && a[j-1] < a[j]))
                swap(&a[j-1], &a[j]);
        }
        PrintArray(a, n, i);
    }
}


void insertSort(int *A, int n, int dir){
    for(int i = 2; i <= n; i++){
        int value = A[i];
        int j = i - 1;

        while (j >= 1 &&
              ((dir == 1 && A[j] > value) || (dir == -1 && A[j] < value)))
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = value;

        PrintArray(A, n, i);
    }
}


void selectionSort(int a[], int n, int dir){
    for(int i = 1; i <= n - 1; i++){
        int idx = i;

        for(int j = i + 1; j <= n; j++){
            if ((dir == 1 && a[j] < a[idx]) || (dir == -1 && a[j] > a[idx]))
                idx = j;
        }

        swap(&a[i], &a[idx]);
        PrintArray(a, n, i);
    }
}

