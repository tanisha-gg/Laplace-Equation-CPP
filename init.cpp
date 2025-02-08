#include "init.h"

void initialize(rarray<double,2>& grid, int N) {
	// Making a square grid
	grid = rarray<double, 2>(N, N);

	// Initialize grid to zeros
	grid.fill(0.0);

// Defining boundary conditions
	double outerSquareLeft = -1.0;
	double outerSquareRight = 1.0;
	double outerSquareBottom = -1.0;
	double outerSquareTop = 1.0;

	double innerSquareLeft = -0.1;
	double innerSquareRight = 0.1;
	double innerSquareBottom = -0.1;
	double innerSquareTop = 0.1;

// Applying boundary conditions. Let's first loop over each grid point along the x direction. 
for (int i = 0; i < N; ++i) {
	// Finding the x coordinate of the ith grid point along the x direction (dividing outer square into N-1 segments)
	double x = outerSquareLeft + (outerSquareRight - outerSquareLeft) * i / (N - 1);

	// Then, loop over each grid point along the y direction
	for (int j = 0; j < N; ++j) {
		// Finding the y coordinate of the ith grid point along the y direction (dividing outer square into N-1 segments).
		double y = outerSquareBottom + (outerSquareTop - outerSquareBottom) * j / (N - 1);

		// Checking if the current grid point lies in the boundaries of the inner square.
		if (x >= innerSquareLeft && x <= innerSquareRight && y >= innerSquareBottom && y <= innerSquareTop) {
			grid[i][j] = 1.0; // Inner square boundary condition

		} else if (x < outerSquareLeft || x > outerSquareRight || y < outerSquareBottom || y > outerSquareTop) {
                grid[i][j] = 0.0; // Outer square boundary condition
            }
        }
    }
}
