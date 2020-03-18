#include "eos.h"

void equationOfState(double density, double *pressure, double *soundSpeed ){
    // sound speed is const
    // Move to consts ??
    double cs = 1.0;
    // P=cs^2*rho
    *pressure = cs*cs*density;
    *soundSpeed = cs;
}
