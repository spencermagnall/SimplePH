#include "eos.h"
#include "arrays.h"
#include "math.h"

void equationOfState(double density, double *pressure, double *soundspeed,double u, double gamma){
    double gammaMinus = gamma - 1.0;
    *pressure = gammaMinus * density * u;    
    *soundspeed = sqrt(gamma*(*pressure/density));
    //printf("SoundSpeed %e \n",*soundspeed);
} 

