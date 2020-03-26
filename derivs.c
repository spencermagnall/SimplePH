#include "derivs.h"
#include "const.h"
#include "arrays.h"
#include "density.h"
#include "eos.h"
#include "force.h"
#include "ghosts.h"
#include "smoothing.h"
    
void derivs(int particles, struct arrays *particleData){
    double rho;
    double cs;
    double pressure;
   
    for (int i=particles+1; i<noghost; i++){
        particleData->exists[i] = false;

    }
    // Set ghost particles
    setGhosts(particles,particleData);
    // Call density
    getDensity(particles, particleData);
    // Copy rho from real particles to ghosts 
    for (int i=0; i<particles; i++){
        particleData->rho[i+nopart] = particleData->rho[i];
        particleData->rho[i+nopart+nopart] = particleData->rho[i];
    }
    // iterate smoothing after density call 
    runSmoothing(particles,particleData);

    // Call equation of state
    // This is a bit ugly but meets the requirements
    for (int i=0; i<nopart; i++){
        if (particleData->exists[i]){
        //printf("i=: %d \n",i);
            rho = particleData->rho[i];
            double u = particleData->u[i];
            double gin = 1.4;
            // cs isn't used currently
            equationOfState(rho, &pressure, &cs,u,gin);
            particleData->P[i] = pressure;
            particleData->cs[i] = cs;
        
        }
    }
    setGhosts(particles,particleData);
    //exit(0);
    // Call accel
    getAccel(particles,particleData);


}
