
First, please make sure you are in the A6 directory. Then, load the following modules:
module load gcc
module load rarray
module load hdf5
module load netcdf

OpenBLAS has already been installed on the teach cluster and should be found from the files. Netcdf should be found once hdf5 has been loaded. 

Then, in the directory A6, to make the executable for the solver,  please type:
make

The executable should be compiled. To run, please type:
./laplace_solver

This will run the solver for the default N=10000, and write the output to the netcdf file output.nc
If you want to run with a different N, please type:
./laplace_solver N

To view output.nc, please type:
ncdump output.nc 

To remove output.nc and re-compile, type:
make clean; make
