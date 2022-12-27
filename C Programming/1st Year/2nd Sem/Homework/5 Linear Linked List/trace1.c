#include <stdio.h> 
#include<conio.h> 
#include<malloc.h> 
struct roy { 
int Item; 
struct roy *next; 
}; 

void main() { 
struct roy *r1,*r2,*r3; 

r1 = (struct roy *) malloc (sizeof(struct roy)); 
r2 = (struct roy *) malloc (sizeof(struct roy)); 
r3 = (struct roy *) malloc (sizeof(struct roy)); 


r1->Item = 357; 
r1->next = NULL; 

r2->Item = 5654; 
r2->next = NULL; 

r3->Item = 14344; 
r3->next = NULL; 

r2->next = r3; 
r3 = r1; 

r1 =r2 ->next; 
r3->next = r2; 

r1->next = r1; 

/*printf("%d\n", r1->Item); 
printf("%d\n", r2->Item); 
printf("%d\n", r3->Item); */

}
