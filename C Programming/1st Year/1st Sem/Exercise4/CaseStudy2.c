/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Factorial
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    unsigned long long facto = 1;
            
    //checking of integers        
    do{
        printf("\nEnter a non-negative integer: ");
        scanf("%d", &num);
            if(num<0){
                printf("Negative integers are not allowed. Please try again.");
            }
    }while(num<0);

    //factorial
    for(int i = 1; i<=num; i++){
        facto*=i;
    }

    //ouput
    printf("The factorial of %d! = %llu", num, facto);

    return 0;
}
