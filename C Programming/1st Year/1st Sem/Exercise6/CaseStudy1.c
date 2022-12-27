/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Abundant, Perfect, or Deficient integer
*/

#include<stdio.h>

int KOMPUTE(int *sum, int num); //function prototype
int main(){
    int N=0, sum=0;
    char ans = 'Y';
    while(ans == 'Y' || ans =='y'){ //will repeat the program as long as user inputs "y"
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+         Abundant, Perfect, or Deficient        +\n");
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        //will loop until a positive integer is given
        do{
            printf("Input any positive integer to check whether it's\ndivisors are DEFICIENT, PERFECT, or ABUNDANT\n");
            printf("   Enter number: ");
            scanf("%d", &N);
            if(N<=0){
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("        Invalid integer. Please try again.        \n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            }
        }while(N<=0);

        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

        //prints out proper divisor 
        printf("Proper divisors are 1");
        for(int i = 2; i < N; i++){
            if(N%i==0){
                printf(", %d", i);
            }
        }

        //adds all proper divisors
        printf("\nSum of proper divisors: 1 ");
        for(int j = 1; j < N; j++){
            if(N%j==0){
                if(j!=1)
                printf("+ %d ", j);
                sum+=j;
            }
        } 
        printf("= %d\n", sum);
        KOMPUTE(&sum, N); //function call

        printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++");;
        printf("\nTry again (Y/N)? ");
        scanf("\n%c", &ans);
    }
    return 0;
}

int KOMPUTE(int *sum, int num){ //function definition
    if(*sum<num){ //deficient
        printf("%d < %d is DEFICIENT", *sum,num);
    } else if(*sum>num){ //abundant
        printf("%d > %d is ABUNDANT", *sum,num);
    } else { //perfect
        printf("%d = %d is PERFECT", *sum,num);
    }

    *sum = 0; //resets value of sum in main()
    return *sum;
}