#include <vector>
#include <cmath>
#include "primes.hpp"

// Primes class private methods
// Method returns true when n is prime, returns false otherwise.
bool Primes::is_prime_(long long n) const
{
    bool result;
    if (n < 2 || smallest_divisor_(n) != n)
        result = false;
    else
        result = true;
    return result;
}

// funtion returns no. of primes p <= n
long long Primes::count_primes_(long long n) const
{
    int count = 0;

    for (long long i = 2; i <= n; i++)
        if (is_prime_(i))
            ++count;

    return count;
}

bool* Primes::sieve_(long long n) const
{
    bool* sieve = new bool[n+1];
    for (long long i = 0; i < 2; ++i) sieve[i] = false;
    for (long long i = 2; i <= n; ++i) sieve[i] = true;
    for (long long i = 2; i*i <= n; i++)
        for (long long j = i*i; j <= n; j += i) sieve[j] = false;
    return sieve;
}

std::vector<long long> Primes::segmented_sieve_(long long n) const
{
    std::vector<long long> primes;
    // compute base primes
    long long segsize = sqrt(n);
    bool* segment = sieve_(segsize);
    for (long long i = 0; i <= segsize; i++)
        if (segment[i])
            primes.push_back(i);
    long long nbp = primes.size();   // tag no. of base primes
    // compute following segments
    for (long long i = segsize+1; i <= n; i += segsize+1) {
        for (long long j = 0; j <= segsize; ++j) segment[j] = true;
        // redo later maybe
        // compute current segment
        for (long long j = 0; j < nbp; j++) {
            long long p = (i/primes[j])*primes[j];
            if (p < i) p += primes[j];
            for (long long k = p; k <= i+segsize; k += primes[j])
                segment[k-i] = false;
        }
        // yield current primes from current segment
        for (long long j = 0; j <= segsize && i+j <= n; j++)
            if (segment[j] == true)
                primes.push_back(i+j);
    }
    delete [] segment;
    return primes;
}

// Method returns smallest proper divisor of n.
long long Primes::smallest_divisor_(long long n) const
{
    long long supremum = sqrt(n), sd = n;
    if (n%2 == 0)
        sd = 2;
    else if (n%3 == 0)
        sd = 3;
    else
        for (long long i = 5; sd == n && i <= supremum; i += 6)
            if (n%i == 0)
                sd = i;
            else if (n%(i+2) == 0)
                sd = i+2;

    return sd;
}

// Method returns factorization of n as vector.
std::vector<long long> Primes::factorize_(long long n) const
{
    std::vector<long long> factors;
    if (n > 1) {
        long long factor = smallest_divisor_(n);
        long long rest = n / factor;
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
