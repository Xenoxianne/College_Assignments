#include <stdio.h> 
#include<conio.h> 
#include<malloc.h> 

struct node { 
    int x; 
    struct node *next; 
}; 

int main() { 
    struct node *root, *newnode; // This will be the unchanging first node 
    root = newnode; // Now root points to a node struct 
    root->next = 0; // The node root points to has its next pointer 
    // set equal to a null pointer 
    root->x = 5;

    printf("%d\n", root->x);

    return 0;
} // By using the -> operator, you can modify the node 
// a pointer (root in this case) points to.
