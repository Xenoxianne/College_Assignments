/*
* CARDS GAME
* GROUP 7 (BSCS 1-2)
* - Gozum, Mabalot, Mangalindan
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//  Cards are made of simply a suit and a value
struct Card{
    int face;
    int suit;
};

//  Each hand is just a set of five cards
struct Hand{
    struct Card cards[5];
};

//  The deck is only going to hold the cards we have already generated.
//  It also has to know how many cards have been dealt so we don't
//  have to iterate through a bunch of blank card objects.
struct Deck{
    struct Card dealtCards[52];
    int numCardsDealt;
};

//  we are making these variables global so that we don't have to deal with
//  managing pointers to local objects.
struct Hand hand1, hand2, hand3, hand4 ;
struct Deck deck;

//  These array will hold all of the strings to make printing simple.
static const char *faceStrings[] = {
    "Two","Three","Four","Five","Six","Seven","Eight","Nine",
    "Ten","Jack","Queen","King","Ace"};
static const char *suitStrings[] = {
    "Hearts","Clubs","Diamonds","Spades"};
static const char *rankStrings[] = {
    "High Card","Single Pair","Two Pair","Three of a Kind","Straight",
    "Flush","Full House","Four of a Kind","Straight Flush"};

//  We need functions for generating hands, printing hands and determining
//  which hand won.
void generateHands(int players);
struct Card dealCard();// Look at the generateHands() for more on this
void printHands(int players);
void analyzeHands(int players);
int playerBet(int h1Rank, int h1Consec, int h1Straight, int h1Flush, int h1Four, int h1Three, int h1Pairs);

int main(){

    // Initialize players as 0
    int players = 0;
    char decision;

    //  First thing, we need to initialize our deck
    deck.numCardsDealt=0;

    //  Seed our random generator
    srand(time(NULL));

    //  This is for the Menu Program
    while(players!=4){
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("                    POKER GAME                    \n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf(" How many players are gonna play?\n");
        printf("\n\t[1] Two Players\n\t[2] Three Players\n\t[3] Four Players\n\t[4] Exit Program\n");
        printf("\n ----- What do you want to do [1-4]? "); scanf("\n%d", &players);

        if(players>0 && players<4){
            system("cls");
            printf("=================================================================================\n");
            printf("                                 DRAWING DECK . . .                              \n");
            printf("=================================================================================\n");
            printf("\n------------------------------- You are Player 1 --------------------------------\n");
            generateHands(players);            //Then generate cards
            analyzeHands(players);             //And find the winner

            // To ask the user if they want to go to the Menu again or Exit the program.
            x:
                printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf(" Do you want to run the program again?\n\tY for yes (Return to Menu)\n\tN for no (Exit the Program)\n");
                printf(" ----- Answer: "); scanf("\n%c", &decision);
                switch (decision){
                    case 'y': case 'Y':
                        system("cls"); break;
                    case 'n': case 'N':
                        goto y; break;
                    default:
                        printf("--------------------------------------------------\n");
                        printf("\t   Please enter a valid answer.\n");
                        printf("--------------------------------------------------");
                        goto x; break;
                }
        }else if(players==4){
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            y:
                printf(" Do you really want to exit the program? (Y/N): ");
                scanf("\n%c", &decision);
                if(decision=='Y' || decision=='y'){
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("                Have a great day! \n");
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    system("PAUSE"); //so program won't automatically exit
                    return 0;               //Exit program
                }else if(decision=='N' || decision=='n'){
                    system("cls");
                    players = 0;    //Rerun main program
                }else{
                    printf("--------------------------------------------------\n");
                    printf("\t   Please enter a valid answer.\n");
                    printf("--------------------------------------------------\n\n");
                    goto y;
                }
        }else{
            printf("--------------------------------------------------\n");
            printf("\t   Please enter a valid answer.\n");
            printf("--------------------------------------------------\n\n");
            players = 0;       //Rerun main program
        }
    }
}

void generateHands(int players){
    int i;// Counter variable

    //  We are going to do both hands in one loop to make the code simpler.
    //  This would be like the dealer alternating giving cards to one
    //  player or the other.
    for(i=0; i<5; i++){
        hand1.cards[i] = dealCard();
        if(players>0)
            hand2.cards[i] = dealCard();
        if(players>1)
            hand3.cards[i] = dealCard();
        if(players>2)
            hand4.cards[i] = dealCard();
    }
}

struct Card dealCard(){
    int i;// Counter variable
    int isUnique;// This variable keeps track if there are other matching cards
    struct Card cardToDeal;// Card we will return
    while(1){// Infinite loop, we will brake out when we get the card
        cardToDeal.face = rand()%13;
        cardToDeal.suit = rand()%4;
        isUnique = 1;
        // We only need to check from 0 to the last card we dealt
        for(i=0; i<deck.numCardsDealt; i++){
            if(deck.dealtCards[i].face == cardToDeal.face && deck.dealtCards[i].suit == cardToDeal.suit)
                isUnique = 0;
        }
        // If cardToDeal hasn't been dealt
        if(isUnique){
            deck.numCardsDealt++;
            deck.dealtCards[deck.numCardsDealt] = cardToDeal;
            return cardToDeal;
        }
    }
}

//  The print statement are a little weird here so we will try and explain.
//  The string arrays we declared around line 40 correspond to the indexes
//  of the cards face or suit value. We are essentially getting the string that
//  is at the index of our face or suit.
void printHands(int players){
    int i;// Counter variable

    if(players>0){
        printf("\n Player 2 has:\n");
        for(i=0; i<5; i++)
            printf("   - %s of %s\n", faceStrings[hand2.cards[i].face], suitStrings[hand2.cards[i].suit]);
    }
    if(players>1){
        printf("\n Player 3 has:\n");
        for(i=0; i<5; i++)
            printf("   - %s of %s\n", faceStrings[hand3.cards[i].face], suitStrings[hand3.cards[i].suit]);
    }
    if(players>2){
        printf("\n Player 4 has:\n");
        for(i=0; i<5; i++)
            printf("   - %s of %s\n", faceStrings[hand4.cards[i].face], suitStrings[hand4.cards[i].suit]);
    }
}

int playerBet(int h1Rank, int h1Consec, int h1Straight, int h1Flush, int h1Four, int h1Three, int h1Pairs){
    int bet, end, valid;
    int flag=0;
    char decision;

    printf("\n Player 1 has:\n");
    for(int i=0; i<5; i++)
        printf("   - %s of %s\n", faceStrings[hand1.cards[i].face], suitStrings[hand1.cards[i].suit]);

    printf("\n Now that Player 1 has been dealt 5 cards...\n\n Please Input your bet.\n");
    printf("    1. High card\n");
    printf("    2. Single pair\n");
    printf("    3. Two pair\n");
    printf("    4. Three of a kind\n");
    printf("    5. Straight\n");
    printf("    6. Flush\n");
    printf("    7. Full house\n");
    printf("    8. Four of a kind\n");
    printf("    9. Straight Flush\n");
    while(flag==0){
        valid=0;
        printf(" ----- What is your bet? ");
        scanf("\n%d",&bet );
        if(bet<1 || bet>9){
            printf("--------------------------------------------------\n");
            printf("\t   Please enter a valid answer.\n");
            printf("--------------------------------------------------\n\n");
            valid=1;
        }
        while(valid==0){
            printf("\n Are you sure about your bet decision? Y/N: ");
            scanf("\n%c", &decision);
            switch (decision)
            {
            case 'Y': case 'y': flag=1; valid=1; break;
            case 'N': case 'n': valid=1; break;
            default:
                printf("--------------------------------------------------\n");
                printf("\t   Please enter a valid answer.\n");
                printf("--------------------------------------------------\n");
                break;
            }
        }
    }

    if(bet==1 && h1Rank==0 ){
        end=1;
    }else if(bet==2 && h1Pairs==1 ){
        end=1;
    }else if(bet==3 && h1Pairs==2 ){
        end=1;
    }else if(bet==4 && h1Three==1 ){
        end=1;
    }else if(bet==5 && h1Straight==1 ){
        end=1;
    }else if(bet==6 && h1Flush==1 ){
        end=1;
    }else if(bet==7 && h1Three==1 && h1Pairs == 1){
        end=1;
    }else if(bet==8 && h1Four==1 ){
        end=1;
    }else if(bet==9 && h1Straight==1 && h1Flush==1){
        end=1;
    }else
        end=2;

    printf("---------------------------------------------------------------------------------\n");
    printf(" You have selected %s.\n",rankStrings[bet-1]);
    if(end==1){
        printf(" Your bet is Valid!\n");
        return bet-1;
    }else if(end==2){
        printf(" Your bet is Not Valid! you have automatically lost...\n");
        return -1;
    }
    return 0;
}

void analyzeHands(int players){
    int i;// Counter variable
    // We need counts of each face and suit so lets make those first
    int hand1FaceCounts[13];
    int hand1SuitCounts[4];
    int hand2FaceCounts[13];
    int hand2SuitCounts[4];
    int hand3FaceCounts[13];
    int hand3SuitCounts[4];
    int hand4FaceCounts[13];
    int hand4SuitCounts[4];

    // We have to initialize these array to zero. You can iterate but
    // we going to use the memset function. If you don't know what that
    // means, just iterate through them.
    memset(hand1FaceCounts,0,sizeof(hand1FaceCounts));
    memset(hand1SuitCounts,0,sizeof(hand1SuitCounts));
    memset(hand2FaceCounts,0,sizeof(hand2FaceCounts));
    memset(hand2SuitCounts,0,sizeof(hand2SuitCounts));
    memset(hand3FaceCounts,0,sizeof(hand3FaceCounts));
    memset(hand3SuitCounts,0,sizeof(hand3SuitCounts));
    memset(hand4FaceCounts,0,sizeof(hand4FaceCounts));
    memset(hand4SuitCounts,0,sizeof(hand4SuitCounts));

    // Now lets go ahead an get those numbers
    for(i=0; i<5; i++){
        hand1FaceCounts[hand1.cards[i].face]++;
        hand1SuitCounts[hand1.cards[i].suit]++;
        hand2FaceCounts[hand2.cards[i].face]++;
        hand2SuitCounts[hand2.cards[i].suit]++;
        hand3FaceCounts[hand3.cards[i].face]++;
        hand3SuitCounts[hand3.cards[i].suit]++;
        hand4FaceCounts[hand4.cards[i].face]++;
        hand4SuitCounts[hand4.cards[i].suit]++;
    }

    // Now we need a bunch of variables to keep track of what each hand has.
    // we are going to abbreviate hand1 into h1 and so on.
    int h1TrueRank=0, h1Rank=0, h1Consec=0, h1Straight=0, h1Flush=0, h1Four=0, h1Three=0, h1Pairs=0;
    int h2Rank=0, h2Consec=0, h2Straight=0, h2Flush=0, h2Four=0, h2Three=0, h2Pairs=0;
    int h3Rank=0, h3Consec=0, h3Straight=0, h3Flush=0, h3Four=0, h3Three=0, h3Pairs=0;
    int h4Rank=0, h4Consec=0, h4Straight=0, h4Flush=0, h4Four=0, h4Three=0, h4Pairs=0;

    // check for flush – 5 cards of the same suit
	for(i=0; i<5; i++){
        if(hand1SuitCounts[i]==5)
            h1Flush=1;
        if(hand2SuitCounts[i]==5)
            h2Flush=1;
        if(hand3SuitCounts[i]==5)
            h3Flush=1;
        if(hand4SuitCounts[i]==5)
            h4Flush=1;
	}

	// check for straight – eg. One each of 5,6,7,8,9
	//    locate the first card
	i = 0;
	while (hand1FaceCounts[i] == 0)
		i++;
	//     count the consecutive non-zero faces
	for (; i < 3 && hand1FaceCounts[i]; i++)
		h1Consec++;
	if (h1Consec == 5)
		h1Straight = 1;

	i = 0;
	while (hand2FaceCounts[i] == 0)
		i++;

	for (; i < 3 && hand2FaceCounts[i]; i++)
		h2Consec++;
	if (h2Consec == 5)
		h2Straight = 1;

	i = 0;
	while (hand3FaceCounts[i] == 0)
		i++;

	for (; i < 3 && hand3FaceCounts[i]; i++)
		h3Consec++;
	if (h3Consec == 5)
		h3Straight = 1;

	i = 0;
	while (hand4FaceCounts[i] == 0)
		i++;

	for (; i < 3 && hand4FaceCounts[i]; i++)
		h4Consec++;
	if (h4Consec == 5)
		h4Straight = 1;

	/* check for 4-of-a-kind, 3-of-a-kind, and pairs */
	for (i = 0; i < 13; i++) {
		if (hand1FaceCounts[i] == 4)
			h1Four = 1;
		if (hand1FaceCounts[i] == 3)
			h1Three = 1;
		if (hand1FaceCounts[i] == 2)
			h1Pairs++;
	}
	for (i = 0; i < 13; i++) {
		if (hand2FaceCounts[i] == 4)
			h2Four = 1;
		if (hand2FaceCounts[i] == 3)
			h2Three = 1;
		if (hand2FaceCounts[i] == 2)
			h2Pairs++;
	}
	for (i = 0; i < 13; i++) {
		if (hand3FaceCounts[i] == 4)
			h3Four = 1;
		if (hand3FaceCounts[i] == 3)
			h3Three = 1;
		if (hand3FaceCounts[i] == 2)
			h3Pairs++;
	}
	for (i = 0; i < 13; i++) {
		if (hand4FaceCounts[i] == 4)
			h4Four = 1;
		if (hand4FaceCounts[i] == 3)
			h4Three = 1;
		if (hand4FaceCounts[i] == 2)
			h4Pairs++;
	}

    // Hand 1 ranking
	if (h1Straight && h1Flush)
		h1Rank=8;
	else if (h1Four)
		h1Rank=7;
	else if (h1Three && h1Pairs == 1)
		h1Rank=6;
	else if (h1Flush)
		h1Rank=5;
	else if (h1Straight)
		h1Rank=4;
	else if (h1Three)
		h1Rank=3;
	else if (h1Pairs == 2)
		h1Rank=2;
	else if (h1Pairs == 1)
		h1Rank=1;
	else
		h1Rank=0;

    // Hand 2 ranking
    if (h2Straight && h2Flush)
		h2Rank=8;
	else if (h2Four)
		h2Rank=7;
	else if (h2Three && h2Pairs == 1)
		h2Rank=6;
	else if (h2Flush)
		h2Rank=5;
	else if (h2Straight)
		h2Rank=4;
	else if (h2Three)
		h2Rank=3;
	else if (h2Pairs == 2)
		h2Rank=2;
	else if (h2Pairs == 1)
		h2Rank=1;
	else
		h2Rank=0;

    //  Hand 3 Ranking
	if (h3Straight && h3Flush)
		h3Rank=8;
	else if (h3Four)
		h3Rank=7;
	else if (h3Three && h3Pairs == 1)
		h3Rank=6;
	else if (h3Flush)
		h3Rank=5;
	else if (h3Straight)
		h3Rank=4;
	else if (h3Three)
		h3Rank=3;
	else if (h3Pairs == 2)
		h3Rank=2;
	else if (h3Pairs == 1)
		h3Rank=1;
	else
		h3Rank=0;

    // Hand 4 Ranking
	if (h4Straight && h4Flush)
		h4Rank=8;
	else if (h4Four)
		h4Rank=7;
	else if (h4Three && h4Pairs == 1)
		h4Rank=6;
	else if (h4Flush)
		h4Rank=5;
	else if (h4Straight)
		h4Rank=4;
	else if (h4Three)
		h4Rank=3;
	else if (h4Pairs == 2)
		h4Rank=2;
	else if (h4Pairs == 1)
		h4Rank=1;
	else
		h4Rank=0;

    //  puts the calculated highest possible Rank for player 1 into another int
    h1TrueRank = h1Rank;

    //  gets the bet of the player 1 and decides if it is Valid
    h1Rank = (playerBet(h1Rank, h1Consec, h1Straight, h1Flush, h1Four, h1Three, h1Pairs));

    printf("\n=================================================================================\n");
    printf("                      Now showing cards of other player(s). . .                  \n");
    printf("=================================================================================\n");
    //Print the cards of the other players
    printHands(players);

    // counter if there are only two or three players
    if(players==1){
        h3Rank = -2;
        h4Rank = -3;
    } else if(players==2){
        h4Rank = -2;
    }

    printf("\n=================================================================================\n\n");
    printf(" Player 1's highest possible combination is: %s.\n",rankStrings[h1TrueRank]);
    if(h1Rank>=0){
        printf(" Player 1's bet is: %s.\n",rankStrings[h1Rank]);
    }else
        printf(" Player 1's is not valid, and therefore is disqualified.\n");

    // Print what each player has
    printf("\n Player 2 has a %s.\n",rankStrings[h2Rank]);
    if(players>1)
        printf(" Player 3 has a %s.\n",rankStrings[h3Rank]);
    if(players>2)
        printf(" Player 4 has a %s.\n",rankStrings[h4Rank]);

    // If we have a tie this will be used for the tie breaker to
    // calculate what the highest card there is in each players card
    int h1highest_cardface=0,h2highest_cardface=0,h3highest_cardface=0,h4highest_cardface=0;
    int h1highest_cardsuit=0,h2highest_cardsuit=0,h3highest_cardsuit=0,h4highest_cardsuit=0;

    // we arr the highest ranking card to an int for a tie Breaker
    for(int i=0; i<4;i++){
        if(hand1.cards[i+1].face>hand1.cards[i].face && hand1.cards[i+1].face>h1highest_cardface){
            h1highest_cardface=hand1.cards[i+1].face;
            h1highest_cardsuit=hand1.cards[i+1].suit;
        }else if(hand1.cards[i].face>hand1.cards[i+1].face && hand1.cards[i].face>h1highest_cardface){
            h1highest_cardface=hand1.cards[i].face;
            h1highest_cardsuit=hand1.cards[i].suit;
        }

        if(hand2.cards[i+1].face>hand2.cards[i].face && hand2.cards[i+1].face>h2highest_cardface){
            h2highest_cardface=hand2.cards[i+1].face;
            h2highest_cardsuit=hand2.cards[i+1].suit;
        }else if(hand2.cards[i].face>hand2.cards[i+1].face && hand2.cards[i].face>h2highest_cardface){
            h2highest_cardface=hand2.cards[i].face;
            h2highest_cardsuit=hand2.cards[i].suit;
        }

        if(hand3.cards[i+1].face>hand3.cards[i].face && hand3.cards[i+1].face>h3highest_cardface){
            h3highest_cardface=hand3.cards[i+1].face;
            h3highest_cardsuit=hand3.cards[i+1].suit;
        }else if(hand3.cards[i].face>hand3.cards[i+1].face && hand3.cards[1].face>h3highest_cardface){
            h3highest_cardface=hand3.cards[i].face;
            h3highest_cardsuit=hand3.cards[i].suit;
        }

        if(hand4.cards[i+1].face>hand4.cards[i].face && hand4.cards[i+1].face>h4highest_cardface){
            h4highest_cardface=hand4.cards[i+1].face;
            h4highest_cardsuit=hand4.cards[i+1].suit;
        }else if(hand4.cards[i].face>hand4.cards[i+1].face && hand4.cards[i].face>h4highest_cardface){
            h4highest_cardface=hand4.cards[i].face;
            h4highest_cardsuit=hand4.cards[i].suit;
        }
    }
    printf("\n=================================================================================");

    // Determine winner
    if(h1Rank>h2Rank && h1Rank>h3Rank && h1Rank>h4Rank)
        printf("\n\t\t\tThat means that player 1 wins!!!\n");
    else if(h2Rank>h3Rank && h2Rank>h4Rank && h2Rank>h1Rank)
        printf("\n\t\t\tThat means that player 2 wins!!!\n");
    else if(h3Rank>h4Rank && h3Rank>h1Rank&& h3Rank>h2Rank)
        printf("\n\t\t\tThat means that player 3 wins!!!\n");
    else if(h4Rank>h1Rank && h4Rank>h2Rank && h4Rank>h3Rank)
        printf("\n\t\t\tThat means that player 4 wins!!!\n");
    else if(h2Rank==h3Rank && h2Rank>h4Rank && h2Rank>h1Rank){
        printf("\n\t\t\tThat means that player 2 and 3 ties!!!\n");
        printf("=================================================================================\n\n");
        printf(" Player 2's Highest Ranking Card is %s of %s.\n",faceStrings[h2highest_cardface], suitStrings[h2highest_cardsuit]);
        printf(" Player 3's Highest Ranking Card is %s of %s.\n",faceStrings[h3highest_cardface], suitStrings[h3highest_cardsuit]);
        printf("\n=================================================================================\n");
        if(h2highest_cardface>h3highest_cardface){
            printf(" Player 2's Highest Ranking Card is higher than Player 3's\n Therefore...\n");
            printf("\t\t\tPlayer 2 Wins!\n");
        }else if(h2highest_cardface<h3highest_cardface){
            printf(" Player 3's Highest Ranking Card is higher than Player 2's\n Therefore...\n");
            printf("\t\t\tPlayer 3 Wins!\n");
        }else if(h2highest_cardface==h3highest_cardface){
            printf(" Player 2's Highest Ranking Card is equal to Player 3's\n Therefore...\n");
            printf("\t\t\tPlayer 2 and 3 is tied!\n");
        }
    }else if(h2Rank==h4Rank && h2Rank>h1Rank && h2Rank>h3Rank){
        printf("\n\t\t\tThat means that player 2 and 4 ties!!!\n");
        printf("=================================================================================\n\n");
        printf(" Player 2's Highest Ranking Card is %s of %s.\n",faceStrings[h2highest_cardface], suitStrings[h2highest_cardsuit]);
        printf(" Player 4's Highest Ranking Card is %s of %s.\n",faceStrings[h4highest_cardface], suitStrings[h4highest_cardsuit]);
        printf("\n=================================================================================\n");
        if(h2highest_cardface>h4highest_cardface){
            printf(" Player 2's Highest Ranking Card is higher than Player 4's\n Therefore,\n");
            printf("\t\t\tPlayer 2 Wins!\n");
        }else if(h2highest_cardface<h4highest_cardface){
            printf(" Player 4's Highest Ranking Card is higher than Player 2's\n Therefore...\n");
            printf("\t\t\tPlayer 4 Wins!\n");
        }else if(h2highest_cardface==h4highest_cardface){
            printf(" Player 2's Highest Ranking Card is equal to Player 4's\n Therefore...\n");
            printf("\t\t\tPlayer 2 and 4 is tied!\n");
        }
    }else if(h2Rank==h1Rank && h2Rank>h4Rank && h2Rank>h3Rank){
        printf("\n\t\t\tThat means that player 1 and 2 ties!!!\n");
        printf("=================================================================================\n\n");
        printf(" Player 1's Highest Ranking Card is %s of %s.\n",faceStrings[h1highest_cardface], suitStrings[h1highest_cardsuit]);
        printf(" Player 2's Highest Ranking Card is %s of %s.\n",faceStrings[h2highest_cardface], suitStrings[h2highest_cardsuit]);
        printf("\n=================================================================================\n");
        if(h1highest_cardface>h2highest_cardface){
            printf(" Player 1's Highest Ranking Card is higher than Player 2's\n Therefore...\n");
            printf("\t\t\tPlayer 1 Wins!\n");
        }else if(h1highest_cardface<h2highest_cardface){
            printf(" Player 2's Highest Ranking Card is higher than Player 1's\n Therefore...\n");
            printf("\t\t\tPlayer 2 Wins!\n");
        }else if(h1highest_cardface==h2highest_cardface){
            printf(" Player 1's Highest Ranking Card is equal to Player 2's\n Therefore...\n");
            printf("\t\t\tPlayer 1 and 2 is tied!\n");
        }
    }else if(h1Rank==h3Rank && h1Rank>h4Rank && h1Rank>h2Rank){
        printf("\n\t\t\tThat means that player 1 and 3 ties!!!\n");
        printf("=================================================================================\n\n");
        printf(" Player 1's Highest Ranking Card is %s of %s.\n",faceStrings[h1highest_cardface], suitStrings[h1highest_cardsuit]);
        printf(" Player 3's Highest Ranking Card is %s of %s.\n",faceStrings[h3highest_cardface], suitStrings[h3highest_cardsuit]);
        printf("\n=================================================================================\n");
        if(h1highest_cardface>h3highest_cardface){
            printf(" Player 1's Highest Ranking Card is higher than Player 3's \n Therefore...\n");
            printf("\t\t\tPlayer 1 Wins!\n");
        }else if(h1highest_cardface<h3highest_cardface){
            printf(" Player 3's Highest Ranking Card is higher than Player 1's \n Therefore...\n");
            printf("\t\t\tPlayer 3 Wins!\n");
        }else if(h1highest_cardface==h3highest_cardface){
            printf(" Player 1's Highest Ranking Card is equal to Player 3's \n Therefore...\n");
            printf("\t\t\tPlayer 1 and 3 is tied!\n");
        }
    }else if(h1Rank==h4Rank && h1Rank>h2Rank && h1Rank>h3Rank){
        printf("\n\t\t\tThat means that player 1 and 4 ties!!!\n");
        printf("=================================================================================\n\n");
        printf(" Player 1's Highest Ranking Card is %s of %s.\n",faceStrings[h1highest_cardface], suitStrings[h1highest_cardsuit]);
        printf(" Player 4's Highest Ranking Card is %s of %s.\n",faceStrings[h4highest_cardface], suitStrings[h4highest_cardsuit]);
        printf("\n=================================================================================\n");
        if(h1highest_cardface>h4highest_cardface){
            printf(" Player 1's Highest Ranking Card is higher than Player 4's \n Therefore...\n");
            printf("\t\t\tPlayer 1 Wins!\n");
        }else if(h1highest_cardface<h4highest_cardface){
            printf(" Player 4's Highest Ranking Card is higher than Player 1's \n Therefore...\n");
            printf("\t\t\tPlayer 4 Wins!\n");
        }else if(h1highest_cardface==h4highest_cardface){
           printf(" Player 1's Highest Ranking Card is equal to Player 4's \n Therefore...\n");
            printf("\t\t\tPlayer 1 and 4 is tied!\n");
        }
    }else if(h3Rank==h4Rank && h3Rank>h2Rank && h3Rank>h1Rank){
        printf("\n\t\t\tThat means that player 3 and 4 ties!!!\n");
        printf("=================================================================================\n\n");
        printf(" Player 3's Highest Ranking Card is %s of %s.\n",faceStrings[h3highest_cardface], suitStrings[h3highest_cardsuit]);
        printf(" Player 4's Highest Ranking Card is %s of %s.\n",faceStrings[h4highest_cardface], suitStrings[h4highest_cardsuit]);
        printf("\n=================================================================================\n");
        if(h3highest_cardface>h4highest_cardface){
            printf(" Player 3's Highest Ranking Card is higher than Player 4's \n Therefore...\n");
            printf("\t\t\tPlayer 3 Wins!\n");
        }else if(h3highest_cardface<h4highest_cardface){
            printf(" Player 4's Highest Ranking Card is higher than Player 3's \n Therefore...\n");
            printf("\t\t\tPlayer 4 Wins!\n");
        }else if(h3highest_cardface==h4highest_cardface){
           printf(" Player 3's Highest Ranking Card is equal to Player 4's \n Therefore...\n");
            printf("\t\t\tPlayer 3 and 4 is tied!\n");
        }
    }else if(h3Rank==h4Rank && h3Rank==h2Rank && h3Rank>h1Rank){
        printf("\n\t\t\tThat means that player 2, 3, and 4 ties!!!\n");
        printf("=================================================================================\n\n");
        printf(" Player 2's Highest Ranking Card is %s of %s.\n",faceStrings[h2highest_cardface], suitStrings[h2highest_cardsuit]);
        printf(" Player 3's Highest Ranking Card is %s of %s.\n",faceStrings[h3highest_cardface], suitStrings[h3highest_cardsuit]);
        printf(" Player 4's Highest Ranking Card is %s of %s.\n",faceStrings[h4highest_cardface], suitStrings[h4highest_cardsuit]);
        printf("\n=================================================================================\n");
        if(h2highest_cardface>h3highest_cardface && h2highest_cardface>h4highest_cardface){
            printf(" Player 2's Highest Ranking Card is higher than Player 3's and Player 4's \n Therefore...\n");
            printf("\t\t\tPlayer 2 Wins!\n");
        }else if(h3highest_cardface>h2highest_cardface && h3highest_cardface>h4highest_cardface){
            printf(" Player 3's Highest Ranking Card is higher than Player 2's and Player 4's \n Therefore...\n");
            printf("\t\t\tPlayer 3 Wins!\n");
        }else if(h4highest_cardface>h2highest_cardface && h4highest_cardface>h3highest_cardface){
            printf(" Player 4's Highest Ranking Card is higher than Player 2's and Player 3's \n Therefore...\n");
            printf("\t\t\tPlayer 4 Wins!\n");
        }else if(h4highest_cardface==h2highest_cardface && h4highest_cardface>h3highest_cardface){
            printf(" Player 2's Highest Ranking Card is equal to Player 4's but higher than Player 3's \n Therefore...\n");
            printf("\t\t\tPlayer 2 and 4 is Tied!");
        }else if(h4highest_cardface==h3highest_cardface && h4highest_cardface>h2highest_cardface){
           printf(" Player 3's Highest Ranking Card is equal to Player 4's but higher than Player 2's \n Therefore...n");
            printf("\t\t\tPlayer 3 and 4 is Tied!");
        }else if(h2highest_cardface==h3highest_cardface && h2highest_cardface>h4highest_cardface){
            printf(" Player 2's Highest Ranking Card is equal to Player 3's but higher than Player 4's \n Therefore...\n");
            printf("\t\t\tPlayer 2 and 3 is Tied!");
        }else if(h2highest_cardface==h3highest_cardface && h2highest_cardface==h4highest_cardface){
            printf(" Player 2's Highest Ranking Card is equal to Player 3's and Player 4's \n Therefore...\n");
            printf("\t\t\tPlayers 2, 3 and 4 are Tied!");
        }
    }else if(h3Rank==h4Rank && h3Rank==h1Rank && h1Rank>h2Rank){
        printf("\n\t\t\tThat means that player 1, 3, and 4 ties!!!\n");
        printf("=================================================================================\n\n");
        printf(" Player 1's Highest Ranking Card is %s of %s.\n",faceStrings[h1highest_cardface], suitStrings[h1highest_cardsuit]);
        printf(" Player 3's Highest Ranking Card is %s of %s.\n",faceStrings[h3highest_cardface], suitStrings[h3highest_cardsuit]);
        printf(" Player 4's Highest Ranking Card is %s of %s.\n",faceStrings[h4highest_cardface], suitStrings[h4highest_cardsuit]);
        printf("\n=================================================================================\n");
        if(h1highest_cardface>h3highest_cardface && h1highest_cardface>h4highest_cardface){
            printf(" Player 1's Highest Ranking Card is higher than Player 3's and Player 4's \n Therefore...\n");
            printf("\t\t\tPlayer 1 Wins!\n");
        }else if(h3highest_cardface>h1highest_cardface && h3highest_cardface>h4highest_cardface){
            printf(" Player 3's Highest Ranking Card is higher than Player 1's and Player 4's \n Therefore...\n");
            printf("\t\t\tPlayer 3 Wins!\n");
        }else if(h4highest_cardface>h1highest_cardface && h4highest_cardface>h3highest_cardface){
            printf(" Player 4's Highest Ranking Card is higher than Player 1's and Player 3's \n Therefore...\n");
            printf("\t\t\tPlayer 4 Wins!\n");
        }else if(h4highest_cardface==h1highest_cardface && h4highest_cardface>h3highest_cardface){
            printf(" Player 1's Highest Ranking Card is equal to Player 4's but higher than Player 3's \n Therefore...\n");
            printf("\t\t\tPlayer 1 and 4 is Tied!\n");
        }else if(h4highest_cardface==h3highest_cardface && h4highest_cardface>h1highest_cardface){
            printf(" Player 3's Highest Ranking Card is equal to Player 4's but higher than Player 1's \n Therefore...\n");
            printf("\t\t\tPlayer 3 and 4 is Tied!\n");
        }else if(h1highest_cardface==h3highest_cardface && h1highest_cardface>h4highest_cardface){
            printf(" Player 1's Highest Ranking Card is equal to Player 3's but higher than Player 4's \n Therefore...\n");
            printf("\t\t\tPlayer 1 and 3 is Tied!\n");
        } else if(h1highest_cardface==h3highest_cardface && h1highest_cardface==h4highest_cardface){
            printf(" Player 1's Highest Ranking Card is equal to Player 3's and Player 4's \n Therefore...\n");
            printf("\t\t\tPlayer 1, 3 and 4 are Tied!\n");
        }
    }else if(h1Rank==h2Rank && h2Rank==h3Rank && h1Rank>h4Rank){
        printf("\n\t\t\tThat means that player 1, 2, and 3 ties!!!\n");
        printf("=================================================================================\n\n");
        printf(" Player 1's Highest Ranking Card is %s of %s.\n",faceStrings[h1highest_cardface], suitStrings[h1highest_cardsuit]);
        printf(" Player 2's Highest Ranking Card is %s of %s.\n",faceStrings[h2highest_cardface], suitStrings[h2highest_cardsuit]);
        printf(" Player 3's Highest Ranking Card is %s of %s.\n",faceStrings[h3highest_cardface], suitStrings[h3highest_cardsuit]);
        printf("\n=================================================================================\n");
        if(h1highest_cardface>h3highest_cardface && h1highest_cardface>h2highest_cardface){
            printf(" Player 1's Highest Ranking Card is higher than Player 2's and Player 3's \n Therefore...\n");
            printf("\t\t\tPlayer 1 Wins!\n");
        }else if(h3highest_cardface>h1highest_cardface && h3highest_cardface>h2highest_cardface){
            printf(" Player 3's Highest Ranking Card is higher than Player 1's and Player 2's \n Therefore...\n");
            printf("\t\t\tPlayer 3 Wins!\n");
        }else if(h2highest_cardface>h1highest_cardface && h2highest_cardface>h3highest_cardface){
            printf(" Player 2's Highest Ranking Card is higher than Player 1's and Player 3's \n Therefore...\n");
            printf("\t\t\tPlayer 2 Wins!\n");
        }else if(h2highest_cardface==h1highest_cardface && h2highest_cardface>h3highest_cardface){
            printf(" Player 1's Highest Ranking Card is equal to Player 2's but higher than Player 3's \n Therefore...\n");
            printf("\t\t\tPlayer 1 and 2 is Tied!");
        }else if(h2highest_cardface==h3highest_cardface && h2highest_cardface>h1highest_cardface){
            printf(" Player 3's Highest Ranking Card is equal to Player 2's but higher than Player 1's \n Therefore...\n");
            printf("\t\t\tPlayer 3 and 2 is Tied!");
        }else if(h1highest_cardface==h3highest_cardface && h1highest_cardface>h2highest_cardface){
            printf(" Player 1's Highest Ranking Card is equal to Player 3's but higher than Player 2's \n Therefore...\n");
            printf("\t\t\tPlayer 1 and 3 is Tied!");
        }else if(h1highest_cardface==h3highest_cardface && h1highest_cardface==h2highest_cardface){
            printf(" Player 1's Highest Ranking Card is equal to Player 2's and Player 3's \n Therefore...\n");
            printf("\t\t\tPlayer 1, 2 and 3 are Tied!");
        }
    }else if(h1Rank==h2Rank && h2Rank==h4Rank && h1Rank>h3Rank){
        printf("\n\t\t\tThat means that player 1, 2, and 4 ties!!!\n");
        printf("=================================================================================\n\n");
        printf(" Player 1's Highest Ranking Card is %s of %s.\n",faceStrings[h1highest_cardface], suitStrings[h1highest_cardsuit]);
        printf(" Player 2's Highest Ranking Card is %s of %s.\n",faceStrings[h2highest_cardface], suitStrings[h2highest_cardsuit]);
        printf(" Player 4's Highest Ranking Card is %s of %s.\n",faceStrings[h4highest_cardface], suitStrings[h4highest_cardsuit]);
        printf("\n=================================================================================\n");
        if(h1highest_cardface>h2highest_cardface && h1highest_cardface>h4highest_cardface){
            printf(" Player 1's Highest Ranking Card is higher than Player 2's and Player 4's \n Therefore...\n");
            printf("\t\t\tPlayer 1 Wins!\n");
        }else if(h2highest_cardface>h1highest_cardface && h2highest_cardface>h4highest_cardface){
            printf(" Player 2's Highest Ranking Card is higher than Player 1's and Player 4's \n Therefore...\n");
            printf("\t\t\tPlayer 2 Wins!\n");
        }else if(h4highest_cardface>h1highest_cardface && h4highest_cardface>h2highest_cardface){
            printf(" Player 4's Highest Ranking Card is higher than Player 1's and Player 2's \n Therefore...\n");
            printf("\t\t\tPlayer 4 Wins!\n");
        }else if(h4highest_cardface==h1highest_cardface && h4highest_cardface>h2highest_cardface){
            printf(" Player 1's Highest Ranking Card is equal to Player 4's but higher than Player 2's \n Therefore...\n");
            printf("\t\t\tPlayer 1 and 4 is Tied!");
        }else if(h4highest_cardface==h2highest_cardface && h4highest_cardface>h1highest_cardface){
             printf(" Player 2's Highest Ranking Card is equal to Player 4's but higher than Player 1's \n Therefore...\n");
            printf("\t\t\tPlayer 2 and 4 is Tied!");
        }else if(h1highest_cardface==h2highest_cardface && h1highest_cardface>h4highest_cardface){
            printf(" Player 1's Highest Ranking Card is equal to Player 2's but higher than Player 4's \n Therefore...\n");
            printf("\t\t\tPlayer 1 and 2 is Tied!");
        }else if(h1highest_cardface==h2highest_cardface && h1highest_cardface==h4highest_cardface){
            printf(" Player 1's Highest Ranking Card is equal to Player 2's and 4's \n Therefore...\n");
            printf("\t\t\tPlayer 1, 2 and 4 are Tied!");
        }
    }else{
        printf("\n\t\t\tBy Luck, ALL players are tied.\n");
        printf("=================================================================================\n\n");
        printf(" Player 1's Highest Ranking Card is %s of %s.\n",faceStrings[h1highest_cardface], suitStrings[h1highest_cardsuit]);
        printf(" Player 2's Highest Ranking Card is %s of %s.\n",faceStrings[h2highest_cardface], suitStrings[h2highest_cardsuit]);
        printf(" Player 3's Highest Ranking Card is %s of %s.\n",faceStrings[h3highest_cardface], suitStrings[h3highest_cardsuit]);
        printf(" Player 4's Highest Ranking Card is %s of %s.\n",faceStrings[h4highest_cardface], suitStrings[h4highest_cardsuit]);
        printf("\n=================================================================================\n");
        if(h1highest_cardface>h2highest_cardface && h1highest_cardface>h3highest_cardface && h1highest_cardface>h4highest_cardface)
            printf("\t\t\tThat means that player 1 wins!!!\n");
        else if(h2highest_cardface>h3highest_cardface && h2highest_cardface>h4highest_cardface && h2highest_cardface>h1highest_cardface)
            printf("\t\t\tThat means that player 2 wins!!!\n");
        else if(h3highest_cardface>h4highest_cardface && h3highest_cardface>h1highest_cardface&& h3highest_cardface>h2highest_cardface)
            printf("\t\t\tThat means that player 3 wins!!!\n");
        else if(h4highest_cardface>h1highest_cardface && h4highest_cardface>h2highest_cardface && h4highest_cardface>h3highest_cardface)
            printf("\t\t\tThat means that player 4 wins!!!\n");
        else if(h2highest_cardface==h3highest_cardface && h2highest_cardface>h4highest_cardface && h2highest_cardface>h1highest_cardface)
            printf("\t\t\tThat means that player 2 and 3 ties!!!\n");
        else if(h2highest_cardface==h4highest_cardface && h2highest_cardface>h1highest_cardface && h2highest_cardface>h3highest_cardface)
            printf("\t\t\tThat means that player 2 and 4 ties!!!\n");
        else if(h2highest_cardface==h1highest_cardface && h2highest_cardface>h4highest_cardface && h2highest_cardface>h3highest_cardface)
            printf("\t\t\tThat means that player 1 and 2 ties!!!\n");
        else if(h1highest_cardface==h3highest_cardface && h1highest_cardface>h4highest_cardface && h1highest_cardface>h2highest_cardface)
            printf("\t\t\tThat means that player 1 and 3 ties!!!\n");
        else if(h1highest_cardface==h4highest_cardface && h1highest_cardface>h2highest_cardface && h1highest_cardface>h3highest_cardface)
            printf("\t\t\tThat means that player 1 and 4 ties!!!\n");
        else if(h3highest_cardface==h4highest_cardface && h3highest_cardface>h2highest_cardface && h3highest_cardface>h1highest_cardface)
            printf("\t\t\tThat means that player 3 and 4 ties!!!\n");
        else if(h3highest_cardface==h4highest_cardface && h3highest_cardface==h2highest_cardface && h3highest_cardface>h1highest_cardface)
            printf("\t\t\tThat means that player 2, 3, and 4 ties!!!\n");
        else if(h3highest_cardface==h4highest_cardface && h3highest_cardface==h1highest_cardface && h1highest_cardface>h2highest_cardface)
            printf("\t\t\tThat means that player 1, 3, and 4 ties!!!\n");
        else if(h1highest_cardface==h2highest_cardface && h2highest_cardface==h3highest_cardface && h1highest_cardface>h4highest_cardface)
            printf("\t\t\tThat means that player 1, 2, and 3 ties!!!\n");
        else if(h1highest_cardface==h2highest_cardface && h2highest_cardface==h4highest_cardface && h1highest_cardface>h3highest_cardface)
            printf("\t\t\tThat means that player 1, 2, and 4 ties!!!\n");
        else if(h1highest_cardface==h2highest_cardface && h2highest_cardface==h3highest_cardface && h3highest_cardface==h4highest_cardface)
            printf("\t\t\tThat means that all player's highest ranking card is the same! They are all Tied!!!\n");
        }
    printf("=================================================================================");
}