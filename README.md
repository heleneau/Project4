# Project4
This project is solved with programs in both C++ and Python. C++ was used to solve the exercises, while python was used to read data from output files, before plotting the results. The programs runs as follows:

## main.cpp
Takes three input arguments from command line:
- 1: The number of spins/size of the lattice, ie "2" gives a 2x2 lattice.
- 2: The number of Monte Carlo cycles.
- 3: The temperature, either 1.0 or 2.4

In `main.cpp` you need to manually change what spin orientation you want, by adding or commenting out the two functions that creates matrixes. Also, you need to manually change what files to write to.

## Python files
All python files reads data from four different text files, change the flags from True/False to run for the different files.
- `plot_accepted_config.py`
- `plot_accepted_vs_temperature.py`
- `plot_equilibrium_20.py`:

## Parallelized files
Enclosed in a directory, read the README-file that exists in this directory for further information about running the programs.
