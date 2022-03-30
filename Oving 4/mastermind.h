#pragma once
#include "std_lib_facilities.h" 

//Initializes mastermind game
void playMasterMind();

//Initializes mastermind game with graphics
void playMasterMindGraphics();

//Returns number of characters in right place
int checkCharactersAndPosition();

//Returns number of guessed characters in code
int checkCharacters(string code, string guess);