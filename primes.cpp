#include <iostream>
#include <vector>
#include <cmath>
#include "primes.hpp"

// Primes class public methods
// brute force primality test interface
bool Primes::isPrime(unsigned long long n) const
{
    return is_prime_(n);
}

// function returns vector containing first n primes
std::vector<unsigned long long> Primes::getPrimes(unsigned long long n) const
{
    return segmented_sieve_(n);
}

// function returns no. of primes p <= n
unsigned long long Primes::countPrimes(unsigned long long n) const
{
    return count_primes_(n);
}

// function returns factorization of n as vector
std::vector<unsigned long long> Primes::Factorize(unsigned long long n) const
{
    return factorize_(n);
}

// Primes class private methods
// Method returns true when n is prime, returns false otherwise.
bool Primes::is_prime_(unsigned long long n) const
{
    bool result;
    if (n < 2 || smallest_divisor_(n) != n)
        result = false;
    else
        result = true;
    return result;
}

// funtion returns no. of primes p <= n
unsigned long long Primes::count_primes_(unsigned long long n) const
{
    int count = 0;

    for (unsigned long long i = 2; i <= n; i++)
        if (is_prime_(i))
            ++count;

    return count;
}

bool* Primes::sieve_(unsigned long long n) const
{
    bool* sieve = new bool[n+1];
    for (unsigned long long i = 0; i < 2; ++i) sieve[i] = false;
    for (unsigned long long i = 2; i <= n; ++i) sieve[i] = true;
    for (unsigned long long i = 2; i*i <= n; i++)
        for (unsigned long long j = i*i; j <= n; j += i) sieve[j] = false;
    return sieve;
}

std::vector<unsigned long long> Primes::segmented_sieve_(unsigned long long n) const
{
    std::vector<unsigned long long> primes;
    // compute base primes
    unsigned long long segsize = sqrt(n);
    bool* segment = sieve_(segsize);
    for (unsigned long long i = 0; i <= segsize; i++)
        if (segment[i])
            primes.push_back(i);
    unsigned long long nbp = primes.size();   // tag no. of base primes
    // compute following segments
    for (unsigned long long i = segsize+1; i <= n; i += segsize+1) {
        for (unsigned long long j = 0; j <= segsize; ++j) segment[j] = true;
        // redo later maybe
        // compute current segment
        for (unsigned long long j = 0; j < nbp; j++) {
            unsigned long long p = (i/primes[j])*primes[j];
            if (p < i) p += primes[j];
            for (unsigned long long k = p; k <= i+segsize; k += primes[j])
                segment[k-i] = false;
        }
        // yield current primes from current segment
        for (unsigned long long j = 0; j <= segsize && i+j <= n; j++)
            if (segment[j] == true)
                primes.push_back(i+j);
    }
    delete [] segment;
    return primes;
}

// Method returns smallest proper divisor of n.
unsigned long long Primes::smallest_divisor_(unsigned long long n) const
{
    unsigned long long supremum = sqrt(n), sd = n;
    if (n%2 == 0)
        sd = 2;
    else if (n%3 == 0)
        sd = 3;
    else
        for (unsigned long long i = 5; sd == n && i <= supremum; i += 6)
            if (n%i == 0)
                sd = i;
            else if (n%(i+2) == 0)
                sd = i+2;

    return sd;
}

// Method returns factorization of n as vector.
std::vector<unsigned long long> Primes::factorize_(unsigned long long n) const
{
    std::vector<unsigned long long> factors;
    if (n > 1) {
        unsigned long long factor = smallest_divisor_(n);
        unsigned long long rest = n / factor;
        factors.push_back(factor);
        while (rest != 1 && !is_prime_(rest)) {
            factor = smallest_divisor_(rest);
            factors.push_back(factor);
            rest = rest / factor;
        }
        if (is_prime_(rest))
            factors.push_back(rest);
    }
    return factors;
}
