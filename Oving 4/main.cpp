#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"

int main()
{
	srand(unsigned(time(nullptr)));
	int menu = 1;
	while (menu != 0)
	{
		cout << "\n\nMenu:\n"
		"0) End\n"
		"1) Task 1 - testCallByValue\n"
		"2) Task 1 - testCallByRef\n"
		"3) Task 1 - swapNumbers\n"
		"4) Task 2 - Student\n"
		"5) Task 3 - Grades\n"
		"6) Play MasterMind\n"
		"7) Play MasterMind w/graphics\n"
		"Choose (0-7): ";
		cin >> menu;
		cout << "\n";

		if(menu == 1){
			testCallByValue();
		}

		else if(menu == 2){
			testCallByReference();
		}

		else if(menu == 3){
			int num1 = 10;
			int num2 = 20;
			cout << "Before swap: num1 = " << num1 << ", num2 = " << num2;

			swapNumbers(num1, num2);
			
			cout << "\nAfter swap: num1 = " << num1 << ", num2 = " << num2;
		}

		else if(menu == 4){
			Student simen {"Simen", "FysMat", 21};
			printStudent(simen);

			string testProgram1 = "FysMat";
			string testProgram2 = "Kyb";

			cout << "\n" << simen.name << " is studying " << testProgram1 << ": ";
			printTrueFalse(isInProgram(simen, testProgram1));

			cout << "\n" << simen.name << " is studying " << testProgram2 << ": ";
			printTrueFalse(isInProgram(simen, testProgram2));

		}

		else if(menu == 5){
			testString();
		}

		else if (menu == 6){
			playMasterMind();
		}

		else if (menu == 7){
			playMasterMindGraphics();
		}
	}
}
