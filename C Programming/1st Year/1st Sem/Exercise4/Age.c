/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Person's age
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int age;
    char ans = 'Y';

    while (ans == 'Y' || ans == 'y'){
        //user input
        printf("\nPlease input your age: ");
        scanf("%d", &age);

        //choosing of age range
        if(age>=0 && age<13){
            printf("C");
        }else if(age>=13 && age<=19){
            printf("T");
        }else if(age>=20){
            printf("A");
        }

        printf("\nDo you want to try again (Y/N)? ");
        scanf("\n%c", &ans);
    }
    return 0;
}