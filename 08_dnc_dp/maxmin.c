#include "maxmin.h"

#ifndef MAX
#define MAX(a,b) ((a)>(b)?a:b)
#endif
#ifndef MIN
#define MIN(a,b) ((a)<(b)?a:b)
#endif

pair MaxMin(int A[], int L, int H)
{
    pair ret1, ret2, ret;
    ret.min = A[L];
    ret.max = A[L];

    // Один элемент
    if (L == H) {
        ret.min = A[L];
        ret.max = A[L];
        return ret;
    }

    // Два элемента
    if (H == L + 1) {
        if (A[L] > A[H]) {
            ret.max = A[L];
            ret.min = A[H];
        } else {
            ret.max = A[H];
            ret.min = A[L];
        }
        return ret;
    }

    // Рекурсивное деление
    int mid = (L + H) / 2;
    ret1 = MaxMin(A, L, mid);
    ret2 = MaxMin(A, mid + 1, H);

    // Объединение результатов
    ret.max = MAX(ret1.max, ret2.max);
    ret.min = MIN(ret1.min, ret2.min);

    return ret;
}
