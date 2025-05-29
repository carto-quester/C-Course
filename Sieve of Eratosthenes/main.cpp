/*

Title: Sieve of Eratosthenes Primes
Summary: This program uses the Sieve of Eratosthenes to find all prime numbers in a user defined range 
with a max array size of 1000
*/
#include <iostream>
#include "primes.h"
//define main function to run
int main(){

    // declare variables min and max

    int min = 1;
    int max =0;

    while(min > max){
        min = getNum("Enter min: ");
        max = getNum("Enter max: ");
    }
    //boolean array with size of 1000
    bool primes[SIZE];
    //iterate through every value and assume every value is prime
    for (int i = 0; i < SIZE; i++)
        primes[i] = true;

    //now iterate through all multiples of 2 and mark them as non prime

    for(int i = 2; i * i < SIZE; i++){

        if (primes[i]){
            for (int j = i * i; j < SIZE; j+= i){
                if( j % i == 0)
                    primes[j] = false;
            }
    }

}
    //now iterate through the boolean array and print all prime numbers in the range
    for (int i = min; i <= max; i++){
        if (primes[i])
            std::cout << i << "\t";

    }
    //move to a new line
    std::cout << std::endl;
    //exit program with return 0
    return 0;
}