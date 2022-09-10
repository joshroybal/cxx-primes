#include <limits>
#include <cmath>
#include "random.hpp"

// Random class private methods.
// Drop long long guards on all accessing methods because state matters.
long long Random::random_long_(long long mp)
{
    if (mp == 131071)
        seed_ = (32719*seed_)%mp;
    else if (mp == 2147483647)
        seed_ = (48271*seed_)%mp;
    else if (mp == 2305843009213693951L)
        seed_ = (437799614237992725UL*seed_)%mp;
    return seed_;
}

std::vector<long long> Random::random_vector_(long long m, long long n)
{
    std::vector<long long> z(n);

    for (int i = 0; i < n; ++i)
        z[i] = random_long_(m);
    return z;
}
