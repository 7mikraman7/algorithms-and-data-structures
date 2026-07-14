// lqueue.c
#include "lqueue.h"
#include "err.h"
#include <stdlib.h>
#include <stdio.h>

struct Node {
    PNode Next;
    TElem Elem;
};

struct LnkQueue {
    PNode Front;
    PNode Rear;
};

int IsEmptyQueue(LQueue Q) {
    if (Q == NULL) Error("IsEmptyQueue: incorrect queue!");
    return Q->Front == NULL;
}

LQueue CreateQueue(void) {
    LQueue Q = malloc(sizeof(struct LnkQueue));
    if (Q == NULL) Error("CreateQueue: out of memory!");
    Q->Front = NULL;
    Q->Rear = NULL;
    return Q;
}

void RemoveQueue(LQueue *PQ) {
    if (PQ == NULL) Error("RemoveQueue: incorrect pointer!");
    if (*PQ == NULL) return;
    LQueue Q = *PQ;
    MakeEmptyQueue(Q);
    free(Q);
    *PQ = NULL;
}

void MakeEmptyQueue(LQueue Q) {
    if (Q == NULL) Error("MakeEmptyQueue: incorrect queue!");
    PNode PFirst;
    while (!IsEmptyQueue(Q)) {
        PFirst = Q->Front;
        if (Q->Front == Q->Rear) Q->Rear = NULL;
        Q->Front = Q->Front->Next;
        free(PFirst);
    }
}

void Enqueue(TElem X, LQueue Q) {
    if (Q == NULL) Error("Enqueue: incorrect queue!");
    PNode PNew = malloc(sizeof(struct Node));
    if (PNew == NULL) Error("Enqueue: out of memory!");
    PNew->Elem = X;
    PNew->Next = NULL;
    if (IsEmptyQueue(Q)) Q->Front = PNew;
    else Q->Rear->Next = PNew;
    Q->Rear = PNew;
}

TElem Front(LQueue Q) {
    if (Q == NULL) Error("Front: incorrect queue!");
    if (IsEmptyQueue(Q)) {
        /* В скриншотах видно сообщение вида:
           Error - Front: queue empty!
           используем именно такой вывод (не завершаем программу) */
        printf("Error - Front: queue empty!\n");
        return 0;
    }
    return Q->Front->Elem;
}

void Dequeue(LQueue Q) {
    if (Q == NULL) Error("Dequeue: incorrect queue!");
    if (IsEmptyQueue(Q)) {
        /* в скриншотах сначала печатают "Dequeue: empty queue" */
        printf("empty queue");
        return;
    }
    PNode PFirst = Q->Front;
    Q->Front = Q->Front->Next;
    if (Q->Front == NULL) Q->Rear = NULL;
    free(PFirst);
}

TElem FrontAndDequeue(LQueue Q) {
    if (Q == NULL) Error("FrontAndDequeue: incorrect queue!");
    if (IsEmptyQueue(Q)) {
        printf("Error - FrontAndDequeue: queue empty!\n");
        return 0;
    }
    TElem X = Q->Front->Elem;
    Dequeue(Q);
    return X;
}

void PrintQueue(LQueue Q) {
    if (Q == NULL) Error("PrintQueue: incorrect queue!");
    if (IsEmptyQueue(Q)) {
        printf("Empty queue");
        return;
    }
    PNode PTmp = Q->Front;
    while (PTmp != NULL) {
        printf("%d ", PTmp->Elem);
        PTmp = PTmp->Next;
    }
}
