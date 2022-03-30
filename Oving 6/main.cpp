#include "std_lib_facilities.h"
#include "oppgave_1.h"
#include "oppgave_2.h"
#include "CourseCatalog.h"
#include "Temps.h"

int main()
{
	int menu = 1;
	while(menu != 0){
		cout << "\n\nMenu:\n"
			"0) End\n"
			"1) Task 1 - Write to file\n"
			"2) Task 1 - Add line numbers\n"
			"3) Task 2 - Count Characters\n"
			"4) Task 2 - Debugging\n"
			"5) Task 3 - CourseCatalog\n"
			"6) Task 4 - Temperatures\n"
			"Choose (0-6): ";
			cin >> menu;
			cout << "\n";

		if(menu == 1){
			string fileName = "Oppgave_1_test" ;
			writeToFile(fileName);
		}

		else if (menu == 2){
			string fileName = "LineNumTest.txt";
			addLineNum(fileName);
		}

		else if(menu == 3){
			string fileName = "grunnlov.txt";
			map<char, int> charOverview = countChars(fileName);
			printMap(charOverview);
		}
		else if(menu == 4){
			const map<string, string> capitalsMap {
			{"Norway", "Oslo"},
			{"Sweden", "Stockholm"},
			{"Denmark", "Copenhagen"}
			};
			cout << "Capitals:\n";
			for (auto& elem : capitalsMap) {
				cout << getCapital(elem.first) << endl;
			}
		}
		else if(menu == 5){
			addBasicCourses();
		}
		else if(menu == 6){
			vector<Temps> temps = readTemps2("temperatures.txt");
			cout << "Fullfort";
			tempStats2(temps);

		}
		else if(menu == 7){
			Temps temptest;
			ifstream testFile;
			testFile.open("temp2.txt", ios::in);
			testFile >> temptest;
			cout << temptest.max << ", " << temptest.min;
		}
	}
}
