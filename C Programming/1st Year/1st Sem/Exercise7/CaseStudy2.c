/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Password
*/
#include<stdio.h>
#include<conio.h>
int main(){
    char password[10], ch;
    int a;
    printf("================ Hello User! ================\n");
    printf("Enter your password <8 characters>: ");
    for(a = 0; a<8; a++){ 
        ch = getch(); //takes input char
        password[a] = ch; //stores each input char in password
        ch = '*'; //automatically changes char typed to *
        printf("%c", ch);
    }
    printf("\n=============================================");
    printf("\nYour password is: %s", password); //displays password
    printf("\n=============================================");
    return 0;
}