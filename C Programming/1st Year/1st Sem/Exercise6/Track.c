/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Running speed per mile
*/
#include<stdio.h>

int min, sec;

int instructions(){
    printf("===============================================\n");
    printf("                SPEED CALCULATOR               \n");
    printf("===============================================\n");
    printf("Hello user!\n");
    printf("\tThis program calculates the speed\nof race track runners in both feet per\nsecond and meters per second.\n");
    printf("-----------------------------------------------\n");
    printf("Kindly input the necessary information:\n");
    printf("Time spent in running 1 mile: \n");
    printf("  - in minutes: ");
    scanf("%d", &min);
    printf("  - in seconds: ");
    scanf("%d", &sec);

    return min, sec;
}

double mpsCalcu(double time){ //meters per second (distance/time)
    return 1609.344/time;
}

double fpsCalcu(double time){ //feet per second (distance/time)
    return 5280/time;
}

int main(){
    char ans = 'y';

    while(ans == 'Y' || ans == 'y'){
        instructions(); //user input and instructions for the program

        double time = (min * 60) + sec; //adds and converts min to sec

        //output
        printf("===============================================\n");
        printf("Your speed per mile is %.2f ft/s or %.2f m/s. \n", fpsCalcu(time), mpsCalcu(time));
        printf("================================================\n");
        printf("Do you want to try again? (Y/N): ");
        scanf("\n%c", &ans);
    }
    return 0;
}