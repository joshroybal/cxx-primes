CXX = cl.exe
CFLAGS = /std:c11 /EHsc /O2
LFLAGS =
EXE = primes.exe
OBJ = main.obj primes.obj random.obj printer.obj

primes.exe: $(OBJ)
	$(CXX) /Fe$@ $(OBJ) $(LFLAGS)

primes.obj: primes.cpp
	$(CXX) /c primes.cpp $(CFLAGS)

random.obj: random.cpp
	$(CXX) /c random.cpp $(CFLAGS)

printer.obj: printer.cpp
	$(CXX) /c printer.cpp $(CFLAGS)

main.obj: main.cpp primes.hpp random.hpp printer.hpp
	$(CXX) /c main.cpp $(CFLAGS)

.PHONY : clean
clean:
	del $(EXE) $(OBJ)
