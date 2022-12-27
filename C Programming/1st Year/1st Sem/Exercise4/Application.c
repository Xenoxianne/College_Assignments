/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Applicant resume
*/

#include<stdio.h>
#include<stdlib.h>

int main(){

float ht;
int cit, age, reco;
char ans = 'Y';

    while(ans == 'Y' || ans == 'y'){
        printf("==================================================");
        printf("\n          JEDI KNIGHT ACADEMY APPLICATION");
        printf("\n==================================================");
            printf("\nInput the following:");
            printf("\nHeight: "); scanf("%f", &ht);
            printf("Age: "); scanf("%d", &age);
            printf("Citizenship (1-citizen, 0-not citizen): "); scanf("%d", &cit);
            printf("Recommendation (1-recommended, 0-not recommended): "); scanf("%d", &reco);

        printf("==================================================\n");
                if(reco == 1){ //recommendation
                    printf("\t\t=====ACCEPTED=====");
                }else if(reco == 0){
                    if(cit == 1){
                        if(ht>=200){ //height
                            if(age>20 && age<26){ //age
                                printf("\t\t=====ACCEPTED=====");
                            }else{
                                printf("\t\t=====REJECTED=====");
                            }
                        }else{
                            printf("\t\t=====REJECTED=====");
                        }
                    }else if(cit == 0){ //citizenship
                        printf("\t\t=====REJECTED=====");
                    }else{
                        printf("Wrong citizenship code. Please try again");
                    } 
                }else{
                    printf("Wrong recomendee's code. Please try again.");
                }
        printf("\nTry again (Y/N)?");
        scanf("\n%c", &ans);
    }   
    return 0;
}