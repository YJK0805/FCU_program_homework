#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "D1109070_advance_card.h"

#define CARDS 52
#define FACES 13
#define HANDS 5  //增加手牌數目 
#define SUIT 4

int main(void) {
	Card deck[CARDS]; // define array of Cards
	Card hand[HANDS];

	// initialize array of pointers
	const char* face[] = { "Ace", "Deuce", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten","Jack", "Queen", "King" };

	// initialize array of pointers
	const char* suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	srand(time(NULL)); // randomize

	fillDeck(deck, face, suit); // load the deck with Cards
	shuffle(deck); // put Cards in random order
	deal(deck, hand); // deal all 52 Cards
	onePair(hand, face); // determine whether there is a pair
	twoPair(hand, face); // determine whether there is two pair
	ThreeOfAKind(hand, face); // determine whether there is three of a kind
	FourOfAKind(hand, face); // determine whether there is four of a kind
	Flush(hand, suit); // determine whether there is a flush
	Straight(hand, face); // determine whether there is a straight
} // end main