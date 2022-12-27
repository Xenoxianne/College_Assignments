/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Weight of candy per bag
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    float A, B, C, D, AmntA, AmntB, AmntC, AmntD;

    //User Input
    printf("Enter the weight of candy per bag");
    printf("\nCandy A: "); scanf("%f", &A);
    printf("Candy B: "); scanf("%f", &B);
    printf("Candy C: "); scanf("%f", &C);
    printf("Candy D: "); scanf("%f", &D);

    //Formula
    AmntA = 35 * A;
    AmntB = 45 * B;
    AmntC = 56 * C;
    AmntD = 57.50 * D;

    //Output
    printf("\n\t  QTY \t\t TOTAL");
    printf("\nCandy A:  %.2f kg \t %.2f Php", A, AmntA);
    printf("\nCandy B:  %.2f kg \t %.2f Php", B, AmntB);
    printf("\nCandy C:  %.2f kg \t %.2f Php", C, AmntC);
    printf("\nCandy D:  %.2f kg \t %.2f Php", D, AmntD);

    return 0;
}