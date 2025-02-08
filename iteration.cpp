#include "iteration.h"
#include <cmath>

double iterate(rarray<double,2>& grid) {
	// Getting the dimensions of the grid
	int N = grid.extent(0);
	// Initializing the variable that will store the maximum change in the old and new value
	double maxchange = 0.0;
    
	// Looping over x,y directions of grid, and defining the old value at each point.
	for (int i = 1; i < N - 1; ++i) {
		for (int j = 1; j < N - 1; ++j) {
			double oldvalue = grid[i][j];

			// Computing the average of direct neighbors in all directions to find the new value.
			double newvalue = 0.25 * (grid[i][j + 1] + grid[i][j - 1] + grid[i + 1][j] + grid[i - 1][j]);
		
			// Updating the grid element
			grid[i][j] = newvalue;
				
			// Calculating the change between the old and new values.
			double change = std::fabs(newvalue - oldvalue);
				
			// Updating the maximum change if the calculated change is greater than the maximum change in the previous iteration. 
			if (change > maxchange) {
				maxchange = change;
			}
		}	
	}

	return maxchange;
	}			

