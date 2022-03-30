#include "Animal.h"
#include "std_lib_facilities.h"

Animal::Animal(int animalAge, string animalName){
    age = animalAge;
    name = animalName;
}

string Animal::nameAndAge(){
    return name + ", " + to_string(age);
}

string Cat::toString(){
    return "Cat: " + nameAndAge();
};

string Dog::toString(){
    return "Dog: " + nameAndAge();
};

void testAnimal(){
    vector<unique_ptr<Animal>> animals;
    animals.emplace_back(new Cat(5, "KittyCat"));
    animals.emplace_back(new Dog(100, "Bessie"));
    for(const auto& elem:animals){
        cout << elem->toString() << endl;
    }
};