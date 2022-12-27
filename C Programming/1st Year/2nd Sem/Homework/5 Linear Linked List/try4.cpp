#include<stdio.h>

struct node { 
int x; 
node *next; 
}; 

int main() { 
node *root; // This won't change, or we would lose the list in memory 
node *conductor; // This will point to each node as it traverses the list 
root = new node; // Sets it to actually point to something 

printf("\n1\nroot: %x", root);
printf("\nnext: %d", root->next);
printf("\nroot: %d", root->x);

root->next = 0; // Otherwise it would not work well 
root->x = 12; 
printf("\n2\nroot: %x", root);
printf("\nnext: %d", root->next);
printf("\nroot: %d", root->x);

conductor = root; // The conductor points to the first node 
printf("\n3\nroot: %x", root);
printf("\next: %d", root->next);
printf("\nroot: %d", root->x);
printf("\nconductor: %x", conductor);
printf("\next: %d", conductor->next);
printf("\nroot: %d", conductor->x);


if ( conductor != 0 ) { 
while ( conductor->next != 0) 
conductor = conductor->next; 
} 
printf("\n0\nroot: %x", root);
printf("\next: %d", root->next);
printf("\nroot: %d", root->x);
printf("\nconductor: %x", conductor);
printf("\next: %d", conductor->next);
printf("\nroot: %d", conductor->x);


conductor->next = new node; // Creates a node at the end of the list
printf("\n4\nroot: %x", root);
printf("\next: %d", root->next);
printf("\nroot: %d", root->x);
printf("\nconductor: %x", conductor);
printf("\nconductor->next: %x", conductor->next);
printf("\next: %d", conductor->next);
printf("\nroot: %d", conductor->x);

conductor = conductor->next; // Points to that node 
printf("\n5\nroot: %x", root);
printf("\next: %d", root->next);
printf("\nroot: %d", root->x);
printf("\nconductor: %x", conductor);
printf("\nconductor->next: %x", conductor->next);
printf("\next: %d", conductor->next);
printf("\nroot: %d", conductor->x);

conductor->next = 0; // Prevents it from going any further 
printf("\n6\nroot: %x", root);
printf("\next: %d", root->next);
printf("\nroot: %d", root->x);
printf("\nconductor: %x", conductor);
printf("\nconductor->next: %x", conductor->next);
printf("\next: %d", conductor->next);
printf("\nroot: %d", conductor->x);

conductor->x = 42;
printf("\n7\nroot: %x", root);
printf("\next: %d", root->next);
printf("\nroot: %d", root->x);
printf("\nconductor: %x", conductor);
printf("\next: %d", conductor->next);
printf("\nroot: %d", conductor->x);

printf("\n%d", conductor->x);

}
