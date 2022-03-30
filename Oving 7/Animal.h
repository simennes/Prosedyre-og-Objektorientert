#pragma once
#include "std_lib_facilities.h"

class Animal{

    protected:
        int age;
        string name;
    public:
        Animal(int animalAge, string animalName);
        virtual ~Animal() {};
        string nameAndAge();
        virtual string toString() = 0;
};

class Cat: public Animal {
    
    public:
        using Animal::Animal;
        string toString();
};

class Dog: public Animal {
    
    public:
        using Animal::Animal;
        string toString();
};

void testAnimal();