
Build
-----

From the directory containing the file `CMakeLists.txt`

 * With OpenMP support:

        ```
        mkdir build_omp
        cd build_omp
        cmake ..
        # OR: cmake -DUSE_OPENMP=yes ..
        make
        ```

 * Without OpenMP support:

        ```
        mkdir build_serial
        cd build_omp
        cmake -DUSE_OPENMP=no ..
        make
        ```

The executable `Ising-Model` is then found in the build directory.
