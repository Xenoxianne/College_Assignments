/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Divisible by
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int N1, N2, M, a = 0, b = 1;
    char ans = 'Y';

    while(ans == 'Y' || ans == 'y'){
        //Input values
        printf("\nEnter your starting value: ");
        scanf("\t%d", &N1);
        printf("Enter your ending value: ");
        scanf("\t%d", &N2);
        printf("Values should be divisible by: ");
        scanf("\t%d", &M);
        printf("====================================");
        
        //Operation
        printf("\nif N1 = %d, N2 = %d and, M = %d \nThe output will be:", N1, N2, M);
        for(N1; N1<=N2; N1++){
            if(N1%M==0){
                printf("\n\t%d. %d", b++, N1);
                a++;
            }
        }
        printf("\n====================================");
        printf("\nThe total number of output are: %d", a); //Output

        printf("\n\nTry again (Y/N)? ");
        scanf("\n%c", &ans);
    }

    return 0;
}