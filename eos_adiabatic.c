#include "eos.h"
#include "arrays.h"
#include "math.h"

void equationOfState(double density, double *pressure, double *soundspeed,double u, double gamma){
    double gammaMinus = gamma - 1.0;
    *pressure = (gammaMinus) * density * u;    
    *soundspeed = sqrt(gamma*(*pressure/density));
    if (*pressure != 1.0 || *pressure != 0.1 ){
        //printf("density: %e \n", density);
        //printf("gamma: %e \n",gamma);
        //printf("gamma-1: %e \n", gammaMinus);
        //printf("u: %e \n", u);
        //printf("pressure: %e \n",*pressure);
        //exit(0);
    }
} 

