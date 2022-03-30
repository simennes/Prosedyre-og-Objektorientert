#pragma once
#include "std_lib_facilities.h"
#include "card.h"
#include "cardDeck.h"

class BlackJack{
    private:
        CardDeck deck{};
        vector<Card> dealerHand;
        vector<Card> playerHand;
        int dealerScore = 0;
        int playerScore = 0;

        int getHandScore(vector<Card> cards);
        bool askPlayerDrawCard();
        void drawPlayerCard();
        void drawDealerCard();

    public:
        BlackJack();
        void playBlackJack();

};