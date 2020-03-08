#include "setup.h"
#include "arrays.h"
#include "const.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int setup(struct arrays *particleData){
    // SETUP PARTICLES
    float xmin = 0.0;
    float xmax = 1.0;
    float cs = 1.0;
    // rho is const
    float rho0 = 1.0;
    // Should dx be a fixed value that determines
    // no part setup ???
    // float dx = (xmax-xmin)/nopart;
    float dx  = 0.01;
    // float drho = (rho0)/nopart;
    //printf("%f",drho);
    float x = xmin;
    int particleNo = 0;
    while(x < xmax){
        
        // Check that we have not exceeded maxp
        if (particleNo > nopart){
            printf("Need a larger MaxP!\n");
            exit(1);
        }

        printf("%d \n",particleNo);
        
        // Set Particle Position
        particleData->x[particleNo] = x;
        
        // Set Mass
        // particleData->m[i] = drho;
        // Have to set mass later 

        // Set Velocity
        particleData->v[particleNo] = cs*1.e-4*sin(x);
        // Set Smoothing Link
        particleData->h[particleNo] = 1.2*dx;
       
        // Move to next particle 
        x+=dx;
        particleNo+= 1;
            
    }

    // setup mass distribution
    float mpart = rho0/particleNo;
    for (int i=0; i < particleNo; i++){
        particleData->m[i] = mpart;
    }
    return particleNo;
}
