/*
    ACTIVITY 6: Linear Search
    GROUP 12
    Gozum, Denise Julianne
    Odias, Marc Lindon
    Ortega, Gladywin Faye
*/

#include <stdio.h>
#include <stdlib.h>

int key;

void search (int q, int *x);

int main(){
    char ans = 'Y'; //repeat program
    while(ans == 'Y' || ans == 'y'){
        int n, *data;
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("                  Linear Search \n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        //Total number of input
        printf("Enter no. of data: ");
        scanf(" %d", &n);
        data = (int*) malloc (n *sizeof (int)); //to treat the pointer variable as an array

        //input data
        printf("Enter data: ");
        for (int i = 0; i < n; i++){
            scanf(" %d", (data+i)); //can also be written as &data[i]
        }

        //Number to search
        printf("\nSearch key: ");
        scanf("%d", &key);
        search(n, data);

        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Do you want to try again? (Y/N): "); //try again
        scanf("\n%c", &ans); printf("\n");
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                Have a great day! \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    system("PAUSE"); //so program won't automatically exit

    return 0;
}

void search (int q, int *x){
    int p, y=0; 

    //searches each data if it is equal to key
    for (p = 0; p < q; p++){
        if (*(x+p) == key){ //can also be written as &data[i]
            printf("Location: ");
            printf("%d is at x + %d.\n", key, p);
            y=1;
        }
    }
    
    //Search key not found
    if (y != 1){
        printf ("Search key is not in the given data. Try again.");
        printf("\nSearch key: ");
        scanf("%d", &key);
        search(q, x);
    }
}