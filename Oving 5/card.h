#pragma once
#include "std_lib_facilities.h"

//Suit of card
enum Suit{clubs, diamonds, hearts, spades};

//Value of card
enum Rank{two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

//Returns name of suit as string
string suitToString(Suit suitName);

//Returns name of rank as string
string rankToString(Rank rankName);


class Card{
private:
    Suit s;
    Rank r;
public:
    Card(Suit suit, Rank rank): s{suit}, r{rank} {};
    string getSuit(Suit suit);
    string getRank(Rank rank);
    string toString();
    bool isAce();
    int getCardValue();
};