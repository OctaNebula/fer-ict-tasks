#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char outstr[200];
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
        len--;
    }
    int out_idx = 0;

    for (int i = 0; i < len; i++)
    {
        char current = str[i];
        int count = 1;

        while (i + 1 < len && str[i + 1] == current)
        {
            count++;
            i++;
        }

        if (count == 1)
        {
            outstr[out_idx++] = current;
        }
        else
        {
            outstr[out_idx++] = current;
            outstr[out_idx++] = '0' + count;
        }
    }

    outstr[out_idx] = '\0';
    printf("%s\n", outstr);

    return 0;
}