// this kata is rubbish

#include <math.h>

double doubles(int maxk, int maxn)
{
    double res = 0.0;
    for (int k = 1; k < maxk + 1; k++)
    {
        for (int n = 1; n < maxn + 1; n++)
        {
            res += 1.0 / (k * pow(n + 1.0, 2.0 * k));
        }
    }
    return res;
}