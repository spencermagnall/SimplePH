#include "setup.h"
#include "arrays.h"
#include "const.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int setup(struct arrays *particleData){
    // SETUP PARTICLES
    //double xmin = 0.0;
    //double xmax = 1.0;
    double cs = 1.0;
    // rho is const
    double rho0 = 1.0;
    double start = 0.05;
    double dx  = (xmax)/nopart;
    printf("dx: %f \n", dx);
    start = 0.5*dx;
    
    double x = start;
    int particleNo = 0;
    int particleIndex = 0;


    while(x < xmax){
        
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
        x = 0.5*dx + (particleNo*dx);
        particleIndex++;
        
            
    }

    // setup mass distribution
    double mpart = rho0*dx;
    for (int i=0; i < particleIndex ; i++){
        particleData->m[i] = mpart;
        printf("index is: %d \n ",i);
    }
    return particleNo;
}
