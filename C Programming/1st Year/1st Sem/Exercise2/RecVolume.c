/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Dimension of a rectangular box
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    float Length, Width, Height, V;

    //Input dimensions
    printf("Enter the length, width, and height of the rectangular box.");
    printf("\nLength: \t"); scanf("%f", &Length);
    printf("Width: \t\t"); scanf("%f", &Width);
    printf("Height: \t"); scanf("%f", &Height);

    //Formula
    V = Length * Width * Height;
    
    //printing of answer
    printf("--------------------");
    printf("\nVolume:  \t%.2f", V);
    return 0;
}                           