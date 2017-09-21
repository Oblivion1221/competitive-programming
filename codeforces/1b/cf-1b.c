#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 50

void rc_ab(int n)
{
    if (n > 0)
    {
        rc_ab((n - 1)/ 26);
        printf("%c", 'A' + (n - 1) % 26);
    }
}

// int ab_rc(char str[], char c)
// {
//     int i = 0, res = 1;
//     if (c)
//     {
//         c = c - 'A' + 1;
//         res = ab_rc(str, str[++i]);
//         res *= 26;
//     }
//     return res;
// }

int ab_rc(char s[])
{
    int res = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        res *= 26;  // (a * 26 + b) * 26 == a * 26^2 + b * 26
        res += s[i] - 'A' + 1;
    }

    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        char s[MAX];
        scanf("%s", s);
        int row, col, i;
        char col_arr[MAX];
        char row_arr[MAX];

        if (sscanf(s, "R%dC%d", &row, &col) == 2)
        {
            rc_ab(col);
            printf("%d\n", row);
        }
        else
        {
            // for (i = 0; i < strlen(s); i++)
            // {
            //     int br = 0;
            //     if (isalpha(s[i]))
            //         br++;
            //     if (br == 0)
            //         col_arr[i] = s[i];
            //     else
            //         row_arr[i - strlen(col_arr)] = s[i];
            // }
            for(i = 0; s[i] > '9'; i++);
            sscanf(s + i, "%d", &row);
            s[i] = '\0';
            col = ab_rc(s);
            printf("R%dC%d\n", row, col);
        }
    }

    return 0;
}
