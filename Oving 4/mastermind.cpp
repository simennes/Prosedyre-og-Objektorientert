#include "mastermind.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "masterVisual.h"

int checkCharactersAndPosition(string code, string guess){
    int numCorrect = 0;
    int length = code.length();

    for(int i = 0; i < length; i++){
        if(code[i] == guess[i]){
            numCorrect++;
        }
    }
    return numCorrect;
}

int checkCharacters(string code, string guess){
    int numCorrect = 0;
    int length = code.length();
    string visited = "";

    for(int i = 0; i < length; i++){
        if(code.find(guess[i]) != string::npos && !(visited.find(guess[i]) != string::npos)){
            numCorrect++;
        }
        visited += guess[i];
    }
    return numCorrect;
}

void playMasterMind(){
    cout << "Welcome to mastermind. A secret code of 4 letters A-F has been created. Try to guess it!\n\n";
    int attempts = 10;
    constexpr int size = 4;
    constexpr int letters = 6;

    string code = "";
    code = randomizeString(size, 'A', 'A' + (letters - 1));
    string guess = "";

    while(true){
        cout << "\nYou have " << attempts << " attempts left.\n";
        guess = readInputToString(size, 'A', 'A' + letters - 1);
        
        if(checkCharactersAndPosition(code, guess) == size){
            cout << "\nCorrect!";
            break;
        }
        cout << "\nYour guess: " << guess;
        cout << "\nYou have " << checkCharacters(code, guess) << " correct characters,\n";
        cout << checkCharactersAndPosition(code, guess) << " are in the right position.\n";
        attempts--;

        if(attempts == 0){
            cout << "\nYou're out of attempts! Better luck next time!\nThe code was: " << code;
            break;
        }
    }
}

void playMasterMindGraphics(){
    constexpr int size = 4;
    constexpr int letters = 6;
    char lower = 'A';
    int attempts = 6;

    string code = "";
    code = randomizeString(size, 'A', 'A' + (letters - 1));
    string guess = "";

    MastermindWindow mwin{900, 20, winW, winH, size, "Mastermind"};

    addGuess(mwin, code, lower);
    mwin.setCodeHidden(true);
    mwin.redraw();

    while(true){
        guess = mwin.getInput(size, 'A', 'A' + letters - 1);
        addGuess(mwin, guess, lower);
        mwin.redraw();
        int correctCharacter = checkCharacters(code, guess);
        int correctPosition = checkCharactersAndPosition(code, guess);
        addFeedback(mwin, correctPosition, correctCharacter);

        attempts--;
        if (correctPosition == size){
            cout << "\nYour guess was correct, congratulations!";
            break;
        }
        else if(attempts == 0){
            cout << "\nYou're out of attempts! Better luck next time!\nThe code was: " << code;
            break;
        }
    }
}