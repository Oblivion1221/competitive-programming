/*
 ID: oblivio7
 PROG: dualpal
 LANG: C
*/

#include <stdio.h>
#include <string.h>
#define MAX 500
char map[10] = {'0','1','2','3','4','5','6',
                '7','8','9'};

void cvt(char* c, int n, int base)
{
    int d = 0;
    while (n != 0)
    {
        c[d] = map[n % base];
        n /= base;
        d++;
    }
    c[d] = '\0';
}

int pal(char* c)
{
    size_t len = strlen(c);
    for (int i = 0; i < len; i++)
        if (c[i] != c[len - i - 1]) return 0;
    return 1;
}

int main()
{
    FILE* fin = fopen("dualpal.in", "r");
    FILE* fout = fopen("dualpal.out", "w");
    int n, s, cnt1 = 0;
    char c[MAX];
    fscanf(fin, "%d %d", &n, &s);
    for (int i = s + 1; cnt1 < n; i++)
    {
        int cnt2 = 0;
        for (int j = 2; j <= 10; j++)
        {
            cvt(c, i, j);
            cnt2 += pal(c);
            if (cnt2 >= 2)
            {
                fprintf(fout, "%d\n", i);
                cnt1++;
                break;
            }
        }
    }

    return 0;
}