/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* FLAMES (friends, lovers, angry, married, enemy, sweetheart)
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char boy[80], girl[80], *LetB, LetG, *bb, *gg, *bbb, *ggg;
    int PointB = 0, PointG = 0; 
    printf("=============================================\n");
    printf("                    FLAMES                   \n");
    printf("=============================================\n");
    printf("Name of Boy: "); gets(boy);
    printf("Name of Girl: "); gets(girl);
        for(int a = 0; a<strlen(boy); a++){
            for(int g = 0; g<strlen(girl); g++){
                if(isalpha(boy[a]) != 0 && isalpha(girl[g]) != 0){
                    if(tolower(boy[a])==tolower(girl[g])){
                        PointB++;
                        bb = strpbrk(boy, girl);
                    }
                }
            }
            for(int b = 0; b<strlen(boy); b++){
                if(isalpha(boy[a]) != 0 && isalpha(girl[a]) != 0){
                    if(tolower(boy[b])==tolower(girl[a])){
                        PointG++;
                        gg = strpbrk(girl, boy);
                    }
                }
            }
        }
    printf("=============================================\n");
    printf("Number of common letters Boy: %d", PointB);
        for(int i = 0; i<strlen(boy); i++){
            strcpy(LetB, boy);
            strncpy(bbb, &LetB[i], strlen(boy));
            bbb = strpbrk(bbb, girl);
            printf(", %c", *bbb);
        }
    
    int points = PointB + PointG;
    printf("\nNumber of common letters Girl: %d", PointG);
    printf("\nTotal Number: %d - ", points);
    
    switch (points%6){
        case 1: printf("Friends"); break;
        case 2: printf("Lovers"); break;
        case 3: printf("Angry"); break;
        case 4: printf("Marriage"); break;
        case 5: printf("Enemy"); break;
        default: printf("Sweetheart"); break;
    }
   
    return 0;
}

/*Write a program to ask the user to input the name of boy and name of girl. Count the number of common letters to their names and add them up. Determine the corresponding equivalent using the game FLAMES! 
Example 
Name of Boy : John Victor Name of Girl : Vicenta Joy 
Number of common letters Boy: 8 (J, o n,V,i,c,t,o) 
Name of common letters Girl : 7 (V,i,c,n,t,J,o)
Total Number : 15 – Angry */
