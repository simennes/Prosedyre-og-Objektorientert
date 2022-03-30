#pragma once
#include "std_lib_facilities.h"
#include "card.h"

class CardDeck{
private:
    vector<Card> c;
public:
    CardDeck();
    void swap(int n1, int n2);
    void print();
    void shuffle(int shuffleTime);
    Card drawCard();
};