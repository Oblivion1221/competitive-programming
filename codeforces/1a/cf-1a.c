#include <stdio.h>

int main()
{
    unsigned long long n = 0, m = 0, a = 0, na = 0, ma = 0, res = 0;
    scanf("%llu %llu %llu", &n, &m, &a); // %I64d
    na = n / a + (n % a ? 1 : 0);
    ma = m / a + (m % a ? 1 : 0);
//    if (n % a)
//        na++;
//    if (m % a)
//        ma++;
    res = na * ma;
    printf("%llu\n", res);
    return 0;
}
