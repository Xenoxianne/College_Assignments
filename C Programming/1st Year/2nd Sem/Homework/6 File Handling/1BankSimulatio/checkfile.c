/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Opening of account
*/

#include<stdio.h>

struct account{
    char accNum[6], PIN[5];
    float bal;
}add[3], check;

int main(){
    FILE *createAcc;
    
    createAcc = fopen("accounts.dat", "rb");
    while(fread(&check, sizeof(struct account), 1, createAcc)!=NULL)
        printf("%s %s %.2f\n", check.accNum, check.PIN, check.bal);

    fclose(createAcc);

    return 0;
}