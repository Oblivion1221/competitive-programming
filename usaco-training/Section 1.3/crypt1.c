/*
 ID: oblivio7
 PROG: crypt1
 LANG: C
 */

#include <stdio.h>
#include <string.h>
int hash[10];   // bit vector
int not_avail(int n)
{
    while (n)
    {
        if (!hash[n % 10]) return 1;    // check if this digit is NOT in the input;
        n /= 10;    // check the previous one;
    }

    return 0;
}

int main()
{
    FILE* fin = fopen("crypt1.in", "r");
    FILE* fout = fopen("crypt1.out", "w");
    int n, temp, res = 0;
    memset(hash, 0, sizeof(hash));
    fscanf(fin, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(fin, "%d", &temp);
        hash[temp] = 1;
    }
    for (int i = 100; i < 1000; i++)
    {
        for (int j = 10; j < 100; j++)
        {
            int m = i * j, pd = i * (j / 10), pe = i * (j % 10);
            if (m > 9999) break;
            if (pe > 999 || pe < 100 || pd > 999 || pd < 100) continue;
            if (not_avail(i) || not_avail(j) || not_avail(m) || not_avail(pe) || not_avail(pd)) continue;
            res++;
        }
    }
    fprintf(fout, "%d\n", res);

    return 0;
}