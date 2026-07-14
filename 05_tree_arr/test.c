#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree_arr.h"
#include "err.h"

int main()
{
    Tree T;
    int maxlevel, level, index;
    int i;

    printf("\nEnter max. level of a tree (1...n): ");
    if (scanf("%d", &maxlevel) != 1)
        Error("Enter Number 1...n!");

    T = CreateTree(maxlevel);

    for (i = 1; i < pow(2, maxlevel + 1); i++)
    {
        Insert(T, i, 4 + i);
        printf("Inserting: element %02d at index [%d]\n", 4 + i, i);
    }

    printf("\nBinary tree:\n");
    PrintTree(T);

    printf("\n(PrintRow) Enter binary tree level: ");
    if (scanf("%d", &level) != 1)
        Error("Wrong input!");
    putchar(' ');
    PrintRow(T, level);

    printf("\n(PrintSubtree) Enter the root (index) of subtree: ");
    if (scanf("%d", &index) != 1)
        Error("Wrong input!");
    putchar(' ');
    PrintSubtree(T, index);

    DisposeTree(T);
    return 0;
}
