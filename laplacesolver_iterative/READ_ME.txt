Assignment 5 - Tanisha Ghosal

This folder contains modules that solve the Laplace equation for the field V in a domain defined by an outer square and an inner square (each with different boundary conditions). The first module is init.cpp (which initializes the grid in an rarray object, applies boundary conditions for the inner and outer square by defining the boundaries and their respective potentials), it has the header file init.h. 
The second module is iteration.cpp, which writes out the iteration over the grid to solve the Laplace equation by updating the potential value based on neighbouring points, and checking for convergence based on the maximum change in potential values. It has the header file iteration.h
The third module is output.cpp, which writes out the potential values for the grid at each iteration into a text file. It has the header file output.h

To make the program, please load the modules first. 
module load gcc
module load rarray

Then, type the following to compile the solver. 

make

To run the test case of N=500 and threshold=10^-6,

make run

Running this should output the txt file with the grid values. You can enter custom values with ./laplace_solver N threshold, replacing N and threshold as required.

To remove object files and try these new values, you first need to:

make clean
