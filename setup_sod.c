#include "setup.h"
#include "arrays.h"
//#include "const.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int setup(struct arrays *particleData){
    double rholeft = 1.0;
    double rhoright = 0.1;
    double dxleft = 0.001;
    double dxright = 0.01;

    // Not really necessary but lets make this explicit
    double mid = 0.0;

    double startleft = sod1 + 0.5*dxleft;
    double endleft = mid-0.5*dxleft;
    double startright = mid + 0.5*dxright;
    double endright = sod2 - 0.5*dxright;

    int particleNo = 0;
    int particleIndex = 0;
    double x = startleft;

    // L.H.S

    while (x<mid){

        particleNo+=1;
        printf("ParticleNo: %d \n",particleNo);
        // Check that we have not exceeded maxp
        if (particleNo > nopart){
            printf("Need a larger MaxP!\n");
            exit(1);
        }
        
        // Set Particle Position
        particleData->x[particleIndex] = x;

        // velocity is 0
        particleData->v[particleIndex] = 0.0;

        // Set Smoothing Link
        particleData->h[particleIndex] = 1.2*dxleft;
        // A Real Particle
        particleData->exists[particleIndex] = true;
        // move to next particle
        x += dxleft;
        particleIndex++;

    }

    x = startright;

    while (x <  sod2){
    
        particleNo+=1;
        printf("Particle is: %d \n",particleNo);
        // Check that we have not exceeded maxp
        if (particleNo > nopart){
            printf("Need a larger MaxP!\n");
            exit(1);
        }
        
        // Set Particle Position
        particleData->x[particleIndex] = x;

        // velocity is 0
        particleData->v[particleIndex] = 0.0;

        // Set Smoothing Link
        particleData->h[particleIndex] = 1.2*dxright;
        // A Real Particle
        particleData->exists[particleIndex] = true;
        // move to next particle
        x += dxright;
        particleIndex++;
    }

    return particleNo;

}
