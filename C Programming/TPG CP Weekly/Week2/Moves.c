/*
* Name: Denise Julianne S. Gozum
* Number of Moves
*/

#include<stdio.h>
#include<math.h>

int main(){
    int t;
    
    //Input number of tests
    scanf("%d", &t);

    int X[t], Y[t]; double ans[t];

    //Tests case
    for(int i = 0; i<t; i++){
        scanf("%d %d", &X[i], &Y[i]);
        ans[i] = fabs(X[i]-Y[i]);
        ans[i] = ceil(ans[i] / 10);
        printf("%d\n", (int)ans[i]);
    }

    return 0;
}