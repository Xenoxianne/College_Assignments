/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Equilateral, Scalene, or Isosceles Triangle
*/

#include<stdio.h>

void TRIANGLE(int a, int b, int c){
    if(a==b && b==c){ //all sides are equal
        printf("This is an EQUILATERAL TRIANGLE\n");
    }else if(a==b || b==c || c==a){ //2 sides are equal
        printf("This is a ISOSCELES TRIANGLE\n");
    } else { //no sides are equal
        printf("This is a SCALENE TRIANGLE\n");
    }
}

int main(){
    int a, b, c;
    char ans = 'Y';
    //will repeat as long as user inputs "y"
    while(ans == 'Y' || ans =='y'){
        printf("--------------------------------------------------\n");
        printf(">                Type of Triangle                <\n");
        printf("--------------------------------------------------\n");
        printf("Enter 3 integers to determine the type of triangle\n   INPUT: ");
        scanf("%d %d %d", &a,&b,&c);
        printf("--------------------------------------------------\n");
        TRIANGLE(a,b,c);
        printf("--------------------------------------------------\n");
        printf("Try again (Y/N)? ");
        scanf("\n%c", &ans);
    }
    return 0;
}