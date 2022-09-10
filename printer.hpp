#ifndef PRINTER_HPP
#define PRINTER_HPP

#include <vector>

class Printer {
    public:
        void printVector(const std::vector<long long>& v) const { print_vector_(v); };
    private:
        void print_vector_(const std::vector<long long>&) const;
};

#endif
