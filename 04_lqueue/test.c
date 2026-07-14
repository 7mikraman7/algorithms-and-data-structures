// test.c
#include <stdio.h>
#include "lqueue.h"

int main(void) {
    /* === ПЕРВЫЙ БЛОК: демонстрация операций над Q1 и Q2 === */
    printf("\nADT Queue\n\n");

    LQueue Q1 = CreateQueue();
    LQueue Q2 = CreateQueue();

    /* Dequeue из пустой очереди (печать как в примере) */
    printf("Dequeue: ");
    Dequeue(Q1);            /* Dequeue prints "empty queue" when empty */
    printf("\n\n");

    /* Enqueue 1..5 в Q1 и Q2 (и печать записи) */
    printf("Enqueue: ");
    for (int i = 1; i <= 5; ++i) {
        printf("Enqueue %d ", i);
        Enqueue(i, Q1);
        Enqueue(i, Q2);
    }
    printf("\n");

    /* Front: печатаем именно метку как в скриншоте */
    printf("Front: [Front(Q1)]\n");
    /* Скриншот показывает три подряд вызова Front, поэтому повторяем */
    printf("%d %d %d\n", Front(Q1), Front(Q1), Front(Q1));

    /* FrontAndDequeue: показываем метку, потом выводим элементы, которые вынимаются */
    printf("FrontAndDequeue: [FrontAndDequeue(Q1)]\n");
    /* Скриншот показывает 4 значения после FrontAndDequeue */
    for (int i = 0; i < 4; ++i) {
        printf("%d ", FrontAndDequeue(Q1));
    }
    printf("\n");

    /* После 4 удалений в очереди должен остаться последний элемент (5) */
    if (!IsEmptyQueue(Q1)) {
        printf("Q1 not empty %d\n", Front(Q1));
    } else {
        printf("Q1 empty\n");
    }

    /* Делает очередь пустой и проверяет */
    MakeEmptyQueue(Q1);
    printf("Q1 empty\n");

    /* MakeEmptyQueue демонстрация для Q2: сначала показать содержимое, затем очистить */
    printf("MakeEmptyQueue:\n");
    if (!IsEmptyQueue(Q2)) {
        printf("Q2 not empty ");
        PrintQueue(Q2);
        printf("\n");
    } else {
        printf("Q2 empty\n");
    }

    MakeEmptyQueue(Q2);
    if (IsEmptyQueue(Q2)) {
        printf("Q2 empty ");
        PrintQueue(Q2); /* PrintQueue when empty prints "Empty queue" */
        printf("\n");
    }
    printf("\n");

    /* === ВТОРОЙ БЛОК: повторный пример — проверка Front над пустым фронтом === */
    printf("ADT Queue\n\n");

    LQueue Q3 = CreateQueue();

    printf("Dequeue: ");
    Dequeue(Q3);  /* empty queue */
    printf("\n\n");

    printf("Enqueue: ");
    for (int i = 1; i <= 5; ++i) {
        printf("Enqueue %d ", i);
        Enqueue(i, Q3);
    }
    printf("\n");

    printf("Front: [Front(Q1)]\n");
    /* в примере вызывают Front несколько раз: показываем три раза как раньше */
    printf("%d %d %d\n", Front(Q3), Front(Q3), Front(Q3));
    printf("\n");

    /* теперь очищаем и демонстрируем Front на пустой очереди */
    MakeEmptyQueue(Q3);
    printf("Q1 empty\n");
    printf("Front: [Front(Q1)]\n");
    /* вызов Front на пустой очереди должен показать сообщение об ошибке (не выходя) */
    Front(Q3);

    /* cleanup */
    RemoveQueue(&Q1);
    RemoveQueue(&Q2);
    RemoveQueue(&Q3);

    printf("\n");
    return 0;
}
