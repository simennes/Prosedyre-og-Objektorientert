#include "ContractDataBase.h"
#include <fstream>

InsuranceContract ContractDataBase::getContract(int id)
{
    // BEGIN: 1b
    
    for(InsuranceContract contract: contracts){
        if (contract.getId() == id){
            return contract;
        }
    }

    // END: 1b
}

int ContractDataBase::numberOfInsuranceType(InsuranceType type)
{
    // BEGIN: 1c

    // Write your answer to assignment 1c here, between the // BEGIN: 1c
    // and // END: 1c comments. Remove the code that is already there.

    (void)type;
    return 0;

    // END: 1c
}

int ContractDataBase::addContract(string holderName, InsuranceType insType, int value)
{
    // BEGIN: 1d 

    int maxId = 0;
    for(InsuranceContract contract: contracts){
        int id = contract.getId();
        if (id > maxId){
            maxId = id;
        }
    }
    InsuranceContract newContract{holderName, insType, value, maxId + 1};
    contracts.push_back(newContract);

    return maxId + 1;

    // END: 1d
}

void ContractDataBase::saveContracts(string filename)
{
    // BEGIN: 1e

    fstream dataFile;
    dataFile.open(filename, ios::out);
    int length = contracts.size();

    for(InsuranceContract contract: contracts){
        string dataString = "";
        dataString += contract.getHolder() + ",";
        dataString += insuranceTypeToString(contract.getInsuranceType()) + ",";
        dataString += to_string(contract.getValue()) + ",";
        dataString += to_string(contract.getId()) + ",";
        dataString += contract.getInsuranceText();

        if(contract.getId() != contracts[length - 1].getId()){
            dataString += "\n";
        }
        dataFile << dataString;
    }
    dataFile.close();

    // END: 1e
}

void ContractDataBase::loadContracts(string filename)
{
    ifstream inFile{filename};
    if (!inFile)
    {
        error("Couldn't open file: ", filename);
    }

    string line;
    while (getline(inFile, line))
    {
        stringstream ss{line};
        char seperator;

        string holderName;
        getline(ss, holderName, ',');

        string insType;
        getline(ss, insType, ',');

        int value;
        ss >> value;
        ss >> seperator;

        int id;
        ss >> id;
        ss >> seperator;

        string insuranceText;
        getline(ss, insuranceText, ',');

        contracts.push_back({holderName, stringToInsuranceType.at(insType), value, id, insuranceText});
    }
}
