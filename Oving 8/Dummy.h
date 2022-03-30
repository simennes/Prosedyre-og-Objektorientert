#pragma once
#include <iostream>

class Dummy {
    public:
        int *num;
        Dummy() {
            num = new int{0};
        }
        Dummy(const Dummy&);
        ~Dummy() {
            delete num;
        }
        Dummy operator=(Dummy rhs) {  
            std::swap(num, rhs.num);
            return *this;
        }
};

void dummyTest();