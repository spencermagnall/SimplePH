#include <stdio.h>
#include "allocate.h"
#include "arrays.h"
#include "application.h"
#include "setup.h"
#include "output.h"
#include "ghosts.h"
#include "density.h"
#include "derivs.h"
#include "kinetic.h"
#include "step.h"

#include <stdlib.h>

void application(){
    printf("Entered Application \n");
    double t = 0.0;
    double tmax = 5.0;
    printf("Working Correctly\n");
    printf("xmin: %f \n",xmin);
    printf("xmax: %f \n",xmax);
    printf("IsSod: %d \n", isSod);
    struct arrays particleData;
    int ifile = 1;
    double tprint = (double)ifile*dtout;
    
    allocate(&particleData);
    // This would be easy in c++ 
    for (int i=0; i < nopart+noghost; i++){
        printf("i = %d \n",i);
        particleData.exists[i] = false;
    }
    printf("Particles exist! \n");
    int particles = setup(&particleData);
    printf("Particles Setup: %d \n",particles);
    printf("xmin %f \n",xmin);
    printf("xmax %f \n", xmax);
    derivs(particles,&particleData);
    //exit(0);
    printf("Derivs passed. \n");
    writeOutput(particles, &particleData,0,t);
    outputEnergy(particles, &particleData,0,t);
    printf("Write output passed \n");
    //exit(0);
    while (t < tmax){
        t += dt;
        for (int i=nopart; i<nopart+noghost; i++){
            particleData.exists[i] = false;

        }
        step(particles, &particleData);
        printf("Time is: %f \n", t);
        outputEnergy(particles,&particleData,ifile,t);
        if (t > tprint){
            writeOutput(particles, &particleData,ifile,t);
            ifile += 1;
            tprint = (double) ifile*dtout;
            //exit(0);
            if (ifile == 10){
                //exit(0);
            }
        }
    }


}
