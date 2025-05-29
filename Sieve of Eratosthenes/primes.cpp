//cpp file to define functions and to be called later into the main.cpp file


#include "primes.h"

//define  getRange to prompt user to enter a range of values, and check if the range is within the bounds of the array
int getNum(const std::string& label){

    std::cout << label;
    int number;
    std::cin >> number;

    while(! isValid(number)){
        std::cout << label;
        std::cin >> number;
    }
    return number;
}    

bool isValid(int number){
    if (number >= 0 && number < 1000)
        return true;
    return false;
}

