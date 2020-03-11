#include "step.h"
#include "derivs.h"
#include "arrays.h"
#include "const.h"

void step(int particles, struct arrays *particleData){
    float x;
    float vstar;
    float v1;
    float partx;
    float partv;
    float parta;

    for (int i=0; i<particles; i++){
        partx = particleData->x[i];
        partv = particleData->v[i];
        parta = particleData->a[i];
        x = partx + dt*partv + 0.5*dt*dt*parta;
        vstar = partv + dt*parta;
        derivs(particles,particleData);
    }
}

