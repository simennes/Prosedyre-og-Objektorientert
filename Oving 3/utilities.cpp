#include "utilities.h"
#include "std_lib_facilities.h"

int randomWithLimits(int upper, int lower){
    return rand() % (upper - lower + 1) + lower;
}