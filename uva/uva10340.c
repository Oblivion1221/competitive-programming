//
//  main.c
//  allinall
//
//  Created by 杨曜先 on 16/5/25.
//  Copyright © 2016年 杨曜先. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    bool flag = 1;
    char s[1001], t[1001];
    while (scanf("%s", s) != EOF)
    {
        scanf("%s", t);
        int slen = (int)strlen(s), tlen = (int)strlen(t);
        if (slen > tlen)
            flag = 0;
        else
        {
            
        }
    }
    return 0;
}