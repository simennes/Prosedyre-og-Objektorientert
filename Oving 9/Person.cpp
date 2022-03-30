#include <iostream>
#include "Person.h"
#include "Car.h"

std::string Person::getEmail() const{
    return email;
}

std::string Person::getName() const{
    return name;
}

void Person::setEmail(std::string newMail){
    email = newMail;
}

bool Person::hasAvailableSeats() const{
    if(car->hasFreeSeats()){
        return true;
    }
    else{
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Person& p){
    os << "Name: " << p.getName() << "\nEmail: " << p.getEmail();
    return os;
}