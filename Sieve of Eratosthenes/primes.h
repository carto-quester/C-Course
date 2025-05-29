//Header file to declare functions

//guard the header file

#ifndef PRIMES_H
#define PRIMES_H

#include <iostream>
#include <string>

const int SIZE = 1000;   // define a constant size for the boolean array

int getNum(const std::string& label);  //declare function that gets range from user passing by reference

bool isValid(int number);   //declare function to check if number is valid

#endif 