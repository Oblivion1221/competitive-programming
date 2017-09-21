/*
 ID: oblivio7
 PROG: barn1
 LANG: C
 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    int* ia = (int*) a;
    int* ib = (int*) b;
    if (*ia == *ib) return 0;
    return *ia > *ib ? -1 : 1;  // descending sort
}

int main()
{
    FILE* fin = fopen("barn1.in", "r");
    FILE* fout = fopen("barn1.out", "w");
    int m, s, c, res = 0;
    fscanf(fin, "%d %d %d", &m, &s, &c);

    if (m >= c)
    {
        fprintf(fout, "%d\n", c);
        return 0;
    }

    int stall_num[c], diff[c - 1];
    for (int i = 0; i < c; i++)
        fscanf(fin, "%d", &stall_num[i]);

    qsort(stall_num, (size_t)c, sizeof(stall_num[0]), cmp);
    for (int i = 1; i <= c; i++)
        diff[i - 1] = stall_num[i - 1] - stall_num[i];

//    for (int i = 0; i < c - 1; i++)
//        printf("%d ", diff[i]);
//    putchar('\n');

    qsort(diff, (size_t)c - 1, sizeof(diff[0]), cmp);

//    for (int i = 0; i < c - 1; i++)
//        printf("%d ", diff[i]);

    res = stall_num[0] - stall_num[c - 1] + m;
    for (int i = 0; i < m - 1; i++)
        res -= diff[i];
    fprintf(fout, "%d\n", res);

    return 0;
}