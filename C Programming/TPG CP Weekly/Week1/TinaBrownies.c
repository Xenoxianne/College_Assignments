/*
* Name: Denise Julianne S. Gozum
* Tina's Brownies
*/
#include<stdio.h>

int main(){
    int t, W, H, N, paper = 1;
    scanf("%d", &t); //input number of tests
    //Forces user to input a value greater than 1 and less than 10000
    while(t<1 || t>10000){
        printf("Invalid input. Try Again\n");
        scanf("%d", &t); //input number of tests
    }
    char *ans[t]; //stores the answer
    
    for(int i = 0; i < t; i++){
        scanf("%d %d %d", &W, &H, &N); //input values
        //Forces user to input the correct value
        while(W<1 || H>10000 || N<1 || N>1000000000){
            printf("Invalid input. Try Again\n");
            scanf("%d %d %d", &W, &H, &N); //input values
        }
        //answer
        if(N == 1){ //only needs 1 piece
            ans[i] = "YES";
        }else{ //Will continue to cut the pieces until it returns an odd number for both W&H
            if(W%2==0 || H%2==0){ //even number
                while(W%2==0){W=W/2; paper*=2;}//cuts width
                while(H%2==0){H=H/2; paper*=2;}//cuts height
                if (N <= paper){ans[i] = "YES";} //if cut is equals to the needed paper
                else{ans[i] = "NO";} //if insuficient number of papers
            }else{ans[i] = "NO";} //odd number
        }paper = 1;
    }
    //prints the answers stored
    for(int j = 0; j < t; j++){
        printf("%s\n", ans[j]);
    }
    return 0;
}