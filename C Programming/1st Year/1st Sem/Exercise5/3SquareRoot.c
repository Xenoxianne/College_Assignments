/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Data sets
*/
#include<stdio.h>
#include<math.h>

int main(){
    int X[20], Y[20], Z[20], N, sum = 0;
    char ans = 'Y';
    //repeats program
    while(ans == 'Y' || ans == 'y'){
        printf("=====================================================\n");
        printf("Fill out the following using a maximum of 20 integers\n");
        printf("=====================================================\n");
        //First List. This will also determine the value of N
        printf("LIST 1\nEnter a maximum of 20 integers. Enter -1 to stop: \n");
        for(N = 0; N < 20;){
            scanf("%d", &X[N]);
            if(X[N] == -1){
                break;
            } N++;
         }
         printf("=====================================================\n");
         //Second list
         printf("LIST 2\nEnter %d integers only: \n", N);
         for(int b = 0; b < N; b++){
            scanf("%d", &Y[b]);
        }
        //Product of the X and Y and storing them to Z
        for(int prod = 0; prod<N; prod++){
            Z[prod] = X[prod]*Y[prod];
            sum+=Z[prod];
        }
        printf("=====================================================\n");
        //displaying square root
        printf("Square root of the items : %.2f", sqrt(sum));

        printf("\n=====================================================\n");
        printf("Would you like to try again? (Y/N): ");
        scanf("\n%c", &ans);
        sum = 0; //reset value of sum
    }
    return 0;
}