/*
 argv[1] : number of spins in each direction
 argv[2] : number of Monte Carlo cycles
 argv[3] : initial temperature
*/

#include <iostream>
#include <cmath>
#include <armadillo>
#include <stdlib.h>     /* srand, rand */
#include <fstream>
#include "functions.h"

#include <chrono>

using namespace std;
using namespace arma;

int main(int argc, char* argv[]){
    if (argc <= 3){
        cout << "ERROR: Bad usage! Please see the README.mp file for command line arguments.";
        exit(1);
    }

    // create files
    ofstream outputfile, plotfile, acceptfile;

    // start time
    chrono::high_resolution_clock::time_point start_time = chrono::high_resolution_clock::now();

    // read input argument to decide size of matrix
    int n = atoi( argv[1] );
    int s = n*n;
    int mc_cycles = atoi( argv[2] );
    double T_init = atof( argv[3] );

    double k_B = 1.0;
    double beta = 1.0 / ( k_B * T_init );
    double J = 1.0;

    mat L = zeros<mat>(n, n);

    // make each random number in loop be random for each program run
    srand (time(NULL));

    // create a random matrix with elements of 1 and -1
    CreateRandomMatrix(n, L);

    // create a matix with elements of 1 only
    //CreateMatrix(s, L);

    // values to add to
    double E = CalculateEnergy(n, J, L);
    double M = CalculateMagneticMoment(L);

    cout << "Initial E: " << E << endl;
    cout << "Initial M: " << M << endl;

    double energy_sum = E;
    double mag_sum = M;
    double energy_sqr = E * E;
    double mag_sqr = M * M;

    double w[17];
    for (int dE = -8; dE <= 8; dE++){
        // set each element in w to be 0
        w[dE + 8] = 0;
        //cout << w[dE + 8] << endl;
    }
    for (int dE = -8; dE <= 8; dE+=4){
        // calculate w for each 4th element
        w[dE+8] = exp(- beta * dE);
        //cout << w[dE+8] << endl;
    }

    // open files
    //outputfile.open("../Python_files/ordered_spin_10.txt");
    //outputfile.open("../Python_files/random_spin_10.txt");
    //outputfile.open("../Python_files/ordered_spin_24.txt");
    //outputfile.open("../Python_files/random_spin_24.txt");

    //acceptfile.open("../Python_files/accept_ordered_10.txt");
    //acceptfile.open("../Python_files/accept_random_10.txt");
    //acceptfile.open("../Python_files/accept_ordered_24.txt");
    //acceptfile.open("../Python_files/accept_random_24.txt");

    int accepted_config;

    for (int k = 1; k <= mc_cycles; k ++){
        // metropolis algorithm
        Metropolis(n, E, M, w, L, accepted_config);

        energy_sum += E;
        mag_sum += fabs(M);
        energy_sqr += E * E;
        mag_sqr += M * M;

        //outputfile << k << "  " << E << "  " << "  " << M << endl;
        //acceptfile << k << "  " << accepted_config << endl;
    }
    acceptfile.close();

    // mean energy
    double mean_energy = energy_sum / ((double) (mc_cycles+1));

    // mean absolute magnetic moment
    double mean_mag = mag_sum / ((double) (mc_cycles+1));

    // specific heat
    double mean_energy2 = energy_sqr / ((double) (mc_cycles+1));
    double spec_heat = ( mean_energy2 - mean_energy * mean_energy ) * beta / T_init;

    // magnetic susceptibility
    double mean_mag2 = mag_sqr / ((double) (mc_cycles+1));
    double mag_susc = ( mean_mag2 - mean_mag * mean_mag ) * beta;

    // end time
    chrono::high_resolution_clock::time_point end_time = chrono::high_resolution_clock::now();
    chrono::milliseconds program_duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    // write values to file for the 2x2 lattice
    if ( atoi(argv[1] ) == 2 ){
        outputfile.open("../Python_files/2x2_output.txt");
        outputfile << "The mean energy: " << mean_energy << endl
                   << "The mean magnetization: " << mean_mag << endl
                   << "The specific heat: " << spec_heat << endl
                   << "The susceptibility: " << mag_susc << endl;
        outputfile.close();
    }
    // write values to file for the 20x20 lattice
    else if ( atoi(argv[1] ) == 20){
        outputfile.open("../Python_files/20x20_output.txt");
        outputfile << "The mean energy: " << mean_energy << endl
                   << "The mean magnetization: " << mean_mag << endl
                   << "The specific heat: " << spec_heat << endl
                   << "The susceptibility: " << mag_susc << endl;
        outputfile.close();
    }

    cout << "End" << endl;
    cout << "Used " << program_duration.count() << " ms" << endl;

    return 0;
}
