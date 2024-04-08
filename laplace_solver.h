#ifndef LAPLACE_SOLVER_H
#define LAPLACE_SOLVER_H

#include <rarray>

// Defining functions
double epsilon(double x);
void makeAandB(int N, rarray<double, 1>& A, rarray<double, 1>& b);
rarray<double, 1> solvelaplace(int N, rarray<double, 1>& A, rarray<double, 1>& b);
void savetonetCDF(int N, const rarray<double, 1>& V, double (*epsilon)(double));

#endif
