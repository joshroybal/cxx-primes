#ifndef PRIMES_HPP
#define PRIMES_HPP

#include <vector>

class Primes {
    public:
        bool isPrime(long long n) const { return is_prime_(n); };
        std::vector<long long> getPrimes(long long n) const { return segmented_sieve_(n); };
        long long countPrimes(long long n) const { return count_primes_(n); };
        std::vector<long long> Factorize(long long n) const { return factorize_(n); };
    private:
        bool is_prime_(long long) const;
        long long count_primes_(long long) const;
        bool* sieve_(long long) const;
        std::vector<long long> segmented_sieve_(long long) const;
        long long smallest_divisor_(long long) const;
        std::vector<long long> factorize_(long long) const;
};

#endif
