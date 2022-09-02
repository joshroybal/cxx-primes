#include <string>
#include <cstdlib>
#include <limits>
#include "random.hpp"

// function returns pseudo-random 0 <= rnd < n
unsigned random(unsigned n)
{
	return n*(rand()/double(RAND_MAX));
}

// function returns random no. with no_digits digits
unsigned random_digits(unsigned n)
{
	char *string = new char[n+1];
	// first digit is in range 1 to 9
	char c = 49+9*rand()/float(RAND_MAX);
	string[0] = c;
	// remaining digits are in range 0 to 9
	for (int i = 1; i < n; i++) {
		c = 48+10*rand()/float(RAND_MAX);
		string[i] = c;
	}
	// cap string with null
	string[n] = '\0';
	return std::stoi(string);
}
