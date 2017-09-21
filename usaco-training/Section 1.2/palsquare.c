/*
 ID: oblivio7
 PROG: palsquare
 LANG: C
*/

#include <stdio.h>
#include <string.h>
#define MAX 500
char map[20] = {'0','1','2','3','4','5','6',
                '7','8','9','A','B','C','D',
                'E','F','G','H','I','J'};

void cvt(char* b, int n, int base)
{
    int d = 0;
    while (n != 0)
    {
        b[d] = map[n % base];
        n /= base;
        d++;
    }
    b[d] = '\0';
}

int pal(char* s)
{
    size_t len = strlen(s);
    for (int i = 0; i < len; i++)
        if (s[i] != s[len - i - 1]) return 0;
    return 1;
}

int main()
{
    FILE* fin = fopen("palsquare.in", "r");
    FILE* fout = fopen("palsquare.out", "w");
    int base, square;
    char b[MAX], c[MAX];
    fscanf(fin, "%d", &base);
    for (int i = 1; i <= 300; i++)
    {
        square = i * i;
        cvt(c, i, base);
        cvt(b, square, base);
        if (pal(b))
        {
            for (size_t j = strlen(c) - 1; j > 0; j--)  // j(index) should not be negative...
                fprintf(fout, "%c", c[j]);
            fprintf(fout, "%c ", c[0]);
            for (size_t j = 0; j < strlen(b); j++)
                fprintf(fout, "%c", b[j]);
            fprintf(fout, "\n");
        }
    }

    return 0;
}
