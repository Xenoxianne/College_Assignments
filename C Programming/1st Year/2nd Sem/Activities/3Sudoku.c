/*
* ACTIVITY: SUDOKU
* GROUP 3 (BSCS 1-2)
* - Catacutan, Gado, Gozum, Iraga, Pabulayan, San Jose
*/

#include<stdio.h>
#include<stdlib.h>

int data, ind;

/**Data Input**/
void input(int n){
  int sudoku[3][3] = {{0,0,0},{0,0,0},{0,0,0}}, element[9] = {0,0,0,0,0,0,0,0,0}; //array
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  //Instructions for game
  printf("Instructions: For this level, you are tasked to \n\t      input %d indices and their respective \n\t      values on a 3x3 grid Sudoku. The \n\t      numbers unused will be automatically \n\t      displayed on the table.\n\n", n);

  for(int i=0; i < n; i++){
    /**Index**/
    printf("%d. What index? \t", i+1);
    scanf("%d", &ind);
      //if input is greater than 9 and less than 0
      while(ind<1 || ind>9){
        printf("\nError! Enter numbers from 1-9 ONLY!");
        printf("\n%d. What index? \t", i+1);
        scanf("%d", &ind);
      }
      //if input is already existing
      while(element[0]==ind || element[1]==ind || element[2]==ind || element[3]==ind || element[4]==ind || element[5]==ind || element[6]==ind || element[7]==ind || element[8]==ind ){
        printf("\nError! Index occupied! Enter another number!");
        printf("\n%d. What index? \t", i+1);
        scanf("%d", &ind);
      }

    /**Data**/
    printf("   Data? \t", i+1);
    scanf("%d", &data); printf("\n");
      //if input is greater than 9 and less than 0
      while(data<1 || data>9){
        printf("Error! Enter numbers from 1-9 ONLY!");
        printf("\n   Data? \t", i+1);
        scanf("%d", &data); printf("\n");
      }
      //if input is already existing
      while(sudoku[0][0]==data || sudoku[0][1]==data || sudoku[0][2]==data || sudoku[1][0]==data || sudoku[1][1]==data || sudoku[1][2]==data || sudoku[2][0]==data || sudoku[2][1]==data || sudoku[2][2]==data){
        printf("Error! Data already exists! Enter another number!");
        printf("\n   Data? \t", i+1);
        scanf("%d", &data); printf("\n");
      }

    /**Assigning Value to Array**/
    switch (ind){
      case 1: sudoku[0][0] = data; break;
      case 2: sudoku[0][1] = data; break;
      case 3: sudoku[0][2] = data; break;
      case 4: sudoku[1][0] = data; break;
      case 5: sudoku[1][1] = data; break;
      case 6: sudoku[1][2] = data; break;
      case 7: sudoku[2][0] = data; break;
      case 8: sudoku[2][1] = data; break;
      case 9: sudoku[2][2] = data; break;
      default: printf("Error! Enter numbers from 1-9 ONLY!");
    }
    element[i] = ind; //stores given value in a different array for checking
  }

  /**Fills in the remaining blank tiles**/
  for(int a = 0; a<3; a++){
    for(int b = 0; b<3; b++){
      if (sudoku[a][b] == 0){
        for(int c = 1; c < 10; c++){
          if(sudoku [0][0] != c && sudoku [0][1] != c && sudoku [0][2] != c && sudoku [1][0] != c && sudoku [1][1] != c && sudoku [1][2] != c && sudoku [2][0] != c && sudoku [2][1] != c && sudoku [2][2] != c){
            sudoku[a][b] = c;
          }
        }
      }
    }
  }

  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("                      OUTPUT\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  printf("\n\t\t   --- --- ---");
  printf("\n\t\t  | "); for(int b = 0; b < 3; b++){printf("%d | ", sudoku[0][b]);}
  printf("\n\t\t   --- --- ---");
  printf("\n\t\t  | "); for(int b = 0; b < 3; b++){printf("%d | ", sudoku[1][b]);}
  printf("\n\t\t   --- --- ---");
  printf("\n\t\t  | "); for(int b = 0; b < 3; b++){printf("%d | ", sudoku[2][b]);}
  printf("\n\t\t   --- --- ---");
}

/**repeat level**/
void repeat(int n){
  char rep = 'Y';
  do{
    input(n);
    printf("\nDo you want to try again? (Y/N): "); scanf("\n%c", &rep); //repeat
  }while(rep == 'Y' || rep == 'y');
}

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