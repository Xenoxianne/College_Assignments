#include <stdio.h>

void sum(int x[]);
int qty;
int main(){

    printf("Enter number of integers: ");
    scanf("%d", &qty);

    int num[qty];
    printf("Enter %d integers:\n", qty);
    for(int i = 0; i<qty; i++){
        printf("   %d. ", (i+1));
        scanf("%d", &num[i]);
    }

    sum(num);

    return 0;
}

void sum(int x[]){
    int n;
    int sum_even;
    int sum_odd;

    sum_even = 0, sum_odd = 0; //removes gigo

    //qty is a global var. which holds the total no. of data
    for(n = 0; n < qty; n++){
        if(n % 2 == 0){
            sum_even += x[n];
        }else{
            sum_odd += x[n];
        }
    }

    //output
    printf("Sum of the even indexed elements %d\n", sum_even);
    printf("Sum of the odd indexed elements %d", sum_odd);
}
