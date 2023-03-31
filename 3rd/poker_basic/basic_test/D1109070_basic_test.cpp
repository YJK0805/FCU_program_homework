#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <sstream>
#include "../poker_basic/D1109070_basic_card.h"
#include "../poker_basic/D1109070_basic_card.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test {
	TEST_CLASS(test) {
public:
	//測試只有2張數字相同，沒有5張同花色，因此理論上只有onePair回傳1，其他皆是回傳0
	TEST_METHOD(TestMethod1) {
		Card hand[5];
		const char* face[] = { "Ace", "Deuce", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten","Jack", "Queen", "King" };
		const char* suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
		hand[0] = { "Ace","Hearts",0,3 };
		hand[1] = { "Ace","Diamonds",0,1 };
		hand[2] = { "Three","Spades",2,3 };
		hand[3] = { "Five","Diamonds",4,1 };
		hand[4] = { "Seven","Spades",6,3 };

		// Check that the funtion matches the expected value
		Assert::AreEqual(1, onePair(hand, face));
		Assert::AreEqual(0, twoPair(hand, face));
		Assert::AreEqual(0, ThreeOfAKind(hand, face));
		Assert::AreEqual(0, FourOfAKind(hand, face));
	}
	//測試只有2組數字相同(1組2張)，沒有5張同花色，因此理論上只有onePair與twoPair回傳1，其他皆是回傳0
	TEST_METHOD(TestMethod2) {
		Card hand[5];
		const char* face[] = { "Ace", "Deuce", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten","Jack", "Queen", "King" };
		const char* suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
		hand[0] = { "Ace","Hearts",0,3 };
		hand[1] = { "Three","Diamonds",2,1 };
		hand[2] = { "Three","Spades",2,3 };
		hand[3] = { "Five","Diamonds",4,1 };
		hand[4] = { "Five","Spades",4,3 };

		// Check that the funtion matches the expected value
		Assert::AreEqual(1, onePair(hand, face));
		Assert::AreEqual(1, twoPair(hand, face));
		Assert::AreEqual(0, ThreeOfAKind(hand, face));
		Assert::AreEqual(0, FourOfAKind(hand, face));
	}
	//測試只有3個數字相同，沒有5張同花色，因此理論上只有ThreeOfAKind回傳1，其他皆是回傳0
	TEST_METHOD(TestMethod3) {
		Card hand[5];
		const char* face[] = { "Ace", "Deuce", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten","Jack", "Queen", "King" };
		const char* suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
		hand[0] = { "Deuce","Clubs",1,2 };
		hand[1] = { "Deuce","Diamonds",1,1 };
		hand[2] = { "Deuce","Spades",1,3 };
		hand[3] = { "Seven","Diamonds",6,1 };
		hand[4] = { "Five","Clubs",4,2 };

		// Check that the funtion matches the expected value
		Assert::AreEqual(0, onePair(hand, face));
		Assert::AreEqual(0, twoPair(hand, face));
		Assert::AreEqual(1, ThreeOfAKind(hand, face));
		Assert::AreEqual(0, FourOfAKind(hand, face));
	}
	//測試只有3個數字相同與另1組2個數字相同，沒有5張同花色，因此理論上只有onePair與ThreeOfAKind回傳1，其他皆是回傳0
	TEST_METHOD(TestMethod4) {
		Card hand[5];
		const char* face[] = { "Ace", "Deuce", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten","Jack", "Queen", "King" };
		const char* suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
		hand[0] = { "Deuce","Clubs",1,2 };
		hand[1] = { "Deuce","Diamonds",1,1 };
		hand[2] = { "Deuce","Spades",1,3 };
		hand[3] = { "Five","Diamonds",4,1 };
		hand[4] = { "Five","Clubs",4,2 };

		// Check that the funtion matches the expected value
		Assert::AreEqual(1, onePair(hand, face));
		Assert::AreEqual(0, twoPair(hand, face));
		Assert::AreEqual(1, ThreeOfAKind(hand, face));
		Assert::AreEqual(0, FourOfAKind(hand, face));
	}
	//測試有4個數字相同，沒有5張同花色，因此理論上只有FourOfAKind回傳1，其他皆是回傳0
	TEST_METHOD(TestMethod5) {
		Card hand[5];
		const char* face[] = { "Ace", "Deuce", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten","Jack", "Queen", "King" };
		const char* suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
		hand[0] = { "Deuce","Clubs",1,2 };
		hand[1] = { "Deuce","Diamonds",1,1 };
		hand[2] = { "Deuce","Spades",1,3 };
		hand[3] = { "Deuce","Diamonds",1,1 };
		hand[4] = { "Five","Clubs",4,2 };

		// Check that the funtion matches the expected value
		Assert::AreEqual(0, onePair(hand, face));
		Assert::AreEqual(0, twoPair(hand, face));
		Assert::AreEqual(0, ThreeOfAKind(hand, face));
		Assert::AreEqual(1, FourOfAKind(hand, face));
	}
	};
}
