#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input, sec, min, hr;

    //getting user input
    printf("Input number of seconds: ");
    scanf("%d", &input);

    //formula
    sec = input % 60;
    hr = input / 60;
    min = hr % 60;
    hr = hr / 60;

    //printing of answers
    printf("\n Second/s: \t %d", sec);
    printf("\n Minute/s: \t %d", min);
    printf("\n Hour/s: \t %d", hr);
    printf("\n The time is: \t %d:%d:%d", hr, min, sec);

    return 0;
}