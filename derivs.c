#include "derivs.h"
#include "const.h"
#include "arrays.h"
#include "density.h"
#include "eos.h"
#include "force.h"
#include "ghosts.h"
#include "smoothing.h"
#include "output.h" 
void derivs(int particles, struct arrays *particleData){
    double rho;
    double cs;
    double pressure;
    int ghosts;
   
    // Set ghost particles
    ghosts = setGhosts(particles,particleData);
    // Call density
    //exit(0);
    getDensity(particles, ghosts, particleData);
    //printf("Particles: %d \n",particles);
    //printf("Ghosts: %d \n",ghosts);
    //exit(0);
    //writeOutput(particles,particleData,-1,0.0);
    //exit(0);
    // Copy rho from real particles to ghosts
    // This should be cheap O(N) 
    ghosts = setGhosts(particles, particleData);
    
    // iterate smoothing after density call 
    if (adapSmooth == 1){ 
        runSmoothing(particles,ghosts,particleData);
        ghosts = setGhosts(particles,particleData);
        
    }
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
    
    ghosts = setGhosts(particles,particleData);
    
    //exit(0);
    // Call accel
    getAccel(particles,ghosts,particleData);


}
