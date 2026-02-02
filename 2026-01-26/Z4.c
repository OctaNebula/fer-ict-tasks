#include <stdio.h>
#include <stdlib.h>

void clear(char **stringarray, int len)
{
    for (int i = 0; i < len; i++)
    {
        free(stringarray[i]);
    }

    free(stringarray);
}

int main()
{
    printf("How many words? > ");
    int n;
    scanf("%d", &n);
    char **words;
    words = malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        words[i] = malloc(100 * sizeof(char));
        printf("Type in the word > ");
        scanf("%s", words[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s ", words[i]);
    }

    clear(words, n);
}
