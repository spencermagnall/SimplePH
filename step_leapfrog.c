#include "step.h"
#include "derivs.h"
#include "arrays.h"
#include "const.h"
#include <stdio.h>
#include <math.h>
void xOne(int particles, struct arrays *particleData){
     float partx;
     float partv;
     float parta;
     float x1;
     // for all particles 
     for (int i=0; i<particles; i++){
         partx = particleData->x[i];
         partv = particleData->v[i];
         parta = particleData->a[i];
         x1 = partx + dt*partv + 0.5*(dt*dt)*parta;
         // handle periodic boundary
         float deltaf = fabs(x1-xmax);
         if (x1 > xmax){
             printf("Moved Max! \n");
             printf("x1: %e \n",x1);
             printf("xmax: %e \n", xmax);
             float deltax = x1-xmax;
             printf("deltax: %e  \n",deltax);
             x1 = xmin + deltax;
         } else if (x1 < xmin){
             printf("Moved Min! \n");
             float deltax = fabs(x1-xmin);
             x1 = xmax - deltax;
         }
         particleData->x[i] = x1;

     }
    
}

void vStar(int particles, struct arrays *particleData){
    float partv;
    float vstar;
    float parta;

    for (int i=0; i<particles; i++){
        partv = particleData->v[i];
        parta = particleData->a[i];
        vstar = partv + dt*parta;
        particleData->v[i] = vstar;
    }

}
// copying array is a little sloppy 
void vOne(int particles, struct arrays *particleData, float oldA[]){
    float vstar;
    float v1;
    float parta;

    for (int i=0; i<particles; i++){
        vstar = particleData->v[i];
        parta = particleData->a[i];
        v1 = vstar + 0.5*dt*(parta-oldA[i]);
        particleData->v[i] = v1;
    }
}

void step(int particles, struct arrays *particleData){
    
    xOne(particles,particleData);
    vStar(particles,particleData);
    
    // store old a
    float a0[particles];
    for (int i=0; i<particles; i++){
        a0[i] = particleData->a[i];
    }
    
    derivs(particles,particleData);
    vOne(particles, particleData, a0);

}


