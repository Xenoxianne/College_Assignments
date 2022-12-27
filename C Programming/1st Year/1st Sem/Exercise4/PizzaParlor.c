//fixed

/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Area and price of divided area
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    const float pi = 3.14; 
    char ans = 'Y';
    int size;
    float price, area;

    while (ans == 'Y' || ans == 'y'){
        printf("\nPizza Sizes (in diameter):\n   ~ 10 inches\n   ~ 12 inches\n   ~ 14 inches\n");
        printf("Please enter your desired pizza size (no. only): ");
        scanf("%d", &size);
        printf("=====================================================");

        switch(size){
        case 10: price = 178; break;
        case 12: price = 259; break;
        case 14: price = 314; break;
        default:
            printf("\nInvalid Input\n");
        }

        printf("\nPizza ordered:\t %d inches (diameter)", size);
        printf("\nPizza price:\t %.2fphp", price);
        printf("\n=====================================================");

        //Area of the pizza
        area = pi*(size/2)*(size/2);

        //Price by the divided area
        price/=area;

        printf("\nArea of the circle:\t\t %.2f square inches", area);
        printf("\nPrice of the divided area:\t %.2fphp\n", price);

        printf("\nTry again?: ");
        scanf("\n%c", &ans);
    }
    return 0;
}