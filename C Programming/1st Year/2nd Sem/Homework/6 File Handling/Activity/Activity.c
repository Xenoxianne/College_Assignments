#include<stdio.h>

int main(){
    FILE *FILE1;
    FILE1 = fopen("Activity.DAT", "w"); 
    char CYBER[10] = "BARKADA"; 
    fwrite(&CYBER, sizeof(CYBER), 1, FILE1);

    FILE1 = fopen("SAMPLE1.DAT", "r");
    fread(&CYBER, sizeof(CYBER), 1, FILE1);
    printf("%s", CYBER);

    fclose(FILE1);

    return 0;
}