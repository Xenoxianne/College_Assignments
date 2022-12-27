/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Prime Number Checker (Positive and negative)
*/
#include<stdio.h>

int is_prime(int n){
    if(n<=0){ //checks if it is negative or 0 number
        return 0;
    }else{
        for(int k = 2; k < n; k++){
            if(n%k==0){ //not prime
                return 0;
                break;
            }
        } 
        return 1; //is prime
    }
}

int main(){
    int n;
    char ans = 'y';
    while(ans == 'y' || ans == 'Y'){
        printf("============================================\n");
        printf(">           IS IT A PRIME NUMBER?          <\n");
        printf(">             1 = yes || 0 = no            <\n");
        printf("============================================\n");
        printf("Enter a number to check if it's prime or not\n");
        printf("Input: ");
        scanf("%d", &n);
        printf("is %d a prime number?: %d", n, is_prime(n));
        printf("\n============================================\n");
    
    printf("Would you like to try again? (Y/N): ");
    scanf("\n%c", &ans);
    }

    return 0;
}