/*
* Name: Denise Julianne S. Gozum
* Peppa's Science Lab
*/

#include<stdio.h>

int main(){
    int N, count = 0;
    
    //Input number of tests
    scanf("%d", &N);

    int A[N], B[N], C[N];
    
    //Tests case
    for(int i = 0; i<N; i++){
        scanf("%d %d %d", &A[i], &B[i], &C[i]);
        if((A[i]==1 && B[i]==1) || (A[i]==1 && C[i]==1) || (B[i]==1 && C[i]==1)){
            count++;
        }
    }

    printf("%d", count); //prints out number of test cases

    return 0;
}