/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* 4 letter word to asterisks
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char str[200];
    int counter = 0; //counts # of words
    printf("================ Four Letter Words ==============\n");
    printf("Enter any number of words/sentences (\"~\" to stop):\n");
    scanf("%[^~]s", str);
    printf("=================================================\n");

    for(int a = 0; a<200; a++){
        if(isalpha(str[a])){ //if it is a letter
            counter++; //add 1 to # of words
        } else{
            if(counter !=4){ //if less than or greater than 4
                counter =0; //reset counter
            }else if(counter == 4){ //if 4 letter word
                str[a - 4] = '*';
                str[a - 3] = '*';
                str[a - 2] = '*';
                str[a - 1] = '*';
                    
                counter = 0; //resets counter
            }
        }
    } printf("%s", str);
    printf("=================================================\n");
    return 0;
}