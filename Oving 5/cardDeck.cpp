#include "cardDeck.h"
#include "std_lib_facilities.h"
#include "card.h"

CardDeck::CardDeck(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            Card card = Card(Suit(i), Rank(j));
            c.push_back(card);
        }
    }
}

void CardDeck::swap(int n1, int n2){
    Card temp = c[n1];
    c[n1] = c[n2];
    c[n2] = temp;
}

void CardDeck::print(){
    for(int i = 0; i < c.size(); i++){
        string cardString = c[i].toString();
        cout << "\n" << cardString;
    }
}

void CardDeck::shuffle(int shuffleTime){
    for(int i = 0; i < shuffleTime; i++){
        int n1 = randint(0, 51);
        int n2 = randint(0, 51);
        CardDeck::swap(n1, n2);
    }
}

Card CardDeck::drawCard(){
    Card card = c.back();
    c.pop_back();
    return card;
}