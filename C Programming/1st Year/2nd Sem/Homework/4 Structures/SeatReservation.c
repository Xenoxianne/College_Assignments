    /*
    * SEAT RESERVATION
    * GROUP 7 (BSCS 1-2)
    * - Gozum, Mabalot, Mangalindan
    */

    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>

    struct seat{
        char A, B, C, D;
    };

    //Initialization of seats
    struct seat seats[5]={
        {'A', 'B', 'C', 'D'},
        {'A', 'B', 'C', 'D'},
        {'A', 'B', 'C', 'D'},
        {'A', 'B', 'C', 'D'},
        {'A', 'B', 'C', 'D'}
    };

    void book();                            //booking for a ticket
    void available(int choice);             //shows available seats to users
    void info(int ticket);                  //takes user info
    void assign(int row, char colLet);      //assigns seat number
    void check();                           //checks the number of seats available

    int errorRowCol = 0, avail = 0;         //avail = total seats avail
    static int count = 0;                   //counter for number of tickets to avail

    //seat reservation
    struct reserve{
        char fname[80];
        char lname[80];
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
            printf("\n----- What do you want to do [1-3]? ");
            scanf("%d", &choice);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

            switch(choice){
                case 1: book(); break;
                case 2: available(choice); break;
                case 3:
                    y:
                    printf("Do you really want to exit the program? (Y/N): ");
                    scanf("\n%c", &ans);
                    if(ans=='Y' || ans=='y'){
                        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                        printf("                Have a great day! \n");
                        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                        system("PAUSE"); //so program won't automatically exit
                    }else if(ans=='N' || ans=='n'){
                        system("cls");
                    }else{
                        printf("--------------------------------------------------\n");
                        printf("\t   Please enter a valid answer.\n"); 
                        printf("--------------------------------------------------\n\n");
                        goto y;
                    }
                    break;
                default:
                    printf("\tInvalid selection. Try again\n");
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    system("PAUSE");
                }count = 0; avail = 0;//resets counter for new user
            }
        return 0;
    }

    //books ticket
    void book(){
        system("cls");
        int toReserve = 0;
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
            printf("-----> Number of Tickets: "); scanf("%d", &toReserve); printf("\n");  //takes number of tickets
            //If there are still available seats yet not enough for the number of tickets user will avail
            if(avail < toReserve){
                printf("==================================================\n");
                printf("\n\tSorry. Not Enough Seat Available.\n");
                printf("\t\tSEATS AVAILABLE: %d\n", avail);
                printf("\n==================================================\n");
            }else{
                avail = 0;                     //resets count availability to 0
                while(count<toReserve){
                    available(0);              //prints available seats (changes everytime user makes a reservation)
                    info(count);               //takes user info
                    if(errorRowCol == 0)       //If there's an error in row/col input, program will repeat user input for that ticket number
                        count++;
                }
                available(0);            //prints final available seats for user to see
                printf("\n=============== %d SEAT/S RESERVED! ===============\n", toReserve);
            }
        }
        system("PAUSE"); //Pause before going back to main menu
    }

    //Outputs Available seats
    void available(int choice){
        //for main availability
        if(choice == 2){
            system("cls");
            printf("\n==================================================\n");
        }

        //for book()
        check();
        printf("\t\t SEATS AVAILABLE: %d\n\n", avail);
        for (int row = 0; row < 5; row++) {
            printf("\t%d   |\t", row+1);
            printf("%c\t%c\t%c\t%c\t", seats[row].A, seats[row].B, seats[row].C, seats[row].D );
            printf("\n");
        }

        //for main availability
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
        printf("  - First name: "); scanf("%s", res[ticket].fname);                     //first name
        printf("  - Last name: "); scanf("%s", res[ticket].lname);                      //last name
        printf("  - Enter seat row (1-5): "); scanf("%d", &res[ticket].seatrow);        //seat row
        printf("  - Enter seat column (A-D): "); scanf("\n%c", &res[ticket].seatcol);   //seat column
        printf("--------------------------------------------------\n");
        assign(res[ticket].seatrow, res[ticket].seatcol);
    }

    //Assigns seat number
    void assign(int row, char colLet){

        //Column
        colLet = toupper(colLet);       //Turns column input into upper case
        int col = 0, seatTaken = 0;         //col = column number, error = error in column
        switch (colLet){                //Assigns column letter to its corresponding struct number
            case 'A': col = 1; break;
            case 'B': col = 2; break;
            case 'C': col = 3; break;
            case 'D': col = 4; break;
            default:
                printf("\t  Invalid Column Input. Try Again.\n");
                printf("--------------------------------------------------\n");
                errorRowCol = 1; seatTaken = 1;
        }

        //Row
        if((row-1)>4){
            printf("\t  Invalid Row Input. Try Again.\n");
            printf("--------------------------------------------------\n");
            errorRowCol = 1;                        //Wrong row and col user input
        }else{
            if(seatTaken != 1){                     //If there is an error in column input, it won't proceed to checking row input
                if(col==1 && seats[row-1].A != 'X'){
                    seats[row-1].A = 'X';           //Reserves seat
                    errorRowCol = 0;                //No errors
                }else if(col==2 && seats[row-1].B != 'X'){
                    seats[row-1].B = 'X';           //Reserves seat
                    errorRowCol = 0;                //No errors
                }else if(col==3 && seats[row-1].C != 'X'){
                    seats[row-1].C = 'X';           //Reserves seat
                    errorRowCol = 0;                //No errors
                }else if(col==4 && seats[row-1].D != 'X'){
                    seats[row-1].D = 'X';           //Reserves seat
                    errorRowCol = 0;                //No errors
                }else{
                    printf("\tSeat is already taken. Try Again.\n");
                    printf("--------------------------------------------------\n");
                    errorRowCol = 1; //Seat already taken
                }
            }
        }
    }

    //checks the number of seats available
    void check(){
        for (int row = 0; row < 5; row++) {
            if(seats[row].A != 'X')
                avail++;                //If seat isn't taken add 1 to counter
            if(seats[row].B != 'X')
                avail++;                //If seat isn't taken add 1 to counter
            if(seats[row].C != 'X')
                avail++;                //If seat isn't taken add 1 to counter
            if(seats[row].D != 'X')
                avail++;                //If seat isn't taken add 1 to counter
        }
    }