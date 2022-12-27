/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 2-5
* Add 2 link lists
*/

#include <stdio.h>
#include <stdlib.h>
 
/* Linked list node */
struct node {
    int data;
    struct node* next;
};
 
/* Function to create a new node with given data */
struct node* newNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
 
/* Function to arr a node at the beginning */
void arrData(struct node** headRef, int newData){
    struct node* new_node = newNode(newData);
    new_node->next = (*headRef);
    (*headRef) = new_node;
}

/* Adds two linked lists and return the head node of resultant list */
struct node* Sum(struct node* first, struct node* second){
    struct node* res = NULL;
    struct node *temp, *prev = NULL;
    int carry = 0, sum;

    while (first != NULL || second != NULL) {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = (sum >= 10) ? 1 : 0; // Carry
        sum = sum % 10; // Update sum if it is greater than 10
        temp = newNode(sum); // Create a new node with sum as data
        
        if (res == NULL)    
            res = temp;
        else
            prev->next = temp;
 
        prev = temp;

        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
 
    if (carry > 0)
        temp->next = newNode(carry);
 
    return res;
}

// A utility function to print a linked list
void Display(struct node* node){
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

static void reverse(struct node** head_ref){
    struct node* prev = NULL;
    struct node* curr = *head_ref;
    struct node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head_ref = prev;
}
 
int main(void){
    struct node* res = NULL;
    struct node* first = NULL;
    struct node* second = NULL;
 
    //First List 
    arrData(&first, 4);
    arrData(&first, 3);
    arrData(&first, 1);
    arrData(&first, 3);
    arrData(&first, 5);
    
    //Second List
    arrData(&second, 1);
    arrData(&second, 7);
    arrData(&second, 2);

    printf("====================================\n");
    printf("          Add 2 Link Lists          \n");
    printf("====================================\n");
    
    //Add the two lists and see result
    res = Sum(first, second);
    printf("First List: "); reverse(&first); Display(first);
    printf("Second List: "); reverse(&second); Display(second);
    printf("------------------------------------\n");
    printf(" - Result: "); reverse(&res); Display(res);
    printf("====================================\n");
    
    return 0;
}