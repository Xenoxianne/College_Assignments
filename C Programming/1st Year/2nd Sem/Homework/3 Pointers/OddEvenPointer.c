#include <stdio.h>

void sum(double b[]);
int qty;
double SumEven = 0, SumOdd = 0;
int main(){

    printf("Enter number of integers: ");
    scanf("%d", &qty);

    double num[qty];
    printf("Enter %d decimal numbers:\n", qty);
    for(int i = 0; i<qty; i++){
        printf("   %d. ", (i+1));
        scanf("%lf", &num[i]);
    }

    sum(num);

    printf("Sum of the even indexed elements %.2lf\n", SumEven);
    printf("Sum of the odd indexed elements %.2lf", SumOdd);

    return 0;
}

void sum(double b[]){
    int n;
    double *sum_even;
    double *sum_odd;

    //assign pointer to global variable
    sum_even = &SumEven, sum_odd = &SumOdd;

    //qty is a global var. which holds the total no. of data
    for(n = 0; n < qty; n++){
        if(n % 2 == 0){
            *sum_even += b[n];
        }else{
            *sum_odd += b[n];
        }
    }
}