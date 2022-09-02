#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "primes.hpp"
#include "random.hpp"


int main()
{	
    Primes object;
    srand(time(0));
    for (int i = 0; i < 25; i++) {
        unsigned rnd = random(UINT_MAX);
        std::cout << ' ' << rnd << ':';
        std::vector<unsigned> factors = object.Factorize(rnd);
        std::vector<unsigned>::const_iterator cit;
        for (cit = factors.begin(); cit != factors.end(); cit++)
            std::cout << ' ' << *cit;
        std::cout << std::endl;
    }
    return 0;
}
