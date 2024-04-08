#include "init.h"
#include "iteration.h"
#include "output.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	// Check if the correct number of arguments is provided
	if (argc != 3) {
		std::cerr << "Please try again. To run, you need: " << argv[0] << " <N> <threshold>" << std::endl;
		return 1;
	}

	// Parse command-line arguments for N and threshold
	int N = std::stoi(argv[1]);
	double threshold = std::stod(argv[2]);
	
	// Creating a grid
	rarray<double, 2> grid;

	// Initialize the grid with boundary conditions
	initialize(grid, N);

	// Iterating until convergence, continuing while the maximum change is greater than the threshold. 
	double maxchange;
	do {
		maxchange = iterate(grid);
	} while (maxchange > threshold);

	// Writing the grid to a file
	std::string filename = "output_grid.txt";
	outputtofile(grid, filename);
	std::cout << "Output written to " << filename << std::endl;
	
	return 0;
}
