#include "output.h"
#include <fstream>

void outputtofile(const rarray<double, 2>& grid, const std::string& filename) {
    std::ofstream file(filename);
    int N = grid.extent(0);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file << grid[i][j] << " ";
        }
        file << "\n";
    }

    file.close();
}
