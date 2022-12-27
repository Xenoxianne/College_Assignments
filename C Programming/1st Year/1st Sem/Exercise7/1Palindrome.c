/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Palindrome
*/
#include<stdio.h>
#include<string.h>
int isPalindrome(char orig[]){
    char copy[80];
    strcpy(copy, orig); //copies the value of the input
    strrev(copy); //reverses input
    //compares the value of both the forward and backward spelling of the input
    if(strcmp(copy, orig)){ 
        return 0; //not palindrome
    } else{ return 1; } //palindrome
}
int main(){
    char str[80];
    printf("============= IS IT A PALINDROME? ============\n");
    printf("Enter any word to check if it is a palindrome:\n");
    gets(str); //accepts input with white spaces
    printf("==============================================\n");
    int result = isPalindrome(str); //function call
    if(result == 1){
        printf("%s is a Palindrome", str);
    }else{
        printf("%s is not a Palindrome", str);
    }
    printf("\n==============================================\n");
    return 0;
}
