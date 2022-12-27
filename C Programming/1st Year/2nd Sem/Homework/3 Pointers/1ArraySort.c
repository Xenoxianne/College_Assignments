/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Array Sort
*/
#include <stdio.h>
#include <stdlib.h>

void reorder(int n, int *arrange);
void output(int n, int *list);

int main(){
    int n, *num;
    char ans = 'Y'; //repeat program
    while(ans == 'Y' || ans == 'y'){
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf(">                 ARRAY SORT                 <\n");
        printf(">             (Least to Greatest)            <\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        //Total number of integers to be entered by user
        printf("Enter number of integers: ");
        scanf("%d", &n);

        num = (int*) malloc(n *sizeof(int)); //to treat the pointer variable as an array
        
        //User Input
        printf("Enter %d integers:\n", n);
        for(int i = 0; i<n; i++){
            scanf("%d", (num + i));
        }

        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Numbers to sort: \n");
        output(n, num); //outputs unsorted group of numbers
        reorder(n, num); //sorts

        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Sorted numbers: \n"); 
        output(n, num); //outputs sorted group of numbers

        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("\nDo you want to try again? (Y/N): "); //try again
            scanf("\n%c", &ans); printf("\n");
        }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf(">              Have a great day!             <\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    system("PAUSE"); //so program won't automatically exit

    return 0;
}

void reorder(int n, int *arrange){
    int temp; //temporary location

    for(int check = 0; check < n - 1; check++){
        for(int compare = check + 1; compare < n; compare++){
            if(*(arrange + compare) < *(arrange + check)){
                temp = *(arrange + check); //places larger value
                *(arrange + check) = *(arrange + compare); //assigns the least value to the index of the value checked
                *(arrange + compare) = temp; //assigns the larger value to the previous index of the least value
            }
        }
    }
}

void output(int n, int *list){
    for(int i = 0; i < n; i++){
        printf("%d ", *(list + i));
    }
}