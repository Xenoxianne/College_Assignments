#include<stdio.h>

struct account{
    int accNum, PIN;
    float bal;
}add;

int main(){
    FILE *createAcc;
    
    createAcc = fopen("account.dat", "wb");
    
    struct account add = {12345, 1997, 50000};
    fwrite(&add, sizeof(struct account), 1, createAcc);

    fclose(createAcc);

    return 0;
}

/*while(fread(&myAccount, sizeof(struct account), 1, login)!=NULL)
        printf("%s %s %.2f\n", myAccount.accNum, myAccount.PIN, myAccount.bal);*/