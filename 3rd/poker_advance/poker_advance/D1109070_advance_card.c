#include <stdio.h>
#include "D1109070_advance_card.h"

#define CARDS 52
#define FACES 13
#define HANDS 5  //增加手牌數目 
#define SUIT 4

// prototypes
void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[]) {
	int i; // counter
	// loop through wDeck
	for (i = 0; i < CARDS; ++i) {
		wDeck[i].face = wFace[i % FACES];
		wDeck[i].suit = wSuit[i / FACES];
		wDeck[i].face_num = i % FACES;
		wDeck[i].suit_num = i / FACES;
	}// end for
}// end function fillDeck

// shuffle cards
void shuffle(Card* const wDeck) {
	size_t i; // counter
	size_t j; // variable to hold random value between 0 - 51
	Card temp; // define temporary structure for swapping Cards
	// loop through wDeck randomly swapping Cards
	for (i = 0; i < CARDS; ++i) {
		j = rand() % CARDS;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	} // end for
} // end function shuffle

// deal cards
void deal(const Card* const wDeck, Card* const hand) {
	size_t i; // counter
	// loop through wDeck
	for (i = 0; i < HANDS; ++i) {
		printf("%s of %s %s", wDeck[i].face, wDeck[i].suit, (i + 1) % 5 ? "  " : "\n");
		hand[i] = wDeck[i];
	} // end for
} // end function deal

int onePair(const Card* const hand, const char* wFace[]) {
	// counter that records how many cards of each rank are in the hand
	unsigned int counter[FACES] = { 0 };
	size_t r, p; // loop counters
	// record how many cards of each rank are in the hand
	for (r = 0; r < HANDS; ++r) {
		++counter[hand[r].face_num];
	}
	// print result if there is a pair
	int count = 0;
	for (p = 0; p < FACES; ++p) {
		if (counter[p] == 2) {
			printf("The hand contains a pair of %ss.\n", wFace[p]);
			count++;
		}
	}
	//if there is a pair return 1 else return 0
	return (count > 0) ? 1 : 0;
} // end function onepair

int twoPair(const Card* const hand, const char* wFace[]) {
	// counter that records how many cards of each rank are in the hand
	unsigned int counter[FACES] = { 0 };
	size_t r, p; // loop counters
	// record how many cards of each rank are in the hand
	for (r = 0; r < HANDS; ++r) {
		++counter[hand[r].face_num];
	}
	// print result if there is two pair
	int count = 0;
	for (p = 0; p < FACES; ++p) {
		count += (counter[p] == 2);
	}
	if (count == 2) {
		printf("The hand contains two pairs\n");
	}
	//if there is two pair return 1 else return 0
	return (count == 2) ? 1 : 0;
} // end function two pair

int ThreeOfAKind(const Card* const hand, const char* wFace[]) {
	// counter that records how many cards of each rank are in the hand
	unsigned int counter[FACES] = { 0 };
	size_t r, p; // loop counters
	// record how many cards of each rank are in the hand
	for (r = 0; r < HANDS; ++r) {
		++counter[hand[r].face_num];
	}
	// print result and return 1 if there is three of a kind
	for (p = 0; p < FACES; ++p) {
		if (counter[p] == 3) {
			printf("The hand contains Three of a kind of %ss.\n", wFace[p]);
			return 1;
		}
	}
	// return 0 if there is not three of a kind
	return 0;
} // end function Three of a kind

int FourOfAKind(const Card* const hand, const char* wFace[]) {
	// counter that records how many cards of each rank are in the hand
	unsigned int counter[FACES] = { 0 };
	size_t r, p; // loop counters
	// record how many cards of each rank are in the hand
	for (r = 0; r < HANDS; ++r) {
		++counter[hand[r].face_num];
	}
	// print result and return 1 if there is four of a kind
	for (p = 0; p < FACES; ++p) {
		if (counter[p] == 4) {
			printf("The hand contains Four of a kind of %ss.\n", wFace[p]);
			return 1;
		}
	}
	// return 0 if there is not four of a kind
	return 0;
} // end function Four of a kind

int Flush(const Card* const hand, const char* wSuit[]) {
	// counter that records how many cards of each rank are in the hand
	unsigned int counter[SUIT] = { 0 };
	size_t r, p; // loop counters
	// record how many cards of each rank are in the hand
	for (r = 0; r < HANDS; ++r) {
		++counter[hand[r].suit_num];
	}
	// print result and return 1 if there is a flush
	for (p = 0; p < SUIT; ++p) {
		if (counter[p] == 5) {
			printf("The hand contains Flush of a kind of %ss.\n", wSuit[p]);
			return 1;
		}
	}
	// return 0 if there is not flush
	return 0;
} // end function Flush

int Straight(const Card* const hand, const char* wFace[]) {
	// counter that records how many cards of each rank are in the hand
	unsigned int counter[FACES] = { 0 };
	size_t r, p; // loop counters
	// record how many cards of each rank are in the hand
	for (r = 0; r < HANDS; ++r) {
		++counter[hand[r].face_num];
	}
	// print result and return 1 if there is a pair
	for (p = 0; p < FACES - 4; ++p) {
		if (counter[p] == 1 && counter[p + 1] == 1 && counter[p + 2] == 1 && counter[p + 3] == 1 && counter[p + 4] == 1) {
			printf("The hand contains Straight.\n");
			return 1;
		}
	}
	// return 0 if there is not straight
	return 0;
} // end function Straight