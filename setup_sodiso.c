#include "setup.h"
#include "const.h"
#include "particledata.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int setup(struct particledata *particleData){
    double rholeft = 1.0;
    double rhoright = 0.1;
    double dxleft = 0.001;
    double dxright = 0.01;

    // Not really necessary but lets make this explicit
    double mid1 = -1.0;
    double mid2 = 0.0;

    //#define xmin sod1
    //#define xmax sod2

    double startleft = sod1 + 0.5*dxleft;
    double startright = mid2 + 0.5*dxright;

    int particleNo = 0;
    int particleIndex = 0;
    double x = xmin + 0.5*dxright;

    // L.H.S

    while (x<mid1){

        particleNo+=1;
        printf("ParticleNo: %d \n",particleNo);
        // Check that we have not exceeded maxp
        if (particleNo > nopart){
            printf("Need a larger MaxP!\n");
            exit(1);
        }
        
        // Set Particle Position
        particleData[particleIndex].x[0] = x;

        // velocity is 0
        particleData[particleIndex].v[0] = 0.0;

        // Set Smoothing Link
        particleData[particleIndex].h = 1.2*dxright;
        // A Real Particle
        particleData[particleIndex].exists = true;
        // Set Mass
        particleData[particleIndex].m = rhoright*dxright; 
        particleData[particleIndex].u = 2.0;
        // move to next particle
        x += dxright;
        particleIndex++;

    }

    x = mid1 + 0.5*dxleft;
    while (x <  sod1){
    
        particleNo+=1;
        printf("Particle is: %d \n",particleNo);
        // Check that we have not exceeded maxp
        if (particleNo > nopart){
            printf("Need a larger MaxP!\n");
            exit(1);
        }
        
        // Set Particle Position
        particleData[particleIndex].x[0] = x;

        // velocity is 0
        particleData[particleIndex].v[0] = 0.0;

        // Set Smoothing Link
        particleData[particleIndex].h = 1.2*dxleft;
        // A Real Particle
        particleData[particleIndex].exists = true;
        particleData[particleIndex].m = rholeft*dxleft;
        particleData[particleIndex].u = 2.5;
        // move to next particle
        x += dxleft;
        particleIndex++;
    }
    x = startleft;
    while (x <  mid2){
    
        particleNo+=1;
        printf("Particle is: %d \n",particleNo);
        // Check that we have not exceeded maxp
        if (particleNo > nopart){
            printf("Need a larger MaxP!\n");
            exit(1);
        }
        
        // Set Particle Position
        particleData[particleIndex].x[0] = x;

        // velocity is 0
        particleData[particleIndex].v[0] = 0.0;

        // Set Smoothing Link
        particleData[particleIndex].h = 1.2*dxleft;
        // A Real Particle
        particleData[particleIndex].exists = true;
        particleData[particleIndex].m = rholeft*dxleft;
        particleData[particleIndex].u = 2.5;
        // move to next particle
        x += dxleft;
        particleIndex++;
    }
    x = startright;
    while (x <  xmax){
    
        particleNo+=1;
        printf("Particle is: %d \n",particleNo);
        // Check that we have not exceeded maxp
        if (particleNo > nopart){
            printf("Need a larger MaxP!\n");
            exit(1);
        }
        
        // Set Particle Position
        particleData[particleIndex].x[0] = x;

        // velocity is 0
        particleData[particleIndex].v[0] = 0.0;

        // Set Smoothing Link
        particleData[particleIndex].h = 1.2*dxright;
        // A Real Particle
        particleData[particleIndex].exists = true;
        particleData[particleIndex].m = rhoright*dxright;
        particleData[particleIndex].u = 2.0;
        // move to next particle
        x += dxright;
        particleIndex++;
    }


    return particleNo;

}
