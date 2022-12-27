/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* 24hr to 12hr format
*/

#include<stdio.h>

void converter(int hrs, int min){
    if(hrs == 0 || hrs == 24){ //12am
        hrs=12; 
        printf("%.2d:%.2d AM\n",hrs,min);
    }else if(hrs == 12){ //12pm
        hrs=12; 
        printf("%.2d:%.2d PM\n",hrs,min);
    }else if(hrs < 12){ //1am-11:59am
        printf("%.2d:%.2d AM\n",hrs,min);
    }else{ //1pm-11:59pm
        hrs-=12;
        printf("%.2d:%.2d PM\n",hrs,min);
    }
}

int main(){
    int time_24, hrs, min;
    char ans = 'Y';
    //will loop the program
    while(ans == 'Y' || ans == 'y'){
        printf("============================================\n");
        printf("        24-hour to 12-hour converter        \n");
        printf("============================================\n");
        //user input
        printf("Enter time in 24-hour format to convert.\n");
        printf("   (0-2400 only): ");
        scanf("%d", &time_24);
        printf("============================================\n");
        //only takes numbers between 0 2400
        if(time_24>=0 && time_24<=2400){ 
            hrs = time_24/100; //get hrs
            min = time_24%100; //get mins
            if(min<60){ //if minutes is larger than 59
                printf("   24-hour time: %.2d:%.2d\n", hrs, min); //prints 24hr
                printf("   12-hour time: "); //prints 12hr
                converter(hrs, min);
            } else{
                printf("Invalid number of minutes.\n");
            }
        }else{
            printf("Invalid 24-hour time format.\n");
        }
        printf("============================================\n");
        printf("Would you like to try again? (Y/N): ");
        scanf("\n%c", &ans);
    }
    return 0;
}