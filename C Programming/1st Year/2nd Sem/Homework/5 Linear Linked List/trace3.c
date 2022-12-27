#include <stdio.h> 
#include<conio.h> 
#include<malloc.h> 
struct node { 
    int x; 
    struct node *next; 
}; 

int main() { 
    struct node *root;      // This won't change, or we would lose the list in memory 
    struct node *conductor; // This will point to each node as it traverses the list 
    struct node *newnode;
    root = newnode;        // Sets it to actually point to something 
    root->next = 0;         // Otherwise it would not work well 
    root->x = 12; 
    conductor = root;       // The conductor points to the first node 

    if ( conductor != 0 ) { 
        /*while ( conductor->next != 0){
            conductor = conductor->next; 
        }*/
    } 

    conductor->next = newnode;     // Creates a node at the end of the list
    conductor = conductor->next;    // Points to that node 
    conductor->next = 0;            // Prevents it from going any further 
    conductor->x = 42;

    printf("%d\n", root->x);
    printf("%d", root->next);

    return 0;
}
