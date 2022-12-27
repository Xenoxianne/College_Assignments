/*
* SEAT RESERVATION
* GROUP 7 (BSCS 1-2)
* - Gozum, Mabalot, Mangalindan
*/

//v2: gets for name

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

//seat reservation
 char seat[5][4] = {{'A', 'B', 'C', 'D'},
                    {'A', 'B', 'C', 'D'},
                    {'A', 'B', 'C', 'D'},
                    {'A', 'B', 'C', 'D'},
                    {'A', 'B', 'C', 'D'},
                   };

void book();                            //booking for a ticket
void available(int choice);                       //shows available seats to users
void info(int ticket);                  //takes user info
void assign(int row, char colLet);      //assigns seat number
void check();                           //checks the number of seats availabe

int flag = 0, avail = 0;                //avail = total seats avail, flag = checks if user input is correct
static int input = 0;                   //input = counter

struct reserve{
    char name[80];
    int seatrow;
    char seatcol;
} res[80];

int main(){
    char ans = 'N'; //repeat program
    int choice;
    while(ans == 'N' || ans == 'n'){
        system("cls");  //clear screen
        //Menu Program
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("                 MABALOT AIRLINES \n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Good day! Thank you for choosing Mabalot Airlines!\n");
        printf("\n----- FLIGHT: Manila -> Japan\n");
        printf("\n\t[1] Book Tickets\n\t[2] See Availability\n\t[3] Exit Program\n");
        printf("\n----- What do you want to do [1-2]? ");
        scanf("%d", &choice);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

        switch(choice){
            case 1: book(); break;
            case 2: available(choice); break;
            case 3:
                printf("Do you really want to exit the program? (Y/N): ");
                scanf("\n%c", &ans); break;
            default: printf("\tInvalid selection. Try again\n");
            }input = 0; //resets counter for new user
        }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                Have a great day! \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    system("PAUSE"); //so program won't automatically exit

    return 0;
}

//books ticket
void book(){
    system("cls"); 
    int num = 0;
    check();    //checks availability first
    
    //if all seats are taken
    if(avail == 0){
        printf("\n==================================================\n");
        printf("\n\tSorry. All 20 Seats are Reserved.\n");
        printf("\n==================================================\n");
    }

    //If there are still available seats
    else{
        printf("================ SEAT RESERVATION ================\n");
        printf("-----> Number of Tickets: "); scanf("%d", &num); printf("\n");  //takes number of tickets
        //If there are still available seats yet not enough for the number of tickets user will avail
        if(avail < num){
            printf("==================================================\n");
            printf("\n\tSorry. Not Enough Seat Available.\n");
            printf("\t\tSEATS AVAILABLE: %d\n", avail);
            printf("\n==================================================\n");
        }else{
            avail = 0;              //resets count availability to 0
            while(input<num){
                available(0);        //prints available seats (changes everytime user makes a reservation)
                info(input);        //takes user info
                if(flag == 0)       //If there's an error, program will repeat user input for that ticket number
                    input++;
            }
            available(0);            //prints final available seats for user to see
            printf("\n=============== %d SEAT/S RESERVED! ===============\n", num);
        }
    }
    system("PAUSE"); //Pause before going back to main menu
}

//Outputs Available seats
void available(int choice){
    if(choice == 2){
        system("cls"); 
        printf("\n==================================================\n");
    }
    check(); 
    printf("\t\t SEATS AVAILABLE: %d\n\n", avail);
    for (int row = 0; row < 5; row++) {
        printf("\t%d   |\t", row+1);
        for(int col = 0; col<4; col++){
            printf("%c \t", seat[row][col]);
        }printf("\n");
    }
    if(choice==2){
        printf("\n==================================================\n");
        printf("\n"); system("PAUSE"); //Pause before going back to main menu
    }
    avail = 0;  //resets count availability to 0
}

//User info for ticket
void info(int ticket){
    printf("\n-------------------- TICKET %d --------------------\n", ticket+1);
    printf("Fill in the ff. to continue\n");
    fflush(stdin);                                                                  //clear input buffer
    printf("  - Full Name: "); gets(res[ticket].name);                               //name
    printf("  - Enter seat row (1-5): "); scanf("%d", &res[ticket].seatrow);        //seat row
    printf("  - Enter seat column (A-D): "); scanf("\n%c", &res[ticket].seatcol);   //seat column
    printf("--------------------------------------------------\n");
    assign(res[ticket].seatrow, res[ticket].seatcol);
}

//Assigns seat number
void assign(int row, char colLet){

    //Column
    colLet = toupper(colLet);       //Turns column input into upper case
    int col = 0, error = 0;         //col = column number, error = error in column
    switch (colLet){                //Assigns column letter to its corresponding array number
        case 'A': col = 0; break;
        case 'B': col = 1; break;
        case 'C': col = 2; break;
        case 'D': col = 3; break;
        default:
            printf("\t  Invalid Column Input. Try Again.\n");
            printf("--------------------------------------------------\n");
            flag = 1; error = 1;
    }

    //Row
    if((row-1)>4){
        printf("\t  Invalid Row Input. Try Again.\n");
        printf("--------------------------------------------------\n");
        flag = 1;                               //Wrong user input
    }else{
        if(error !=1){                          //If there is an error in column input, it won't proceed to checking row input
            if(seat[row-1][col] != 'X'){
                seat[row-1][col] = 'X';         //Reserves seat
                flag = 0;                       //Correct user input
            }else if(seat[row-1][col] == 'X'){
                printf("\tSeat is already taken. Try Again.\n");
                printf("--------------------------------------------------\n");
                flag = 1;                       //Wrong user input
            }
        }
    }
}

//checks the number of seats availabe
void check(){
    for (int row = 0; row < 5; row++) {
        for(int col = 0; col<4; col++){
            if(seat[row][col] != 'X'){      //If seat isn't taken add 1 to counter
                avail++;
            }
        }
    }
}