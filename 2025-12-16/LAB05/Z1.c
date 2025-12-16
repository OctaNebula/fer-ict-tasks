#include <math.h>
#include <stdio.h>

float PiSuma(int n) {
    float pi4;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            pi4 += ((1.0 / (1.0 + i * 2)));
            // printf("\nAdded %f", (1.0 / (1.0 + i * 2)));
        }
        if (!(i % 2 == 0)) {
            pi4 -= ((1.0 / (1.0 + i * 2)));
            // printf("\nSubtracted %f", (1.0 / (1.0 + i * 2)));
        }
    }
    // printf("%f", pi4 * 4);
    return (pi4 * 4);
}

float Volumen(float d, float h, int n) {
    float pi = PiSuma(n);
    float volume = powf((d / 2), 2.0) * pi * h;
    return volume;
}

int main() {
    int n;
    float d, h;
    printf("Upisite broj clanova reda > ");
    scanf("%d", &n);
    printf("Upisite promjer baze cilindra > ");
    scanf("%f", &d);
    printf("Upisite visinu cilindra > ");
    scanf("%f", &h);

    if (!((n <= 100) && (n >= 1) && (d <= 100) && (d >= 1) && (h <= 100) &&
          (h >= 1))) {
        printf("Ucitani parametri nisu dobri!");
        return 0;
    }

    printf("Volumen cilindra (PI pomocu reda) > %.4f\n", Volumen(d, h, n));
    printf("Volumen cilindra (PI pomocu asin) > %.4f\n",
           powf((d / 2), 2.0) * asin(1.0) * h * 2);
    printf("Apsolutna razlika > %.4f\n",
           fabs(Volumen(d, h, n) - powf((d / 2), 2.0) * asin(1.0) * h * 2));
}