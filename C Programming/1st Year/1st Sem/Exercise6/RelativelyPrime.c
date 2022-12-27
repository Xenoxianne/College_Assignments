/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Relatively Prime Numbers
*/

#include<stdio.h>

int rel_prime(int n){
    if(n<=0){       //if n is zero or a negative number
        return 0;
    }else{
        for(int i = 2; i < n; i++){
            if(n%i==0){ //not prime
                return 0;
                break;
            }
        } 
        return 1; //is prime
    }
}

int main(){
    int i, j, prime;
    char ans = 'Y';

    while(ans == 'Y' || ans == 'y'){ //loops the program as long as user inputs Y
        printf("******************************************\n");
        printf("         Relatively Prime Numbers         \n");
        printf("******************************************\n");
        printf("Enter two numbers to check if they are\nrelatively prime\n");
        printf("   - First number: ");
        scanf("%d", &i);
        printf("   - Second number: ");
        scanf("%d", &j);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Legend: 1 = Yes\n\t0 = No\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

        if(rel_prime(i)==1 && rel_prime(j)==1){ //checks if both addends are prime
            prime = 1;
        } else {prime = 0;}
        printf("Are integers %d and %d relatively prime? %d\n", i, j, prime);
        printf("******************************************");

        printf("\nWould you like to try again? (Y/N): ");
        scanf("\n%c", &ans);
    }
    return 0;
}