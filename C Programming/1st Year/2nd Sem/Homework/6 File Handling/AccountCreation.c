#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

struct account{
    char accNum[5];
    char PIN[4];
    float bal;
} add, check;

int main(){
    char ans = 'Y';
    int checkAccNum;
    FILE *createAcc;

    while(ans == 'Y'){
        system("cls");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("             PUP Online Banking System            \n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

        printf("\n\t\tCREATE NEW ACCOUNT");
        createAcc = fopen("accounts.dat", "a+");

        account_no:
            printf("Enter a account number: "); scanf("%s", check.accNum);
            while(fscanf(createAcc,"%c %c %f\n", &add.accNum, &add.PIN, &add.bal)!=EOF){
            if (check.accNum == add.accNum){
                printf("Account no. already in use!");
                fordelay(1000000000);
                    goto account_no;
            }
    }

        y:
        printf("Do you want to try again? (Y/N)");
        scanf("\n%c", &ans);
        ans = toupper(ans);
        if(ans!='N' || ans!='Y'){
            printf("--------------------------------------------------\n");
            printf("\t   Please enter a valid answer.\n"); 
            printf("--------------------------------------------------\n\n");
            goto y;
        }
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("    Thanks for using PUP Online Banking System    \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    return 0;
}

void fordelay(int j){   
    int i,k;
    for(i=0;i<j;i++)
         k=i;
}