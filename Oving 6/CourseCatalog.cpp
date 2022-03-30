#include "std_lib_facilities.h"
#include "CourseCatalog.h"
#include <fstream>

CourseCatalog::CourseCatalog(){
    fstream dataFile;
    dataFile.open("course_catalog.txt", ios::in);

    string line;
    while(getline(dataFile, line)){
        int length = line.size();
        addCourse(line.substr(0, 6), line.substr(8, length + 1));
    }
    dataFile.close();
}

void CourseCatalog::addCourse(string courseCode, string courseName){
    if(courseMap.count(courseCode) == 0){
        courseMap.insert({courseCode, courseName});
    }
    else{
        courseMap[courseCode] = courseName;
    }
    saveData();
}

void CourseCatalog::removeCourse(string courseCode){
    courseMap.erase(courseCode);
}

string CourseCatalog::getCourse(string courseCode){
    string courseName = courseMap.at(courseCode);
    return courseName;
}

void CourseCatalog::saveData(){
    fstream dataFile;
    dataFile.open("course_catalog.txt", ios::out);
    for(const auto& elem:courseMap){
        string line = "\n" + elem.first + ";" + elem.second;
        dataFile << line;
    }
    
}

ostream& operator<<(ostream& os, const CourseCatalog& courseCatalog){
    for(const auto& elem:courseCatalog.courseMap){
        os << "\nCourse Code: " << elem.first << ",    Name: " << elem.second;
    }
    return os;
}

void addBasicCourses(){
    CourseCatalog basics;
    vector<string> basicCodes = {"TDT4110", "TDT4102", "TMA4100"};
    vector<string> basicNames = {"Informasjonsteknologi grunnkurs", 
    "Prosedyre- og objektorientert programmering", "TMA4100 Matematikk 1"};

    for(int i = 0; i < basicCodes.size(); i++){
        basics.addCourse(basicCodes[i], basicNames[i]);
    }
    basics.addCourse("TDT4102", "C++");
    cout << basics;
};