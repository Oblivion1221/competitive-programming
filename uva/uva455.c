//
//  uva455.c
//  periodicstr
//
//  Created by 杨曜先 on 16/4/16.
//  Copyright © 2016年 杨曜先. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX 85
char s[MAX];

int OK (char *s, int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = i; j < b; j+=a)
        {
            if (s[j] != s[i])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int N;
    scanf("%d", &N);
    while (N--)
    {
        int k = 0;
        scanf("\n%s", s);
        int len = (int)strlen(s);
        for (int i = 1; i <= len; ++i)
        {
            if (len % i == 0) //Crucial Part!
            {
                if (OK(s, i, len))
                {
                    k = i;
                    break;
                }
            }
        }
        if (N == 0) printf("%d\n", k);
        else printf("%d\n\n", k);
    }
    return 0;
}