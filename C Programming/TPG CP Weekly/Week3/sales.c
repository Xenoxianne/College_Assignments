#include<stdio.h>

int main(){
    int s[3], c[3], ans[3];
    
    for(int a = 0; a<3; a++){
        scanf("%d %d", &s[a], &c[a]);
        ans[a] = s[a] - c[a];
    }

    if(ans[0]>ans[1] && ans[0]>ans[2]){
        printf("One in a million!");
    }else if(ans[1]>ans[0] && ans[1]>ans[2]){
        printf("How you like that?");
    }else{
        printf("Happiness!");
    }

    return 0;
}