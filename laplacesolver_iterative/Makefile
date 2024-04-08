CXX = g++
CXXFLAGS = -std=c++17 -O2
LDLIBS = -lm

all: laplace_solver

laplace_solver: main.o init.o iteration.o output.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

main.o: main.cpp init.h iteration.h output.h
	$(CXX) $(CXXFLAGS) -c $<

init.o: init.cpp init.h
	$(CXX) $(CXXFLAGS) -c $<

iteration.o: iteration.cpp iteration.h
	$(CXX) $(CXXFLAGS) -c $<

output.o: output.cpp output.h
	$(CXX) $(CXXFLAGS) -c $<

run: laplace_solver
	./laplace_solver 500 1e-6

clean:
	rm -f laplace_solver *.o

