#include "std_lib_facilities.h"
#include "card.h"

string suitToString(Suit suitName){
    vector<string> suitNames{"Clubs", "Diamonds", "Hearts", "Spades"};
    string name = suitNames[suitName];
    return name;
}

string rankToString(Rank rankName){
    vector<string> rankNames{"Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
     "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    string name = rankNames[rankName];
    return name;
}

string Card::getSuit(Suit suit){
    string suitName = suitToString(suit);
    return suitName;
}
string Card::getRank(Rank rank){
    string rankName = rankToString(rank);
    return rankName;
}
string Card::toString(){
    string cardName = getRank(r) + " of " + getSuit(s);
    return cardName;
}

bool Card::isAce(){
    if (getRank(r) == "Ace"){
        return true;
    }
    else{
        return false;
    }
}

int Card::getCardValue(){
    if(r < 9){
        return r + 2;
    }
    else if(isAce()){
        return 11;
    }
    else{
        return 10;
    }
}