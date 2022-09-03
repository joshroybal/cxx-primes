#include <sstream>
#include <ctime>
#include <climits>
#include "random.hpp"

// Random class public interface accessor methods.
unsigned long long Random::randomNumber()
{
    return random_number_();
}

unsigned long long Random::randomNumber(unsigned long long n)
{
    return random_number_(n);
}

unsigned long long Random::randomNumber(unsigned long long lo,
                                        unsigned long long hi)
{
    return random_number_(lo, hi);
}

// Random class private methods.
// Drop const guards on all accessing methods because state matters.
void Random::randomize_()
{
    // 64-bit Linear Congruential Generator.
    // https://nuclear.llnl.gov/CNP/rng/rngman/node4.html
    if (seed_ == 0) seed_ = time(0);
    seed_ = 2862933555777941757ULL*seed_+3037000493ULL%ULLONG_MAX;
}

unsigned long long Random::random_number_()
{
    randomize_();
    return seed_;
}

// Method returns pseudo-random 0 <= rnd < n.
// avoid using this one
unsigned long long Random::random_number_(unsigned long long n)
{
    randomize_();
    return n*(seed_/double(ULLONG_MAX));
}

// Method returns pseudo-random lo <= rnd <= hi.
unsigned long long Random::random_number_(unsigned long long lo,
                                          unsigned long long hi)
{
    randomize_();
    return lo+(seed_)%(hi-lo+1);
}
