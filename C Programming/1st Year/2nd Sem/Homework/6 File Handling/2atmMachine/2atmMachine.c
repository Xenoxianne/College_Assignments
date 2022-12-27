/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* ATM Machine Simulator
*/

//Account num, PIN, and balance depends on what is written in the accounts.dat file

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

struct account{
    int accNum, PIN;
    float bal;
}myAccount;

FILE *loginFile;    //for original file

int menu();                 //main menu
char repeat(char again);    //question if user wants to repeat the program
void balance();             //checks and updates balance
void fordelay(int j);       //slight pause before clearing the screen

int main(){
    int checkAccNum, checkPIN;  //acc number and acc PIN

    loginAgain:
        system("cls");  //clears screen
        printf("========== PUP Online Banking System ==========\n");

        loginFile = fopen("account.dat", "rb"); //opens file for account
        if(loginFile == NULL){                  //if file does not have any content
            printf("-----------------------------------------------\n");
            printf("             Error in opening file             \n");
            printf("-----------------------------------------------\n");
            return 0;   //close the program
        }else{          //if file has content
            printf("\n   Enter account number: \t"); scanf("%d", &checkAccNum); //user input for account num
            fread(&myAccount, sizeof(struct account), 1, loginFile);            //takes in contents of account file
            if(checkAccNum == myAccount.accNum){    //if account exists
                for(int i = 0, a = 3; i<3; i++){    //allows user to input up to 3x 
                    printf("   Enter PIN: \t\t\t"); scanf("%d", &checkPIN); //user input for PIN
                    if(checkPIN != myAccount.PIN && a!=0){  //if PIN does not match with acc num
                        printf("\n-------------------------------------------------\n");
                        printf("          Incorrect PIN! %d chance/s left.        \n", --a);
                        printf("-------------------------------------------------\n\n");
                    }else break;    //cancels loop if PIN matches acc num

                    if(a==0){   //if user enters incorrect PIN 3x, account is "assumed" to belocked
                        fordelay(1000000000);
                        system("cls");
                        printf("-------------------------------------------------\n");
                        printf("\tYour account has been locked.\n  Please contact your Bank's Customer Services.");
                        printf("\n-------------------------------------------------\n");
                        return 0;
                    }
                    printf("   Account Number: \t\t%d\n", myAccount.accNum);
                }
                printf("\n===============================================\n");
                fclose(loginFile);  //closes file
                printf("Loading");
                for(int i=0;i<=6;i++){
                    fordelay(100000000);
                    printf(".");
                } 
                balance(); 
            }else{  //if account does not exist
                printf("\n-------------------------------------------------\n");
                printf("             Account does not exist!             \n");
                printf("-------------------------------------------------\n");
                fordelay(1000000000);
                goto loginAgain;
            }
        }
    return 0;
}

void balance(){
    FILE *filetemp; //for temporary file
    char again = 'Y';   //variable for repetition

    while(again == 'Y'){    //repeats the program
        menu(); //main program
        
        loginFile = fopen("account.dat", "wb");
        fwrite(&myAccount, sizeof(struct account), 1, loginFile);    //overwrites file to save new balance
        fclose(loginFile);  //close file

        again = repeat(again);  //repeat the program as user wishes to
    }
    system("cls");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("            Please take your receipt!            \n");
    printf("  Thank you for using PUP Online Banking System!  \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int menu(){
    int ans;    //choice
    float cash = 0; //money to deposit or withdraw
    
    menu:
        system("cls");
        printf("\xB2\xB2\xB2\xB2  Welcome to PUP-On-Line Banking Systems \xB2\xB2\xB2\xB2\n");
        printf("\n\t[ 1 ] Balance Inquiry\n\t[ 2 ] Deposit\n\t[ 3 ] Withdraw\n");
        printf("\n--- Press the number of your choice: ");
        scanf("%d", &ans);

        switch(ans){
            case 1: //balance inquiry
                system("cls");
                printf("================ Balance Inquiry ================\n\n");
                printf("   Current balance is: \tP%.2f", myAccount.bal);
                printf("\n\n=================================================\n");
                break;
            case 2: //deposit
                system("cls");
                printf("==================== Deposit ====================\n\n");
                printf("   Current balance is: \t\tP%.2f\n", myAccount.bal);
                printf("   Enter amount to deposit:\tP"); scanf("%f", &cash);
                myAccount.bal += cash;  //adds cash to previous balance
                printf("\n--------------------------------------------------\n");
                printf("\n   You have deposited: \t\tP%.2f", cash);
                printf("\n   Your new balance is: \tP%.2f", myAccount.bal);
                printf("\n\n=================================================\n");
                break;
            case 3: //withdraw
                system("cls");
                printf("==================== Withdraw ===================\n\n");
                if(myAccount.bal == 0){ //if balance is 0
                    printf("  You currently have 0 balance in your account.");
                }else{
                    printf("   Current balance is: \t\tP%.2f\n", myAccount.bal);
                    printf("   Enter amount to withdraw:\tP"); scanf("%f", &cash);
                    printf("\n--------------------------------------------------\n");
                    if(myAccount.bal < cash){   //if cash to withdraw is greater than users balance
                        printf("\t      Insufficient balance.\n"); 
                        printf("--------------------------------------------------\n");
                        printf("\n   Current balance is: \t\tP%.2f", myAccount.bal);
                    }else{  //if cash to withdraw is enought for user to withdraw
                        myAccount.bal -= cash;  //deducts the amount to withdraw from the previous balance
                        printf("\n   You have withdrawn: \t\tP%.2f", cash);
                        printf("\n   Your new balance is: \tP%.2f", myAccount.bal);
                    }
                }
                printf("\n\n=================================================\n");
                break;
            default: //not part of the choices
                printf("--------------------------------------------------\n");
                printf("\t   Please enter a valid answer.\n"); 
                printf("--------------------------------------------------\n\n");
                fordelay(1000000000); goto menu;
        }
}

char repeat(char again){
    question:
        printf("Would you like to do another transaction?(Y/N): "); scanf("\n%c", &again);  //takes user input for repeating the program
        again = toupper(again); //turns input to uppercase
        if(again!='Y' && again!='N'){   //wrong user input
            printf("--------------------------------------------------\n");
            printf("\t   Please enter a valid answer.\n"); 
            printf("--------------------------------------------------\n\n");
            goto question;
        }else{  //correct input
            return again;
        }
}

void fordelay(int j){   
    int i,k;
    for(i=0;i<j;i++)
        k=i;
}