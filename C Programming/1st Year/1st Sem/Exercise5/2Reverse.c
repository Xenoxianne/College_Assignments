/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Reverse Array Values
*/
#include<stdio.h>
int N; //length of array
void REVERSE(int X[], int Y[]){
    int b = N-1;
    //gives the value to Y in reverse order
    for(int a = 0; a<N; a++){
            Y[a] = X[b];
            b--;
    }
    printf("=================================================\n");
    printf("X[]: "); //prints X (original order)
    for(int j = 0; j < N; j++){
        printf("%d ", X[j]);
    }
    printf("\nY[]: "); //print y (reverse order)
    for(int k = 0; k<N; k++){
        printf("%d ", Y[k]);
    }
}

int main(){
    char ans = 'Y';
    //repeats program
    while(ans == 'Y' || ans == 'y'){
        printf("=================================================\n");
        printf(">              REVERSE ARRAY VALUES             <\n");
        printf("=================================================\n");
        printf("How many numbers do you want to enter? ");
        scanf("%d", &N);

        int X[N], Y[N];

        //Values of X (original order)
        printf("Please enter %d values: \n", N);
        for(int i = 0; i<N; i++){
            scanf("%d", &X[i]);
        }

        REVERSE(X, Y); //function call

        printf("\n=================================================\n");
        printf("Would you like to try again? (Y/N): ");
        scanf("\n%c", &ans);
        }
    return 0;
}