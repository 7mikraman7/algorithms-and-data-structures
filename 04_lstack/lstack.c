// SS 2019, KPI FEI TUKE

#include "lstack.h"
#include "err.h"
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    PNode Next;
    TElem Elem;
};

struct LnkStack
{
    PNode First;
    PNode Last;
};

int IsEmptyStack(LStack S)
{
    if (S == NULL) Error("IsEmptyStack: incorrect stack!");
    return S->First == NULL;
}

LStack CreateStack(void)
{
    LStack S;
    S = malloc(sizeof(struct LnkStack));
    if (S == NULL) Error("CreateStack: out of memory!");
    S->First = NULL;
    S->Last = NULL;
    return S;
}

void RemoveStack(LStack *PS)
{
    if (PS == NULL) Error("RemoveStack: incorrect pointer!");
    if (*PS == NULL) return;
    LStack S = *PS;
    MakeEmptyStack(S);
    free(S);
    *PS = NULL;
}

void MakeEmptyStack(LStack S)
{
    if (S == NULL) Error("MakeEmptyStack: incorrect stack!");
    PNode PTop;
    while (!IsEmptyStack(S))
    {
        PTop = S->First;
        if (S->First == S->Last) S->Last = NULL;
        S->First = S->First->Next;
        free(PTop);
    }
}

void Push(TElem X, LStack S)
{
    PNode PNew;
    if (S == NULL) Error("Push: incorrect stack!");
    PNew = malloc(sizeof(struct Node));
    if (PNew == NULL) Error("Push: out of memory!");
    PNew->Elem = X;
    PNew->Next = S->First;
    if (IsEmptyStack(S)) S->Last = PNew;
    S->First = PNew;
}

void PrintStack(LStack S)
{
    if (S == NULL) Error("PrintStack: incorrect stack!");
    if (IsEmptyStack(S)) printf("empty stack");
    else
    {
        PNode PTmp = S->First;
        printf("Top> ");
        while (PTmp != NULL)
        {
            printf("%d ", PTmp->Elem);
            PTmp = PTmp->Next;
        }
    }
}

// === New functions ===

TElem Top(LStack S)
{
    if (S == NULL) Error("Top: incorrect stack!");
    if (IsEmptyStack(S))
    {
        Error("Top: stack empty!");
        return 0;
    }
    return S->First->Elem;
}

void Pop(LStack S)
{
    if (S == NULL) Error("Pop: incorrect stack!");
    if (IsEmptyStack(S))
    {
        printf("Pop: empty stack\n");
        return;
    }

    PNode PTop = S->First;
    S->First = S->First->Next;
    if (S->First == NULL) S->Last = NULL;
    free(PTop);
}

TElem TopAndPop(LStack S)
{
    if (S == NULL) Error("TopAndPop: incorrect stack!");
    if (IsEmptyStack(S))
    {
        Error("TopAndPop: stack empty!");
        return 0;
    }

    TElem X = S->First->Elem;
    PNode PTop = S->First;
    S->First = S->First->Next;
    if (S->First == NULL) S->Last = NULL;
    free(PTop);
    return X;
}
