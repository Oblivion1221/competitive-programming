/*
 ID: oblivio7
 PROG: milk
 LANG: C
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 5010
typedef struct {
    int price;
    int unit;
}FType;

int cmp(const void* a, const void* b)
{
    FType* fa = (FType*) a;
    FType* fb = (FType*) b;
    if (fa -> price == fb -> price) return 0;
    return fa -> price > fb -> price ? 1 : -1;
}

int main()
{
    FILE* fin = fopen("milk.in", "r");
    FILE* fout = fopen("milk.out", "w");

    int n, m, res = 0;
    fscanf(fin, "%d %d", &n, &m);
    FType Farmer[MAX];
    for (int i = 0; i < m; i++)
        fscanf(fin, "%d %d", &Farmer[i].price, &Farmer[i].unit);
    qsort(Farmer, (size_t)m, sizeof(Farmer[0]), cmp);
    for (int i = 0; i < m; i++)
        if (n - Farmer[i].unit > 0)
        {
            res += Farmer[i].price * Farmer[i].unit;
            n -= Farmer[i].unit;
        }
        else
        {
            res += Farmer[i].price * n;
            break;
        }
    fprintf(fout, "%d\n", res);

    return 0;
}
