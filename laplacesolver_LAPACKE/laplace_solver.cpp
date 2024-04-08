#include <cmath>
#include <iostream>
#include <lapacke.h> // LAPACKE header file
#include <netcdf>
#include <rarray> 
#include "laplace_solver.h"

using namespace netCDF;

// Epsilon function
double epsilon(double x) {
	return 1 + 10 * std::cos(2 * M_PI * x) * std::cos(2 * M_PI * x);
}

// Making the matrix A and the vector b
void makeAandB(int N, rarray<double, 1>& A, rarray<double, 1>& b) {
	double dx = 1.0 / N;
	double dx2 = dx * dx;

	// Initializing arrays
	A = rarray<double, 1>(N - 1);
	b = rarray<double, 1>(N - 1);

	// Applying discretization
	for (int i = 0; i < N - 1; ++i) {
		double xi = (i + 1) * dx;
		double epsilon_left = epsilon(xi - 0.5 * dx);
		double epsilon_right = epsilon(xi + 0.5 * dx);
		
		if (i == 0) {
			A[i] = epsilon_left + epsilon_right - 2 * epsilon(xi);
			b[i] = epsilon_right / dx2;
    		} else if (i == N - 2) {
			A[i] = epsilon_left - epsilon(xi);
			b[i] = (1 - epsilon_left) / dx2;
		} else {
			A[i] = epsilon_left + epsilon_right - 2 * epsilon(xi);
			b[i] = epsilon_right / dx2;

		}		

	}
}

// Solving Laplace Equation
rarray<double, 1> solvelaplace(int N, rarray<double, 1>& A, rarray<double, 1>& b) {
	rarray<double, 1> V(N - 1);
	rarray<int,1> ipiv(N - 1); // Pivot indices
	
	// Using dptsv (for tridiagonal matrix)
	int info = LAPACKE_dptsv(LAPACK_COL_MAJOR, N - 1, 1, &A[0], &b[0], &V[0], N - 1);

	// Apply boundary conditions to solution V and returning it.
	V[0] = 0.0;
	V[N - 2] = 1.0;
	
	return V;
}	

// Saving epsilon and V to netCDF file
void savetonetCDF(int N, const rarray<double, 1>& V, double (*epsilon_func)(double)) {

	// Create output file
	netCDF::NcFile dataFile("output.nc", netCDF::NcFile::replace);

	// Define dimensions
	auto xDim = dataFile.addDim("x", N);
   
	// Define variables
	auto varV = dataFile.addVar("V", netCDF::ncDouble, xDim);
	auto varEpsilon = dataFile.addVar("epsilon", netCDF::ncDouble, xDim);
	
	// Generate epsilon values
	rarray<double, 1> eps(N);
	for (int i = 0; i < N; ++i) {
		double x = (i + 0.5) / N;
		eps[i] = epsilon_func(x);
	}

	// Write data to the variables
	varV.putVar(std::vector<size_t>{0}, std::vector<size_t>{N}, &V[0]);
	varEpsilon.putVar(std::vector<size_t>{0}, std::vector<size_t>{N}, &eps[0]);
}


