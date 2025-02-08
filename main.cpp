#include <iostream>
#include <string>
#include "laplace_solver.h"
#include "init.h"
#include "iteration.h"
#include "output.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <method> <N>\n";
        std::cerr << "Methods: lapack, iterative\n";
        return EXIT_FAILURE;
    }

    std::string method = argv[1];
    int N = std::stoi(argv[2]);

    if (method == "lapack") {
        // LAPACKE-based solver
        rarray<double, 1> A, b;
        makeAandB(N, A, b);

        rarray<double, 1> V = solvelaplace(N, A, b);

        savetonetCDF(N, V, epsilon);

        std::cout << "LAPACKE solution saved to output.nc" << std::endl;
    } else if (method == "iterative") {
        // Iterative solver
        rarray<double, 2> grid;
        initialize(grid, N);

        double tolerance = 1e-6;
        double maxchange;
        int iterations = 0;

        do {
            maxchange = iterate(grid);
            iterations++;
        } while (maxchange > tolerance);

        outputtofile(grid, "output.txt");

        std::cout << "Iterative solution saved to output.txt after " << iterations << " iterations" << std::endl;
    } else {
        std::cerr << "Unknown method: " << method << "\n";
        return EXIT_FAILURE;
    }

    return 0;
}
