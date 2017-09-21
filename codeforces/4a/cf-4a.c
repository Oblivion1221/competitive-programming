#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n != 2)
        printf("%s\n", (n % 2) ? "NO" : "YES");
    else
        printf("NO\n");
    return 0;
}