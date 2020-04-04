#include "ghosts.h"
#include "arrays.h"
#include "const.h"
#include <stdio.h>
#include <stdlib.h>

void setData(int i,int particles, int ghosts, struct arrays *particleData){
                particleData->v[particles+ghosts-1] = particleData->v[i];
                particleData->h[particles+ghosts-1] = particleData->h[i];
                particleData->m[particles+ghosts-1] = particleData->m[i];
                particleData->a[particles+ghosts-1] = particleData->a[i];
                particleData->rho[particles+ghosts-1] = particleData->rho[i];
                particleData->P[particles+ghosts-1] = particleData->P[i];
                particleData->u[particles+ghosts-1] = particleData->u[i];
                particleData->exists[particles+ghosts-1] = true;
}

int setGhosts(int particles, struct arrays *particleData){
    int ghosts = 0;
    double range = xmax - xmin;
    for (int i=0; i<particles; i++){
        //printf("Ghosts: %d \n",ghosts);    
        if (particleData->x[i] + 2.0*particleData->h[i] > xmax){
                ghosts+=1;
                particleData->x[particles+ghosts-1] = particleData->x[i] - range;
                setData(i,particles,ghosts,particleData);
            
            } else if (particleData->x[i] - 2.0*particleData->h[i] < xmin){
                ghosts+=1;
                particleData->x[particles+ghosts-1] =  particleData->x[i]+range;
                setData(i,particles,ghosts,particleData);
                
            }
            
    }

    return ghosts;

}

