/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Goldbach conjecture
*/
#include<stdio.h>

#define START 700
#define FINISH 1100

int is_prime(int n){ //checks if an integer is prime or not
    if(n==1){
        return 1;
    }else{
        for(int i = 2; i < n; i++){
            if(n%i==0){ //not prime
                return 1;
                break;
            }
        } 
        return 0; //is prime
    }
}

void goldbach(int n){
    int a = 0; //list for the leftmost  addends
    for(int b=n; b>0; b--){ //list the rightmost addends
        if(is_prime(a)==0 && is_prime(b)==0){ //checks if both addends are prime
            printf("%d = %d + %d\n", n, a, b); //output
            break;
        }
        a++;
    }
}

int main(){
    printf("******************************************\n");
    printf("            Goldbach Conjecture           \n");
    printf("    Start = %d \t Finish = %d        \n", START, FINISH);
    printf("******************************************\n");
    if(START>2){ //checks if start is greater than 2
        for(int n = START; n <= FINISH; n++){ 
            if(n%2==0){ //takes all even numbers
                goldbach(n);
            }
        }
    }    
    return 0;   
}