/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 2-5
* Unsorted Array B
*/

#include<stdio.h>

int main(){
    char* arr[] = {"Mitch", "Diane", "Jack", "Robbie", "Katherine"};
    int Length  = sizeof(arr)/sizeof(arr[0]), pos;

    //Printing Original Array
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
    arr[pos-1] = add; //adding Morrie

    //Printing all elements + Morrie
    for(int i = 0; i<Length+1; i++){
        printf("[%d] %s \t| address: %x\n", i, arr[i], &arr[i]);
    }

    //Deleting Jack
    printf("\n======= Deleting an element ======\n");
    for(int i = 0; i<Length+1; i++){
        if(arr[i] == "Jack"){
            for (int j = i; j < Length; j++)
                arr[j] = arr[j+1];
        }
    }

    //Printing all elements - Jack
    for(int i = 0; i<Length; i++){
        printf("[%d] %s \t| address: %x\n", i, arr[i], &arr[i]);
    }

    return 0;
}