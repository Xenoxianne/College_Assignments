/*
* Name: Denise Julianne S. Gozum
* TWanted: Bebetime
*/

#include<stdio.h>
#include<string.h>

int main(){
    int n, p, i;
    char month[80], *ans[n][p];;

    scanf("%d", &n); //number of test cases
    //Forces user to input a value greater than 1 and less than 10
    while(n<1 || n>10){
        printf("Error. Try Again.\n"); //REMOVE DIS
        scanf("%d", &n); //number of test cases
    }
    for(int a = 0; a<n; a++){
        printf("# of peeps\n"); //REMOVE DIS
        scanf("%d", &p); //number of people
        //Forces user to input a value greater than 1 and less than 10
        while(p<1 || p>5){
            printf("Error. Try Again.\n"); //REMOVE DIS
            scanf("%d", &p); //number of test cases
        }
        for(int b = 0; b<p; b++){
            scanf("%s %d", month, &i);
            strlwr(month);
            if(strcmp(month, "january")==0 || strcmp(month, "march")==0 || strcmp(month, "july")==0 || strcmp(month, "august")==0 || strcmp(month, "october")==0 || strcmp(month, "december")==0){
                if(i>=1 && i<=31){ans[a][b] = "It's not you, it's me.";}
            }else if(strcmp(month, "june")==0 || strcmp(month, "september")==0|| strcmp(month, "november")==0){
                if(i>=1 && i<=30){ans[a][b] = "It's not you, it's me.";}
            }else if(strcmp(month, "february")==0){
                if(i>=1 && i<=28){ans[a][b] = "It's not you, it's me.";}
            }else if(strcmp(month, "april")==0){
                if(i>=20 && i<=30){ans[a][b] = "It's a match!";}
                else if(i>=1 && i<=19){ans[a][b] = "It's not you, it's me.";}
            }else if(strcmp(month, "may")==0){
                if(i>=1 && i<=20){ans[a][b] = "It's a match!";}
                else if(i>=21 && i<=31){ans[a][b] = "It's not you, it's me.";}
            
            }
        }
    }

    //prints the answers stored
    for(int j = 0; j<n; j++){ //0
        for(int k = 0; k<p; k++){ //0
            printf("%d,%d = %s\n",j, k, ans[j][k]); //0, 0
        }
    }
    return 0;
}