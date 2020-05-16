#ifndef PARTICLEDATA_H
#define PARTICLEDATA_H

struct particledata{
    // Struct that contains particle data
    // for a SPH particle 


    double x[3]; // position
    double v[3]; // velocity
    double a[3]; // acceleration
    double m; // mass
    double h; // smoothing length
    double rho; // density
    double u; // internal energy
    double Pressure; // Pressure on the particle 
    double cs; // Sound speed

};

#endif // PARTICLEDATA_H
