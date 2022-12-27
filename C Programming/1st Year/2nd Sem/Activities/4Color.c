#include<stdio.h>
#include<Windows.h>

int main(){
    int i;
    for(i=0; i<10; i++){
      printf("\033[0;36m");
      printf("Lydinar Dastas");
      Sleep(500);
      system("cls");
      Sleep(500);
    }
    getch();
    return 0;
}
