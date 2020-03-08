#include "ghosts.h"
#include "arrays.h"
#include "const.h"

void setGhosts(int particles, struct arrays *particleData){
    for (int i=0; i<particles; i++){
        particleData->x[i+nopart] = particleData->x[i] + particleData->x[nopart];
        particleData->v[i+nopart] = particleData->v[i];
        particleData->h[i+nopart] = particleData->h[i];
        particleData->m[i+nopart] = particleData->m[i];
        particleData->rho[i+nopart] = particleData->rho[i];


    }        
}

