/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* 3 Integers in descending order
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int a, b, c;
    char ans = 'Y';

    while (ans == 'Y'|| ans == 'y')
    {
        //input 3 integers
        printf("Enter 3 integers");
        printf("\nFirst number: \t"); scanf("%d", &a);
        printf("Second number: \t"); scanf("%d", &b);
        printf("Third number: \t"); scanf("%d", &c);
        printf("====================================");
        printf("\nDescending order of entered numbers:");

        //Evaluating input and printing them in decending order
        if(a<=c && a<=b){
            if (b<=c){
                printf("\n %d \n %d \n %d", c, b, a);
            }else{
                printf("\n %d \n %d \n %d", b, c, a);
            } 
        }if (b<=c && b<=a){
            if(a<=c){
                printf("\n %d \n %d \n %d", c, a, b);
            }else{
                printf("\n %d \n %d \n %d", a, c, b);
            }
        }if (c<=a && c<=b){
            if(a<=b){
                printf("\n %d \n %d \n %d", b, a, c);
            }else{
                printf("\n %d \n %d \n %d", a, b, c);
            }
        }   
    
        printf("\nTry again (Y/N)?");
        scanf("\n%c", &ans);
    }
    return 0;
}