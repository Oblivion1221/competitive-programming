//
//  uva1584.c
//  
//
//  Created by 杨曜先 on 16/3/27.
//  Copyright © 2016年 杨曜先. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define maxn 105

int less (const char * s, int p, int q)
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if(s[(p+i)%n] != s[(q+i)%n])
            return s[(p+i)%n] < s[(q+i)%n];
    }
    return 0;
}

int main(void)
{
    char s[maxn];
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        int ans = 0;
        int n = strlen(s);
        for (int i = 1; i < n; i++)
        {
            if (less(s, i, ans))
                ans = i;
        }
        for(int i = 0; i < n; i++)
            putchar(s[(i+ans)%n]);
        putchar('\n');
    }
    return 0;
}
