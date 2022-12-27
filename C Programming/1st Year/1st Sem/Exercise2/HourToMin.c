/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Hours to Minutes Converter
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int H, HM;

    //Input hours
    printf("Input number of hours: ");
    scanf("%d", &H);

    //Formula
    HM = H * 60;

    //Output
    printf("%d hours is equal to %d minutes.", H, HM);

    return 0;
}