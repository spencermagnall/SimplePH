#include "ghosts.h"
#include "arrays.h"
#include "const.h"
#include <stdio.h>
#include <stdlib.h>

void setData(int i,int particles, int ghosts, struct arrays *particleData){
                particleData->v[particles+ghosts-1] = particleData->v[i];
                particleData->h[particles+ghosts-1] = particleData->h[i];
                particleData->m[particles+ghosts-1] = particleData->m[i];
                //printf("m: %f \n", particleData->m[i]);
                particleData->a[particles+ghosts-1] = particleData->a[i];
                particleData->rho[particles+ghosts-1] = particleData->rho[i];
                //printf("rho %f \n", particleData->rho[i]);
                particleData->P[particles+ghosts-1] = particleData->P[i];
                particleData->u[particles+ghosts-1] = particleData->u[i];
                particleData->exists[particles+ghosts-1] = true;
}

int setGhosts(int particles, struct arrays *particleData){
    for (int i=particles; i<noghost; i++){
         particleData->exists[i] = false;

     }

    int ghosts = 0;
    
    if (isSod == 1){
        double leftbound = particleData->x[0];
        double rightbound = particleData->x[particles-1];
        double dxleft;
        double dxright;
        
        #ifdef spcright
        dxright = spcright;
        #endif
        
        //printf("Leftbound %f \n",leftbound);
        //printf("Rightbound %f \n",rightbound);
        //exit(0);
        for (int i=1; i<4; i++){
            //printf("Ghosts: %d \n",ghosts);
            ghosts+=1;
            particleData->x[particles+ghosts-1] = leftbound - i*(dxright);
            setData(0,particles,ghosts,particleData);
            ghosts+=1;
            particleData->x[particles+ghosts-1] = rightbound + i*(dxright);
            setData(particles-1,particles,ghosts,particleData);

        }

        return ghosts;
    }
    
    double range = xmax - xmin;
    for (int i=0; i<particles; i++){
        //printf("Ghosts: %d \n",ghosts);    
        if (particleData->x[i] + 2.0*particleData->h[i] > xmax){
                ghosts+=1;
                //printf("ghostindex: %d \n", particles+ghosts-1);
                particleData->x[particles+ghosts-1] = particleData->x[i] - range;
                setData(i,particles,ghosts,particleData);
            
            } else if (particleData->x[i] - 2.0*particleData->h[i] < xmin){
                ghosts+=1;
                //printf("ghostindex: %d \n", particles+ghosts-1);
                particleData->x[particles+ghosts-1] =  particleData->x[i]+range;
                setData(i,particles,ghosts,particleData);
                
            }
            
    }

    return ghosts;

}

