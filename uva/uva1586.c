//
//  uva1586.c
//  molarmass
//
//  Created by 杨曜先 on 16/4/9.
//  Copyright © 2016年 杨曜先. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 90
char s[MAX];
double tot = 0.00;
int ans;

void get_num(char c)
{
    switch(c)
    {
        case 'C':
            tot += ans*12.01;
            break;
        case 'H':
            tot += ans*1.008;
            break;
        case 'O':
            tot += ans*16.00;
            break;
        case 'N':
            tot += ans*14.01;
            break;
    }
}

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        tot = 0;
        scanf("%s", s);
        for (int i = 0; i < (int)strlen(s); i++)
        {
            if(isdigit(s[i]))
            {
                if(isdigit(s[i+1]) && s[i+1] != '\0')
                {
                    ans = (s[i]-'0')*10 + (s[i+1]-'0') - 1;
                    get_num(s[i-1]);
                }
                else if(isdigit(s[i-1]))
                    continue;
                else
                {
                    ans = (s[i]-'0') - 1;
                    get_num(s[i-1]);
                }
            }
            else
            {
                ans = 1;
                get_num(s[i]);
            }
        }
        printf("%.3lf\n", tot);
    }
    return 0;
}