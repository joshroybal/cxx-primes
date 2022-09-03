#include <iostream>
#include <vector>
#include "primes.hpp"
#include "random.hpp"


int main()
{
    Primes myPrimes;
    Random myRandom;
    for (int i = 0; i < 25; i++) {
        unsigned long long rnd = myRandom.randomNumber();
        std::vector<unsigned long long> factors = myPrimes.Factorize(rnd);
        std::cout << ' ' << rnd << ':';
        std::vector<unsigned long long>::const_iterator cit;
        for (cit = factors.begin(); cit != factors.end(); cit++)
            std::cout << ' ' << *cit;
        std::cout << std::endl;
    }
    return 0;
}
