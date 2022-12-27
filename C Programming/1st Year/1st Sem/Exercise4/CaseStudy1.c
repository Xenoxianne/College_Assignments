/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Prime Factors
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
int num, prime;
char ans = 'Y';

    while(ans == 'Y' || ans == 'y'){
        printf("====================================================");
        printf("\n                PRIME FACTORIZATION");              
        printf("\n====================================================");

        do{
            printf("\nEnter a non-negative integer: ");
            scanf("%d", &num);
                if(num<0){
                    printf("Negative integers are not allowed. Please try again.");
                }
        }while(num<0);

        printf("%d = 1", num);
        for(int i=2; i<=num; i++){
            if(num%i==0){
                prime=1;
                for(int j=2; j<=i/2; j++){
                    if(i%j==0){
                        prime=0;
                        break;
                    }
                }
                if(prime==1){
                    printf(" * %d", i);
                }
            }
        }

        printf("\nTry again (Y/N)? ");
        scanf("\n%c", &ans);
    }
return 0;
}