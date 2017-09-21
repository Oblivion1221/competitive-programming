/*
 ID: oblivio7
 LANG: C
 PROG: milk2
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
}Time;

int cmp(const void *m1, const void *m2)
{
    Time * m = (Time *) m1;
    Time * n = (Time *) m2;
    if (m -> start == n -> start)
    {
        if (m -> end == n -> end) return 0;
        return m -> end < n -> end ? -1 : 1;
    }
    return m -> start < n -> start ? -1 : 1;
}

int main()
{
//    FILE *fin = fopen("milk2.in", "r");
//    FILE *fout = fopen("milk2.out", "w");

    int n;
    scanf("%d", &n);
    Time t[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &t[i].start, &t[i].end);
    qsort(t, (size_t)n, sizeof(t[0]), cmp);
    int last = 0, idle = 0, tmp;
    Time current = t[0];
    for (int i = 1; i < n; i++)
    {
        if (current.end < t[i].start)
        {
            tmp = t[i].start - current.end;
            if (tmp > idle)
                idle = tmp;
            tmp = current.end - current.start;
            if(tmp > last)
                last = tmp;
            current = t[i];
        }
        else if (current.end < t[i].end)
            current.end = t[i].end;
    }

    tmp = current.end - current.start;
    if (tmp > last)
        last = tmp;

    printf("%d %d\n", last, idle);

    return 0;
}

//  Wrong Solution:
//    long last = 0, idle = 0, max1 = 0, max2 = 0;
//    int flag1 = 0, flag2 = 0, flag3 = 0;
//    if (n == 1) { max1 = t[0].end - t[0].start; max2 = 0; }
//    else
//        for (int i = 1; i < n; i++)
//        {
//            if (t[i].start <= t[i - 1].end)
//            {
//                flag3 = 1;
//                if (flag2 == 0) if (flag1 == 0) {
//                    flag1 = 1;
//                    last += t[i].end - t[i - 1].start;
//                }
//                else
//                    last += t[i].end - t[i - 1].end;
//                else {
//                    max1 = max1 > last ? max1 : last;
//                    last = 0;
//                    flag2 = 0;
//                }
//            }
//            else if (t[i].start > t[i - 1].end)
//            {
//                flag1 = 0;
//                flag2 = 1;
//                if (flag3 == 0)
//                    idle += t[i].start - t[i - 1].end;
//                else
//                {
//                    max2 = max2 > idle ? max2 : idle;
//                    idle = 0;
//                }
//            }
//        }
//
//    fprintf(fout, "%ld %ld\n", max1, max2);