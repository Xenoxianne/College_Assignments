/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Opening of account
*/

#include<stdio.h>

struct account{
    char accNum[6], PIN[5]; //account number and PIN
    float bal;  //balance
}add[3];

int main(){
    FILE *createAcc;    //initialize variable for file
    
    createAcc = fopen("accounts.dat", "wb"); //open file
    
    struct account add[3] = {{"12345", "1234", 10000},  //values to be stored in file
                             {"11231", "1123", 20000},  //Acc num, PIN, balance
                             {"05290", "0529", 15000}}; 
    for(int i = 0; i<3; i++)    //save all 3 structure data inside file
        fwrite(&add[i], sizeof(struct account), 1, createAcc);

    fclose(createAcc);  //close file

    return 0;
}