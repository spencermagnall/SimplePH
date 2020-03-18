#include "derivs.h"
#include "const.h"
#include "arrays.h"
#include "density.h"
#include "eos.h"
#include "force.h"
#include "ghosts.h"
    
void derivs(int particles, struct arrays *particleData){
    double rho;
    double cs;
    double pressure;
    
    // Set ghost particles
    setGhosts(particles,particleData);
    // Call density
    getDensity(particles, particleData);
    // Copy rho from real particles to ghosts 
    for (int i=0; i<particles; i++){
        particleData->rho[i+nopart] = particleData->rho[i];
        particleData->rho[i+nopart+nopart] = particleData->rho[i];
    }
    // Call equation of state
    // This is a bit ugly but meets the requirements
    for (int i=0; i<nopart+noghost; i++){
        rho = particleData->rho[i];
        // cs isn't used currently
        equationOfState(rho, &pressure, &cs);
        particleData->P[i] = pressure;
    }
    // Call accel
    getAccel(particles,particleData);


}
