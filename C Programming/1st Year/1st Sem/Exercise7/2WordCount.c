/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Palindrome
*/
#include<stdio.h>
#include<string.h>

void wordCount(char word[200]){ //checks word count for all the paragraph
	int cell[200] = { 0 }, i, set = 0;
    char *point; point = word;

    for (i = *point++;  i != 0;  i = *point++) {
        if (i == ' ' || i == '\n') {
            cell[set] += 1;
            set = 0;
        }
        else
            set += 1;
    }
    cell[set] += 1; 

    for (set = 1; set < sizeof(cell)/sizeof(cell[0]); set++) {
        int count = cell[set];
        if (count > 0)
            printf("   %d Word(s) with %d Letter(s)\n",count, set);
    }
}

int main(){
    char str[200];
    int word = 0, line = 1;
    printf("================= Number of Words =================\n");
    printf("Enter any number of words/sentences (\"~\" to stop):\n");
    scanf("%[^~]s", str);
    printf("===================================================\n");

    printf("Word Count \n");
    for(int a = 0; str[a]!='\0'; a++){ //checks until last paragraph
        if(str[a]=='\n'){ //checks until there is a newline
            line++; //add line
            word++; //add word
            printf("   Line %d: %d words\n", line, word);
            word = 0; //reset word count
        }else{
            if(str[a]==' ' || str[a]=='\t'){ //checks per word after spacing
                word++;    
            }
        }
    }printf("\nTotal number of words: \n"); wordCount(str);
    printf("===================================================");
    return 0;
}