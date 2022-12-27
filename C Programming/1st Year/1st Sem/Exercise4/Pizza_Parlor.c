/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Area and price of divided area
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    const float pi = 3.14; 
    int size;
    float price, area;
    char ans = 'Y';

    while(ans == 'Y' || ans == 'y'){
            printf("====================================================");
            printf("\n                    PIZZA PARLOR");
            printf("\n====================================================");
            printf("\nDomino's Menu:");
            printf("\nPizza Sizes (in diameter):\n   ~ 10 inches.....178 Php\n   ~ 12 inches.....259 Php\n   ~ 14 inches.....314 Php");
            printf("\n====================================================");
            printf("\nEnter the following:");
            printf("\nPizza size (in diameter): \t");
            scanf("%d", &size);
            printf("Pizza price (in pesos): \t");
            scanf("%f", &price);
            printf("====================================================");

            //Area of the pizza
            area = pi*(size/2)*(size/2);

            //Price by the divided area
            price/=area;

            printf("\nArea of the circle:\t\t%.2f square inches", area);
            printf("\nPrice of the divided area:\t%.2fphp\n", price);

        printf("\nTry again (Y/N)? ");
        scanf("\n%c", &ans);
    }
    return 0;
}