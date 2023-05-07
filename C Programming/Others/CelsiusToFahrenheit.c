#include <stdio.h>
#include <stdlib.h>

int main(){

    float celsius, fahrenheit;

    printf("=== CELSIUS TO FAHRENHEIT ===\n\n");
    printf("Value in Celsius: ");
    scanf("%f", &celsius);

    // Formula to convert Celsius to Fahrenheit
    fahrenheit = (celsius * 9/5) + 32;
    printf("\n%.1f degrees Celsius converts to %.1f degrees Fahrenheit.", celsius, fahrenheit);

    return 0;
}