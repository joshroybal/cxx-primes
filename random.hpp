#ifndef RANDOM_HPP
#define RANDOM_HPP

class Random {
    public:
        unsigned long long randomNumber();
        unsigned long long randomNumber(unsigned long long);
        unsigned long long randomNumber(unsigned long long,
                                        unsigned long long);
    private:
        unsigned long long seed_ = 0;
        void randomize_();
        unsigned long long random_number_();
        unsigned long long random_number_(unsigned long long);
        unsigned long long random_number_(unsigned long long,
                                          unsigned long long);
};

#endif
