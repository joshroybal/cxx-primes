CXX = c++
CFLAGS = -std=c++11 -pedantic-errors -Werror -O2
LFLAGS = -static -s

primes: main.o primes.o random.o
	$(CXX) -o $@ $^ $(LFLAGS)

main.o: main.cpp primes.hpp random.hpp
	$(CXX) -c $< $(CFLAGS) 

primes.o: primes.cpp primes.hpp
	$(CXX) -c $< $(CFLAGS)

random.o: random.cpp random.hpp
	$(CXX) -c $< $(CFLAGS)

.PHONY : clean
clean:
	$(RM) primes *.o *~
