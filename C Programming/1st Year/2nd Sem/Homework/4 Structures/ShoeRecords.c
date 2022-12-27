/*
* SHOE RESERVATION
* GROUP 10 BSCS 1-2
* - Gozum, San Jose, Javier
*/

#include<stdio.h>
#include<stdlib.h>  //system()
#include<string.h>  //memset()

struct size{
	int stock;	            // mag default tayo ng 5 stocks?
};

struct style{
    float price;            // price na ililink sa sa style
	struct size umu[12];	// nasa loob ng size yung price and number of pairs on hand
}sty[51] = {{1000.5, {5, 7, 8, 9, 3, 4, 1, 6, 10, 2, 11, 12}},
           {2400.90, {8, 7, 0, 6, 4, 5, 0, 2}}};

void newRecord();
void display();
void changePrice();
void changeStock();
int check();
int Avail(int isAvail);
char again(char ans);
int show(int stock);

int ch, available = 51; //alt. system pause, available slots

int main(){
    char ans = 'N'; //repeat program
    int choice;
    while(ans == 'N' || ans == 'n'){
        system("cls");  //clear screen
        check();
        //Menu Program
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t  GSJ Shoe Stocks \n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t   Current number of styles: %d/51\n", (51 - available));
        printf("\n\t[1] Enter a new record");
        printf("\n\t[2] Display a record");
        printf("\n\t[3] Change the price of stock item");
        printf("\n\t[4] Change the quantity on hand");
        printf("\n\t[5] Exit");
        printf("\n\n----- What do you want to do [1-5]? ");
        scanf("%d", &choice);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

        available = 51;

        switch(choice){
            case 1: newRecord(); break;
            case 2: display(); break;
            case 3: changePrice(); break;
            case 4: changeStock(); break;
            case 5:
                y:
                    printf("Do you really want to exit the program? (Y/N): ");
                    scanf("\n%c", &ans);
                    if(ans=='Y' || ans=='y'){
                        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                        printf("                Have a great day! \n");
                        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                        system("PAUSE"); //so program won't automatically exit
                        return 0;        //Exit program
                    }else if(ans=='N' || ans=='n'){
                        system("cls");
                    }else{
                        printf("--------------------------------------------------\n");
                        printf("\t   Please enter a valid answer.\n");
                        printf("--------------------------------------------------\n\n");
                        goto y;
                    }break;
            default:
                printf("\tInvalid selection. Try again\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                system("PAUSE");
            }available = 51; //reset availability
        }
    return 0;
}

//Creates a new record
void newRecord(){
    static int numSize, shoeSize, exist[51][12] = {}, notAvail, c = -1, count = 0;  //numbe rof shoe size, shoe size, stores stocks entered, stock # already used, counter
    int isAvail = 0;    //if stock # is not used
    char ans = 'Y';     //repeats program
    while(ans == 'Y' || ans == 'y'){
        c++;
        system("cls");
        memset(exist, 0, 51*12*sizeof exist[0][0]);     //array set to 0
        check();
        printf("=========================================================\n");
        printf("\t\t      NEW RECORD\n");
        printf("\t     Current number of styles: %d/51\n", (51 - available));         //shows number of available styles
        printf("=========================================================\n");

        //Stock number
        printf("Enter stock number (0 - 50 only): "); scanf("%d", &isAvail);
            while(isAvail < 0 || isAvail > 50){   //Entered number is invalid
                printf("\nInput should be between 0 - 50 only. Try Again.");
                printf("\nEnter stock number (0 - 50 only): "); scanf("%d", &isAvail);
            }
        notAvail = Avail(isAvail);   //checks if the stock # has no existing product
        if(notAvail != 0){          //Stock # has existing product is notAvail
            printf("\n=========================================================");
            printf("\n\t   Record for stock %d already exists.", isAvail);
            isAvail = 0;
        }else{
            printf("---------------------------------------------------------");
            printf("\nEnter details for STOCK # %d", isAvail);

            //Getting stock price
            printf("\n   - Price: P"); scanf("%f", &sty[isAvail].price);
            while(sty[isAvail].price <= 0){             //If entered num is 0
                printf("\nError! Price should be > 0. Try Again.");
                printf("\n   - Price: "); scanf("%f", &sty[isAvail].price);
            }

            //number of shoe sizes to enter
            printf("   - How many shoe sizes do you need?\n     (up to 12 only): "); scanf("%d", &numSize);
                while(numSize < 0 || numSize > 12){       //Entered number is invalid
                    printf("\nInput should be between 0 - 12 only. Try Again.");
                    printf("\n   - How many shoe sizes do you need?\n     (up to 12 only): "); scanf("%d", &numSize);
                }

            //Getting Shoe Size and Stocks
            for(int b = 0; b < numSize; b++){
                //Shoe Size
                printf("\n   %d.) Shoe Size (size 3-14 only): ", b+1); scanf("%d", &shoeSize);
                x:
                    while(shoeSize < 3 || shoeSize > 14){           //Entered shoesize is invalid
                        printf("\nError! Shoe size should be between 3 - 14 only. Try Again.");
                        printf("\n   %d.) Shoe Size (3-14 only): ", b+1); scanf("%d", &shoeSize);
                    }
                    while(exist[c][shoeSize-3] == 1){               //Entered shoesize has already been encoded
                        printf("\nError! Shoe size has been encoded already. Try Again.");
                        printf("\n   %d.) Shoe Size (3-14 only): ", b+1); scanf("%d", &shoeSize);
                        goto x; //checks if shoe size exists
                    }

                //Stocks per size
                printf("       Number of Stocks: "); scanf("%d", &sty[isAvail].umu[shoeSize - 3].stock);
                    while(sty[isAvail].umu[shoeSize - 3].stock < 1){      //Entered stock is invalid
                        printf("\nError! number of stocks should be < 0. Try Again.");
                        printf("\n       Number of Stocks: "); scanf("%d", &sty[isAvail].umu[shoeSize - 3].stock);
                    }
                exist[c][shoeSize-3] = 1;    //to catch repeating shoesize
            }count++;
            show(isAvail);
            printf("\n============== STOCK %d SUCCESSFULLY ADDED! =============\n", isAvail);
        }
    memset(exist, 0, 51*12*sizeof exist[0][0]);     //resets array to 0
    exit:
        if(isAvail == 0) printf("\n=========================================================");
        printf("\nDo you want to try again? (Y/N): ");
        ans = again(ans); available = 51;
        if(ans == 'E') goto exit;
    }
        printf("=========================================================\n");
        while (ch = getchar() != '\n' && ch != EOF);    // keeps grabbing chars until none left
        printf("Back to main menu . . ."); getchar();   // NOW pause the program
}

//Shows available stocks
void display(){
    static int notAvail = 0; int choice, isAvail = 0;
    char ans = 'N';
    while(ans == 'N' || ans == 'n'){
        system("cls");
        check();   //checks number of styles are available
        printf("=========================================================\n");
        printf("\t\t     STOCK RECORD");
        printf("\n\t     Current number of styles: %d/51\n", (51 - available));
        printf("=========================================================\n");
        printf("\n\t[1] See all filled stock numbers");
        printf("\n\t[2] View a specific stock number");
        printf("\n\t[3] Back to main menu");
        printf("\n\n----- What do you want to do [1-3]? ");
            scanf("%d", &choice);
        printf("=========================================================\n");
        switch (choice){
        case 1:                         //See all
            system("cls");
            for(int a = 0; a<51; a++){
                if(sty[a].price!=0){    //shows available styles
                    show(a);
                }
            }printf("\n");
            system("PAUSE"); available = 51;
            break;
        case 2:                         //See only a specific stocks
            system("cls");
            printf("=========================================================");
            printf("\nEnter stock number (0 - 50 only): "); scanf("%d", &isAvail);
                while(isAvail < 0 || isAvail > 50){   //Entered number is invalid
                    printf("\nInput should be between 0 - 50 only. Try Again.");
                    printf("\nEnter stock number (0 - 50 only): "); scanf("%d", &isAvail);
                }
            notAvail = Avail(isAvail);
            if(notAvail != -1){         //No recorded has been created
                printf("\n=========================================================");
                printf("\n\t No record has been created for stock %d", isAvail);
                printf("\n=========================================================\n");
                system("PAUSE");
            }else{                      //Shows stock
                show(isAvail);
                printf("\n"); system("PAUSE");
            }
            available = 51;
            break;
        case 3:
            exit:
                printf("Are you sure? (Y/N): ");
                ans = again(ans); available = 51;
                if(ans == 'E') goto exit;
                printf("=========================================================\n");
                while (ch = getchar() != '\n' && ch != EOF);    // keeps grabbing chars until none left
                printf("Back to main menu . . ."); getchar();   // NOW pause the program
            break;
        default:
            printf("\tInvalid selection. Try again\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            system("PAUSE"); available = 51;
            break;
        }
    }
}

//Changes the Price of the Product (Joyce)
void changePrice(){
    int rprice, exists;
    float nprice;
    char ans = 'Y';
repeat:
    check();
    system("cls");
    printf("=========================================================\n");
    printf("\t     CHANGE PRICE OF SHOES ON HAND");
    printf("\n\t     Current number of styles: %d/51\n", (51 - available));
    printf("=========================================================\n");
    //Stock number
	printf("Change price of stock number? (0-50 only): ");
	scanf("%d", &rprice);
        while(rprice < 0 || rprice > 50){   //Entered number is invalid
            printf("\nInput should be between 0 - 50 only. Try Again.");
            printf("\nChange price of stock number? (0-50 only):  "); scanf("%d", &rprice);
        }
    exists = Avail(rprice);
    if(exists != -1){         //No recorded has been created
        printf("\n=========================================================");
        printf("\n\t No record has been created for stock %d", rprice);
        printf("\n=========================================================");
    }else{                      //Shows stock
        show(rprice);           //shows current list

        //New Price
        printf("\nEnter the new price: P");
        scanf("%f", &nprice);
        sty[rprice].price = nprice;

        show(rprice);           //Shows new price list
        printf("\n=========================================================");
    }
    exit:
        printf("\nDo you want to try again? (Y/N): ");
        ans = again(ans); available = 51;
        if(ans == 'Y') goto repeat;         //Repeats function
        else if(ans == 'E') goto exit;      //Forces user to input correct ans
        else{                               //Exit program
            printf("=========================================================\n");
            while (ch = getchar() != '\n' && ch != EOF);    // keeps grabbing chars until none left
            printf("Back to main menu . . ."); getchar();   // NOW pause the program
        }
}

//Changes the number of stocks of the Product
void changeStock(){
    char ans = 'Y';
repeat:
    check();
    system("cls");
    printf("=========================================================\n");
    printf("\t    CHANGE QUANITY OF PAIRS ON HAND");
    printf("\n\t     Current number of styles: %d/51\n", (51 - available));
    printf("=========================================================\n");
        int numsize,shoesize,henka,mkm,exists;
        //Stock #
        printf("Number of Style? (choose from 0-50) ");
        scanf(" %d",&numsize);
            while(numsize < 0 || numsize > 50){   //Entered number is invalid
                printf("\nInput should be between 0 - 50 only. Try Again.");
                printf("\nNumber of Style? (choose from 0-50) "); scanf("%d", &numsize);
            }
        exists = Avail(numsize);  //Checks if there is existing record
        if(exists != -1){         //No recorded has been created
            printf("\n=========================================================");
            printf("\n\t No record has been created for stock %d", numsize);
            printf("\n=========================================================\n");
            exit:
                printf("Do you want to try again? ");
                ans = again(ans); available = 51;
                if(ans == 'Y') goto repeat;     //repeat function
                if(ans == 'N') goto out;        //Exit program
                if(ans == 'E') goto exit;       //forces user to enter correct ans
        }else{                      //Shows stock
            saizu:
                show(numsize);
                printf("\n");
                printf("What Size (choose from 3-14): ");
                scanf(" %d",&shoesize);

                if(shoesize <3 || shoesize >14){
                    printf("\nError! Shoe size should be between 3 - 14 only. Try Again.\n");
                    goto saizu;
                }

                printf("\nCurrently, there are %d pairs of this item\n",sty[numsize].umu[shoesize - 3].stock);
                printf("  - what value would you change it to: ");
                    scanf(" %d",&henka);

                if(henka == sty[numsize].umu[shoesize - 3].stock){
                    show(numsize);
                    printf("\n=============== Number of stocks retained ===============\n", numsize);
                }else{
                    sty[numsize].umu[shoesize - 3].stock = henka;
                    show(numsize);
                    printf("\n========== There are now %d pairs of this item ==========\n",sty[numsize].umu[shoesize - 3].stock);
                }

                printf("\n\t[1] Change a stock for another size\n\t[2] Change a stock for another style\n\t[3] Return to main menu");
                printf("\n\n----- What do you want to do [1-3]? "); scanf("%d",&mkm);
                if(mkm == 1){				// same style different size
                    available = 51; goto saizu;
                }
                if(mkm == 2){				// completely different style
                    available = 51; goto repeat;
                }else{
                    exit2:
                    printf("=========================================================\n");
                    printf("Are you sure? (Y/N): ");
                    ans = again(ans); available = 51;
                    if(ans == 'N') goto repeat;
                    if(ans == 'E') goto exit2;
                out:
                    printf("=========================================================\n");
                    while (ch = getchar() != '\n' && ch != EOF);    // keeps grabbing chars until none left
                    printf("Back to main menu . . ."); getchar();   // NOW pause the program
                    return;
                }
        }
}

//checks available styles left
int check(){
    for(int a = 0, b = 1; a < 51; a++){
        if(sty[a].price!=0)
            available -= b;     //counts number of slots used
    }
}

//checks if there stock num already exist
int Avail(int isAvail){
    for(int a = 0; a < 51; a++){
        if(sty[a].price!=0){
            if(isAvail == a)
                return -1;     //if stock is not available for new record
        }
    }return 0;     //stock is available for new record
}

char again(char ans){
    scanf("\n%c", &ans);
    if(ans=='Y' || ans=='y'){
        return 'Y';
    }else if(ans=='N' || ans=='n'){
        return 'N';
    }else{
        printf("--------------------------------------------------\n");
        printf("\t   Please enter a valid answer.\n");
        printf("--------------------------------------------------\n\n");
        return 'E';
    }
}

//shows specific stock
int show(int stock){
    printf("\n---------------------------------------------------------\n");
    printf("|  STOCK NUMBER  |  STYLE  |  PRICE  |  SIZE  |  PAIRS  |\n");
    printf("---------------------------------------------------------\n");
    printf("\t %d\t%7d     P %.2f\t", stock, stock, sty[stock].price);       //stock number, style number, stock price
    for(int b = 0, c = 3; b<12; b++, c++){
        printf("%3d\t%4d\n\t\t\t\t\t", c, sty[stock].umu[b].stock);   //shoe size, shoe stock
    }
}
