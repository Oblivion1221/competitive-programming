//
//  uva232.cpp
//  CrosswordAnswers
//
//  Created by 杨曜先 on 16/4/23.
//  Copyright © 2016年 杨曜先. All rights reserved.
//

#include <stdio.h>
#define MAX 15
char maps[MAX][MAX];
int nums[MAX][MAX];
int main()
{
    int r, c;
    int kase = 0;
    while (scanf("%d", &r) && r)
    {
        scanf("%d", &c);
        int cnt = 1;
        for (int i = 0; i < r; i++)
        {
            scanf("%s", maps[i]);
            for (int j = 0; j < c; j++)
                if ((i-1<0 || j-1<0 || maps[i-1][j] == '*' || maps[i][j-1] == '*') && maps[i][j] != '*')
                    nums[i][j] = cnt++;
        }
        if (kase++) printf("\n");
        printf("puzzle #%d:\nAcross\n", kase);
        
        for (int i = 0; i < r; i++)
        {
            bool flag = true;
            for (int j = 0; j < c; j++)
                if (maps[i][j] != '*')
                {
                    if (flag)
                        printf("%3d.", nums[i][j]);
                    printf("%c", maps[i][j]);
                    flag = false;
                }
                else
                {
                    if (!flag)
                    {
                        printf("\n");
                        flag = !flag;
                    }
                }
            if (!flag) printf("\n");
        }
        printf("Down\n");
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (maps[i][j] == '*' || ((i) && maps[i-1][j] != '*'))
                    continue;
                bool flag = true;
                for (int x = i; x < r; x++)
                    if (maps[x][j] != '*')
                    {
                        if (flag)
                            printf("%3d.", nums[x][j]);
                        printf("%c", maps[x][j]);
                        flag = false;
                    }
                    else
                    {
                        if (!flag)
                        {
                            printf("\n");
                            flag = !flag;
                            break;
                        }
                    }
                if (!flag) printf("\n");
            }
        }
    }
    return 0;
}