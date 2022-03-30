#include "std_lib_facilities.h"
#include "card.h"
#include "cardDeck.h"
#include "blackJack.h"

bool tryAgain(){
	char ans;
	cout << "\n\nTry again? [Y/N] ";
	cin >> ans;
	if(toupper(ans) == 'Y'){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
	/*
	Rank r = Rank::king;
	Suit s = Suit::hearts;
	string rank = rankToString(r);
	string suit = suitToString(s);
	cout << "Rank: " << rank << " Suit: " << suit << '\n';
	Card c{Suit::diamonds, Rank::jack};
	cout << c.toString() << '\n';

	CardDeck cd{};
	cd.shuffle(1000);
	cd.print();
	*/

	while(true){
		BlackJack blackJack{};
		blackJack.playBlackJack();
		if(!tryAgain()){
			break;
		}
	}
}