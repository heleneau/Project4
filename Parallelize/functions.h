#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

void CreateRandomMatrix(int n, mat &L) ;
void CreateMatrix(int s, mat &L) ;
double CalculateEnergy(int n, double J, mat &L) ;
double CalculateMagneticMoment(mat &L) ;
double CalculatePartitionFunction(double beta, double E) ;
void Metropolis(unsigned int &seed, int n, double &E, double &M, double *w, mat &L, int &accepted_config) ;

#endif // FUNCTIONS_H
