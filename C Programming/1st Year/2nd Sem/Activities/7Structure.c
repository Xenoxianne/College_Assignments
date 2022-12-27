/*
    ACTIVITY 6: Linear Search
    GROUP 10
    Gozum, Denise Julianne
    Garcia, Jordan
    Sta Ana, Jethro
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int idno;
    char fname[80];
    char lname[80];
} st[5], temp;

int main(){
    char ans = 'Y'; //repeat program
    while(ans == 'Y' || ans == 'y'){
        int id[5]={};
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("                   STRUCTURE \n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        //User input
        printf("Enter the ff: \n");
        for(int in = 0; in<5; in++){
            printf("\nSTUDENT %d \n", in+1);
            printf("  - ID Num: ");
            scanf("%d", &st[in].idno);
                //checks for duplicate id number
                while(id[0] == st[in].idno || id[1] == st[in].idno|| id[2] == st[in].idno || id[3] == st[in].idno || id[4] == st[in].idno){
                    printf("\n  Error! ID No. Already Taken\n");
                    printf("  - ID Num: ");
                    scanf("%d", &st[in].idno);
                }

            printf("  - First Name: ");
            scanf("%s", st[in].fname);

            printf("  - Last Name: ");
            scanf("%s", st[in].lname);

            id[in] = st[in].idno; //assigns input in array 
        }

        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("LIST OF STUDENTS:\n");
        //compare idno (ascending order)
        for(int a = 0; a<5; a++){
            for(int b = a+1; b<5; b++){
                if(st[a].idno > st[b].idno){
                    temp = st[a]; 
                    st[a]= st[b]; 
                    st[b] = temp;
                }
            }
            //print
            printf("  %d.  [%d] %s, %s \n", (a+1), st[a].idno, st[a].lname, st[a].fname);
        }

        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Do you want to try again? (Y/N): "); //try again
        scanf("\n%c", &ans);
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                Have a great day! \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    system("PAUSE"); //so program won't automatically exit

    return 0;
}