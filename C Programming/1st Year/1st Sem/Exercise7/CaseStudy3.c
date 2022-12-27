/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 1- 2
* Password + Pig Latin
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>

void Pig_Latin_Converter(){
    char word[80], vowel[]="aeiou", rev[80], first[20], word2[80];
    int length, result;
    printf("\n=============================================\n");
    printf(">            PIG LATIN CONVERTER            <\n");
    printf("=============================================\n");
    printf("Enter any word: ");
    scanf("%s", word);
    strlwr(word); //makes the word lowercase
    //result takes the first char that matches
    length = strlen(word); result = strcspn(word,vowel); 
    printf("=============================================\n");
    printf("\"%s\" in Pig Latin is: ", word);
    if(result == 0 || result == length){ //rule 1 and 2
        printf("%s", strcat(word, "yay"));
    }else{ //rule 3
        strcpy(rev, word); //copies word 1 to 2 (hello = hello)
        strrev(rev); //reverses word (olleh)
        strncpy(word2, rev, (length - result)); //takes number of char (olle)
        strrev(word2); //reverses back (ello)
        strncpy(first, word, result); //takes the front consonants (h)
        printf("%s%say", word2,first);
    }
}

int main(){
    char pass[10] = " ", pass2[10] = " ", ch, ans = 'Y';;
    int a;
    printf("================ Hello User! ================\n");
    printf("Enter a new 8 character password: ");
    for(a = 0; a<8; a++){
        ch = getch(); //takes input char
        pass[a] = ch; //gives each input char to pass array
        ch = '*'; //automatically changes char typed to *
        printf("%c", ch); //prints on screen
    }
    printf("\nYour password is: %s", pass); //displays password
    x:
    printf("\n=============================================\n");
    printf("Enter your password to continue: ");
        for(a = 0; a<8; a++){
            ch = getch();
            pass2[a] = ch;
            ch = '*';
            printf("%c", ch);
        }
        if (strcmp(pass, pass2) != 0){ //password does not match
            printf("\nWrong Password, Try again? (Y/N): ");
            scanf("\n%c", &ans);
            printf("Your password is: %s", pass);
            if(ans == 'y' || ans == 'Y') goto x;
        }else{ //password matches
            Pig_Latin_Converter();
        }
    return 0;
}