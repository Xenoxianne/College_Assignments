/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Student name, sum scores, and average of test scores
*/

#include<stdio.h>
#include<string.h>
void TEST(){
    char name[80]; //stores the names
    int ans[5], total = 0.0; //ans[5] stores test scores

    //gets the name of the student
    printf("Enter student name: ");
    scanf("%s", name);
    
    //takes user answer and declares their score
    for(int a = 0; a<5; a++){
        printf("Enter Answer #%d? ", a+1);
        scanf("%d", &ans[a]); //student answer
        //gives the score right after giving the answer
        switch(ans[a]){
            case 1: ans[a] = 1; break;
            case 2: ans[a] = 2; break;
            case 3: ans[a] = 3; break;
            case 4: ans[a] = 4; break;
            case 5: ans[a] = 5; break;
            default: ans[a] = 0;
        }
        total+=ans[a]; //adds up the students score
    }
    printf("===============================================================\n");
    //prints the name in upper case, shows sum, and displays one decimal average by converting int to double
    printf("%s, your total score is %d and your average score is %.1f", strupr(name), total, (double)total/5);
}

int main(){
    char ans = 'Y';
    //repeats program
    while(ans == 'Y' || ans == 'y'){
        printf("===============================================================\n");
        printf("                          TEST SCORES                          \n");
        printf("===============================================================\n");
        TEST();
        printf("\n===============================================================\n");
        printf("Would you like to try again? (Y/N): ");
        scanf("\n%c", &ans);
    }
    return 0;
}
