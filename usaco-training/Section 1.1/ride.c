/* 
ID: oblivio7 
PROG: ride 
LANG: C
*/

#include <stdio.h>
#define MAX 50

int main()
{
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    
    char str1[MAX], str2[MAX];
    int tot1 = 1, tot2 = 1;
    fscanf(fin, "%s %s", str1, str2);
    
    for (int i = 0; str1[i] != '\0'; i++)
        tot1 *= str1[i] - 'A' + 1;
    for (int i = 0; str2[i] != '\0'; i++)
        tot2 *= str2[i] - 'A' + 1;
    
    if (tot1 % 47 == tot2 % 47)
        fprintf (fout, "GO\n");
    else
        fprintf (fout, "STAY\n");

    return 0;
}
