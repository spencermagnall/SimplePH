#include "smoothing.h"
#include "arrays.h"
#include "density.h"
#include "ghosts.h"
void getSmoothing(struct arrays *particleData,int ghosts){
    double hnew;
    double h;
    double hfac = 1.2;
    double partMass;
    double partRho;

    for (int i=0; i<nopart+ghosts; i++){
        partMass = particleData->m[i];
        partRho = particleData->rho[i];
        h = particleData->h[i];
        hnew = hfac*(partMass/partRho);
        particleData->h[i] = hnew;

    }
}

void runSmoothing(int particles,int ghosts, struct arrays *particleData){
    getSmoothing(particleData,ghosts);
    getDensity(particles,ghosts,particleData); 
    ghosts = setGhosts(particles,particleData);
    getSmoothing(particleData,ghosts);
    getDensity(particles,ghosts,particleData);
    ghosts = setGhosts(particles,particleData);
    getSmoothing(particleData,ghosts);
}
