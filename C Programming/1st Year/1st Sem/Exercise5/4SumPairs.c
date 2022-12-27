/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Sum of succeeding pairs
*/
#include<stdio.h>

int main(){
    int X[11], Y[10];
    char ans = 'Y';
    //repeats program
    while(ans == 'Y' || ans == 'y'){
        printf("=====================================================\n");
        printf("             Sum of the Succeeding Pairs             \n");
        printf("=====================================================\n");
        printf("Enter eleven numbers: ");
        for (int i = 0; i < 11; i++){
            scanf("%d", &X[i]);
        }
        printf("SUM of TWO succeeding pairs: ");
        for(int i = 0, j = 1; i<10; i++, j++){
            Y[i] = X[i]+X[j]; //takes the sum of 2 succeeding pairs
            printf("%d ", Y[i]);
        }
        printf("\n=====================================================\n");
        printf("Would you like to try again? (Y/N): ");
        scanf("\n%c", &ans);
    }
    return 0;
}