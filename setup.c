#include "setup.h"
#include "arrays.h"
#include "const.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int setup(struct arrays *particleData){
    // SETUP PARTICLES
    // Should migrate some of these values to const
    //float xmin = 0.0;
    //float xmax = 1.0;
    float cs = 1.0;
    // rho is const
    float rho0 = 1.0;
    // Should dx be a fixed value that determines
    // no part setup ???
    // float dx = (xmax-xmin)/nopart;
     float dx  = 1./99.;      
     //for 0-1 inclusive
    //float dx = 0.99
    // float drho = (rho0)/nopart;
    //printf("%f",drho);
    float x = xmin;
    int particleNo = 0;
    int particleIndex = 0;

    // Particles should not be allowed to be placed on boundaries
    // i.e start at xmin+dx and end at xmax-dx or vice-versa
    // have to handle boundary conditions carefully with ghost particles

    while(x < xmax + dx ){
       
        particleNo+= 1;
        printf("Particle no: %d \n",particleNo);
        printf("%f \n", x);  
        
        // Check that we have not exceeded maxp
        if (particleNo  > nopart){
            printf("Need a larger MaxP!\n");
            exit(1);
        }

        
        
        // Set Particle Position
        particleData->x[particleIndex] = x;
        
        // Set Mass
        // particleData->m[i] = drho;
        // Have to set mass later 

        // Set Velocity
        particleData->v[particleIndex] = cs*1.e-4*sin(2*M_PI*x);
        // Set Smoothing Link
        particleData->h[particleIndex] = 1.2*dx;
        // A real particle
        particleData->exists[particleIndex] = true;
        // Move to next particle 
        x+=dx;
        particleIndex++;
        
            
    }

    // setup mass distribution
    float mpart = rho0*dx;
    for (int i=0; i < particleIndex ; i++){
        particleData->m[i] = mpart;
        printf("index is: %d \n ",i);
    }
    return particleNo;
}
