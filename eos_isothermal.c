#include "eos.h"

void equationOfState(float density, float *pressure, float *soundSpeed ){
    // sound speed is const
    // Move to consts ??
    float cs = 1.0;
    // P=cs^2*rho
    *pressure = cs*cs*density;
    *soundSpeed = cs;
}
