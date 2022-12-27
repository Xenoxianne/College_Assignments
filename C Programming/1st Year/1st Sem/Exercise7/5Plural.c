/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Plural noun
*/
#include<stdio.h>
#include<string.h>
int main(){
    char noun[80], endsY[80] = " "; 
    printf("============= SINGULAR TO PLURAL ============\n");
    printf("Enter any singular noun: ");
    scanf("%s", noun);
    int length = strlen(noun);

    printf("=============================================\n");
    printf("The plural form of %s is: ", noun);
    if(noun[length - 1] == 'y'){
        strncpy(endsY, noun, length-1);
        printf("%s", strcat(endsY, "ies"));
    } else if(noun[length-1] == 's' || 
    (noun[length-2] == 'c' && noun[length-1] == 'h') ||
    (noun[length-2] == 's' && noun[length-1] == 'h')){
        printf("%s", strcat(noun, "es"));
    } else {
        printf("%s", strcat(noun, "s"));
    }
    printf("\n=============================================\n");
    return 0;
}