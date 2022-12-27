/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Sum of all even index
*/
#include<stdio.h>

void EVEN(int num[]){
    int sum = 0;
    //Checks each element
    for(int j = 0; j < 20; j++){
        if(j%2==0){ //takes only the value in even indexes
            sum += num[j];
        }
    }
    printf("\nThe sum of all even indexes: %d", sum);
} 

int main(){
    int BSIT[20];
    char ans = 'Y';
    //repeats program
    while(ans == 'Y' || ans == 'y'){
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf(">          Sum of all even index values         <\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        //user input
        printf("Enter 20 integers: \n");
        for(int i = 0; i < 20; i++){
            scanf("%d", &BSIT[i]);
        }
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        //prints all the value inside the array
        printf("The values you entered are: \n");
        for(int k = 0; k < 20; k++){
            printf("%d ", BSIT[k]);
        }

        EVEN(BSIT); //calls the function
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Would you like to try again? (Y/N): ");
        scanf("\n%c", &ans);
    }
    
    return 0;
}