/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Prime Number Checker
*/
#include<stdio.h>
#include<stdlib.h>
int prime(int a);
int main(){
    int n; 
    char ans = 'Y';
    while(ans == 'Y' || ans == 'y'){
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf(">             IS IT A PRIME NUMBER?             <\n");
        printf(">           0 = prime || 1 = not prime          <\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        do{
            printf("Enter a non-negative integer: ");
            scanf("%d", &n);
            if(n<0){
                printf("Invalid negative integer. Please try again.\n");
            }
        }while(n<0);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Is %d prime or not? %d\n", n, prime(n));
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Would you like to try again? (Y/N): ");
    scanf("\n%c", &ans);
    }

    return 0;
}

int prime(int n){
    if(n==0){ // if n is 0
        return 1;
    }else{
        for(int i = 2; i < n; i++){
            if(n%i==0){ //not prime
                return 1;
                break;
            }
        } 
        return 0; //is prime
    }
}