/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 2-5
* Unsorted Array A
*/

#include<stdio.h>

int main(){
    char* arr[] = {"Mitch", "Diane", "Jack", "Robbie", "Katherine"};
    int Length  = sizeof(arr)/sizeof(arr[0]), pos;

    //Printing Orriginal Array
    printf("===== Original Unsorted Array =====\n");
    for(int i = 0; i<Length; i++){
        printf("[%d] %s \t| address: %x\n", i, arr[i], &arr[i]);
    }

    //Adding Morrie
    printf("\n======= arring an element ======\n");
    char add[] = "Morrie";
    printf("Enter element position to add Morrie: "); scanf("%d", &pos);
    //Moving elements to the right
    for(int i = Length; i>=pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos-1] = add; //adding Morries

    //Printing all elements + Morrie
    for(int i = 0; i<Length+1; i++){
        printf("[%d] %s \t| address: %x\n", i, arr[i], &arr[i]);
    }

    return 0;
}