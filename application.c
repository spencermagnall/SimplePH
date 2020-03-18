#include <stdio.h>
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
    double t = 0.0;
    double tmax = 5.0;
    printf("Working Correctly\n");
    struct arrays particleData;
    int ifile = 1;
    double tprint = (double)ifile*dtout;

    // This would be easy in c++ 
    for (int i=0; i < nopart+noghost; i++){
        particleData.exists[i] = false;
    }

    int particles = setup(&particleData);
    printf("Particles Setup: %d",particles);
    printf("\n");
    //exit(0);
    // passes particles-1 since arrays start at 0
    //setGhosts(particles,&particleData);
    //printf("SetGhost passed. \n");
    //getDensity(particles,&particleData);
    //printf("Density calc passed. \n");
    derivs(particles,&particleData);
    printf("Derivs passed. \n");
    writeOutput(particles, &particleData,0,t);
    printf("Write output passed \n");
    //exit(0);
    while (t < tmax){
        t += dt;
        for (int i=nopart; i<nopart+noghost; i++){
            particleData.exists[i] = false;

        }
        step(particles, &particleData);
        printf("Time is: %f \n", t);
        //double ke = getKinetic(particles,&particleData);
        //printf("Kinetic Energy: %f \n",ke);
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
