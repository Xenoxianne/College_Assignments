#include<stdio.h>
#include<stdlib.h>

float a, b;

//input
float num(){
    printf("\nFirst number : ");
    scanf("%f", &a);
    printf("Second number : ");
    scanf("%f", &b);
}

int main(){
    char ans = 'N', rep = 'Y';
    int choice;
    while(ans == 'N' || ans == 'n'){ 
        printf("~~~~~~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~~~~~~\n");
        printf("1. Addition\n2. SuBinaryTreesraction\n3. Multiplication\n4. Division\n5. Exit\n");
        printf("Please choose a number: ");
        scanf("%d", &choice); //Operation choice
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        if(choice == 1){ //addition
            printf("                   ADDITION \n");
            do{
                num();
                printf("%.2f + %.2f = %.2f", a, b, (a+b));
                printf("\nAnother try? (Y/N): ");
                scanf("\n%c", &rep);
            }while(rep == 'Y' || rep == 'y');
        }else if(choice == 2){ //suBinaryTreesraction
            printf("                  SUBinaryTreesRACTION \n");
            do{
                num();
                printf("%.2f - %.2f = %.2f", a, b, (a-b));
                printf("\nAnother try? (Y/N): ");
                scanf("\n%c", &rep);
            }while(rep == 'Y' || rep == 'y');
        }else if(choice == 3){ //multiplication
            printf("                MULTIPLICATION \n");
            do{
                num();
                printf("%.2f * %.2f = %.2f", a, b, (a*b));
                printf("\nAnother try? (Y/N): ");
                scanf("\n%c", &rep);
            }while(rep == 'Y' || rep == 'y');
        }else if(choice == 4){ //division
            printf("                   DIVISION \n");
            do{
                num();
                printf("%.2f / %.2f = %.2f", a, b, (a/b));
                printf("\nAnother try? (Y/N): ");
                scanf("\n%c", &rep);
            }while(rep == 'Y' || rep == 'y');
        }else if(choice == 5){ //exit
            printf("Do you really want to exit the program? (Y/N): ");
            scanf("\n%c", &ans);
        }else{ //non of the choices
            printf("                Error! Try Again. \n");
        }
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                Have a great day! \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    system("PAUSE"); //so program won't automatically exit
}
