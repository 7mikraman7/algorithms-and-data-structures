#include <limits.h>
#include "matrix.h"

int chainMatrixMultiplication(int *r, int n)
{
    int m[n+1][n+1];
    int i, j, k, L, q;

    // Главная диагональ = 0 (оставляем как было)
    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    // Длина цепочки L = 2..n
    for (L = 2; L <= n; L++)
    {
        for (i = 1; i <= n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;

            // Перебор возможных разрезов
            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + r[i - 1] * r[k] * r[j];

                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n];
}
