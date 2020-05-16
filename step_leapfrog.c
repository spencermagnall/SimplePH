#include "step.h"
#include "derivs.h"
#include "arrays.h"
#include "ghosts.h"
#include "const.h"
#include <stdio.h>
#include <math.h>
void xOne(int particles, struct arrays *particleData,double dt){
     double partx;
     double partv;
     double parta;
     double x1;
     // for all particles 
     for (int i=0; i<particles; i++){
         partx = particleData->x[i];
         partv = particleData->v[i];
         parta = particleData->a[i];
         x1 = partx + dt*partv + 0.5*(dt*dt)*parta;
         // handle periodic boundary
         if (x1 > xmax){
             double deltax = x1-xmax;
             x1 = xmin + deltax;
         } else if (x1 < xmin){
             double deltax = fabs(x1-xmin);
             x1 = xmax - deltax;
         }
         particleData->x[i] = x1;

     }
    
}

void vStar(int particles, struct arrays *particleData,double dt){
    double partv;
    double vstar;
    double parta;

    for (int i=0; i<particles+noghost; i++){
        partv = particleData->v[i];
        parta = particleData->a[i];
        vstar = partv + dt*parta;
        particleData->v[i] = vstar;
    }

}
// copying array is a little sloppy 
void vOne(int particles, struct arrays *particleData, double oldA[], double dt){
    double vstar;
    double v1;
    double parta;

    for (int i=0; i<particles; i++){
        vstar = particleData->v[i];
        parta = particleData->a[i];
        v1 = vstar + 0.5*dt*(parta-oldA[i]);
        particleData->v[i] = v1;
    }
}
void u(int particles, struct arrays *particleData,double dt){
    double u;
    double du;
    for (int i=0; i<particles; i++){
        u = particleData->u[i];
        du = particleData->du[i];
        u = u + du*dt;
        particleData->u[i] = u;
    }

}
void u1(int particles, struct arrays *particleData, double oldDU[],double dt){
    double u;
    double du;

    for (int i=0; i<particles; i++){
        u = particleData->u[i];
        du = particleData->du[i];

        u = u + 0.5*dt*(du-oldDU[i]);
        particleData->u[i] = u;
    }
}
double step(int particles, struct arrays *particleData,double dt){
    double dtnew;
    xOne(particles,particleData,dt);
    // set x pos of ghosts again
    setGhosts(particles,particleData);
    vStar(particles,particleData,dt);
    
    u(particles,particleData,dt);
    // store old a
    double a0[particles+noghost];
    double du0[particles+noghost];
    for (int i=0; i<particles; i++){
        a0[i] = particleData->a[i];
        du0[i] = particleData->du[i];
    }
         
    dtnew = derivs(particles,particleData);
    u1(particles,particleData,du0,dt);
    vOne(particles, particleData, a0,dt);
    return dtnew;

}


