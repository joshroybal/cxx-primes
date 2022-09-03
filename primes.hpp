#ifndef PRIMES_HPP
#define PRIMES_HPP

#include <vector>

class Primes {
    public:
        bool isPrime(unsigned long long) const;
        std::vector<unsigned long long> getPrimes(unsigned long long) const;
        unsigned long long countPrimes(unsigned long long) const;
        std::vector<unsigned long long> Factorize(unsigned long long) const;
    private:
        bool is_prime_(unsigned long long) const;
        unsigned long long count_primes_(unsigned long long) const;
        bool* sieve_(unsigned long long) const;
        std::vector<unsigned long long> segmented_sieve_(unsigned long long) const;
        unsigned long long smallest_divisor_(unsigned long long) const;
        std::vector<unsigned long long> factorize_(unsigned long long) const;
};

#endif
