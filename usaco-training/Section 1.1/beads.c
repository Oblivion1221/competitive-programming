/*
ID: oblivio7
LANG: C
PROG: beads
*/


#include <stdio.h>
#include <string.h>

int total(char *s, int n)
{
    int rflag = 1, bflag = 1, tot = 0;
    for (int i = n; i >= 0; i--)
    {
        if (s[i] == 'w') tot++;
        if (s[i] == 'r' && rflag == 1) { bflag = 0; tot++; }
        if (s[i] == 'b' && bflag == 1) { rflag = 0; tot++; }
        if (s[i] == 'r' && rflag == 0)  break;
        if (s[i] == 'b' && bflag == 0)  break;
    }
    rflag = bflag = 1;
    for (int i = n + 1; i <= 2 * n; i++)
    {
        if (s[i] == 'w') tot++;
        if (s[i] == 'r' && rflag == 1) { bflag = 0; tot++; }
        if (s[i] == 'b' && bflag == 1) { rflag = 0; tot++; }
        if (s[i] == 'r' && rflag == 0)  break;
        if (s[i] == 'b' && bflag == 0)  break;
    }

    return tot;
}

int main()
{
    FILE *fin = fopen("beads.in", "r");
    FILE *fout = fopen("beads.out", "w");

    int n;
    int res = 0;
    char s[1000], tmp[1000];    // make sure the index is big enough (Runtime Error: Illegal file open (/dev/tty))
    fscanf(fin, "%d", &n);
    fscanf(fin, "%s", s);
    strcpy(tmp, s);
    strcat(s, tmp);
    // fprintf(fout, "%s", s);

    for (int i = 0; i < 2 * n; i++)
        res = res > total(s, i) ? res : total(s, i);

    fprintf(fout, "%d\n", res > n ? n : res); // Test 2: rrr

    return 0;
}