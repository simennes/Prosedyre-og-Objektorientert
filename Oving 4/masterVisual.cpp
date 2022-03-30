#include "masterVisual.h"
#include "mastermind.h"

void addGuess(MastermindWindow &mwin, const string code, const char startLetter)
{
	Guess newGuess = {code, startLetter};
	mwin.guesses.push_back(newGuess);
}

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter)
{
	Feedback newFeedback = {correctPosition, correctCharacter};
	mwin.feedbacks.push_back(newFeedback);
}

void MastermindWindow::drawCodeHider()
{
	if(code_hidden) {
		draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY, Color::black);
	}
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size, const string &title) 
: AnimationWindow(x, y, w, h, title),
guessBtn{upperLeftCornerBtn.x, upperLeftCornerBtn.y, btnW, btnH, "Add"},
guess{upperLeftCornerInBox.x, upperLeftCornerInBox.y, inBoxW, inBoxH, "Guess"},
size(size)
{
	add(guess);
	add(guessBtn);
	guessBtn.callback(cb_guess, this);
};

string MastermindWindow::wait_for_guess()
{
	while (!button_pressed && !should_close())
	{
		for(int guessIndex = 0; guessIndex < guesses.size(); guessIndex++) {
			//Implementer gjett slik at det vises fargede rektangler i grafikkvinduet
			{
			char lower = guesses[guessIndex].startLetter;
			int yPos = (3 + 2*guessIndex)*padY;

			char c = guesses[guessIndex].code[0] - lower;
			draw_rectangle(Point{padX, yPos}, padX, padY, c);

			c = guesses[guessIndex].code[1] - lower;
			draw_rectangle(Point{3*padX, yPos}, padX, padY, c);

			c = guesses[guessIndex].code[2] - lower;
			draw_rectangle(Point{5*padX, yPos}, padX, padY, c);

			c = guesses[guessIndex].code[3] - lower;
			draw_rectangle(Point{7*padX, yPos}, padX, padY, c);
			}
		}

		for(int feedbackIndex = 0; feedbackIndex < feedbacks.size(); feedbackIndex++) {
			int pos = feedbacks[feedbackIndex].correctPosition;
			int num = feedbacks[feedbackIndex].correctCharacter - pos;
			int yPos = 5.5*padY + feedbackIndex*2*padY;

			for (int i = 0; i < size; i++)
			{
				int xPos = 9*padX + (1 + 2*i)*radCircle;
				if(pos > 0){
					draw_circle(Point{xPos, yPos}, radCircle, 0);
					pos--;
				}
				else if(num > 0){
					draw_circle(Point{xPos, yPos}, radCircle, 7);
					num--;
				}
				else{
					draw_circle(Point{xPos, yPos}, radCircle, 49);
				}
			}
		}

		// Burde tegnes sist siden den skal ligge på toppen
		drawCodeHider();

		next_frame();
	}
	button_pressed = false;
	string newGuess = guess.value();
	guess.value(0);
	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput && !should_close())
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input.at(i);
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again" << endl;
		}
	}
	return guess;
}

void MastermindWindow::setCodeHidden(bool hidden) {
	code_hidden = hidden;
}