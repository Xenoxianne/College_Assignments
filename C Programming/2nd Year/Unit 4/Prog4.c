/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 2-5
* Circular Linked List
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * nextptr;
}*savenode;

//Created node
void CreateList(int n){
    int num;
    struct node *curr, *newnode;

    if(n >= 1){
        savenode = (struct node *)malloc(sizeof(struct node));

        printf("  - Input data for node 1: ");
        scanf("%d", &num);
        savenode->data = num;
        savenode->nextptr = NULL;
        curr = savenode;
        for(int i=2; i<=n; i++){
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("  - Input data for node %d: ", i);
            scanf("%d", &num);
            newnode->data = num;
            newnode->nextptr = NULL;	// next address of new node set as NULL
            curr->nextptr = newnode;	// link prev node to newnode
            curr = newnode;   		    // move current node
        }
        curr->nextptr = savenode; 		//last node is linking with first node
    }
}

//Print out node values
void Display(){
    struct node *temp;
    int n = 1;

    if(savenode == NULL){
        printf("No data found in the List yet.\n");
    }else{
        temp = savenode;
        printf("==============================\n");
        printf("Data entered in the list are:\n");

        do{
            printf("  - Data %d = %d\n", n, temp->data);

            temp = temp->nextptr;
            n++;
        }while(temp != savenode);
    }
}

int main(){
    int n;
    savenode = NULL;
    char exit = 'Y'; //exit menu
        
    while(exit == 'Y' || exit == 'y'){
        system("cls");
        printf("==============================\n");	
        printf("     Circular Linked List     \n");
        printf("==============================\n");	   	
        printf("Input the number of nodes: ");
        scanf("%d", &n);
        printf("------------------------------\n");	   	   		
    
        CreateList(n); 
        Display();
        printf("==============================\n");
        printf("Try again? (Y/N): "); scanf("\n%c", &exit);
    }
    printf("==============================\n");
    printf("       HAVE A GREAT DAY!      \n");
    printf("==============================");

    return 0;
}