//
//  uva227.c
//  puzzle
//
//  Created by 杨曜先 on 16/4/17.
//  Copyright © 2016年 杨曜先. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX 5
char maps[MAX][MAX];
char cmd[10001];

int main()
{
    int kase = 0;
    while (gets(maps[0]))
    {
        int x = 0, y = 0;
        int blank_x = 0, blank_y = 0;
        if (maps[0][0] == 'Z') break;
        for (int i = 1; i < MAX; i++)
            gets(maps[i]);
        
        for (int x = 0; x < MAX; x++)
        {
            for (int y = 0; y < MAX; y++)
                if (maps[x][y] == ' ')
                {
                    blank_x = x;
                    blank_y = y;
                    break;
                }
        }
        
        int cnt = 0;
        while (scanf("%c", &cmd[cnt]))
        {
            if (cmd[cnt] != '0') cnt++;
            else break;
        }
        cmd[cnt] = 0; //数组终止于0
        getchar(); //解决'\n'
        
        int flag = 0;
        for (int i = 0; cmd[i]; i++)
        {
            switch (cmd[i])
            {
                case 'A': x = blank_x-1; y = blank_y; break;
                case 'B': x = blank_x+1; y = blank_y; break;
                case 'L': x = blank_x; y = blank_y-1; break;
                case 'R': x = blank_x; y = blank_y+1; break;
            }
        
        
            if (x > 4 || x < 0 || y > 4 || y < 0)
            {
                flag = 1;
                break;
            }
            else
            {
                maps[blank_x][blank_y] = maps[x][y];
                maps[x][y] = ' ';
                blank_x = x; blank_y = y;
            }
        }
        
        if (kase++) putchar('\n');
        printf("Puzzle #%d:\n", kase);
        if (flag) printf("This puzzle has no final configuration.\n");
        else
        {
            for (int i = 0; i < MAX; i++)
            {
                for (int j = 0; j < MAX; j++)
                {
                    if (j) putchar(' ');
                    printf("%c", maps[i][j]);
                }
                putchar('\n');
            }
        }
    }
    return 0;
}
