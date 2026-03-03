#include <stdio.h>

int main()
{
    unsigned number, sample, bit;
    scanf("%d%d%d", &number, &sample, &bit);

    int mask = (1 << bit) - 1;

    sample &= mask;

    int count = 0;
    int max_shift = 32 - bit;
    for (int i = max_shift; i >= 0; i--)
    {
        int window = (number >> i) & mask;
        if ((unsigned int)window == sample)
        {
            count++;
        }
    }
    printf("Obrazac se pojavljuje %d puta.", count);
}