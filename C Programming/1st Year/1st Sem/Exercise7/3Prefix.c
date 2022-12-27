/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Longest Common Prefix
*/
#include<stdio.h>
#include<string.h>

void ComPref(char str1[], char str2[]){
    char com[80] = " ";
    int a = 0; 
    if(str1[a]==str2[a]){ //if the first letters are in common
        printf("The longest common prefix of \"%s\" and \n\"%s\" is: ", str1, str2);
        //takes the number placement of the letters that are common
        for(a = 0; str1[a]==str2[a]; a++);
            strncpy(com, str1, a);  //copies the common letters to com
            printf("%s", com);
    } else { //when no letters are in common
        printf("Empty String");
    }
    printf("\n================================================\n");
}

int main(){
    char str1[80], str2[80];
    printf("============= LONGEST COMMON PREFIX ============\n");
    printf("Enter 2 words to get their longest common prefix\n");
    printf("Word 1: "); scanf("%s", str1);
    printf("Word 2: "); scanf("%s", str2);
    printf("================================================\n");

    ComPref(str1, str2);

    return 0;
}