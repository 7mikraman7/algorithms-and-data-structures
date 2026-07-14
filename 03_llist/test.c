#include <stdio.h>
#include "llist.h"

int main(void)
{
    LList L0, L1, L2, Ltmp;
    PNode P;
    int i;

    /* create lists */
    L0 = MakeEmpty(NULL);
    L1 = MakeEmpty(NULL);
    L2 = MakeEmpty(NULL);

    /* L0: InsertBeg 0..9 -> becomes 9 8 ... 0 */
    for(i = 0; i < 10; i++) InsertBeg(i, L0);

    /* L1: InsertEnd 0..9 -> 0 1 ... 9 */
    for(i = 0; i < 10; i++) InsertEnd(i, L1);

    printf("FreshCat: [L2 = FreshCat(L0,L1)]\n");
    printf("L0: ");
    PrintList(L0);
    printf("\n");
    printf("L1: ");
    PrintList(L1);
    printf("\n");
    printf("L2: ");
    PrintList(L2); /* currently empty */
    printf("\n");

    /* create L2 as fresh concatenation */
    L2 = FreshCat(L0, L1);

    /* print originals and result */
    printf("L0: ");
    PrintList(L0);
    printf("\n");
    printf("L1: ");
    PrintList(L1);
    printf("\n");
    printf("L2: ");
    PrintList(L2);
    printf("\n\n");

    /* FastCat: append L1 onto L0 (L1 becomes empty) */
    printf("FastCat: [FastCat(L0,L1)]\n");
    printf("L0: ");
    PrintList(L0);
    printf("\n");
    printf("L1: ");
    PrintList(L1);
    printf("\n");

    FastCat(L0, L1);

    printf("L0: ");
    PrintList(L0);
    printf("\n");
    printf("L1: ");
    PrintList(L1);
    printf("\n\n");

    /* Cut: L1 = Cut(L2, P) where P points to element 5 in L2
       before cut L1 (variable) is empty (from FastCat) - we show that */
    printf("Cut: [L1 = Cut(L2,P)]\n");
    printf("L1: ");
    PrintList(L1);
    printf("\n");
    printf("L2: ");
    PrintList(L2);
    printf("\n");

    P = Member(5, L2); /* find first '5' in L2 */
    Ltmp = Cut(L2, P); /* Ltmp will be the right part (assigned to L1 in task) */

    /* assign to L1 as in the example */
    RemoveList(&L1); /* ensure L1 is empty pointer before assigning */
    L1 = Ltmp;

    printf("L1: ");
    PrintList(L1);
    printf("\n");

    /* cleanup */
    RemoveList(&L0);
    RemoveList(&L1);
    RemoveList(&L2);

    return 0;
}
