#include "std_lib_facilities.h"
#include "oppgave_1.h"
#include <fstream>

void writeToFile(string fileName){
    fstream myFile;
    myFile.open(fileName, ios::out);

    if(!myFile){
        cout << "File not created.\n";
    }
    else{
        cout << "File '" << fileName << "' created\n";

        cout << "Write to file, type 'quit' to stop.\n";
        string input = "";
        while(true){
            cout << "\nWrite to file: ";
            cin >> input;
            if(input == "quit"){
                break;
            }
            input += "\n";
            myFile << input;
        }
        myFile.close();
        
    }
}

void addLineNum(string fileName){
    fstream myFile;
    myFile.open(fileName, ios::in);

    if(!myFile){
        cout << "File does not exist.\n";
    }
    else{
        
        vector<string> fileVector;
        string line;
        int i = 1;
        while(getline(myFile, line)){
            string lineNum = to_string(i);
            string newLine = lineNum + ". " + line + "\n";
            fileVector.push_back(newLine);
            i++;
        }
        myFile.close();

        fstream newFile;
        newFile.open(fileName + "_copy.txt", ios::out);

        for(int i = 0; i < fileVector.size(); i++){
            newFile << fileVector[i];
        }
        newFile.close();
    
    }
}