/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* function DWARF
*/

#include<stdio.h>
#include<stdlib.h>

void DWARF(int n, int s);    //function declaration

int main(){
   int num, a, sum=0;
   char ans = 'Y';

    while(ans == 'Y' || ans == 'y'){
        //checking of integers        
        do{
            printf("\nEnter a non-negative integer: ");
            scanf("%d", &num);
                if(num<0){
                    printf("Negative integers are not allowed. Please try again.");
                }
        }while(num<0);

        //factors
        printf("Factors are:");
            for(int i=1; i<num; i++){
                if(num%i==0){
                    printf(" %d ", i);
                }
            }

        //Sum of the factors
        printf("\nSum of it's factors: 1");
            for(a=1; a<num; a++){
                if(num%a==0){
                    if(a!=1)
                    printf(" + %d", a);
                    sum+=a;
                }
            }
        printf(" = %d", sum);

        DWARF(num, sum);      //function call

        printf("\n\nTry again (Y/N)? ");
        scanf("\n%c", &ans);
    }
return 0;
}

void DWARF(int n, int s){           //function definition
    //converting int to float
    float half = (float)n/2;

    //DWARF or NOT DWARF
    printf("\nHalf of the number: %d/2 = %.2f", n, half);
    if (s > half){
        printf("\n%d is DWARF", n);
    }else{
        printf("\n%d is NOT DWARF", n);
    }
}