#include "AnimationWindow.h"
#include "Emoji.h"

// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 1000;
constexpr int emojiRadius = 60;

int main()
{

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

	EmptyFace emoji1{emojiRadius, tl};
	emoji1.draw(win);

	SmilingFace emoji2{emojiRadius, {tl.x + (25 + 100), tl.y}};
	emoji2.draw(win);

	SadFace emoji3{emojiRadius, {tl.x + 2*(25 + 100), tl.y}};
	emoji3.draw(win);

	AngryFace emoji4{emojiRadius, {tl.x + 3*(25 + 100), tl.y}};
	emoji4.draw(win);

	WinkingFace emoji5{emojiRadius, {tl.x + 4*(25 + 100), tl.y}};
	emoji5.draw(win);

	SurprisedFace emoji6{emojiRadius, {tl.x + 5*(25 + 100), tl.y}};
	emoji6.draw(win);

	win.wait_for_close();
}
