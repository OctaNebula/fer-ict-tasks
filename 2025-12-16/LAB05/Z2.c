#include <stdio.h>
void zbroj(int n1, int d1, int n2, int d2, int *np, int *dp) {
    int n, d;
    n = n1 * d2 + n2 * d1;
    d = d1 * d2;

    *np = n;
    *dp = d;
    for (int i = 2; i < 13; i++) {
        while (!(n % i) && !(d % i)) {
            n /= i;
            d /= i;
        } /*
         if (!(!(n % i) && !(d % i))) {
             printf("Couldn't divide by %d\n", i);
         }
         else {
             printf("Successfully divided by %d", i);
         }*/
    }

    return;
}