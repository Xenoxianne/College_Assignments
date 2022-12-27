/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* N Factorial
*/
#include<stdio.h>
#include<stdlib.h>

unsigned long long facto(int n){
    if (n == 0){    //if n = 0
        return 1;
    }
    return(n * facto(n-1)); //will loop until n in (n-1) reaches 1
}

int main(){
    char ans = 'Y';
    int n;

    while(ans == 'Y' || ans== 'y'){
        //loop until a non-negative integer is entered
        do{
            printf("========== FACTORIAL CALCULATOR ==========\n");
            printf("Enter a non-negative integer: ");
            scanf("%d", &n);
            if(n<0){
                    printf("Negative integers are not allowed.\nPlease try again.\n");
                }
        }while(n<0);

        printf("------------------------------------------\n");
        printf("The factorial of %d! = %llu", n, facto(n)); //answer
        printf("\n------------------------------------------\n");
        printf("Would you like to try again? (Y/N): ");
        scanf("\n%c", &ans);
    }

    return 0;
}