#pragma once
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void testCallByValue();

void incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes);
void testCallByReference();

void swapNumbers(int& num1, int& num2);

struct Student{
string name;
string studyProgram;
int age;
};

void printStudent(Student studentName);

bool isInProgram(Student studentName, string program);
void printTrueFalse(bool value);

string randomizeString(int length, char lowerLim, char upperLim);
int randomWithLimits(int upper, int lower);
string readInputToString(int length, char lowerLim, char upperLim);
int countChar(string text, char letter);