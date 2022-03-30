#pragma once
#include "Car.h"
#include <iostream>

class Person{
    private:
        std::string name;
        std::string email;
        std::unique_ptr<Car> car;

    public:
    Person(std::string argName, std::string argEmail, std::unique_ptr<Car> argCar = nullptr):
    name{argName}, email{argEmail}, car{std::move(argCar)}{};

    std::string getEmail() const;
    std::string getName() const;
    void setEmail(std::string newMail);
    bool hasAvailableSeats() const;
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};