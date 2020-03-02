#include "setup.h"
#include "arrays.h"
#include "const.h"
#include <math.h>

int setup(struct arrays *particleData){
    // SETUP PARTICLES
    float xmin = 0.0;
    float xmax = 1.0;
    float cs = 1.0;
    // rho is const
    float rho0 = 1.0;
    float dx = (xmax-xmin)/nopart;
    float drho = (rho0)/nopart;
    float x = xmin;
    int particleSetup = 0;
    for(int i=0; i < nopart;i++){
        // Set Particle Position
        particleData->x[i] = x;
        // Set Mass
        particleData->m[i] = drho;
        // Set Velocity
        particleData->v[i] = cs*1.e-4*sin(x);
        // Set Smoothing Link
        particleData->h[i] = 1.2*dx;
        // Move to next particle 
        x+=dx;
        particleSetup+= 1;
            
    }
    return particleSetup;
}
