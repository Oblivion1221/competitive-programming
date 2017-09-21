//
//  uva1368.c
//  DNAconsensusstring
//
//  Created by 杨曜先 on 16/4/30.
//  Copyright © 2016年 杨曜先. All rights reserved.
//

#include <stdio.h>
#define max1 60
#define max2 1010
char dna[max1][max2];

int imax (int a, int b, int c, int d)
{
    int e;
    e = (a>b?a:b)>c?(a>b?a:b):c;
    return e>d?e:d;
}

void count (int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        int t = 0, g = 0, a = 0, c = 0;
        for (int j = 0; j < m; j++)
        {
            switch (dna[j][i])
            {
                case 'A': a++; break;
                case 'G': g++; break;
                case 'T': t++; break;
                case 'C': c++; break;
            }
        }
        int x = imax(a,g,t,c);
        if (a==x) printf("%c", 'A');
        else if (g==x) printf("%c", 'G');
        else if (t==x) printf("%c", 'T');
        else if (c==x) printf("%c", 'C');
    }
    putchar('\n');
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int m, n;
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; i++)
            scanf("%s", dna[i]);
        count(m, n);
    }
    return 0;
}