#include <stdio.h>

int main() {
    float R, G, B, C, M, Y, K, W, Rf, Gf, Bf, max;

    printf("Enter the values of R, G, B (0-255): ");
    scanf("%f %f %f", &R, &G, &B);

    if (R < 0 || R > 255) {
        printf("Invalid value for R, enter between 0 and 255.\n");
        scanf("%f", &R);
    }
    if (G < 0 || G > 255) {
        printf("Invalid value for G, enter between 0 and 255.\n");
        scanf("%f", &G);
    }
    if (B < 0 || B > 255) {
        printf("Invalid value for B, enter between 0 and 255.\n");
        scanf("%f", &B);
    }

    Rf = R / 255;
    Gf = G / 255;
    Bf = B / 255;

    W = 1.0;
    C = W - Rf;
    M = W - Gf;
    Y = W - Bf;

    printf("\nRGB: (%f, %f, %f)\n", R, G, B);
    printf("***********************************\n");
    printf("RGB to CMY Values:\n");
    printf("Cyan: %f\nMagenta: %f\nYellow: %f\n", C, M, Y);

    printf("\nRGB to CMYK Values:\n");
    if (R == 0 && G == 0 && B == 0) {
        printf("Cyan: 0\nMagenta: 0\nYellow: 0\nBlack: 1\n");
    } else {
        max = Rf;
        if (Gf > max) max = Gf;
        if (Bf > max) max = Bf;

        W = max;

        C = (W - Rf) / W;
        M = (W - Gf) / W;
        Y = (W - Bf) / W;
        K = 1 - W;

        printf("Cyan: %f\nMagenta: %f\nYellow: %f\nBlack: %f\n", C, M, Y, K);
    }
    printf("***********************************\n");

    return 0;
}
