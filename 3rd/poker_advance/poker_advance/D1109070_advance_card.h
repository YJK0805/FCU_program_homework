#ifndef card_h
#define card_h

//card structure definition
struct card {
	const char* face; // define pointer face
	const char* suit; // define pointer suit
	int face_num;
	int suit_num;
}; // end struct card

typedef struct card Card; // new type name for struct card

// declare functions
void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[]);
void shuffle(Card* const wDeck);
void deal(const Card* const wDeck, Card* const hand);
int onePair(const Card* const hand, const char* wFace[]);
int twoPair(const Card* const hand, const char* wFace[]);
int ThreeOfAKind(const Card* const hand, const char* wFace[]);
int FourOfAKind(const Card* const hand, const char* wFace[]);
int Flush(const Card* const hand, const char* wSuit[]);
int Straight(const Card* const hand, const char* wFace[]);

#endif