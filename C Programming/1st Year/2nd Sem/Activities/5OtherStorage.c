/*
* ACTIVITY: OTHER STORAGE
* GROUP 3 (BSCS 1-2)
* - Catacutan, Gado, Gozum, Iraga, Pabulayan, San Jose
*/

#include<stdio.h>
#include<stdlib.h>
#include<E:\Code\input.c> //Flashdrive
#include<D:\Code\repeat.c> //HDD

void main(){
  char ans = 'N';
  int choice; //chosen level

  /**Menu**/
  while(ans == 'N' || ans == 'n'){
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                      SUDOKU\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t 1. Easy - 6 inputs / 3 missing");
    printf("\n\t 2. Average - 5 inputs / 4 missing");
    printf("\n\t 3. Hard - 4 inputs / 5 missing\n\t 4. Exit\n");
    printf("\t What difficulty (1-4?): "); scanf("%d", &choice); //Level Choice
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      if(choice == 1){ //Easy
        printf("                      EASY \n");
        repeat(6);
      }else if(choice == 2){ //Average
        printf("                     AVERAGE \n");
        repeat(5);
      }else if(choice == 3){ //Hard
        printf("                      HARD \n");
        repeat(4);
      }else if(choice == 4){ //exit
        printf("Do you really want to exit the program? (Y/N): ");
        scanf("\n%c", &ans);
      }else{ //non of the choices
        printf("                 Error! Try Again. \n");
      }
  }

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("                Have a great day! \n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  system("PAUSE"); //so program won't automatically exit
}