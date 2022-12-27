/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* FLAMES (friends, lovers, angry, married, enemy, sweetheart)
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int num(char *name1, char *name2){ //length of string
    int n = 0;
    if (strlen(name2)>strlen(name1))
        n=strlen(name1); //first name is longer
    else
        n=strlen(name2); //second name is longer
    return n;
}

int commonLet(char *name1, char *name2){ //identifies common letters
    int n = num(name1, name2), i=0, j, letter = 0;

    for(int i = 0; i<n; i++){ //name1
        for(int j = 0; j<n; j++){ //name2
            if(isalpha(name1[i]) != 0 && isalpha(name2[j]) != 0){ //checks if it is a letter
                if(tolower(name1[i])==tolower(name2[j])){ //turns to lowercase and checks if they're equal
                    if(letter==0){ //first letter
                        printf("%c", name1[i]);
                        letter++; i++; j=-1;
                    }else{ //following letters
                        printf(",%c", name1[i]);
                        i++; j=-1;
                    }
                }
            }
        }
    }
}

int countLet(char *name1, char *name2){ //number of common letters
    int n = num(name1, name2), counter = 0;

    for(int i = 0; i<n; i++){ //name1
        for(int j = 0; j<n; j++){ //name2
            if(isalpha(name1[i]) != 0 && isalpha(name2[j]) != 0){ //checks if it is a letter
                if(tolower(name1[i])==tolower(name2[j])){ //turns to lowercase and checks if they're equal
                    counter++; i++; j=-1;
                    }
                }
            }
        } return counter;
}

int main(){
    char boy[80], girl[80], f[] = "flames";
    int PointB = 0, PointG = 0, Points = 0; 
    printf("=============================================\n");
    printf("                    FLAMES                   \n");
    printf("=============================================\n");
    printf("Name of Boy: "); gets(boy);
    printf("Name of Girl: "); gets(girl);
    printf("=============================================\n");
    PointB = countLet(boy,girl); PointG = countLet(girl,boy);
    Points = PointB + PointG; //adds points
    printf("Number of common letters Boy: %d (", PointB);
        commonLet(boy, girl); printf(")\n");
    printf("Number of common letters Girl: %d (", PointG);
        commonLet(girl, boy); printf(")\n");
    printf("=============================================\n");
    printf("Total Number: %d - ", Points);   
    while (Points>6) Points-=6; //computes
    switch (f[Points-1]){ //identifies what type of relationship
        case 'f': printf("Friends"); break;
        case 'l': printf("Lovers"); break;
        case 'a': printf("Angry"); break;
        case 'm': printf("Marriage"); break;
        case 'e': printf("Enemy"); break;
        case 's': printf("Sweetheart"); break;
        default: printf("Not compatible"); break;
    }
    printf("\n=============================================\n");
    return 0;
}
