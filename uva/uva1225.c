//
//  uva1225.c
//  digit_counting
//
//  Created by 杨曜先 on 16/4/10.
//  Copyright © 2016年 杨曜先. All rights reserved.

#include <stdio.h>
#include <string.h>
#define MAX 10
int r[MAX];

int main(void)
{
    int T;
    int N;
    scanf("%d", &T);
    while (T--)
    {
        memset(r, 0, sizeof(r));
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
        {
            int x = i, y;
            while (x > 0)
            {
                y = x % 10;
                r[y]++;
                x /= 10;
            }
        }
        for (int i = 0; i < MAX; i++)
        {
            if(i) printf(" ");
            printf("%d", r[i]);
        }
        putchar('\n');
    }

    return 0;
}