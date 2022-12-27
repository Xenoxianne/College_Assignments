/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Max and min elements of an array (Array ver.)
*/
#include<stdio.h>
#include <stdlib.h>

void MinMax(int r, int c, int arr[r][c]);

int main(){
    int row, col;
    char ans = 'Y'; //repeat program
    while(ans == 'Y' || ans == 'y'){
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf(">            IDENTIFY MAX AND MIN            <\n");
        printf(">               (ARRAY VERSION)              <\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    //take number of rows and columns for array
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &col);

    int arr[row][col];

    //user input
    printf("Enter the integers for the ff: \n");
    for(int i = 0; i < row; i++){
        printf("   - Row %d ", i+1);
        for(int j = 0; j < col; j++){
            printf("column %d: ", j+1);
            scanf("%d", &arr[i][j]); printf("\t   ");
        } printf("\n");
    }

    //display array
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("ENTERED INTEGERS\n");
    for(int i = 0; i < row; i++){
        printf("Row %d:\t|", i+1);
        for(int j = 0; j < col; j++){
            printf("  %d  |", arr[i][j]);
        } printf("\n");
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    MinMax(row, col, arr); //search for min and max element

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

void MinMax(int r, int c, int arr[r][c]){
    int max = arr[0][0], min = arr[0][0], MaxRowLoc = 1, MaxColLoc = 1, MinRowLoc = 1, MinColLoc = 1;

    //determines min and max element in array
    for(int a = 0; a < r; a++){
        for(int b = 0; b < c; b++){
            if(max < arr[a][b]){
                max = arr[a][b]; //sets value as max
                MaxRowLoc = a+1; MaxColLoc = b+1; //location
            } else if(min > arr[a][b]){
                min = arr[a][b]; //sets value as min
                MinRowLoc = a+1; MinColLoc = b+1; //location
            }
        }
    }

    //Output
    printf("Minimum element is %d found in row %d, column %d\n", min, MinRowLoc, MinColLoc);
    printf("Maximum element is %d found in row %d, column %d", max, MaxRowLoc, MaxColLoc);
}