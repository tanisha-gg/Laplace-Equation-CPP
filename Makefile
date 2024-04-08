CXX=g++
CXXFLAGS= -std=c++17
LDFLAGS= -lnetcdf -lnetcdf_c++4 -lopenblas -lgfortran

all: laplace_solver

laplace_solver: laplace_solver.o main.o
	$(CXX) $(CXXFLAGS) laplace_solver.o main.o -o laplace_solver $(LDFLAGS)

main.o: laplace_solver.h main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

laplace_solver.o: laplace_solver.h laplace_solver.cpp
	$(CXX) $(CXXFLAGS) -c laplace_solver.cpp -o laplace_solver.o

clean:
	rm -f *.o laplace_solver output.nc







