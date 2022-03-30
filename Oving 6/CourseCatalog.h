#pragma once
#include "std_lib_facilities.h"

class CourseCatalog{
    private:
        map<string, string> courseMap;
        void saveData();
    public:
        CourseCatalog();
        void addCourse(string courseCode, string courseName);
        void removeCourse(string courseCode);
        string getCourse(string courseCode);
        friend ostream& operator<<(ostream&, const CourseCatalog&);
};

//Adds some basic courses to CourseCatalog object
void addBasicCourses();