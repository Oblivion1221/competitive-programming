//
//  uva1585.c
//  score
//
//  Created by 杨曜先 on 16/4/8.
//  Copyright © 2016年 杨曜先. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX 90
int T;
char s[MAX];
int main()
{
    int O = 1;
    scanf("%d", &T);
    while(T--)
    {
        int tot = 0;
        O = 1;
        scanf("%s", s);
        for (int i = 0; s[i] != '\0'; i++)
        {
            if(s[i] == 'O')
                tot += O++;
            else
                O = 1;
        }
        printf("%d\n", tot);
    }
    
    return 0;
}