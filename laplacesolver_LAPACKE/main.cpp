#include <iostream>
#include <rarray>
#include <cmath>
#include "laplace_solver.h"

int main(int argc, char *argv[]) {
	int N = 10000; // Default value

	// Check if command-line argument is provided
	if (argc > 1) {
		N = std::atoi(argv[1]); // Convert the argument to integer
	}

	// Constructing the tridiagonal matrix A and vector b
	rarray<double, 1> A, b;
	makeAandB(N, A, b);

	// Solve the system
	rarray<double, 1> V = solvelaplace(N, A, b);

	// Output to netCDF file
	savetonetCDF(N, V, epsilon);

	std::cout << "Epsilon and the solution for V have been saved to output.nc" << std::endl;

	return 0;
}
