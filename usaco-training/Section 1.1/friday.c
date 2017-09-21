/*
ID: oblivio7 
PROG: friday
LANG: C
*/

#include <stdio.h>

int main()
{
    FILE *fin  = fopen ("friday.in", "r");  
    FILE *fout = fopen ("friday.out", "w");
    int n;
    fscanf(fin, "%d", &n);

    int day = 1;
    int cnt[7] = {0, 0, 0, 0, 0, 0, 0};
    int days_in_month1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days_in_month2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int k = 0; k < n; k++)
    {
        if ((1900 + k) % 4 != 0 || ((1900 + k) % 100 == 0 && (1900 + k) % 400 != 0))
            for (int i = 0; i < 12; i++)
                for (int j = 1; j <= days_in_month1[i]; j++)
                {
                    if (j == 13) cnt[day]++;
                    day = ++day % 7;
                }
        else
            for (int i = 0; i < 12; i++)
                for (int j = 1; j <= days_in_month2[i]; j++)
                {
                    if (j == 13) cnt[day]++;
                    day = ++day % 7;
                }
    }

    fprintf(fout, "%d ", cnt[6]);
    for (int i = 0; i < 5; i++) fprintf(fout, "%d ", cnt[i]);
    fprintf(fout, "%d\n", cnt[5]);

    return 0;
}
