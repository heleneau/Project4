#include <iostream>
#include <cmath>
#include <armadillo>
#include <stdlib.h>     /* srand, rand */
#include "functions.h"

using namespace std;
using namespace arma;

// n = matrix size,
void CreateRandomMatrix(int n, mat &L){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int r = rand() % n;

            if (r == 1){
                L(i, j) = 1.0;
            }
            else {
                L(i, j) = -1.0;
            }
        }
    }
    return;
}

// s = number of rows/columns
void CreateMatrix(int s, mat &L){
    for (int i = 0; i < s; i++){
        L(i) = 1.0;
    }
}

// function to calculate periodic boundary conditions and energy
double CalculateEnergy(int n, double J, mat &L){
    double E = 0;

#   pragma omp parallel for reduction(+:E) shared(J,L,n)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int ip = (i + 1) % n;
            int jp = (j + 1) % n;
            E += -J*L(i,j)*( L(ip,j) + L(i,jp));
        }
    }
    return E;
}

// function to calculate magnetic moment
double CalculateMagneticMoment(mat &L){
    // magnetization
    double mag = accu(L);
    return mag;
}

// function to calculate partition function
double CalculatePartitionFunction(double beta, double E){
    // partition function
    double part_func = exp( - beta * E );
    return part_func;
}

// n = matrix row/column
void Metropolis(int n, double &E, double &M, double *w, mat &L, int &accepted_config){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int ix = rand() % n;
            int iy = rand() % n;

            // periodic boundary conditions
            int ip = (ix + 1) % n;
            int in = (ix - 1 + n) % n;
            int jp = (iy + 1) % n;
            int jn = (iy - 1 + n) % n;

            // calculate delta E
            int delta_E = 2.0 * L(ix, iy) * ( L(ip, iy) + L(in, iy) + L(ix, jp) + L(ix, jn) );

            double r = rand() / ((double) std::numeric_limits<int>::max());
            if (r <= w[delta_E+8]){
                L(ix, iy) *= -1.0;
                E += (double) delta_E;
                M += (double) 2.0 * L(ix, iy);
                accepted_config += 1;
            }
        }
    }
    return;
}
