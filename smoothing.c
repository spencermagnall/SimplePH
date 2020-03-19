#include "smoothing.h"
#include "arrays.h"

void getSmoothing(struct arrays *particleData){
    double hnew;
    double h;
    double hfac = 1.2;
    double partMass;
    double partRho;

    for (int i=0; i<nopart+noghost; i++){
        partMass = particleData->m[i];
        partRho = particleData->rho[i];
        h = particleData->h[i];
        hnew = hfac*(partMass/partRho);
        particleData->h[i] = hnew;

    }
}

void runSmoothing(struct arrays *particleData){
    getSmoothing(particleData);
    getSmoothing(particleData);
    getSmoothing(particleData);
}
