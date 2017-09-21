#include <stdio.h>
#include <string.h>
#define MAX 100

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        char word[MAX];
        scanf("%s", word);
        if (strlen(word) > 10)
        {
            // int tot = 0;
            // for (int i = 1; i < strlen(word) - 1; i++)
            //     tot++;
            printf("%c%lu%c\n", word[0], strlen(word) - 2, word[strlen(word) - 1]);
        }
        else
            printf("%s\n", word);
    }

    return 0;
}
