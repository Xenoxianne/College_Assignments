/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Late Fines
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
int days;
char ans = 'Y';
    while (ans == 'Y' || ans == 'y'){
        //Input late days
        printf("Input number of days late: ");
        scanf("%d", &days);

        //Fines
        if(days<=0){
            printf("No Fine");
        }else{
            if(days<=2){
                printf("Fine: 10.00");
            }else if(days<=4){
                printf("Fine: 15.00");
            }else if(days<=5){
                printf("Fine: 20.00");
            }else{
                printf("Fine: Equals to the amount of rent\n\tCD = 50.00\n\tVHS = 35.00\n");
            }
        }
        printf("\nTry again (Y/N)? ");
        scanf("\n%c", &ans);
    }
    return 0;
}