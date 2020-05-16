#include "eos.h"

void equationOfState(double density, double *pressure, double *soundSpeed,double u, double gamma ){
    // sound speed is const
    double cs = 1.0;
    // P=cs^2*rho
    *pressure = cs*cs*density;
    *soundSpeed = cs;
}
