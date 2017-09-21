/*
ID: oblivio7 
PROG: gift1
LANG: C
*/

#include <stdio.h>
#include <string.h>
#define MAX 15
typedef struct {
    char name[MAX];
    int money;
}Person;

int main()
{
    FILE *fin  = fopen ("gift1.in", "r");  
    FILE *fout = fopen ("gift1.out", "w");

    int NP;
    fscanf(fin, "%d", &NP);
    Person p[NP];
    for (int i = 0; i < NP; i++)
    {
        fscanf(fin, "%s", p[i].name);
        p[i].money = 0;
    }

    char p_tmp[MAX];
    int money_give, p_num;
    for (int i = 0; i < NP; i++)
    {
        fscanf(fin, "%s", p_tmp);
        fscanf(fin, "%d %d", &money_give, &p_num);
        if (p_num)  // this line could not be removed: float point exception(line 40)
        {
            for (int l = 0; l < NP; l++)    // 1st input may not be 1st person
                if (strcmp(p_tmp, p[l].name) == 0)
                {
                    p[l].money -= money_give - money_give % p_num; // here: cannot divide 0
                    break;
                }
            for (int j = 0; j < p_num; j++)
            {
                fscanf(fin, "%s", p_tmp);
                if (money_give) // this line could be removed
                    for (int k = 0; k < NP; k++)
                        if (strcmp(p_tmp, p[k].name) == 0)
                        {
                            p[k].money += money_give / p_num;
                            break;
                        }
            }
        }
    }

    for (int i = 0; i < NP; i++)
        fprintf(fout, "%s %d\n", p[i].name, p[i].money);

    return 0;
}