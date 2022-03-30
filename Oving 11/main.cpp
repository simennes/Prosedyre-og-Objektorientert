#include <iostream>
#include <vector>
#include <set>

void replaceVec(std::vector<std::string>& vec, std::string old, std::string replacement){
	for(std::vector<std::string>::iterator itr = vec.begin(); itr < vec.end(); itr++){
		if(*itr == old){
			*itr = replacement;
		}
	}
}

void replaceSet(std::set<int>& set, int old, int replacement){
	for(std::set<int>::iterator itr = set.begin(); itr != set.end();){
		if(*itr == old){
			itr = set.erase(itr);
			set.insert(replacement);
		}
		else{
			itr++;
		}
	}
}

int main()
{
	int menu = 1;
	while (menu != 0)
	{
		std::cout << "\n\nMenu:\n"
		"0) End\n"
		"1) Test iterators for vector\n"
		"2) Test iterators for set\n"
		"Choose (0-2): ";
		std::cin >> menu;
		std::cout << "\n";

		if(menu == 1){
			std::vector<std::string> stringVec = {"Hydrogen", "Helium", "Lithium", 
			"Beryllium", "Bor", "Karbon", "Nitrogen"};

			std::vector<std::string>::iterator itr;
			for(itr = stringVec.begin(); itr != stringVec.end(); itr++){
				std::cout << *itr << "\n";
			}

			std::cout << "\n---------------------------------------------\nReverse:\n\n";

			for(std::vector<std::string>::reverse_iterator revItr = stringVec.rbegin(); revItr != stringVec.rend(); revItr++){
				std::cout << *revItr << "\n";
			}

			std::cout << "\n---------------------------------------------\nReplace test:\n\n";
			std::cout << "Before:\n";
			for(std::vector<std::string>::iterator itr = stringVec.begin(); itr != stringVec.end(); itr++){
				std::cout << *itr << ", ";
			}
			std::cout << "\n\nAfter (replace Bor with Boron):\n";
			replaceVec(stringVec, "Bor", "Boron");
			for(std::vector<std::string>::iterator itr = stringVec.begin(); itr != stringVec.end(); itr++){
				std::cout << *itr << ", ";
			}
		}
		else if(menu == 2){
			std::set<int> testSet = {1,35,12,14,66,32,10,33,7};

			for(std::set<int>::iterator itr = testSet.begin(); itr != testSet.end(); itr++){
				std::cout << *itr << "\n";
			}

			std::cout << "\n---------------------------------------------\nReverse:\n\n";

			for(std::set<int>::reverse_iterator revItr = testSet.rbegin(); revItr != testSet.rend(); revItr++){
				std::cout << *revItr << "\n";
			}

			std::cout << "\n---------------------------------------------\nReplace test:\n\n";
			std::cout << "Before:\n";
			for(std::set<int>::iterator itr = testSet.begin(); itr != testSet.end(); itr++){
				std::cout << *itr << ", ";
			}
			std::cout << "\n\nAfter (replace 33 with 99):\n";
			replaceSet(testSet, 33, 99);
			for(std::set<int>::iterator itr = testSet.begin(); itr != testSet.end(); itr++){
				std::cout << *itr << ", ";
			}
		}
	}
}
