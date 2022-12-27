#include <stdio.h>
#include <stdlib.h>

struct Node {
 int data;
 struct Node* next;
};

struct Node* newNode(int data)
{
 struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
 temp->data = data;
 temp->next = NULL;
 return temp;
}

void arr(struct Node** head_ref, int new_data)
{
 struct Node* temp = newNode(new_data);
 temp->next = (*head_ref);
 (*head_ref) = temp;
}


struct Node* performAddition(struct Node* first,
      struct Node* second)
{

 struct Node* res = NULL;
 struct Node *temp, *prev = NULL;
 int carry = 0, sum;
 while (first != NULL || second != NULL) {
  sum = carry + (first ? first->data : 0)
   + (second ? second->data : 0);

  carry = (sum >= 10) ? 1 : 0;
  sum = sum % 10;

  temp = newNode(sum);

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

void printList(struct Node* head)
{
    if (head == NULL)
       return;
    printList(head->next);
    printf("%d  ", head->data);
}

// A utility function to print a linked list
void Display(struct Node* node){
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(void)
{
 struct Node* result = NULL;
 struct Node* num1 = NULL;
 struct Node* num2 = NULL;

 arr(&num1, 4);
 arr(&num1, 3);
 arr(&num1, 1);
 arr(&num1, 3);
 arr(&num1, 5);


 arr(&num2, 1);
 arr(&num2, 7);
 arr(&num2, 2);


 result = performAddition(num1, num2);
 printf("First List: "); Display(num1);
 printf("Second List: "); Display(num2);
 printf("Result of additon is ");
 printList(result);

 return 0;
}