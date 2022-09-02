CXX = cl.exe
CFLAGS = /EHsc /O2
LFLAGS =

primes.exe: main.obj primes.obj random.obj
	$(CXX) /Fe$@ main.obj primes.obj random.obj $(LFLAGS)

primes.obj: primes.cpp primes.hpp
	$(CXX) /c primes.cpp $(CFLAGS)

random.obj: random.cpp random.hpp
	$(CXX) /c random.cpp $(CFLAGS)

main.obj: main.cpp primes.hpp random.hpp
	$(CXX) /c main.cpp $(CFLAGS)

.PHONY : clean
clean:
	del *.exe *.obj
