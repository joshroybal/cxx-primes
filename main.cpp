#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include "primes.hpp"
#include "random.hpp"
#include "printer.hpp"

void process(long long, long long);

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " n" << std::endl;
        return 1;
    }
    std::istringstream iss(argv[1]);
    int n;
    iss >> n;

    long long m1 = pow(2, 17) - 1;
    long long m2 = pow(2, 31) - 1;
    long long m3 = long long(pow(2, 61)) - 1;

    std::cout << "Factorizing " << n << " 17-bit integers." << std::endl;
    process(m1, n);

    std::cout << "Factorizing " << n << " 31-bit integers." << std::endl;
    process(m2, n);

    std::cout << "Factorizing " << n << " 61-bit integers." << std::endl;
    process(m3, n);

    return 0;
}

void process(long long m, long long n)
{
    Random randomObject(time(0));
    Primes primesObject;
    Printer printerObject;

    std::vector<long long> z = randomObject.randomVector(m, n);
    std::vector<long long>::const_iterator cit;
    for (cit = z.begin(); cit != z.end(); ++cit) {
        std::cout << *cit << ':';
        printerObject.printVector(primesObject.Factorize(*cit));
    }
}
