#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1
struct TEMPLATE{
	char name[15];
	int age;
	struct TEMPLATE *next;
};

int main(){
    //2
    struct TEMPLATE *HEAD, *TAIL, *CURRENT;
    
    //3
    CURRENT = (struct TEMPLATE*)malloc(sizeof(struct TEMPLATE));

    //4
    strcpy(CURRENT->name, "Loyda");

    //5
    CURRENT->age = 24;

    //6
    CURRENT->next = NULL;

    //7
    HEAD = CURRENT;

    //8
    TAIL = CURRENT;

    //9
    CURRENT = (struct TEMPLATE*)malloc(sizeof(struct TEMPLATE));

    //10
    scanf("%s", CURRENT->name);
    scanf("%d", &CURRENT->age);

    //11
    CURRENT->next = NULL;
    HEAD->next = CURRENT; 
    TAIL = CURRENT;

    //12
    CURRENT = HEAD;
	printf("%s\n", CURRENT->name); 
    printf("%d\n", CURRENT->age); 

    //13
    CURRENT = TAIL;
	printf("%s\n", CURRENT->name); 
    printf("%d\n", CURRENT->age); 

    return 0;
}
