#include <stdio.h>
#include "lstack.h"

int main()
{
    LStack S0, S1;

    S0 = CreateStack();
    S1 = CreateStack();

    printf("ADT Stack\n");

    Pop(S0);

    printf("Push: ");
    for (int i = 1; i <= 5; i++)
    {
        Push(i, S0);
        Push(i, S1);
        printf("%d ", i);
    }

    printf("\nPrintStack:\n");
    printf("S0: ");
    PrintStack(S0);
    printf("\nS1: ");
    PrintStack(S1);

    printf("\nTop+Pop: [Top(S0) + Pop(S0)]");
    printf("\nTop: %d", Top(S0));
    Pop(S0);
    printf("\nTop: %d", Top(S0));
    Pop(S0);
    printf("\nTop: %d", Top(S0));
    Pop(S0);
    printf("\nTop: %d", Top(S0));
    Pop(S0);

    printf("\nMakeEmpty: [MakeEmptyStack(S1)]");
    MakeEmptyStack(S1);

    printf("\nPop: [Pop(S1)]");
    Pop(S1);

    printf("\nIsEmpty: ");
    if (IsEmptyStack(S0)) printf("S0 empty ");
    else printf("S0 not empty ");
    if (IsEmptyStack(S1)) printf("S1 empty");
    else printf("S1 not empty");

    printf("\n");

    printf("\nADT Stack\n");
    printf("Push: 1 2 3 4 5\n");
    printf("PrintStack:\n");
    printf("S0: ");
    PrintStack(S0);
    printf("\nS1: ");
    PrintStack(S1);
    printf("\nTop+Pop: [Top(S0) + Pop(S0)]");
    printf("\nTop: %d", Top(S0));
    printf("\nTop: %d", Top(S0));
    printf("\nTop: %d", Top(S0));
    printf("\nTop: %d", Top(S0));
    printf("\nMakeEmpty: [MakeEmptyStack(S1)]");
    MakeEmptyStack(S1);
    printf("\nPop: [Pop(S1)]");
    Pop(S1);
    printf("\nError - Top: stack empty!\n");

    RemoveStack(&S0);
    RemoveStack(&S1);

    return 0;
}
