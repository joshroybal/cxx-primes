#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <vector>

class Random {
    public:
        Random() : seed_(1) {};
        Random(long long seed) : seed_(seed) {};
        void reset() { seed_ = 1; };
        long randomLong(long long m)
            { return random_long_(m); };
        std::vector<long long> randomVector(long long m, long long n)
            { return random_vector_(m, n); };
    private:
        long long seed_;
        long long random_long_(long long);
        std::vector<long long> random_vector_(long long, long long);
};

#endif
