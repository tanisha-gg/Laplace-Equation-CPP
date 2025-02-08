# Laplace Solver

This project solves the Laplace equation using either a LAPACKE-based direct method or an iterative approach in C++.

## Requirements

- C++ compiler with C++11 support
- LAPACKE
- NetCDF library

## Building

To build the project, run:

```bash
make
```
To run the solver,

```./laplace_solver <method> <N>```

Where:
method: Choose between lapack and iterative. 
N: Number of grid points.
