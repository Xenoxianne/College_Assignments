/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Weight on Planet Converter
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    float Weight, WM, WJ;

    //Input weight
    printf("Enter you weight in pounds: "); 
    scanf("%f", &Weight);

    //Formula
    WM = Weight * 0.38; //Weight on Mars
    WJ = Weight * 2.64; //Weight on Jupiter

    //Output
    printf("\nWeight on Mars: \t %.2f pounds\n", WM);
    printf("Weight on Jupiter: \t %.2f pounds\n", WJ);
}