#include "Utilities.h"
#include <fstream>

string toGreek(string sentence)
{
    // BEGIN: 2a

    string updatedString = "";
    for(char c : sentence){
        if(c != ' '){
            char newChar = c + 2;
            updatedString += newChar;
        }
    }
    return updatedString;
    
    // END: 2a
}

vector<vector<string>> loadSvada()
{
    // BEGIN: 2b

    vector<vector<string>> svadaVector;
    fstream svadaFile;
    svadaFile.open("SvadaWords.txt", ios::in);

    string line;
    vector<string> groupVector;
    while(getline(svadaFile, line)){
        if(line != "||"){
            groupVector.push_back(line);
        }
        else{
            svadaVector.push_back(groupVector);
            groupVector.clear();
        }
    }
    svadaVector.push_back(groupVector);
    svadaFile.close();

    return svadaVector;

    // END: 2b
}

string svadaGenerator(vector<vector<string>> svadaVec)
{
    // BEGIN: 2c1

    string svadaString = "";
    for(vector<string> group : svadaVec){
        int randIndex = randint(0, group.size() - 1);
        svadaString += group[randIndex] + " "; 
    }
    
    return svadaString;
    // END: 2c1
}