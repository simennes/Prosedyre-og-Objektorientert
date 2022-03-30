#include "std_lib_facilities.h"
#include "card.h"
#include "cardDeck.h"
#include "blackJack.h"

BlackJack::BlackJack(){
    deck.shuffle(10000);
    for(int i = 0; i < 2; i++){
        drawPlayerCard();
        drawDealerCard();
    }
    while(getHandScore(dealerHand) < 17){
        drawDealerCard();
    }
}

int BlackJack::getHandScore(vector<Card> cards){
    int score = 0;
    for(int i = 0; i < cards.size(); i++){
        score += cards[i].getCardValue();
    }
    return score;
}

bool BlackJack::askPlayerDrawCard(){
    char answer;
    cout << "\n\nDraw another card? [Y/N]: ";
    cin >> answer;
    if(toupper(answer) == 'Y'){
        return true;
    }
    else{
        return false;
    }
}

void BlackJack::drawPlayerCard(){
    Card card = deck.drawCard();
    playerHand.push_back(card);
    playerScore += card.getCardValue();
}

void BlackJack::drawDealerCard(){
    Card card = deck.drawCard();
    dealerHand.push_back(card);
    dealerScore += card.getCardValue();
}

void BlackJack::playBlackJack(){
    
    cout << "\nDealer's first card is: " << dealerHand[0].toString() << endl;
    cout << "\nYour cards are:";
    for(int i = 0; i < 2; i++){
        cout << "\n";
        cout << playerHand[i].toString();
    }

    while(true){
        bool gameDone = false;
        if(playerScore == 21 && dealerScore != 21){
            cout << "\nYou got blackjack! Congratulations!";
            gameDone = true;
            break;
        }
        else if(playerScore > 21){
            cout << "\nYour score is " << playerScore << ", you lost.";
            gameDone = true;
            break;
        }
        else if(askPlayerDrawCard()){
            drawPlayerCard();
            cout << "\nYou got " << playerHand.back().toString();
            cout << "\nYour cards are now: ";
            for(int i = 0; i < playerHand.size(); i++){
                cout << "\n -";
                cout << playerHand[i].toString();
            }
        }
        else{gameDone = true;}
        if (gameDone){
            cout << "\nThe dealers cards were:";
            for(int i = 0; i < dealerHand.size(); i++){
                cout << "\n -";
                cout << dealerHand[i].toString();
            }
            cout << "\n\nYour score is " << playerScore << " and the dealer's score is " << dealerScore;
            if(playerScore > dealerScore || dealerScore > 21){
                cout << ". Congratulations, you won!";
                break;
            }
            else{
                cout << ". You lost.";
                break;
            }
        }

    }
}