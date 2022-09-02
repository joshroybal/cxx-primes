#ifndef PRIMES_HPP
#define PRIMES_HPP

#include <vector>

class Primes {
    public:
        bool isPrime(unsigned) const;
        std::vector<unsigned> getPrimes(unsigned) const;
        unsigned countPrimes(unsigned) const;
        std::vector<unsigned> Factorize(unsigned) const;
    private:
        bool is_prime_(unsigned) const;
        unsigned count_primes_(unsigned) const;
        bool* sieve_(unsigned) const;
        std::vector<unsigned> segmented_sieve_(unsigned) const;
        unsigned smallest_divisor_(unsigned) const;
        std::vector<unsigned> factorize_(unsigned) const;
};

#endif
