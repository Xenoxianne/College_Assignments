/*
* Name: Denise Julianne S. Gozum
* Number of Moves
*/

#include<stdio.h>

int main(){
    int n, bills = 0, a = 0;
    
    //Input amount to withdraw
    scanf("%d", &n);
    
    //determines number of bills
    if(n>=100){
        a = n/100; n -= a * 100;
        bills += a; a = 0;
    }
    if(n>=20){
        a += n/20; n -= a * 20;
        bills += a; a = 0;
    }
    if(n>=10){
        a += n/10; n -= a * 10;
        bills += a; a = 0;
    }
    if(n>=5){
        a += n/5;  n -= a * 5;
        bills += a; a = 0;
    }
    if(n>=1){bills += n;}

    printf("%d", bills);

    return 0;
}