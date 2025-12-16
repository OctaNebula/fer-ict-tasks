#include <stdio.h>

int PovecajKonvertiraj(float *posnovica, int bonus, float *ppostotak)
{
    float ratio = 7.53450;
    float osnovica = *posnovica;

    *ppostotak = ((float)bonus / osnovica) * 100;

    *posnovica = (osnovica + bonus) / ratio;

    if (*ppostotak >= 10.0)
    {
        return 1;
    }

    return 0;
}