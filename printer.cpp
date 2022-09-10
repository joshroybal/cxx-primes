#include <iostream>
#include <vector>
#include "printer.hpp"

// Printer class private methods.
void Printer::print_vector_(const std::vector<long long>& z) const
{
    std::vector<long long>::const_iterator cit;
    for (cit = z.begin(); cit != z.end(); ++cit)
        std::cout << ' ' << *cit;
    std::cout << std::endl;
}
