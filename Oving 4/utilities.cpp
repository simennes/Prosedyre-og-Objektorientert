#include "utilities.h"
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << endl;
}

void incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes){
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    cout << startValue;
}

void testCallByReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << incrementByValueNumTimes(v0, increment, iterations) << endl;
}

void swapNumbers(int& num1, int& num2){
    int tempNum = num1;
    num1 = num2;
    num2 = tempNum;
}

void printStudent(Student studentName){
    string name = studentName.name;
    string studyProgram = studentName.studyProgram;
    int age = studentName.age;
    
    cout << "Name: " << name << endl;
    cout << "Study Program: " << studyProgram << endl;
    cout << "Age: " << age << endl;
}

bool isInProgram(Student studentName, string program){
    if (program == studentName.studyProgram){
        return true;
    }
    else{
        return false;
    }
}

void printTrueFalse(bool value){
    if (value == 1){
        cout << "true";
    }
    else{
        cout << "false";
    }
}

int randomWithLimits(int lower, int upper){
    return rand() % (upper - lower + 1) + lower;
}

string randomizeString(int length, char lowerLim, char upperLim){
    string randStr = "";

    for(int i = 0; i < length; i++){
        int num = randomWithLimits(0, upperLim - lowerLim);
        randStr += (lowerLim + num);
    }
    return randStr;
}

string readInputToString(int length, char lowerLim, char upperLim){
    string inputString = "";

    for(int i = 0; i < length; i++){
        char inputChar;
        cout << "Type character: ";
        cin >> inputChar;
        toupper(inputChar);

        while(cin.fail() || inputChar - lowerLim > upperLim - lowerLim || inputChar - lowerLim < 0){
            cout << "\nInput was not a valid character. Please try again: ";
            cin >> inputChar;
            toupper(inputChar);
        }

        inputString += inputChar;
    }
    return inputString;
}

int countChar(string text, char letter){
    int num = 0;
    for(int i = 0; i < text.length(); i++){
        if(text[i] == letter){
            num++;
        }
    }
    return num;
}