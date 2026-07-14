#include <stdio.h>
#include "lqueue.h"

void RadixSort(char* A[], int n, int k) {
    char* B[10][n];
    int pocB[10];
    int x, y;
    int i, j;

    for (i = 0; i < 10; i++)
        pocB[i] = 0;

    for (j = k - 1; j >= 0; j--) {

        for (i = 0; i < n; i++) {
            x = A[i][j] - '0';
            B[x][pocB[x]++] = A[i];
        }

        for (y = 0, x = 0; x < 10; x++) {
            for (i = 0; i < pocB[x]; i++)
                A[y++] = B[x][i];

            pocB[x] = 0;
        }
    }
}

void RadixSortQueue(char* A[], int n, int k) {
    LQueue mainQ;
    LQueue buckets[10];
    TElem e;

    int i, pos, digit;

    mainQ = CreateQueue();

    for (i = 0; i < 10; i++)
        buckets[i] = CreateQueue();

    for (i = 0; i < n; i++)
        Enqueue(A[i], mainQ);

    for (pos = k - 1; pos >= 0; pos--) {

        for (;;) {
            if (IsEmptyQueue(mainQ))
                break;

            e = FrontAndDequeue(mainQ);
            digit = e[pos] - '0';
            Enqueue(e, buckets[digit]);
        }

        for (digit = 0; digit < 10; digit++) {

            while (!IsEmptyQueue(buckets[digit])) {
                e = FrontAndDequeue(buckets[digit]);
                Enqueue(e, mainQ);
            }
        }

        PrintQueue(mainQ);
        printf("\n");
    }

    i = 0;
    while (!IsEmptyQueue(mainQ)) {
        e = FrontAndDequeue(mainQ);
        A[i++] = e;
    }
}
