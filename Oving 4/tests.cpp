#include "tests.h"
#include "std_lib_facilities.h"
#include "utilities.h"

void testString(){
    string grades = "";
    grades = randomizeString(8, 'A', 'F');
    cout << grades;

    vector<int> gradeCount(6);
    double gradeSum = 0;
    for(int i = 0; i < 5; i++){
        gradeCount[i] = countChar(grades, 'A' + i);
        gradeSum += gradeCount[i] * (5 - i);
    }
    cout << "\nAvrage grade: " << gradeSum/8;
}