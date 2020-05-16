#include "ghosts.h"
#include "arrays.h"
#include "const.h"
#include <stdio.h>
#include <stdlib.h>

//  OLD NAIVE GHOSTS ROUTINE

void setGhosts(int particles, struct arrays *particleData){
    double range = xmax - xmin;
    for (int i=0; i<particles; i++){
        // Don't set additional ghost particles on boundary 
        //if (particleData->x[i] != xmin && particleData->x[i] != xmax){
            particleData->x[i+nopart] = particleData->x[i] + range; 
            particleData->v[i+nopart] = particleData->v[i];
            particleData->h[i+nopart] = particleData->h[i];
            particleData->m[i+nopart] = particleData->m[i];
            particleData->a[i+nopart] = particleData->a[i];
            particleData->rho[i+nopart] = particleData->rho[i];
            particleData->P[i+nopart] = particleData->P[i];
            particleData->u[i+nopart] = particleData->u[i];
            particleData->exists[i+nopart] = true;
            //printf("index is: %d \n", i+nopart); 
       // }
    }

    for (int i=0; i<particles; i++){
        //if (particleData->x[i] != xmin && particleData->x[i] != xmax){
        particleData->x[i+2*nopart] =  particleData->x[i]-range;
        //printf("x is: %f \n", particleData->x[i]-1.0);
        particleData->v[i+2*nopart] = particleData->v[i];
        particleData->h[i+2*nopart] = particleData->h[i];
        particleData->m[i+2*nopart] = particleData->m[i];
        particleData->a[i+2*nopart] = particleData->a[i];
        particleData->rho[i+2*nopart] = particleData->rho[i];
        particleData->P[i+2*nopart] = particleData->P[i];
        particleData->u[i+2*nopart] = particleData->u[i];
        particleData->exists[i+2*nopart] = true;
        //printf("index is: %d \n" ,i+2*nopart);
        //}
    }

     //exit(1);
}

