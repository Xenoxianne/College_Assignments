/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* 3 Digit Computation
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int A, B, C, Sum, Diff, Prod, Quo, SumSquare;

    //User input
    printf("Input 3 digits: \n");
    scanf("%d %d %d", &A, &B, &C);

    //Computation
    Sum = A + B + C; //Sum
    Diff = A - B - C; //Difference
    Prod = A * B * C; //Product
    Quo = A / B / C; //Quotient
    SumSquare = (A*A) + (B*B) + (C*C); //Sum of their squares

    //Answers
    printf("\n----------Answers----------");
    printf("\nSum: \t\t\t%d\n", Sum);
    printf("Difference: \t\t%d\n", Diff);
    printf("Product: \t\t%d\n", Prod);
    printf("Quotient: \t\t%d\n", Quo);
    printf("Sum of their squares: \t%d", SumSquare);

    return 0;
}