#include <stdio.h>
int main()
{

    float R, G, B;
    float C, M, Y, K, W, Rf, Gf, Bf, max;
    printf("Enter the values of R,G & B: ");
    scanf("%f%f%f", &R, &G, &B);
    if (R < 0 || R > 255)
    {
        printf("Enter R within limit\n");
        scanf("%f", &R);
    }
    if (G < 0 || G > 255)
    {
        printf("Enter G within limits\n");
        scanf("%f", &G);
    }
    if (B < 0 || B > 255)
    {
        printf("Enter B within limits\n");
        scanf("%f", &B);
    }
    printf("\nR,G,B: %f,%f,%f\n", R, G, B);

    Rf = R / 255;
    Gf = G / 255;
    Bf = B / 255;

    printf("***********************************\n");
    printf("RGB to CMY Values\n");
    W = 1;
    printf("White: %f\n", W);
    C = W - Rf;
    M = W - Gf;
    Y = W - Bf;
    printf("The value of Cyan: %f\n", C);
    printf("The value of Magenta: %f\n", M);
    printf("The value of Yellow: %f\n", Y);
    printf("***********************************\n");

    printf("RGB to CMYK Values\n");
    if (R == 0 && G == 0 && B == 0)
    {
        printf("The value of Cyan: 0\n");
        printf("The value of Magenta: 0\n");
        printf("The value of Yellow: 0\n");
        printf("The value of Black: 1\n");
    }
    else
    {
        max = Rf;
        if (max < Gf)
            max = Gf;
        if (max < Bf)
            max = Bf;
        W = max;
        printf("White: %f\n", W);
        C = (W - Rf) / W;
        M = (W - Gf) / W;
        Y = (W - Bf) / W;
        K = 1 - W;
        printf("The value of Cyan: %f\n", C);
        printf("The value of Magenta: %f\n", M);
        printf("The value of Yellow: %f\n", Y);
        printf("The value of Black: %f\n", K);
    }
    printf("***********************************\n");
}