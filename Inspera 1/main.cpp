#include "std_lib_facilities.h"
#include "InsuranceContract.h"
#include "ContractDataBase.h"
#include "Utilities.h"

//------------------------------------------------------------------------------'

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	ContractDataBase db{};
	db.loadContracts("DataBase.txt");
	InsuranceContract contract{"Jonas Lie", InsuranceType::Car, 1000, 1242, ""};
	//You can test your code under here
	
	db.addContract("Simen", InsuranceType::Car, 1000);
	db.saveContracts("Tester.txt");

	cout << toGreek("alle") << endl;

	vector<vector<string>> svadaVec = loadSvada();
	for(vector<string> group : svadaVec){
		cout << "---------" << endl;
		for(string text : group){
			cout << text << endl;
		}
	}

	return 0;
}

//------------------------------------------------------------------------------
