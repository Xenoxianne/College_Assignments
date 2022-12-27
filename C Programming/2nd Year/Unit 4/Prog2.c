/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 2-5
* Sorted Array A
*/

#include<stdio.h>
#include<string.h>

int main(){
    char arr[][30] = {"Mitch", "Diane", "Jack", "Robbie", "Katherine"}, temp[10];
    int Length  = sizeof(arr)/sizeof(arr[0]);

    //Printing Original Array
    printf("===== Original Unsorted Array =====\n");
    for(int i = 0; i<Length; i++){
        printf("[%d] %s \t| address: %x\n", i, arr[i], &arr[i]);
    }

    //Sort Array
    printf("\n========== Sorted Array ===========\n");
    for(int i=0; i<Length; i++){
        for(int j=0; j<Length-1-i; j++){
            if(strcmp(arr[j], arr[j+1]) > 0){
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }
    for(int i = 0; i<Length; i++){
        printf("[%d] %s \t| address: %x\n", i, arr[i], &arr[i]);
    }

    char* arr1[] = {"Diane", "Jack", "Katherine", "Mitch", "Robbie"};
    //Adding Morrie
    printf("\n======= arring an element ======\n");
    char add[] = "Morrie";
    //Moving elements to the right
    for(int i = Length; i>=4; i--){
        arr1[i] = arr1[i-1];
    }
    arr1[4-1] = add; //adding Morrie

    //Printing all elements + Morrie
    for(int i = 0; i<Length+1; i++){
        printf("[%d] %s \t| address: %x\n", i, arr1[i], &arr1[i]);
    }

    //Deleting Jack
    printf("\n======= Deleting an element ======\n");
    for(int i = 0; i<Length+1; i++){
        if(arr1[i] == "Jack"){
            for (int j = i; j < Length; j++)
                arr1[j] = arr1[j+1];
        }
    }

    //Printing all elements - Jack
    for(int i = 0; i<Length; i++){
        printf("[%d] %s \t| address: %x\n", i, arr1[i], &arr1[i]);
    }
    
    return 0;
}