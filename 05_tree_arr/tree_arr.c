#include "err.h"
#include "tree_arr.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

struct TreeRecord
{
    int MaxLevel;
    int *Array;
};

Tree CreateTree(int MaxLevel)
{
    Tree T = malloc(sizeof(struct TreeRecord));
    if (T == NULL) Error("Out of space!!!");
    T->Array = malloc((1 << (MaxLevel + 1)) * sizeof(int)); // 2^(MaxLevel+1)
    if (T->Array == NULL) Error("Out of space!!!");
    T->MaxLevel = MaxLevel;
    MakeEmpty(T);
    return T;
}

void MakeEmpty(Tree T)
{
    if (T == NULL) Error("No tree!");
    int size = 1 << (T->MaxLevel + 1);
    for (int i = 0; i < size; i++)
        T->Array[i] = 0;
}

void Insert(Tree T, int Index, int Elem)
{
    if (T == NULL) Error("No tree!");
    int size = (1 << (T->MaxLevel + 1)) - 1;
    if (Index < 1 || Index > size) Error("Bad index!");
    T->Array[Index] = Elem;
}

void DisposeTree(Tree T)
{
    if (T)
    {
        free(T->Array);
        free(T);
    }
}

void PrintSpaces(int Count)
{
    while (Count-- > 0) putchar(' ');
}

void PrintTree(Tree T)
{
    if (T == NULL) Error("No tree!");
    int m = 4 * (1 << T->MaxLevel);
    int k = 1;

    for (int i = 1; i <= T->MaxLevel + 1; i++)
    {
        int n = 1 << (i - 1);
        for (int j = 0; j < n; j++)
        {
            int l = (m - 2 * n) / n;
            if (j == 0) PrintSpaces(l - (l / 2));
            else PrintSpaces(l);
            printf("%02d", T->Array[k++]);
        }
        putchar('\n');
    }
}

void PrintRow(Tree T, int Level)
{
    if (T == NULL) Error("No tree!");
    if (Level < 1 || Level > T->MaxLevel + 1) Error("Wrong level!");

    int start = 1 << (Level - 1);
    int end = (1 << Level) - 1;

    for (int i = start; i <= end; i++)
        if (T->Array[i] != 0)
            printf("%02d ", T->Array[i]);
    putchar('\n');
}

void PrintSubtree(Tree T, int Index)
{
    if (T == NULL) Error("No tree!");
    int total = (1 << (T->MaxLevel + 1)) - 1;
    if (Index < 1 || Index > total) Error("Wrong index!");

    int *queue = malloc((total + 1) * sizeof(int));
    if (queue == NULL) Error("Out of space!");

    int front = 0, rear = 0;
    queue[rear++] = Index;

    while (front < rear)
    {
        int node = queue[front++];
        if (node > total) continue;

        if (T->Array[node] != 0)
            printf("%02d ", T->Array[node]);

        int left = node * 2;
        int right = node * 2 + 1;

        if (left <= total && T->Array[left] != 0)
            queue[rear++] = left;
        if (right <= total && T->Array[right] != 0)
            queue[rear++] = right;
    }

    free(queue);
    putchar('\n');
}

void MyPrintf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    vprintf(format, ap);
    va_end(ap);
}
